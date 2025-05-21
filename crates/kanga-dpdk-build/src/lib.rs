use {
    pkg_config::Config as PkgConfig,
    std::{
        error::Error,
        fs::{File, exists},
        io::{BufRead, BufReader, Result as IoResult, Write, stdout},
        path::PathBuf,
    },
};

pub use {bindgen, pkg_config};
pub type BindgenBuilder = bindgen::Builder;
pub type BoxError = Box<dyn Error + Send + Sync + 'static>;

const ALLOWLIST_FILE_NAME: &str = "allowlist.txt";
const BLOCKLIST_FILE_NAME: &str = "blocklist.txt";

/// Information about the DPDK library.
#[derive(Clone, Debug)]
pub struct DpdkMetadata {
    /// The version of the DPDK library.
    pub version: String,

    /// Include paths for the DPDK library.
    pub include_paths: Vec<PathBuf>,

    /// Library paths for linking.
    pub link_paths: Vec<PathBuf>,

    /// The mode to use for linking.
    pub link_mode: LinkMode,
}

/// The mode to use for linking.
#[derive(Clone, Debug, Default, Eq, PartialEq)]
pub enum LinkMode {
    /// Default linking (dynamic if available, otherwise static).
    #[default]
    Default,

    /// Dynamic linking.
    Dynamic,

    /// Static linking.
    Static,
}

impl DpdkMetadata {
    /// Creates a new `DpdkMetadata` instance by probing for the DPDK package configuration.
    pub fn new() -> Result<Self, BoxError> {
        // Determine the link mode based on the environment variable or default to dynamic.
        let link_mode = LinkMode::from_cfg();

        let mut pkg_config = PkgConfig::new();
        pkg_config.cargo_metadata(false);

        if link_mode == LinkMode::Static {
            pkg_config.statik(true);
        }

        // Get pkg-config info about the DPDK libraries.
        let library = pkg_config.probe("libdpdk")?;

        Ok(Self::from_library_and_link_mode(library, link_mode))
    }

    /// Creates a new `DpdkMetadata` instance from the given library and link mode.
    pub fn from_library_and_link_mode(library: pkg_config::Library, link_mode: LinkMode) -> Self {
        Self {
            version: library.version,
            include_paths: library.include_paths,
            link_paths: library.link_paths,
            link_mode,
        }
    }

    /// Returns the major version of the DPDK library.
    #[inline(always)]
    pub fn major(&self) -> &str {
        self.version.split('.').next().expect("Invalid DPDK version")
    }

    /// Returns the minor version of the DPDK library.
    #[inline(always)]
    pub fn minor(&self) -> &str {
        self.version.split('.').nth(1).expect("Invalid DPDK version")
    }

    /// Returns the patch version of the DPDK library.
    #[inline(always)]
    pub fn patch(&self) -> Option<&str> {
        self.version.splitn(3, '.').nth(2)
    }

    /// Writes Cargo metadata to the specified writer.
    pub fn write_cargo_metadata<W: Write>(&self, w: &mut W) -> IoResult<()> {
        writeln!(w, r#"cargo::rustc-check-cfg=cfg(dpdk_link_mode, values("dynamic", "static"))"#)?;
        writeln!(w, "cargo::rustc-check-cfg=cfg(dpdk_major, values(any()))")?;
        writeln!(w, "cargo::rustc-check-cfg=cfg(dpdk_minor, values(any()))")?;
        writeln!(w, "cargo::rustc-check-cfg=cfg(dpdk_patch, values(any()))")?;

        for link_path in &self.link_paths {
            writeln!(w, "cargo::rustc-link-search=native={}", link_path.display())?;
        }

        if exists(ALLOWLIST_FILE_NAME).expect("Unable to check for allowlist.txt") {
            writeln!(w, "cargo::rerun-if-changed={ALLOWLIST_FILE_NAME}")?;
        }
        if exists(BLOCKLIST_FILE_NAME).expect("Unable to check for blocklist.txt") {
            writeln!(w, "cargo::rerun-if-changed={BLOCKLIST_FILE_NAME}")?;
        }

        Ok(())
    }

    /// Prints Cargo metadata to stdout.
    pub fn print_cargo_metadata(&self) -> IoResult<()> {
        self.write_cargo_metadata(&mut stdout())
    }

    /// Writes Cargo metadata to link a library.
    pub fn write_lib_link(&self, lib: &str, w: &mut dyn Write) -> IoResult<()> {
        match self.link_mode {
            LinkMode::Default => writeln!(w, "cargo:rustc-link-lib={lib}")?,
            LinkMode::Dynamic => writeln!(w, "cargo:rustc-link-lib=dylib={lib}")?,
            LinkMode::Static => writeln!(w, "cargo:rustc-link-lib=static={lib}")?,
        }
        Ok(())
    }

    /// Prints Cargo metadata to link a library to stdout
    pub fn print_lib_link(&self, lib: &str) {
        self.write_lib_link(lib, &mut stdout()).unwrap_or_else(|_| {
            panic!("Unable to write library link for {lib}");
        });
    }

    /// Creates a bindgen builder that consumes the specified header file and processes
    /// `allowlist.txt` and `blocklist.txt` files if they exist.
    pub fn bindgen_builder(&self, header: &str) -> BindgenBuilder {
        let mut builder = self
            .add_include_paths(BindgenBuilder::default())
            .header(header)
            .generate_cstr(true)
            .wrap_unsafe_ops(true)
            .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()));

        if let Ok(allow) = File::open(ALLOWLIST_FILE_NAME) {
            let allow = BufReader::new(allow);
            for line in allow.lines() {
                let line = line.unwrap_or_else(|_| panic!("Unable to read line from {ALLOWLIST_FILE_NAME}"));
                let line = line.trim();
                if !line.is_empty() {
                    builder = builder.allowlist_item(line.trim());
                }
            }
        }

        if let Ok(block) = File::open(BLOCKLIST_FILE_NAME) {
            let block = BufReader::new(block);
            for line in block.lines() {
                let line = line.unwrap_or_else(|_| panic!("Unable to read line from {BLOCKLIST_FILE_NAME}"));
                let line = line.trim();
                if !line.is_empty() {
                    builder = builder.blocklist_item(line.trim());
                }
            }
        }

        builder
    }

    /// Adds include paths to a bindgen builder.
    fn add_include_paths(&self, builder: BindgenBuilder) -> BindgenBuilder {
        let mut builder = builder;

        for include_path in &self.include_paths {
            builder = builder.clang_arg(format!("-I{}", include_path.display()));
        }

        builder
    }
}

impl LinkMode {
    /// Returns the link mode based on cfg attributes.
    pub fn from_cfg() -> Self {
        if cfg!(dpdk_link_mode = "dynamic") {
            LinkMode::Dynamic
        } else if cfg!(dpdk_link_mode = "static") {
            LinkMode::Static
        } else {
            LinkMode::Default
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_dpdk_metadata() {
        let metadata = DpdkMetadata::new().expect("Unable to get DPDK metadata");
        println!("DPDK Version: {}", metadata.version);
        println!("Include Paths: {:?}", metadata.include_paths);
        println!("Link Paths: {:?}", metadata.link_paths);
        println!("Link Mode: {:?}", metadata.link_mode);
    }
}

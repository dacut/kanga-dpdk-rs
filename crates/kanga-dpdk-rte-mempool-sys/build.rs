use {
    kanga_dpdk_build::DpdkMetadata,
    std::{env, path::PathBuf},
};

fn main() {
    let metadata = DpdkMetadata::new().expect("Unable to get DPDK metadata");
    metadata.print_cargo_metadata().expect("Unable to print DPDK metadata");
    metadata.print_lib_link("rte_mempool");
    metadata.print_lib_link("rte_eal");
    metadata.print_lib_link("rte_ring");
    metadata.print_lib_link("rte_telemetry");

    // We need accessors to the static inline functions in the C code
    cc::Build::new()
    .includes(&metadata.include_paths)
        .file("rust_accessors.c")
        .static_flag(true)
        .flag_if_supported("-Werror")
        .flag_if_supported("-Wno-deprecated-declarations")
        .flag_if_supported("-mssse3")
        .compile("rte_mempool_rust_accessors");
    println!("cargo:rustc-link-lib=static=rte_mempool_rust_accessors");

    let bindings = metadata.bindgen_builder("bindings.h").generate().expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").expect("OUT_DIR not set"));
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .unwrap_or_else(|_| panic!("Failed to write bindings to {}", out_path.display()));
}

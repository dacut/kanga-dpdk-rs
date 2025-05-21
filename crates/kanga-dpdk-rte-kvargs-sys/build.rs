use {
    kanga_dpdk_build::DpdkMetadata,
    std::{env, path::PathBuf},
};

fn main() {
    let metadata = DpdkMetadata::new().expect("Unable to get DPDK metadata");
    metadata.print_cargo_metadata().expect("Unable to print DPDK metadata");
    metadata.print_lib_link("rte_kvargs");
    let bindings = metadata.bindgen_builder("bindings.h").generate().expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").expect("OUT_DIR not set"));
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .unwrap_or_else(|_| panic!("Failed to write bindings to {}", out_path.display()));
}

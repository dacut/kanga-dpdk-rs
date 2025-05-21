#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(unsafe_op_in_unsafe_fn)]
#![allow(clippy::upper_case_acronyms)]

pub use {kanga_dpdk_rte_eal_sys::rte_memzone, libc::FILE};

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_rte_ring_memsize() {
        unsafe {
            let size = rte_ring_get_memsize(32);
            assert!(size > 0);
        }
    }
}

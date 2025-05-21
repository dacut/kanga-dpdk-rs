#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(unsafe_op_in_unsafe_fn)]
#![allow(clippy::upper_case_acronyms)]

pub use {
    kanga_dpdk_rte_eal_sys::{rte_iova_t, rte_memzone, rte_spinlock_t},
    libc::FILE,
};
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use {super::*, kanga_dpdk_rte_eal_sys::SOCKET_ID_ANY};

    #[test]
    fn test_mempool() {
        unsafe {
            let name = c"test_mempool".as_ptr();
            // This will fail; we haven't initialized DPDK.
            let mp = rte_mempool_create_empty(name, 1022, 800, 0, 0, SOCKET_ID_ANY, 0);
            assert!(mp.is_null());
        }
    }
}

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(unsafe_op_in_unsafe_fn)]
#![allow(clippy::upper_case_acronyms)]

pub type FILE = libc::FILE;
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use {super::*, kanga_dpdk_rte_eal_sys::{kanga_dpdk_rte_errno_get, SOCKET_ID_ANY}};

    #[test]
    fn test_mempool() {
        unsafe {
            let name = c"test_mempool".as_ptr();
            let mp = rte_mempool_create_empty(name, 1022, 800, 0, 0, SOCKET_ID_ANY, 0);
            assert!(!mp.is_null(), "Failed to create mempool: {}", kanga_dpdk_rte_errno_get());

            rte_mempool_free(mp);
        }
    }
}

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(unsafe_op_in_unsafe_fn)]
#![allow(clippy::upper_case_acronyms)]

pub use {kanga_dpdk_rte_eal_sys::rte_iova_t, kanga_dpdk_rte_mempool_sys::rte_mempool, libc::FILE};

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_mbuf_flag() {
        unsafe {
            let flag = rte_get_rx_ol_flag_name(1);
            assert!(!flag.is_null());
        }
    }
}

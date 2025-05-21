use kanga_dpdk_rte_eal_sys::kanga_dpdk_rte_errno_get;

pub fn main() {
    unsafe {
        let err = kanga_dpdk_rte_errno_get();
        println!("DPDK Error Number: {err}");
    }
}
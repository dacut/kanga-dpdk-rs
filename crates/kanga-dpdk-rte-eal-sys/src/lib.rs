#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(unsafe_op_in_unsafe_fn)]

pub use libc::{__s32, __u8, __u16, __u32, __u64, FILE, timespec};

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

unsafe extern "C" {
    pub unsafe fn kanga_dpdk_rte_errno_get() -> i32;
    pub unsafe fn kanga_dpdk_rte_errno_set(code: i32);
}

#[cfg(test)]
mod tests {
    use {super::*, std::ffi::CStr};

    #[test]
    fn test_errno() {
        unsafe {
            let err = kanga_dpdk_rte_errno_get();
            assert_eq!(err, 0);
        }
    }

    #[test]
    fn test_runtime_dir() {
        unsafe {
            let runtime_dir = rte_eal_get_runtime_dir();
            let runtime_dir_cstr = CStr::from_ptr(runtime_dir);
            let runtime_dir_str = runtime_dir_cstr.to_str().unwrap();
            println!("Runtime directory: {runtime_dir_str}");
        }
    }

    #[test]
    fn test_version() {
        unsafe {
            let version_prefix = CStr::from_ptr(rte_version_prefix());
            let version_year = rte_version_year();
            let version_month = rte_version_month();
            let version_minor = rte_version_minor();
            let version_suffix = CStr::from_ptr(rte_version_suffix());
            let version_release = rte_version_release();
            let version = CStr::from_ptr(rte_version());

            let version_prefix_str = version_prefix.to_str().unwrap();
            let version_suffix_str = version_suffix.to_str().unwrap();
            let version_str = version.to_str().unwrap();

            println!(
                "Version: prefix={version_prefix_str} year={version_year} month={version_month} minor={version_minor} suffix={version_suffix_str} release={version_release} versoion={version_str}"
            );
        }
    }
}

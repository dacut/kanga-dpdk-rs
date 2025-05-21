#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(unsafe_op_in_unsafe_fn)]
#![allow(clippy::upper_case_acronyms)]

pub use libc::FILE;
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use super::*;
 
    #[test]
    fn test_timer_alloc() {
        unsafe {
            // This fails since we haven't initialized the EAL.
            let _result = rte_timer_subsystem_init();
        }
    }
}

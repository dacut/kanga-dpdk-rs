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
    fn test_log_register() {
        let log_name = c"test_log";

        unsafe {
            let value1 = rte_log_register(log_name.as_ptr());
            let value2 = rte_log_register(log_name.as_ptr());

            assert!(value1 > 0);
            assert_eq!(value1, value2);
        }
    }

    #[test]
    fn test_log_types() {
        println!("RTE_LOGTYPE_EAL: {RTE_LOGTYPE_EAL}");
        println!("RTE_LOGTYPE_USER1: {RTE_LOGTYPE_USER1}");
        println!("RTE_LOGTYPE_USER2: {RTE_LOGTYPE_USER2}");
        println!("RTE_LOGTYPE_USER3: {RTE_LOGTYPE_USER3}");
        println!("RTE_LOGTYPE_USER4: {RTE_LOGTYPE_USER4}");
        println!("RTE_LOGTYPE_USER5: {RTE_LOGTYPE_USER5}");
        println!("RTE_LOGTYPE_USER6: {RTE_LOGTYPE_USER6}");
        println!("RTE_LOGTYPE_USER7: {RTE_LOGTYPE_USER7}");
        println!("RTE_LOGTYPE_USER8: {RTE_LOGTYPE_USER8}");
        println!("RTE_LOGTYPE_USER9: {RTE_LOGTYPE_FIRST_EXT_ID}");
    }

    #[test]
    fn test_log_levels() {
        println!("RTE_LOG_EMERG: {RTE_LOG_EMERG}");
        println!("RTE_LOG_ALERT: {RTE_LOG_ALERT}");
        println!("RTE_LOG_CRIT: {RTE_LOG_CRIT}");
        println!("RTE_LOG_ERR: {RTE_LOG_ERR}");
        println!("RTE_LOG_WARNING: {RTE_LOG_WARNING}");
        println!("RTE_LOG_NOTICE: {RTE_LOG_NOTICE}");
        println!("RTE_LOG_INFO: {RTE_LOG_INFO}");
        println!("RTE_LOG_DEBUG: {RTE_LOG_DEBUG}");
        println!("RTE_LOG_MAX: {RTE_LOG_MAX}");
    }
}

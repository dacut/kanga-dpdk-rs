#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(unsafe_op_in_unsafe_fn)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_alloc() {
        unsafe {
            let td = rte_tel_data_alloc();
            assert!(!td.is_null(), "Failed to allocate memory for rte_tel_data");
            let err = rte_tel_data_start_dict(td);
            assert_eq!(err, 0, "Failed to start dictionary");
            let err = rte_tel_data_add_dict_int(td, c"test_key".as_ptr(), 1234);
            assert_eq!(err, 0, "Failed to add integer to dictionary");
            rte_tel_data_free(td);
        }
    }
}
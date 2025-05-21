#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(unsafe_op_in_unsafe_fn)]
#![allow(clippy::upper_case_acronyms)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use super::*;
    use std::ptr::null;

    #[test]
    fn test_kvargs_parse() {
        let args = c"foo=bar,baz=qux".as_ptr();
        let valid_key_1 = c"foo".as_ptr();
        let valid_key_2 = c"baz".as_ptr();
        let valid_keys = [valid_key_1, valid_key_2, null()];
        
        unsafe {
            let kvargs = rte_kvargs_parse(args, valid_keys.as_ptr());
            assert_eq!((*kvargs).count, 2);
        }
    }
}
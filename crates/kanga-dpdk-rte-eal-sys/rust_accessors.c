#include "rust_accessors.h"

int kanga_dpdk_rte_errno_get(void)
{
    return rte_errno;
}

void kanga_dpdk_rte_errno_set(int err)
{
    rte_errno = err;
}
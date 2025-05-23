#include "rust_accessors.h"

uint32_t kanga_dpdk_rte_ring_get_prod_htd_max(const struct rte_ring *r)
{
    return rte_ring_get_prod_htd_max(r);
}

int kanga_dpdk_rte_ring_set_prod_htd_max(struct rte_ring *r, uint32_t v)
{
    return rte_ring_set_prod_htd_max(r, v);
}

uint32_t kanga_dpdk_rte_ring_get_cons_htd_max(const struct rte_ring *r)
{
    return rte_ring_get_cons_htd_max(r);
}

int kanga_dpdk_rte_ring_set_cons_htd_max(struct rte_ring *r, uint32_t v)
{
    return rte_ring_set_cons_htd_max(r, v);
}

unsigned int kanga_dpdk_rte_ring_count(const struct rte_ring *r)
{
    return rte_ring_count(r);
}

unsigned int kanga_dpdk_rte_ring_free_count(const struct rte_ring *r)
{
    return rte_ring_free_count(r);
}

int kanga_dpdk_rte_ring_full(const struct rte_ring *r)
{
    return rte_ring_full(r);
}

int kanga_dpdk_rte_ring_empty(const struct rte_ring *r)
{
    return rte_ring_empty(r);
}

unsigned int kanga_dpdk_rte_ring_get_size(const struct rte_ring *r)
{
    return rte_ring_get_size(r);
}

unsigned int kanga_dpdk_rte_ring_get_capacity(const struct rte_ring *r)
{
    return rte_ring_get_capacity(r);
}

enum rte_ring_sync_type kanga_dpdk_rte_ring_get_prod_sync_type(const struct rte_ring *r)
{
    return rte_ring_get_prod_sync_type(r);
}

int kanga_dpdk_rte_ring_is_prod_single(const struct rte_ring *r)
{
    return rte_ring_is_prod_single(r);
}

enum rte_ring_sync_type kanga_dpdk_rte_ring_get_cons_sync_type(const struct rte_ring *r)
{
    return rte_ring_get_cons_sync_type(r);
}

int kanga_dpdk_rte_ring_is_cons_single(const struct rte_ring *r)
{
    return rte_ring_is_cons_single(r);
}

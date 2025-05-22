#include "rust_accessors.h"

struct rte_mempool_objhdr *kanga_dpdk_rte_mempool_get_header(void *obj)
{
    return rte_mempool_get_header(obj);
}

struct rte_mempool *kanga_dpdk_rte_mempool_from_obj(void *obj)
{
    return rte_mempool_from_obj(obj);
}

struct rte_mempool_objtlr *kanga_dpdk_rte_mempool_get_trailer(void *obj)
{
    return rte_mempool_get_trailer(obj);
}

struct rte_mempool_ops *kanga_dpdk_rte_mempool_get_ops(int ops_index)
{
    return rte_mempool_get_ops(ops_index);
}

int kanga_dpdk_rte_mempool_ops_dequeue_contig_blocks(struct rte_mempool *mp, void **first_obj_table, unsigned int n)
{
    return rte_mempool_ops_dequeue_contig_blocks(mp, first_obj_table, n);
}

int kanga_dpdk_rte_mempool_full(const struct rte_mempool *mp)
{
    return rte_mempool_full(mp);
}

int kanga_dpdk_rte_mempool_empty(const struct rte_mempool *mp)
{
    return rte_mempool_empty(mp);
}

rte_iova_t kanga_dpdk_rte_mempool_virt2iova(const void *elt)
{
    return rte_mempool_virt2iova(elt);
}

void *kanga_dpdk_rte_mempool_get_priv(struct rte_mempool *mp)
{
    return rte_mempool_get_priv(mp);
}
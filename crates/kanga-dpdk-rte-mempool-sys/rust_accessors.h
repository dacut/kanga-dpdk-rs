#include <rte_common.h>
#include <rte_mempool.h>
#include <rte_mempool_trace_fp.h>

struct rte_mempool_objhdr *kanga_dpdk_rte_mempool_get_header(void *obj);
struct rte_mempool *kanga_dpdk_rte_mempool_from_obj(void *obj);
struct rte_mempool_objtlr *kanga_dpdk_rte_mempool_get_trailer(void *obj);
struct rte_mempool_ops *kanga_dpdk_rte_mempool_get_ops(int ops_index);
int kanga_dpdk_rte_mempool_ops_dequeue_contig_blocks(struct rte_mempool *mp, void **first_obj_table, unsigned int n);
int kanga_dpdk_rte_mempool_full(const struct rte_mempool *mp);
int kanga_dpdk_rte_mempool_empty(const struct rte_mempool *mp);
rte_iova_t kanga_dpdk_rte_mempool_virt2iova(const void *elt);

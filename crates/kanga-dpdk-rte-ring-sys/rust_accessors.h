#include <rte_ring.h>

uint32_t kanga_dpdk_rte_ring_get_prod_htd_max(const struct rte_ring *r);
int kanga_dpdk_rte_ring_set_prod_htd_max(struct rte_ring *r, uint32_t v);
uint32_t kanga_dpdk_rte_ring_get_cons_htd_max(const struct rte_ring *r);
int kanga_dpdk_rte_ring_set_cons_htd_max(struct rte_ring *r, uint32_t v);
unsigned int kanga_dpdk_rte_ring_count(const struct rte_ring *r);
unsigned int kanga_dpdk_rte_ring_free_count(const struct rte_ring *r);
int kanga_dpdk_rte_ring_full(const struct rte_ring *r);
int kanga_dpdk_rte_ring_empty(const struct rte_ring *r);
unsigned int kanga_dpdk_rte_ring_get_size(const struct rte_ring *r);
unsigned int kanga_dpdk_rte_ring_get_capacity(const struct rte_ring *r);
enum rte_ring_sync_type kanga_dpdk_rte_ring_get_prod_sync_type(const struct rte_ring *r);
int kanga_dpdk_rte_ring_is_prod_single(const struct rte_ring *r);
enum rte_ring_sync_type kanga_dpdk_rte_ring_get_cons_sync_type(const struct rte_ring *r);
int kanga_dpdk_rte_ring_is_cons_single(const struct rte_ring *r);

#include <rte_mbuf.h>

void kanga_dpdk_rte_mbuf_prefetch_part1(struct rte_mbuf *m);
void kanga_dpdk_rte_mbuf_prefetch_part2(struct rte_mbuf *m);
rte_iova_t kanga_dpdk_rte_mbuf_iova_get(struct rte_mbuf *m);
void kanga_dpdk_rte_mbuf_iova_set(struct rte_mbuf *m, rte_iova_t iova);
rte_iova_t kanga_dpdk_rte_mbuf_data_iova(const struct rte_mbuf *mb);
rte_iova_t kanga_dpdk_rte_mbuf_data_iova_default(const struct rte_mbuf *mb);
struct rte_mbuf *kanga_dpdk_rte_mbuf_from_indirect(struct rte_mbuf *mi);
char *kanga_dpdk_rte_mbuf_buf_addr(struct rte_mbuf *mb, struct rte_mempool *mp);
char *kanga_dpdk_rte_mbuf_data_addr_default(struct rte_mbuf *mb);
char *kanga_dpdk_rte_mbuf_to_baddr(struct rte_mbuf *md);
void *kanga_dpdk_rte_mbuf_to_priv(struct rte_mbuf *m);
uint32_t kanga_dpdk_rte_pktmbuf_priv_flags(struct rte_mempool *mp);
uint16_t kanga_dpdk_rte_mbuf_refcnt_read(const struct rte_mbuf *m);
void kanga_dpdk_rte_mbuf_refcnt_set(struct rte_mbuf *m, uint16_t new_value);
uint16_t kanga_dpdk_rte_mbuf_refcnt_update(struct rte_mbuf *m, int16_t value);
uint16_t kanga_dpdk_rte_mbuf_refcnt_read(const struct rte_mbuf *m);
void kanga_dpdk_rte_mbuf_refcnt_set(struct rte_mbuf *m, uint16_t new_value);
uint16_t kanga_dpdk_rte_mbuf_ext_refcnt_update(struct rte_mbuf_ext_shared_info *shinfo, int16_t value);
struct rte_mbuf *kanga_dpdk_rte_mbuf_raw_alloc(struct rte_mempool *mp);
uint16_t kanga_dpdk_rte_pktmbuf_data_room_size(struct rte_mempool *mp);
uint16_t kanga_dpdk_rte_pktmbuf_priv_size(struct rte_mempool *mp);
void kanga_dpdk_rte_pktmbuf_reset_headroom(struct rte_mbuf *m);
void kanga_dpdk_rte_pktmbuf_reset(struct rte_mbuf *m);
struct rte_mbuf *kanga_dpdk_rte_pktmbuf_alloc(struct rte_mempool *mp);
int kanga_dpdk_rte_pktmbuf_alloc_bulk(struct rte_mempool *pool, struct rte_mbuf **mbufs, unsigned count);
struct rte_mbuf_ext_shared_info *kanga_dpdk_rte_pktmbuf_ext_shinfo_init_helper(
    void *buf_addr, uint16_t *buf_len, rte_mbuf_extbuf_free_callback_t free_cb, void *fcb_opaque);
void kanga_dpdk_rte_pktmbuf_attach_extbuf(
    struct rte_mbuf *m, void *buf_addr, rte_iova_t buf_iova, uint16_t buf_len, struct rte_mbuf_ext_shared_info *shinfo);
void kanga_dpdk_rte_mbuf_dynfield_copy(struct rte_mbuf *mdst, const struct rte_mbuf *msrc);
void kanga_dpdk_rte_pktmbuf_attach(struct rte_mbuf *mi, struct rte_mbuf *m);
void kanga_dpdk_rte_pktmbuf_detach(struct rte_mbuf *m);
void kanga_dpdk_rte_pktmbuf_free(struct rte_mbuf *m);
void kanga_dpdk_rte_pktmbuf_refcnt_update(struct rte_mbuf *m, int16_t v);
uint16_t kanga_dpdk_rte_pktmbuf_headroom(const struct rte_mbuf *m);
uint16_t kanga_dpdk_rte_pktmbuf_tailroom(const struct rte_mbuf *m);
struct rte_mbuf *kanga_dpdk_rte_pktmbuf_lastseg(struct rte_mbuf *m);
uint32_t kanga_dpdk_rte_pktmbuf_pkt_len(struct rte_mbuf *m);
uint16_t kanga_dpdk_rte_pktmbuf_data_len(struct rte_mbuf *m);
char *kanga_dpdk_rte_pktmbuf_prepend(struct rte_mbuf *m, uint16_t len);
char *kanga_dpdk_rte_pktmbuf_append(struct rte_mbuf *m, uint16_t len);
char *kanga_dpdk_rte_pktmbuf_adj(struct rte_mbuf *m, uint16_t len);
int kanga_dpdk_rte_pktmbuf_trim(struct rte_mbuf *m, uint16_t len);
int kanga_dpdk_rte_pktmbuf_is_contiguous(const struct rte_mbuf *m);
const void *kanga_dpdk_rte_pktmbuf_read(const struct rte_mbuf *m, uint32_t off, uint32_t len, void *buf);
int kanga_dpdk_rte_pktmbuf_chain(struct rte_mbuf *head, struct rte_mbuf *tail);
int kanga_dpdk_rte_validate_tx_offload(const struct rte_mbuf *m);
int kanga_dpdk_rte_pktmbuf_linearize(struct rte_mbuf *mbuf);
uint32_t kanga_dpdk_rte_mbuf_sched_queue_get(const struct rte_mbuf *m);
uint8_t kanga_dpdk_rte_mbuf_sched_traffic_class_get(const struct rte_mbuf *m);
uint8_t kanga_dpdk_rte_mbuf_sched_color_get(const struct rte_mbuf *m);
void kanga_dpdk_rte_mbuf_sched_get(
    const struct rte_mbuf *m, uint32_t *queue_id, uint8_t *traffic_class, uint8_t *color);
void kanga_dpdk_rte_mbuf_sched_queue_set(struct rte_mbuf *m, uint32_t queue_id);
void kanga_dpdk_rte_mbuf_sched_traffic_class_set(struct rte_mbuf *m, uint8_t traffic_class);
void kanga_dpdk_rte_mbuf_sched_color_set(struct rte_mbuf *m, uint8_t color);
void kanga_dpdk_rte_mbuf_sched_set(
    struct rte_mbuf *m, uint32_t queue_id, uint8_t traffic_class, uint8_t color);

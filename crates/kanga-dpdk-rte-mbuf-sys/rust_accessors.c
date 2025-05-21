#include "rust_accessors.h"

void kanga_dpdk_rte_mbuf_prefetch_part1(struct rte_mbuf *m)
{
    rte_mbuf_prefetch_part1(m);
}

void kanga_dpdk_rte_mbuf_prefetch_part2(struct rte_mbuf *m)
{
    rte_mbuf_prefetch_part2(m);
}

rte_iova_t kanga_dpdk_rte_mbuf_iova_get(struct rte_mbuf *m)
{
    return rte_mbuf_iova_get(m);
}

void kanga_dpdk_rte_mbuf_iova_set(struct rte_mbuf *m, rte_iova_t iova)
{
    rte_mbuf_iova_set(m, iova);
}

rte_iova_t kanga_dpdk_rte_mbuf_data_iova(const struct rte_mbuf *mb)
{
    return rte_mbuf_data_iova(mb);
}

rte_iova_t kanga_dpdk_rte_mbuf_data_iova_default(const struct rte_mbuf *mb)
{
    return rte_mbuf_data_iova_default(mb);
}

struct rte_mbuf *kanga_dpdk_rte_mbuf_from_indirect(struct rte_mbuf *mi)
{
    return rte_mbuf_from_indirect(mi);
}

char *kanga_dpdk_rte_mbuf_buf_addr(struct rte_mbuf *mb, struct rte_mempool *mp)
{
    return rte_mbuf_buf_addr(mb, mp);
}

char *kanga_dpdk_rte_mbuf_data_addr_default(struct rte_mbuf *mb)
{
    return rte_mbuf_data_addr_default(mb);
}

char *kanga_dpdk_rte_mbuf_to_baddr(struct rte_mbuf *md)
{
    return rte_mbuf_to_baddr(md);
}

void *kanga_dpdk_rte_mbuf_to_priv(struct rte_mbuf *m)
{
    return rte_mbuf_to_priv(m);
}

uint32_t kanga_dpdk_rte_pktmbuf_priv_flags(struct rte_mempool *mp)
{
    return rte_pktmbuf_priv_flags(mp);
}

uint16_t kanga_dpdk_rte_mbuf_refcnt_read(const struct rte_mbuf *m)
{
    return rte_mbuf_refcnt_read(m);
}

void kanga_dpdk_rte_mbuf_refcnt_set(struct rte_mbuf *m, uint16_t new_value)
{
    rte_mbuf_refcnt_set(m, new_value);
}

uint16_t kanga_dpdk_rte_mbuf_refcnt_update(struct rte_mbuf *m, int16_t value)
{
    return rte_mbuf_refcnt_update(m, value);
}

uint16_t kanga_dpdk_rte_mbuf_ext_refcnt_read(const struct rte_mbuf_ext_shared_info *shinfo)
{
    return rte_mbuf_ext_refcnt_read(shinfo);
}

void kanga_dpdk_rte_mbuf_ext_refcnt_set(struct rte_mbuf_ext_shared_info *shinfo, uint16_t new_value)
{
    rte_mbuf_ext_refcnt_set(shinfo, new_value);
}

uint16_t kanga_dpdk_rte_mbuf_ext_refcnt_update(struct rte_mbuf_ext_shared_info *shinfo, int16_t value)
{
    return rte_mbuf_ext_refcnt_update(shinfo, value);
}

struct rte_mbuf *kanga_dpdk_rte_mbuf_raw_alloc(struct rte_mempool *mp)
{
    return rte_mbuf_raw_alloc(mp);
}

uint16_t kanga_dpdk_rte_pktmbuf_data_room_size(struct rte_mempool *mp)
{
    return rte_pktmbuf_data_room_size(mp);
}

uint16_t kanga_dpdk_rte_pktmbuf_priv_size(struct rte_mempool *mp)
{
    return rte_pktmbuf_priv_size(mp);
}

void kanga_dpdk_rte_pktmbuf_reset_headroom(struct rte_mbuf *m)
{
    rte_pktmbuf_reset_headroom(m);
}

void kanga_dpdk_rte_pktmbuf_reset(struct rte_mbuf *m)
{
    rte_pktmbuf_reset(m);
}

struct rte_mbuf *kanga_dpdk_rte_pktmbuf_alloc(struct rte_mempool *mp)
{
    return rte_pktmbuf_alloc(mp);
}

int kanga_dpdk_rte_pktmbuf_alloc_bulk(struct rte_mempool *pool, struct rte_mbuf **mbufs, unsigned count)
{
    return rte_pktmbuf_alloc_bulk(pool, mbufs, count);
}

struct rte_mbuf_ext_shared_info *kanga_dpdk_rte_pktmbuf_ext_shinfo_init_helper(
    void *buf_addr, uint16_t *buf_len, rte_mbuf_extbuf_free_callback_t free_cb, void *fcb_opaque)
{
    return rte_pktmbuf_ext_shinfo_init_helper(buf_addr, buf_len, free_cb, fcb_opaque);
}

void kanga_dpdk_rte_pktmbuf_attach_extbuf(
    struct rte_mbuf *m, void *buf_addr, rte_iova_t buf_iova, uint16_t buf_len, struct rte_mbuf_ext_shared_info *shinfo)
{
    rte_pktmbuf_attach_extbuf(m, buf_addr, buf_iova, buf_len, shinfo);
}

void kanga_dpdk_rte_mbuf_dynfield_copy(struct rte_mbuf *mdst, const struct rte_mbuf *msrc)
{
    rte_mbuf_dynfield_copy(mdst, msrc);
}

void kanga_dpdk_rte_pktmbuf_attach(struct rte_mbuf *mi, struct rte_mbuf *m)
{
    rte_pktmbuf_attach(mi, m);
}

void kanga_dpdk_rte_pktmbuf_detach(struct rte_mbuf *m)
{
    rte_pktmbuf_detach(m);
}

void kanga_dpdk_rte_pktmbuf_free(struct rte_mbuf *m)
{
    rte_pktmbuf_free(m);
}

void kanga_dpdk_rte_pktmbuf_refcnt_update(struct rte_mbuf *m, int16_t v)
{
    rte_pktmbuf_refcnt_update(m, v);
}

uint16_t kanga_dpdk_rte_pktmbuf_headroom(const struct rte_mbuf *m)
{
    return rte_pktmbuf_headroom(m);
}

uint16_t kanga_dpdk_rte_pktmbuf_tailroom(const struct rte_mbuf *m)
{
    return rte_pktmbuf_tailroom(m);
}

struct rte_mbuf *kanga_dpdk_rte_pktmbuf_lastseg(struct rte_mbuf *m)
{
    return rte_pktmbuf_lastseg(m);
}

uint32_t kanga_dpdk_rte_pktmbuf_pkt_len(struct rte_mbuf *m)
{
    return rte_pktmbuf_pkt_len(m);
}

uint16_t kanga_dpdk_rte_pktmbuf_data_len(struct rte_mbuf *m)
{
    return rte_pktmbuf_data_len(m);
}

char *kanga_dpdk_rte_pktmbuf_prepend(struct rte_mbuf *m, uint16_t len)
{
    return rte_pktmbuf_prepend(m, len);
}

char *kanga_dpdk_rte_pktmbuf_append(struct rte_mbuf *m, uint16_t len)
{
    return rte_pktmbuf_append(m, len);
}

char *kanga_dpdk_rte_pktmbuf_adj(struct rte_mbuf *m, uint16_t len)
{
    return rte_pktmbuf_adj(m, len);
}

int kanga_dpdk_rte_pktmbuf_trim(struct rte_mbuf *m, uint16_t len)
{
    return rte_pktmbuf_trim(m, len);
}

int kanga_dpdk_rte_pktmbuf_is_contiguous(const struct rte_mbuf *m)
{
    return rte_pktmbuf_is_contiguous(m);
}

const void *kanga_dpdk_rte_pktmbuf_read(const struct rte_mbuf *m, uint32_t off, uint32_t len, void *buf)
{
    return rte_pktmbuf_read(m, off, len, buf);
}

int kanga_dpdk_rte_pktmbuf_chain(struct rte_mbuf *head, struct rte_mbuf *tail)
{
    return rte_pktmbuf_chain(head, tail);
}

int kanga_dpdk_rte_validate_tx_offload(const struct rte_mbuf *m)
{
    return rte_validate_tx_offload(m);
}

int kanga_dpdk_rte_pktmbuf_linearize(struct rte_mbuf *mbuf)
{
    return rte_pktmbuf_linearize(mbuf);
}

uint32_t kanga_dpdk_rte_mbuf_sched_queue_get(const struct rte_mbuf *m)
{
    return rte_mbuf_sched_queue_get(m);
}

uint8_t kanga_dpdk_rte_mbuf_sched_traffic_class_get(const struct rte_mbuf *m)
{
    return rte_mbuf_sched_traffic_class_get(m);
}

uint8_t kanga_dpdk_rte_mbuf_sched_color_get(const struct rte_mbuf *m)
{
    return rte_mbuf_sched_color_get(m);
}

void kanga_dpdk_rte_mbuf_sched_get(
    const struct rte_mbuf *m, uint32_t *queue_id, uint8_t *traffic_class, uint8_t *color)
{
    rte_mbuf_sched_get(m, queue_id, traffic_class, color);
}

void kanga_dpdk_rte_mbuf_sched_queue_set(struct rte_mbuf *m, uint32_t queue_id)
{
    rte_mbuf_sched_queue_set(m, queue_id);
}

void kanga_dpdk_rte_mbuf_sched_traffic_class_set(struct rte_mbuf *m, uint8_t traffic_class)
{
    rte_mbuf_sched_traffic_class_set(m, traffic_class);
}

void kanga_dpdk_rte_mbuf_sched_color_set(struct rte_mbuf *m, uint8_t color)
{
    rte_mbuf_sched_color_set(m, color);
}

void kanga_dpdk_rte_mbuf_sched_set(
    struct rte_mbuf *m, uint32_t queue_id, uint8_t traffic_class, uint8_t color)
{
    rte_mbuf_sched_set(m, queue_id, traffic_class, color);
}

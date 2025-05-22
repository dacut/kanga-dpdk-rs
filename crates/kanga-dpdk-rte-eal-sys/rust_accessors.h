#include <sys/types.h>

#include <rte_bitmap.h>
#include <rte_bitops.h>
#include <rte_bitset.h>
#include <rte_common.h>
#include <rte_eal.h>
#include <rte_errno.h>
#include <rte_lcore.h>
#include <rte_lcore_var.h>
#include <rte_mcslock.h>
#include <rte_reciprocal.h>
#include <rte_seqcount.h>
#include <rte_seqlock.h>
#include <rte_ticketlock.h>
#include <rte_time.h>
#include <rte_uuid.h>

/* rte_bitmap static inline functions */
uint32_t kanga_dpdk_rte_bitmap_get_memory_footprint(uint32_t n_bits);
struct rte_bitmap *kanga_dpdk_rte_bitmap_init(uint32_t n_bits, uint8_t *mem, uint32_t mem_size);
struct rte_bitmap *kanga_dpdk_rte_bitmap_init_with_all_set(uint32_t n_bits, uint8_t *mem, uint32_t mem_size);
void kanga_dpdk_rte_bitmap_reset(struct rte_bitmap *bmp);
int kanga_dpdk_rte_bitmap_free(struct rte_bitmap *bmp);
void kanga_dpdk_rte_bitmap_prefetch0(struct rte_bitmap *bmp, uint32_t pos);
uint64_t kanga_dpdk_rte_bitmap_get(struct rte_bitmap *bmp, uint32_t pos);
void kanga_dpdk_rte_bitmap_set(struct rte_bitmap *bmp, uint32_t pos);
void kanga_dpdk_rte_bitmap_set_slab(struct rte_bitmap *bmp, uint32_t pos, uint64_t slab);
void kanga_dpdk_rte_bitmap_clear(struct rte_bitmap *bmp, uint32_t pos);
int kanga_dpdk_rte_bitmap_scan(struct rte_bitmap *bmp, uint32_t *pos, uint64_t *slab);

/* rte_bitops static inline functions */
uint32_t kanga_dpdk_rte_bit_relaxed_get32(unsigned int nr, volatile uint32_t *addr);
void kanga_dpdk_rte_bit_relaxed_set32(unsigned int nr, volatile uint32_t *addr);
void kanga_dpdk_rte_bit_relaxed_clear32(unsigned int nr, volatile uint32_t *addr);
uint32_t kanga_dpdk_rte_bit_relaxed_test_and_set32(unsigned int nr, volatile uint32_t *addr);
uint32_t kanga_dpdk_rte_bit_relaxed_test_and_clear32(unsigned int nr, volatile uint32_t *addr);
uint64_t kanga_dpdk_rte_bit_relaxed_get64(unsigned int nr, volatile uint64_t *addr);
void kanga_dpdk_rte_bit_relaxed_set64(unsigned int nr, volatile uint64_t *addr);
void kanga_dpdk_rte_bit_relaxed_clear64(unsigned int nr, volatile uint64_t *addr);
uint64_t kanga_dpdk_rte_bit_relaxed_test_and_set64(unsigned int nr, volatile uint64_t *addr);
uint64_t kanga_dpdk_rte_bit_relaxed_test_and_clear64(unsigned int nr, volatile uint64_t *addr);
unsigned int kanga_dpdk_rte_clz32(uint32_t v);
unsigned int kanga_dpdk_rte_clz64(uint64_t v);
unsigned int kanga_dpdk_rte_ctz32(uint32_t v);
unsigned int kanga_dpdk_rte_ctz64(uint64_t v);
unsigned int kanga_dpdk_rte_popcount32(uint32_t v);
unsigned int kanga_dpdk_rte_popcount64(uint64_t v);
unsigned int kanga_dpdk_rte_ffs32(uint32_t v);
unsigned int kanga_dpdk_rte_ffs64(uint64_t v);
uint32_t kanga_dpdk_rte_combine32ms1b(uint32_t x);
uint64_t kanga_dpdk_rte_combine64ms1b(uint64_t v);
uint32_t kanga_dpdk_rte_bsf32(uint32_t v);
int kanga_dpdk_rte_bsf32_safe(uint32_t v, uint32_t *pos);
uint32_t kanga_dpdk_rte_bsf64(uint64_t v);
int kanga_dpdk_rte_bsf64_safe(uint64_t v, uint32_t *pos);
uint32_t kanga_dpdk_rte_fls_u32(uint32_t x);
uint32_t kanga_dpdk_rte_fls_u64(uint64_t x);
int kanga_dpdk_rte_is_power_of_2(uint32_t n);
uint32_t kanga_dpdk_rte_align32pow2(uint32_t x);
uint32_t kanga_dpdk_rte_align32prevpow2(uint32_t x);
uint64_t kanga_dpdk_rte_align64pow2(uint64_t v);
uint64_t kanga_dpdk_rte_align64prevpow2(uint64_t v);
uint32_t kanga_dpdk_rte_log2_u32(uint32_t v);
uint32_t kanga_dpdk_rte_log2_u64(uint64_t v);

/* rte_bitset static inline functions */
void kanga_dpdk_rte_bitset_init(uint64_t *bitset, size_t size);
bool kanga_dpdk_rte_bitset_test(const uint64_t *bitset, size_t bit_num);
void kanga_dpdk_rte_bitset_set(uint64_t *bitset, size_t bit_num);
void kanga_dpdk_rte_bitset_clear(uint64_t *bitset, size_t bit_num);
void kanga_dpdk_rte_bitset_assign(uint64_t *bitset, size_t bit_num, bool bit_value);
void kanga_dpdk_rte_bitset_flip(uint64_t *bitset, size_t bit_num);
bool kanga_dpdk_rte_bitset_atomic_test(const uint64_t *bitset, size_t bit_num, int memory_order);
void kanga_dpdk_rte_bitset_atomic_set(uint64_t *bitset, size_t bit_num, int memory_order);
void kanga_dpdk_rte_bitset_atomic_clear(uint64_t *bitset, size_t bit_num, int memory_order);
void kanga_dpdk_rte_bitset_atomic_assign(uint64_t *bitset, size_t bit_num, bool bit_value, int memory_order);
void kanga_dpdk_rte_bitset_atomic_flip(uint64_t *bitset, size_t bit_num, int memory_order);
void kanga_dpdk_rte_bitset_set_all(uint64_t *bitset, size_t size);
void kanga_dpdk_rte_bitset_clear_all(uint64_t *bitset, size_t size);
size_t kanga_dpdk_rte_bitset_count_set(const uint64_t *bitset, size_t size);
size_t kanga_dpdk_rte_bitset_count_clear(const uint64_t *bitset, size_t size);
ssize_t kanga_dpdk_rte_bitset_find_first_set(const uint64_t *bitset, size_t size);
ssize_t kanga_dpdk_rte_bitset_find_set(const uint64_t *bitset, size_t size, size_t start_bit, size_t len);
ssize_t kanga_dpdk_rte_bitset_find_set_wrap(const uint64_t *bitset, size_t size, size_t start_bit, size_t len);
ssize_t kanga_dpdk_rte_bitset_find_first_clear(const uint64_t *bitset, size_t size);
ssize_t kanga_dpdk_rte_bitset_find_clear(const uint64_t *bitset, size_t size, size_t start_bit, size_t len);
ssize_t kanga_dpdk_rte_bitset_find_clear_wrap(const uint64_t *bitset, size_t size, size_t start_bit, size_t len);
void kanga_dpdk_rte_bitset_copy(uint64_t *__rte_restrict dst_bitset, const uint64_t *__rte_restrict src_bitset, size_t size);
void kanga_dpdk_rte_bitset_or(uint64_t *dst_bitset, const uint64_t *src_bitset0, const uint64_t *src_bitset1, size_t size);
void kanga_dpdk_rte_bitset_and(uint64_t *dst_bitset, const uint64_t *src_bitset0, const uint64_t *src_bitset1, size_t size);
void kanga_dpdk_rte_bitset_xor(uint64_t *dst_bitset, const uint64_t *src_bitset0, const uint64_t *src_bitset1, size_t size);
void kanga_dpdk_rte_bitset_complement(uint64_t *dst_bitset, const uint64_t *src_bitset, size_t size);
void kanga_dpdk_rte_bitset_shift_left(uint64_t *dst_bitset, const uint64_t *src_bitset, size_t size, size_t shift_bits);
void kanga_dpdk_rte_bitset_shift_right(uint64_t *dst_bitset, const uint64_t *src_bitset, size_t size, size_t shift_bits);
bool kanga_dpdk_rte_bitset_equal(const uint64_t *bitset_a, const uint64_t *bitset_b, size_t size);
ssize_t kanga_dpdk_rte_bitset_to_str(const uint64_t *bitset, size_t size, char *buf, size_t capacity);

/* rte_common static inline functions */
int kanga_dpdk_rte_is_aligned(const void * const __rte_restrict ptr, const unsigned int align);

/* rte_eal static inline functions */
int kanga_dpdk_rte_gettid(void);

/* rte_errno thread-local variable accessors */
int kanga_dpdk_rte_errno_get(void);
void kanga_dpdk_rte_errno_set(int err);

/* rte_lcore_var static inline functions */
void *kanga_dpdk_rte_lcore_var_lcore(unsigned int lcore_id, void *handle);

/* rte_lcore static inline functions */
unsigned kanga_dpdk_rte_lcore_id(void);

/* rte_mcslock static inline functions */
void kanga_dpdk_rte_mcslock_lock(RTE_ATOMIC(rte_mcslock_t *) *msl, rte_mcslock_t *me);
void kanga_dpdk_rte_mcslock_unlock(RTE_ATOMIC(rte_mcslock_t *) *msl, RTE_ATOMIC(rte_mcslock_t *) me);
int kanga_dpdk_rte_mcslock_trylock(RTE_ATOMIC(rte_mcslock_t *) *msl, rte_mcslock_t *me);
int kanga_dpdk_rte_mcslock_is_locked(RTE_ATOMIC(rte_mcslock_t *) msl);

/* rte_reciprocal static inline functions */
uint32_t kanga_dpdk_rte_reciprocal_divide(uint32_t a, struct rte_reciprocal R);

/* rte_seqcount static inline functions */
void kanga_dpdk_rte_seqcount_init(rte_seqcount_t *seqcount);
uint32_t kanga_dpdk_rte_seqcount_read_begin(const rte_seqcount_t *seqcount);
bool kanga_dpdk_rte_seqcount_read_retry(const rte_seqcount_t *seqcount, uint32_t begin_sn);
void kanga_dpdk_rte_seqcount_write_begin(rte_seqcount_t *seqcount);
void kanga_dpdk_rte_seqcount_write_end(rte_seqcount_t *seqcount);

/* rte_seqlock static inline functions */
void kanga_dpdk_rte_seqlock_init(rte_seqlock_t *seqlock);
uint32_t kanga_dpdk_rte_seqlock_read_begin(const rte_seqlock_t *seqlock);
bool kanga_dpdk_rte_seqlock_read_retry(const rte_seqlock_t *seqlock, uint32_t begin_sn);
void kanga_dpdk_rte_seqlock_write_lock(rte_seqlock_t *seqlock);
void kanga_dpdk_rte_seqlock_write_unlock(rte_seqlock_t *seqlock);

/* rte_ticketlock static inline functions */
void kanga_dpdk_rte_ticketlock_init(rte_ticketlock_t *tl);
void kanga_dpdk_rte_ticketlock_lock(rte_ticketlock_t *tl);
void kanga_dpdk_rte_ticketlock_unlock(rte_ticketlock_t *tl);
int kanga_dpdk_rte_ticketlock_is_locked(rte_ticketlock_t *tl);
void kanga_dpdk_rte_ticketlock_recursive_init(rte_ticketlock_recursive_t *tlr);
void kanga_dpdk_rte_ticketlock_recursive_lock(rte_ticketlock_recursive_t *tlr);
void kanga_dpdk_rte_ticketlock_recursive_unlock(rte_ticketlock_recursive_t *tlr);
int kanga_dpdk_rte_ticketlock_recursive_trylock(rte_ticketlock_recursive_t *tlr);

/* rte_time static inline functions */
uint64_t kanga_dpdk_rte_cyclecounter_cycles_to_ns(struct rte_timecounter *tc, uint64_t cycles);
uint64_t kanga_dpdk_rte_timecounter_update(struct rte_timecounter *tc, uint64_t cycle_now);
uint64_t kanga_dpdk_rte_timespec_to_ns(const struct timespec *ts);
struct timespec kanga_dpdk_rte_ns_to_timespec(uint64_t nsec);

/* rte_uuid static inline functions */
void kanga_dpdk_rte_uuid_copy(rte_uuid_t dst, const rte_uuid_t src);
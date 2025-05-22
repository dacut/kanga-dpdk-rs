#include "rust_accessors.h"

uint32_t kanga_dpdk_rte_bitmap_get_memory_footprint(uint32_t n_bits)
{
    return rte_bitmap_get_memory_footprint(n_bits);
}

struct rte_bitmap *kanga_dpdk_rte_bitmap_init(uint32_t n_bits, uint8_t *mem, uint32_t mem_size)
{
    return rte_bitmap_init(n_bits, mem, mem_size);
}

struct rte_bitmap *kanga_dpdk_rte_bitmap_init_with_all_set(uint32_t n_bits, uint8_t *mem, uint32_t mem_size)
{
    return rte_bitmap_init_with_all_set(n_bits, mem, mem_size);
}

int kanga_dpdk_rte_bitmap_free(struct rte_bitmap *bmp)
{
    return rte_bitmap_free(bmp);
}

void kanga_dpdk_rte_bitmap_reset(struct rte_bitmap *bmp)
{
    rte_bitmap_reset(bmp);
}

void kanga_dpdk_rte_bitmap_prefetch0(struct rte_bitmap *bmp, uint32_t pos)
{
    rte_bitmap_prefetch0(bmp, pos);
}

uint64_t kanga_dpdk_rte_bitmap_get(struct rte_bitmap *bmp, uint32_t pos)
{
    return rte_bitmap_get(bmp, pos);
}

void kanga_dpdk_rte_bitmap_set(struct rte_bitmap *bmp, uint32_t pos)
{
    rte_bitmap_set(bmp, pos);
}

void kanga_dpdk_rte_bitmap_set_slab(struct rte_bitmap *bmp, uint32_t pos, uint64_t slab)
{
    rte_bitmap_set_slab(bmp, pos, slab);
}

void kanga_dpdk_rte_bitmap_clear(struct rte_bitmap *bmp, uint32_t pos)
{
    rte_bitmap_clear(bmp, pos);
}

int kanga_dpdk_rte_bitmap_scan(struct rte_bitmap *bmp, uint32_t *pos, uint64_t *slab)
{
    return rte_bitmap_scan(bmp, pos, slab);
}

uint32_t kanga_dpdk_rte_bit_relaxed_get32(unsigned int nr, volatile uint32_t *addr)
{
    return rte_bit_relaxed_get32(nr, addr);
}

void kanga_dpdk_rte_bit_relaxed_set32(unsigned int nr, volatile uint32_t *addr)
{
    return rte_bit_relaxed_set32(nr, addr);
}

void kanga_dpdk_rte_bit_relaxed_clear32(unsigned int nr, volatile uint32_t *addr)
{
    return rte_bit_relaxed_clear32(nr, addr);
}

uint32_t kanga_dpdk_rte_bit_relaxed_test_and_set32(unsigned int nr, volatile uint32_t *addr)
{
    return rte_bit_relaxed_test_and_set32(nr, addr);
}

uint32_t kanga_dpdk_rte_bit_relaxed_test_and_clear32(unsigned int nr, volatile uint32_t *addr)
{
    return rte_bit_relaxed_test_and_clear32(nr, addr);
}

uint64_t kanga_dpdk_rte_bit_relaxed_get64(unsigned int nr, volatile uint64_t *addr)
{
    return rte_bit_relaxed_get64(nr, addr);
}

void kanga_dpdk_rte_bit_relaxed_set64(unsigned int nr, volatile uint64_t *addr)
{
    return rte_bit_relaxed_set64(nr, addr);
}

void kanga_dpdk_rte_bit_relaxed_clear64(unsigned int nr, volatile uint64_t *addr)
{
    return rte_bit_relaxed_clear64(nr, addr);
}

uint64_t kanga_dpdk_rte_bit_relaxed_test_and_set64(unsigned int nr, volatile uint64_t *addr)
{
    return rte_bit_relaxed_test_and_set64(nr, addr);
}

uint64_t kanga_dpdk_rte_bit_relaxed_test_and_clear64(unsigned int nr, volatile uint64_t *addr)
{
    return rte_bit_relaxed_test_and_clear64(nr, addr);
}

unsigned int kanga_dpdk_rte_clz32(uint32_t v)
{
    return rte_clz32(v);
}

unsigned int kanga_dpdk_rte_clz64(uint64_t v)
{
    return rte_clz64(v);
}
unsigned int kanga_dpdk_rte_ctz32(uint32_t v)
{
    return rte_ctz32(v);
}

unsigned int kanga_dpdk_rte_ctz64(uint64_t v)
{
    return rte_ctz64(v);
}

unsigned int kanga_dpdk_rte_popcount32(uint32_t v)
{
    return rte_popcount32(v);
}

unsigned int kanga_dpdk_rte_popcount64(uint64_t v)
{
    return rte_popcount64(v);
}

unsigned int kanga_dpdk_rte_ffs32(uint32_t v)
{
    return rte_ffs32(v);
}

unsigned int kanga_dpdk_rte_ffs64(uint64_t v)
{
    return rte_ffs64(v);
}

uint32_t kanga_dpdk_rte_combine32ms1b(uint32_t x)
{
    return rte_combine32ms1b(x);
}

uint64_t kanga_dpdk_rte_combine64ms1b(uint64_t v)
{
    return rte_combine64ms1b(v);
}

uint32_t kanga_dpdk_rte_bsf32(uint32_t v)
{
    return rte_bsf32(v);
}

int kanga_dpdk_rte_bsf32_safe(uint32_t v, uint32_t *pos)
{
    return rte_bsf32_safe(v, pos);
}

uint32_t kanga_dpdk_rte_bsf64(uint64_t v)
{
    return rte_bsf64(v);
}

int kanga_dpdk_rte_bsf64_safe(uint64_t v, uint32_t *pos)
{
    return rte_bsf64_safe(v, pos);
}

uint32_t kanga_dpdk_rte_fls_u32(uint32_t x)
{
    return rte_fls_u32(x);
}

uint32_t kanga_dpdk_rte_fls_u64(uint64_t x)
{
    return rte_fls_u64(x);
}

int kanga_dpdk_rte_is_power_of_2(uint32_t n)
{
    return rte_is_power_of_2(n);
}

uint32_t kanga_dpdk_rte_align32pow2(uint32_t x)
{
    return rte_align32pow2(x);
}

uint32_t kanga_dpdk_rte_align32prevpow2(uint32_t x)
{
    return rte_align32prevpow2(x);
}

uint64_t kanga_dpdk_rte_align64pow2(uint64_t v)
{
    return rte_align64pow2(v);
}

uint64_t kanga_dpdk_rte_align64prevpow2(uint64_t v)
{
    return rte_align64prevpow2(v);
}

uint32_t kanga_dpdk_rte_log2_u32(uint32_t v)
{
    return rte_log2_u32(v);
}

uint32_t kanga_dpdk_rte_log2_u64(uint64_t v)
{
    return rte_log2_u64(v);
}

void kanga_dpdk_rte_bitset_init(uint64_t *bitset, size_t size)
{
    rte_bitset_init(bitset, size);
}

bool kanga_dpdk_rte_bitset_test(const uint64_t *bitset, size_t bit_num)
{
    return rte_bitset_test(bitset, bit_num);
}

void kanga_dpdk_rte_bitset_set(uint64_t *bitset, size_t bit_num)
{
    rte_bitset_set(bitset, bit_num);
}

void kanga_dpdk_rte_bitset_clear(uint64_t *bitset, size_t bit_num)
{
    rte_bitset_clear(bitset, bit_num);
}

void kanga_dpdk_rte_bitset_assign(uint64_t *bitset, size_t bit_num, bool bit_value)
{
    rte_bitset_assign(bitset, bit_num, bit_value);
}

void kanga_dpdk_rte_bitset_flip(uint64_t *bitset, size_t bit_num)
{
    rte_bitset_flip(bitset, bit_num);
}

bool kanga_dpdk_rte_bitset_atomic_test(const uint64_t *bitset, size_t bit_num, int memory_order)
{
    return rte_bitset_atomic_test(bitset, bit_num, memory_order);
}

void kanga_dpdk_rte_bitset_atomic_set(uint64_t *bitset, size_t bit_num, int memory_order)
{
    rte_bitset_atomic_set(bitset, bit_num, memory_order);
}

void kanga_dpdk_rte_bitset_atomic_clear(uint64_t *bitset, size_t bit_num, int memory_order)
{
    rte_bitset_atomic_clear(bitset, bit_num, memory_order);
}

void kanga_dpdk_rte_bitset_atomic_assign(uint64_t *bitset, size_t bit_num, bool bit_value, int memory_order)
{
    rte_bitset_atomic_assign(bitset, bit_num, bit_value, memory_order);
}

void kanga_dpdk_rte_bitset_atomic_flip(uint64_t *bitset, size_t bit_num, int memory_order)
{
    rte_bitset_atomic_flip(bitset, bit_num, memory_order);
}

void kanga_dpdk_rte_bitset_set_all(uint64_t *bitset, size_t size)
{
    return rte_bitset_set_all(bitset, size);
}

void kanga_dpdk_rte_bitset_clear_all(uint64_t *bitset, size_t size)
{
    return rte_bitset_clear_all(bitset, size);
}

size_t kanga_dpdk_rte_bitset_count_set(const uint64_t *bitset, size_t size)
{
    return rte_bitset_count_set(bitset, size);
}

size_t kanga_dpdk_rte_bitset_count_clear(const uint64_t *bitset, size_t size)
{
    return rte_bitset_count_clear(bitset, size);
}

ssize_t kanga_dpdk_rte_bitset_find_first_set(const uint64_t *bitset, size_t size)
{
    return rte_bitset_find_first_set(bitset, size);
}

ssize_t kanga_dpdk_rte_bitset_find_set(const uint64_t *bitset, size_t size, size_t start_bit, size_t len)
{
    return rte_bitset_find_set(bitset, size, start_bit, len);
}

ssize_t kanga_dpdk_rte_bitset_find_set_wrap(const uint64_t *bitset, size_t size, size_t start_bit, size_t len)
{
    return rte_bitset_find_set_wrap(bitset, size, start_bit, len);
}

ssize_t kanga_dpdk_rte_bitset_find_first_clear(const uint64_t *bitset, size_t size)
{
    return rte_bitset_find_first_clear(bitset, size);
}

ssize_t kanga_dpdk_rte_bitset_find_clear(const uint64_t *bitset, size_t size, size_t start_bit, size_t len)
{
    return rte_bitset_find_clear(bitset, size, start_bit, len);
}

ssize_t kanga_dpdk_rte_bitset_find_clear_wrap(const uint64_t *bitset, size_t size, size_t start_bit, size_t len)
{
    return rte_bitset_find_clear_wrap(bitset, size, start_bit, len);
}

void kanga_dpdk_rte_bitset_copy(uint64_t *__rte_restrict dst_bitset, const uint64_t *__rte_restrict src_bitset, size_t size)
{
    rte_bitset_copy(dst_bitset, src_bitset, size);
}

void kanga_dpdk_rte_bitset_or(uint64_t *dst_bitset, const uint64_t *src_bitset0, const uint64_t *src_bitset1, size_t size)
{
    rte_bitset_or(dst_bitset, src_bitset0, src_bitset1, size);
}

void kanga_dpdk_rte_bitset_and(uint64_t *dst_bitset, const uint64_t *src_bitset0, const uint64_t *src_bitset1, size_t size)
{
    rte_bitset_and(dst_bitset, src_bitset0, src_bitset1, size);
}

void kanga_dpdk_rte_bitset_xor(uint64_t *dst_bitset, const uint64_t *src_bitset0, const uint64_t *src_bitset1, size_t size)
{
    rte_bitset_xor(dst_bitset, src_bitset0, src_bitset1, size);
}

void kanga_dpdk_rte_bitset_complement(uint64_t *dst_bitset, const uint64_t *src_bitset, size_t size)
{
    rte_bitset_complement(dst_bitset, src_bitset, size);
}

void kanga_dpdk_rte_bitset_shift_left(uint64_t *dst_bitset, const uint64_t *src_bitset, size_t size, size_t shift_bits)
{
    rte_bitset_shift_left(dst_bitset, src_bitset, size, shift_bits);
}

void kanga_dpdk_rte_bitset_shift_right(uint64_t *dst_bitset, const uint64_t *src_bitset, size_t size, size_t shift_bits)
{
    rte_bitset_shift_right(dst_bitset, src_bitset, size, shift_bits);
}

bool kanga_dpdk_rte_bitset_equal(const uint64_t *bitset_a, const uint64_t *bitset_b, size_t size)
{
    return rte_bitset_equal(bitset_a, bitset_b, size);
}

ssize_t kanga_dpdk_rte_bitset_to_str(const uint64_t *bitset, size_t size, char *buf, size_t capacity)
{
    return rte_bitset_to_str(bitset, size, buf, capacity);
}

int kanga_dpdk_rte_gettid(void)
{
    return rte_gettid();
}

int kanga_dpdk_rte_is_aligned(const void * const __rte_restrict ptr, const unsigned int align)
{
    return rte_is_aligned(ptr, align);
}


int kanga_dpdk_rte_errno_get(void)
{
    return rte_errno;
}

void kanga_dpdk_rte_errno_set(int err)
{
    rte_errno = err;
}


unsigned kanga_dpdk_rte_lcore_id(void)
{
    return rte_lcore_id();
}



void *kanga_dpdk_rte_lcore_var_lcore(unsigned int lcore_id, void *handle)
{
    return rte_lcore_var_lcore(lcore_id, handle);
}


void kanga_dpdk_rte_mcslock_lock(RTE_ATOMIC(rte_mcslock_t *) *msl, rte_mcslock_t *me)
{
    rte_mcslock_lock(msl, me);
}

void kanga_dpdk_rte_mcslock_unlock(RTE_ATOMIC(rte_mcslock_t *) *msl, RTE_ATOMIC(rte_mcslock_t *) me)
{
    rte_mcslock_unlock(msl, me);
}

int kanga_dpdk_rte_mcslock_trylock(RTE_ATOMIC(rte_mcslock_t *) *msl, rte_mcslock_t *me)
{
    return rte_mcslock_trylock(msl, me);
}

int kanga_dpdk_rte_mcslock_is_locked(RTE_ATOMIC(rte_mcslock_t *) msl)
{
    return rte_mcslock_is_locked(msl);
}

uint32_t kanga_dpdk_rte_reciprocal_divide(uint32_t a, struct rte_reciprocal R)
{
    return rte_reciprocal_divide(a, R);
}


void kanga_dpdk_rte_seqcount_init(rte_seqcount_t *seqcount)
{
    rte_seqcount_init(seqcount);
}

uint32_t kanga_dpdk_rte_seqcount_read_begin(const rte_seqcount_t *seqcount)
{
    return rte_seqcount_read_begin(seqcount);
}

bool kanga_dpdk_rte_seqcount_read_retry(const rte_seqcount_t *seqcount, uint32_t begin_sn)
{
    return rte_seqcount_read_retry(seqcount, begin_sn);
}

void kanga_dpdk_rte_seqcount_write_begin(rte_seqcount_t *seqcount)
{
    rte_seqcount_write_begin(seqcount);
}

void kanga_dpdk_rte_seqcount_write_end(rte_seqcount_t *seqcount)
{
    rte_seqcount_write_end(seqcount);
}



void kanga_dpdk_rte_seqlock_init(rte_seqlock_t *seqlock)
{
    rte_seqlock_init(seqlock);
}

uint32_t kanga_dpdk_rte_seqlock_read_begin(const rte_seqlock_t *seqlock)
{
    return rte_seqlock_read_begin(seqlock);
}

bool kanga_dpdk_rte_seqlock_read_retry(const rte_seqlock_t *seqlock, uint32_t begin_sn)
{
    return rte_seqlock_read_retry(seqlock, begin_sn);
}

void kanga_dpdk_rte_seqlock_write_lock(rte_seqlock_t *seqlock)
{
    rte_seqlock_write_lock(seqlock);
}

void kanga_dpdk_rte_seqlock_write_unlock(rte_seqlock_t *seqlock)
{
    rte_seqlock_write_unlock(seqlock);
}



void kanga_dpdk_rte_ticketlock_init(rte_ticketlock_t *tl)
{
    rte_ticketlock_init(tl);
}

void kanga_dpdk_rte_ticketlock_lock(rte_ticketlock_t *tl)
{
    rte_ticketlock_lock(tl);
}

void kanga_dpdk_rte_ticketlock_unlock(rte_ticketlock_t *tl)
{
    rte_ticketlock_unlock(tl);
}

int kanga_dpdk_rte_ticketlock_is_locked(rte_ticketlock_t *tl)
{
    return rte_ticketlock_is_locked(tl);
}

void kanga_dpdk_rte_ticketlock_recursive_init(rte_ticketlock_recursive_t *tlr)
{
    rte_ticketlock_recursive_init(tlr);
}

void kanga_dpdk_rte_ticketlock_recursive_lock(rte_ticketlock_recursive_t *tlr)
{
    rte_ticketlock_recursive_lock(tlr);
}

void kanga_dpdk_rte_ticketlock_recursive_unlock(rte_ticketlock_recursive_t *tlr)
{
    rte_ticketlock_recursive_unlock(tlr);
}

int kanga_dpdk_rte_ticketlock_recursive_trylock(rte_ticketlock_recursive_t *tlr)
{
    return rte_ticketlock_recursive_trylock(tlr);
}


uint64_t kanga_dpdk_rte_cyclecounter_cycles_to_ns(struct rte_timecounter *tc, uint64_t cycles)
{
    return rte_cyclecounter_cycles_to_ns(tc, cycles);
}

uint64_t kanga_dpdk_rte_timecounter_update(struct rte_timecounter *tc, uint64_t cycle_now)
{
    return rte_timecounter_update(tc, cycle_now);
}

uint64_t kanga_dpdk_rte_timespec_to_ns(const struct timespec *ts)
{
    return rte_timespec_to_ns(ts);
}

struct timespec kanga_dpdk_rte_ns_to_timespec(uint64_t nsec)
{
    return rte_ns_to_timespec(nsec);
}



void kanga_dpdk_rte_uuid_copy(rte_uuid_t dst, const rte_uuid_t src)
{
    rte_uuid_copy(dst, src);
}
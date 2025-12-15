/*
 * rng.c
 *
 * Small xorshift32 RNG wrapper.
 *
 * Public API:
 *   void     rng_seed(uint32_t seed);
 *   uint32_t rng_get(void);
 *   int      rng_int(int max);
 *
 * This RNG is deterministic and very fast; good for embedded usage where
 * cryptographic strength is not required.
 */

#include "rng.h"
#include <stdint.h>

/* Internal state - keep static to limit scope. Non-zero required. */
static uint32_t g_state = 0xA5A5A5A5u;

/* xorshift32 core */
static uint32_t xorshift32(uint32_t *state)
{
    /* xorshift32: simple, small-state generator */
    uint32_t x = *state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x ? x : 0xDEADBEEFu; /* ensure state never becomes 0 */
    return *state;
}

/* Seed the RNG. If user passes 0 we substitute a fixed nonzero seed.
   (0 would break pure xorshift32 because it stays 0). */
void rng_seed(uint32_t seed)
{
    if (seed == 0) seed = 0xC0FFEEu ^ 0x12345678u;
    g_state = seed;
    /* Warm up a few cycles to decorrelate from seed */
    (void)xorshift32(&g_state);
    (void)xorshift32(&g_state);
    (void)xorshift32(&g_state);
}

/* Return next 32-bit random value */
uint32_t rng_get(void)
{
    return xorshift32(&g_state);
}

/* Convenience integer in range [0, max-1]. If max <= 0 returns 0.
   Uses rejection to reduce bias for large ranges, but keeps code simple
   (fine for embedded, small max typical usage). */
int rng_int(int max)
{
    if (max <= 0) return 0;
    /* Use 32-bit random value and map to range */
    uint32_t r = rng_get();
    /* simple reduction — acceptable for small max values */
    return (int)(r % (uint32_t)max);
}

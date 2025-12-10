#ifndef RNG_H
#define RNG_H

#include <stdint.h>

/* Seed the RNG. If seed == 0 a default nonzero seed will be used. */
void rng_seed(uint32_t seed);

/* Return next 32-bit random value. */
uint32_t rng_get(void);

/* Convenience: return random integer in [0, max-1]. If max <= 0 returns 0. */
int rng_int(int max);

#endif /* RNG_H */

#include "euclid_engine_v2.h"
#include "rng.h"
#include <stdint.h>
#include <stdbool.h>

/* ============================================================
   Fallback Limits
   ============================================================ */

/* If not provided by header, define safe maximum */
#ifndef EUCLID_MAX_STEPS
#define EUCLID_MAX_STEPS 64
#endif

/* ============================================================
   Helpers
   ============================================================ */

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ============================================================
   Probability helper
   ============================================================ */
/*
 * Contract (from header):
 *   int euclid_probability_pass(int probability);
 *
 * probability: 0..127
 * return: 1 = pass, 0 = block
 */
int euclid_probability_pass(int probability)
{
    probability &= 0x7F; /* MIDI-safe */

    int r = (int)(rng_get() & 0x7F);
    return (r < probability) ? 1 : 0;
}

/* ============================================================
   Core Euclid generator
   ============================================================ */
/*
 * steps    : number of steps
 * pulses  : number of hits
 * rotation: rotation offset
 * out     : buffer [steps] → 0/1
 */
int euclid_generate(int steps, int pulses, int rotation, uint8_t *out)
{
    if (!out) return -1;

    steps  = clampi(steps, 1, EUCLID_MAX_STEPS);
    pulses = clampi(pulses, 0, steps);

    /* trivial cases */
    if (pulses == 0)
    {
        for (int i = 0; i < steps; i++)
            out[i] = 0;
        return steps;
    }

    if (pulses >= steps)
    {
        for (int i = 0; i < steps; i++)
            out[i] = 1;
        return steps;
    }

    /* --------------------------------------------------------
       Deterministic Euclid distribution (Bjorklund-lite)
       -------------------------------------------------------- */
    int bucket = 0;

    for (int i = 0; i < steps; i++)
    {
        bucket += pulses;
        if (bucket >= steps)
        {
            bucket -= steps;
            out[i] = 1;
        }
        else
        {
            out[i] = 0;
        }
    }

    /* --------------------------------------------------------
       Rotation
       -------------------------------------------------------- */
    if (rotation != 0)
    {
        rotation = ((rotation % steps) + steps) % steps;

        uint8_t tmp[EUCLID_MAX_STEPS];

        for (int i = 0; i < steps; i++)
            tmp[(i + rotation) % steps] = out[i];

        for (int i = 0; i < steps; i++)
            out[i] = tmp[i];
    }

    return steps;
}

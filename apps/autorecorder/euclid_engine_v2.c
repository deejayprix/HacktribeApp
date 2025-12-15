/*
 * euclid_engine_v2.c
 *
 * Euclid engine (v2) implementation — multi-slot, probability, fill mode, rotation.
 *
 * Relies on types declared in randomizer.h:
 *   - eu_slot_t
 *   - eu_channel_t
 *   - RANDOMIZER_MAX_STEPS
 *   - EU_MODE_*
 *
 * Uses rng_get() from cpu/include/rng.h (if available) as entropy source.
 */

#include <stdint.h>
#include <stdbool.h>
#include <string.h> /* memcpy, memmove */

#include "euclid_engine_v2.h"
#include "randomizer.h"   /* eu_slot_t, eu_channel_t, RANDOMIZER_MAX_STEPS, EU_MODE_* */
#include "rng.h"          /* uint32_t rng_get(void) */

/* ------------------------------------------------------------------------ */
/* small helpers */

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* safe local buffer size — relies on RANDOMIZER_MAX_STEPS being reasonably small */
#ifndef EUCLID_LOCAL_MAX
#define EUCLID_LOCAL_MAX (RANDOMIZER_MAX_STEPS)
#endif

/* ------------------------------------------------------------------------ */
/* Probability helper: takes 0..127 and returns 1 on pass, 0 otherwise.
 * Uses rng_get() if provided, otherwise a deterministic fallback (midpoint).
 */
int euclid_probability_pass(int probability)
{
    probability = clampi(probability, 0, 127);

    /* rng_get is declared as uint32_t rng_get(void) in cpu/include/rng.h */
    uint32_t r = 0;
    /* defensively call rng_get if present */
    r = (uint32_t)(rng_get ? (rng_get() & 0x7F) : 64u);

    return (r < (uint32_t)probability) ? 1 : 0;
}

/* ------------------------------------------------------------------------ */
/* Fill-mode helper: forces gates on strong subdivisions.
 * Simple heuristic: mark step 0 (and optionally quarter notes) as strong.
 * This can be adjusted if you want different emphasis patterns.
 */
int euclid_fill_mode_gate(int step_index, int steps)
{
    if (steps <= 0) return 0;

    /* always emphasize the first step */
    if (step_index == 0) return 1;

    /* if steps divisible by 4, emphasize every (steps/4)-th step */
    int quarter = steps / 4;
    if (quarter > 0 && (step_index % quarter) == 0) return 1;

    return 0;
}

/* ------------------------------------------------------------------------ */
/* rotate helper: rotate right by amount (positive) */
void euclid_rotate(uint8_t *buf, int len, int amount)
{
    if (!buf || len <= 0) return;

    if (len > EUCLID_LOCAL_MAX) return; /* safety */

    amount %= len;
    if (amount < 0) amount += len;
    if (amount == 0) return;

    uint8_t tmp[EUCLID_LOCAL_MAX];
    /* copy tail */
    memcpy(tmp, buf + (len - amount), (size_t)amount);
    /* shift body to the right */
    memmove(buf + amount, buf, (size_t)(len - amount));
    /* put tail into front */
    memcpy(buf, tmp, (size_t)amount);
}

/* ------------------------------------------------------------------------ */
/* Core Euclid generator:
 *  - steps: length (1 .. RANDOMIZER_MAX_STEPS)
 *  - pulses: number of On pulses (0 .. steps)
 *  - rotation: rotate result by rotation (can be negative)
 *  - out_gates: buffer with capacity at least 'steps' bytes
 *
 * Returns number of steps written (== steps) or 0 on error.
 */
int euclid_generate(int steps, int pulses, int rotation, uint8_t *out_gates)
{
    if (!out_gates) return 0;

    steps = clampi(steps, 1, RANDOMIZER_MAX_STEPS);
    pulses = clampi(pulses, 0, steps);

    /* clear */
    for (int i = 0; i < steps; ++i) out_gates[i] = 0;

    if (pulses == 0) return steps;

    /* Bresenham-like distribution algorithm */
    int bucket = 0;
    for (int i = 0; i < steps; ++i)
    {
        bucket += pulses;
        if (bucket >= steps)
        {
            bucket -= steps;
            out_gates[i] = 1;
        }
    }

    /* apply rotation */
    euclid_rotate(out_gates, steps, rotation);

    return steps;
}

/* ------------------------------------------------------------------------ */
/* Compile a single eu_slot_t into its compiled[] buffer (0/1 values) */
void euclid_compile_slot(eu_slot_t *slot)
{
    if (!slot) return;

    /* ensure reasonable bounds */
    int steps = clampi(slot->steps, 1, RANDOMIZER_MAX_STEPS);
    int pulses = clampi(slot->pulses, 0, steps);
    int rotation = slot->rotation; /* rotation may be signed */
    int probability = clampi(slot->probability, 0, 127);
    eu_mode_t mode = slot->mode;

    /* clear compiled array up to steps */
    for (int i = 0; i < RANDOMIZER_MAX_STEPS; ++i) slot->compiled[i] = 0;

    if (!slot->enabled) return;

    uint8_t base[RANDOMIZER_MAX_STEPS];
    /* generate base euclid pattern */
    euclid_generate(steps, pulses, rotation, base);

    /* depending on mode, apply probability / fill / standard */
    for (int i = 0; i < steps; ++i)
    {
        uint8_t gate = base[i];

        switch (mode)
        {
            case EU_MODE_OFF:
                /* if mode OFF, just forward base pattern */
                /* gate remains as base */
                break;

            case EU_MODE_STANDARD:
                /* standard Euclid: gate stays as base */
                break;

            case EU_MODE_FILL:
                /* Fill mode: force-on for strong subdivisions OR base gate */
                if (euclid_fill_mode_gate(i, steps)) gate = 1;
                else gate = base[i];
                break;

            case EU_MODE_PROB:
                /* Probability mode: if base gate set, then use probability check */
                if (base[i])
                {
                    if (!euclid_probability_pass(probability))
                        gate = 0;
                }
                else
                {
                    gate = 0;
                }
                break;

            default:
                /* unknown mode — fall back to base */
                break;
        }

        slot->compiled[i] = gate ? 1 : 0;
    }

    /* zero remaining steps (if any) already ensured above */
}

/* ------------------------------------------------------------------------ */
/* Compile all slots for a channel */
void euclid_compile_channel(eu_channel_t *ch)
{
    if (!ch) return;

    for (int s = 0; s < RANDOMIZER_MAX_EU_SLOTS_PER_CH; ++s)
    {
        euclid_compile_slot(&ch->slots[s]);
    }
}

/* ------------------------------------------------------------------------ */
/* Return the compiled gate (0/1) for given channel, slot and step index */
int euclid_get_gate(const eu_channel_t *ch, int slot, int step)
{
    if (!ch) return 0;

    if (slot < 0 || slot >= RANDOMIZER_MAX_EU_SLOTS_PER_CH) return 0;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS) return 0;

    const eu_slot_t *sl = &ch->slots[slot];

    if (!sl->enabled) return 0;

    int steps = clampi(sl->steps, 1, RANDOMIZER_MAX_STEPS);
    if (step >= steps) return 0;

    return sl->compiled[step] ? 1 : 0;
}

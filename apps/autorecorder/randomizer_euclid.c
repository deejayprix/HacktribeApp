#include "euclid_engine_v2.h"
#include "randomizer.h"
#include "rng.h"
#include <stdint.h>
#include <stdbool.h>



/* We define clampi BEFORE any use */
static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ============================================================
   EUCLID STAGED PARAMETERS
   ============================================================ */

static int eu_stage_ch = 0;
static int eu_stage_slot = 0;

static int eu_stage_pulses = 0;
static int eu_stage_steps  = 16;
static int eu_stage_rotation = 0;
static int eu_stage_probability = 127;
static eu_mode_t eu_stage_mode = EU_MODE_STANDARD;

/* ============================================================
   EXPORTED GLOBAL ARRAY FROM randomizer.c
   ============================================================ */
extern eu_channel_t g_eu_channels[RANDOMIZER_MAX_CHANNELS];

/* ============================================================
   STAGE SETTERS (NRPN)
   ============================================================ */

void randomizer_euclid_stage_channel(int ch)
{
    eu_stage_ch = clampi(ch, 0, RANDOMIZER_MAX_CHANNELS - 1);
}

void randomizer_euclid_stage_slot(int slot)
{
    eu_stage_slot = clampi(slot, 0, RANDOMIZER_MAX_EU_SLOTS_PER_CH - 1);
}

void randomizer_euclid_stage_pulses(int p)
{
    eu_stage_pulses = clampi(p, 0, RANDOMIZER_MAX_STEPS);
}

void randomizer_euclid_stage_steps(int s)
{
    eu_stage_steps = clampi(s, 1, RANDOMIZER_MAX_STEPS);
}

void randomizer_euclid_stage_rotation(int r)
{
    eu_stage_rotation = r;
}

void randomizer_euclid_stage_probability(int p)
{
    eu_stage_probability = clampi(p, 0, 127);
}

void randomizer_euclid_stage_mode(uint8_t m)
{
    if (m > EU_MODE_PROB) m = EU_MODE_PROB;
    eu_stage_mode = (eu_mode_t)m;
}

/* ============================================================
   COMMIT — builds compiled Euclid lane
   ============================================================ */

void randomizer_euclid_commit(void)
{
    eu_channel_t *ch = &g_eu_channels[eu_stage_ch];
    eu_slot_t *slot = &ch->slots[eu_stage_slot];

    slot->pulses = eu_stage_pulses;
    slot->steps  = eu_stage_steps;
    slot->rotation = eu_stage_rotation;
    slot->probability = eu_stage_probability;
    slot->mode = eu_stage_mode;

    uint8_t gates[RANDOMIZER_MAX_STEPS] = {0};

    int ret = euclid_generate(slot->steps,
                              slot->pulses,
                              slot->rotation,
                              gates);

    if (ret > 0)
    {
        for (int i = 0; i < slot->steps; ++i)
            slot->compiled[i] = gates[i];
    }

    slot->enabled = true;
}

/* ============================================================
   Enable/disable slot
   ============================================================ */

void randomizer_euclid_set_enabled(int ch, int slot, int en)
{
    if (ch < 0 || ch >= RANDOMIZER_MAX_CHANNELS) return;
    if (slot < 0 || slot >= RANDOMIZER_MAX_EU_SLOTS_PER_CH) return;

    g_eu_channels[ch].slots[slot].enabled = (en != 0);
}

/* ============================================================
   Live rotation (NRPN 0x2109)
   ============================================================ */

void randomizer_euclid_live_rotate(int ch, int slot, int delta)
{
    if (ch < 0 || ch >= RANDOMIZER_MAX_CHANNELS) return;
    if (slot < 0 || slot >= RANDOMIZER_MAX_EU_SLOTS_PER_CH) return;

    g_eu_channels[ch].slots[slot].rotation += delta;
}

/* ============================================================
   Query compiled gate value (used by randomizer.c)
   ============================================================ */

int randomizer_get_euclid_value_public(int ch, int slot, int step)
{
    if (ch < 0 || ch >= RANDOMIZER_MAX_CHANNELS) return 0;
    if (slot < 0 || slot >= RANDOMIZER_MAX_EU_SLOTS_PER_CH) return 0;
    eu_slot_t *s = &g_eu_channels[ch].slots[slot];
    if (!s->enabled) return 0;
    if (step < 0 || step >= s->steps) return 0;

    /* probability override mode */
    if (s->mode == EU_MODE_PROB)
    {
        int r = (int)(rng_get() & 0x7F);
        return (r < s->probability) ? 1 : 0;
    }

    /* normal compiled gate */
    return (s->compiled[step] != 0);
}

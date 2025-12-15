#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "ft_types.h"
#include "rng.h"
#include "pattern_writer.h"
#include "mod_matrix.h"
#include "euclid_engine_v2.h"



/* Global Euclid storage used by randomizer_euclid.c */
eu_channel_t g_eu_channels[RANDOMIZER_MAX_CHANNELS];

static uint32_t g_seed = 0xC0FFEE;
static int g_density = 100;
static int g_variation = 0;
static int g_freeze = 0;
static int g_section = 0;

/* Motion lanes (type is defined in randomizer.h) */
static motion_lane_t g_motions[RANDOMIZER_MAX_MOTION_LANES];

/* Undo buffer (type defined in randomizer.h) */
static randomizer_undo_entry_t g_undo[RANDOMIZER_UNDO_SLOTS];
static int g_undo_top = 0;

/* Helpers */
static inline int clampi(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* Core / settings */
void randomizer_set_seed(int seed) {
    g_seed = (uint32_t)seed;
    if (&rng_seed) rng_seed(g_seed);
}

void randomizer_set_density(int pct) {
    g_density = clampi(pct, 0, 100);
}
void randomizer_set_variation(int v) {
    g_variation = clampi(v, 0, 127);
}
void randomizer_set_freeze(int en) {
    g_freeze = en ? 1 : 0;
}
void randomizer_set_section(int s) {
    g_section = s;
}
int randomizer_get_section(void) { return g_section; }
int randomizer_get_variation(void){ return g_variation; }

/* Motion lanes */
int randomizer_create_motion_lane(int id, int length) {
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return -1;
    length = clampi(length, 1, RANDOMIZER_MAX_MOTION_LEN);
    g_motions[id].length = length;
    g_motions[id].enabled = true;
    for (int i=0;i<length;i++) g_motions[id].values[i]=0;
    return 0;
}
int randomizer_set_motion_value(int id, int idx, int val) {
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return -1;
    if (!g_motions[id].enabled) return -2;
    if (idx < 0 || idx >= g_motions[id].length) return -3;
    g_motions[id].values[idx] = val;
    return 0;
}
int randomizer_set_motion_length(int id, int length) {
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return -1;
    length = clampi(length, 1, RANDOMIZER_MAX_MOTION_LEN);
    g_motions[id].length = length;
    return 0;
}
int randomizer_set_motion_enabled(int id, int en) {
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return -1;
    g_motions[id].enabled = (en ? true : false);
    return 0;
}
int randomizer_get_motion_value(int id, int idx) {
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return 0;
    if (!g_motions[id].enabled) return 0;
    if (idx < 0 || idx >= g_motions[id].length) return 0;
    return g_motions[id].values[idx];
}
int randomizer_get_motion_length(int id) {
    if (id < 0 || id >= RANDOMIZER_MAX_MOTION_LANES) return 0;
    return g_motions[id].length;
}

/* Mod routes — forward to mod_matrix */
int randomizer_add_mod_route(void *route)
{
    if (!route) return -1;
    return mod_matrix_add((const mod_route_t *)route);
}

int randomizer_remove_mod_route(int idx)
{
    return mod_matrix_remove(idx);
}

int randomizer_clear_mod_routes(void)
{
    return mod_matrix_clear();
}

/* Undo */
static void undo_clear_entry(randomizer_undo_entry_t *u) {
    if (!u) return;
    u->part = -1;
    u->page = -1;
    u->n = 0;
    /* steps don't need explicit clearing */
}
static void undo_push(int part, int page, const ft_step_t *steps, int n) {
    int idx = g_undo_top % RANDOMIZER_UNDO_SLOTS;
    randomizer_undo_entry_t *u = &g_undo[idx];
    u->part = part;
    u->page = page;
    u->n = (n > RANDOMIZER_MAX_STEPS) ? RANDOMIZER_MAX_STEPS : n;
    if (steps && u->n > 0) {
        memcpy(u->steps, steps, sizeof(ft_step_t) * u->n);
    } else {
        u->n = 0;
    }
    g_undo_top++;
}
int randomizer_undo_last_public(void) {
    if (g_undo_top == 0) return -1;
    int idx = (g_undo_top - 1) % RANDOMIZER_UNDO_SLOTS;
    randomizer_undo_entry_t *u = &g_undo[idx];
    if (u->part < 0 || u->n == 0) return -1;
    if (pattern_write_pattern) pattern_write_pattern(u->part, u->steps, u->n);
    undo_clear_entry(u);
    return 0;
}

/* Pattern generation — minimal, deterministic-ish filler */
int randomize_generate_pattern(int part, int steps_count, ft_step_t *steps_out, int section_bar) {
    if (!steps_out) return -1;
    if (steps_count <= 0 || steps_count > RANDOMIZER_MAX_STEPS) return -1;
    uint32_t seed_local = g_seed ^ (uint32_t)part ^ (uint32_t)section_bar;
    if (&rng_seed) rng_seed(seed_local);
    for (int i=0;i<steps_count;i++){
        int r = (rng_get ? (rng_get() & 0x7F) : 64);
        ft_step_t s = { .part = (uint8_t)part, .step = (uint8_t)i, .pitch = (uint8_t)(r % 128), .velocity = (uint8_t)((r>>1)%128), .gate = (uint8_t)((r&0x7)?127:0) };
        steps_out[i] = s;
    }
    /* push undo snapshot */
    undo_push(part, 0, steps_out, steps_count);
    return steps_count;
}

int randomize_and_write_pattern_paged(int part, int steps_count, int section, int page) {
    ft_step_t tmp[RANDOMIZER_MAX_STEPS];
    int n = randomize_generate_pattern(part, steps_count, tmp, section);
    if (n > 0 && pattern_write_pattern) {
        return pattern_write_pattern(part, tmp, n);
    }
    return -1;
}

int randomize_and_write_pattern_paged_simple(int part, int steps_count, ft_step_t *steps_out) {
    int n = randomize_generate_pattern(part, steps_count, steps_out, g_section);
    if (n > 0 && pattern_write_pattern) {
        return pattern_write_pattern(part, steps_out, n);
    }
    return -1;
}

/* Stubbed Euclid API functions: declarations exist in header but implementations are in randomizer_euclid.c.
   Provide weak wrappers here if header expects (they will be linked to the real ones from randomizer_euclid.c). */
extern void randomizer_euclid_stage_channel(int ch);
extern void randomizer_euclid_stage_slot(int slot);
extern void randomizer_euclid_stage_pulses(int p);
extern void randomizer_euclid_stage_steps(int s);
extern void randomizer_euclid_stage_rotation(int r);
extern void randomizer_euclid_stage_probability(int p);
extern void randomizer_euclid_stage_mode(uint8_t m);
extern void randomizer_euclid_commit(void);
extern void randomizer_euclid_set_enabled(int ch, int slot, int en);
extern void randomizer_euclid_live_rotate(int ch, int slot, int delta);
extern int randomizer_get_euclid_value_public(int ch, int slot_id, int step_index);

/* Misc */
void randomizer_init_default(void) {
    /* initialize RNG + motions + undo */
    if (&rng_seed) rng_seed(g_seed);
    for (int i=0;i<RANDOMIZER_MAX_MOTION_LANES;i++) {
        g_motions[i].length = 1;
        g_motions[i].enabled = false;
        for (int j=0;j<RANDOMIZER_MAX_MOTION_LEN;j++) g_motions[i].values[j] = 0;
    }
    for (int i=0;i<RANDOMIZER_UNDO_SLOTS;i++) undo_clear_entry(&g_undo[i]);
    g_undo_top = 0;
}

void randomizer_tick_once(void) {
    /* placeholder for periodic updates (if needed) */
    (void)0;
}

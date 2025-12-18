#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <stdint.h>
#include <stdbool.h>

#include "ft_types.h"
#include "scale_engine.h"
#include "condition_engine.h"

/* ========= CONSTANTS ========= */
#define RANDOMIZER_MAX_CHANNELS         16
#define RANDOMIZER_MAX_STEPS            64
#define RANDOMIZER_MAX_MOTION_LANES     8
#define RANDOMIZER_MAX_MOTION_LEN       64
#define RANDOMIZER_UNDO_SLOTS           16
#define RANDOMIZER_MAX_EU_SLOTS_PER_CH  4

/* ========= EUCLID MODES ========= */
typedef enum {
    EU_MODE_OFF = 0,
    EU_MODE_STANDARD = 1,
    EU_MODE_FILL = 2,
    EU_MODE_PROB = 3
} eu_mode_t;

/* ========= MOTION STRUCT ========= */
typedef struct {
    int length;
    bool enabled;
    int values[RANDOMIZER_MAX_MOTION_LEN];
} motion_lane_t;

/* ========= EUCLID SLOT/CHANNEL ========= */
typedef struct {
    int pulses;
    int steps;
    int rotation;
    int probability; /* 0..127 */
    eu_mode_t mode;
    bool enabled;
    uint8_t compiled[RANDOMIZER_MAX_STEPS]; /* 0/1 gates after compile */
} eu_slot_t;

typedef struct {
    eu_slot_t slots[RANDOMIZER_MAX_EU_SLOTS_PER_CH];
} eu_channel_t;

/* ========= UNDO ENTRY ========= */
typedef struct {
    int part;
    int page;
    int n;
    ft_step_t steps[RANDOMIZER_MAX_STEPS];
} randomizer_undo_entry_t;

/* ========= API ========= */

/* Core / settings */
void randomizer_set_seed(int seed);
void randomizer_set_density(int pct);    /* 0..100 */
void randomizer_set_variation(int v);    /* 0..127 */
void randomizer_set_freeze(int en);
void randomizer_set_section(int s);
int  randomizer_get_section(void);
int  randomizer_get_variation(void);

/* Motion lanes */
int randomizer_create_motion_lane(int id, int length);
int randomizer_set_motion_value(int id, int idx, int val);
int randomizer_set_motion_length(int id, int length);
int randomizer_set_motion_enabled(int id, int en);
int randomizer_get_motion_value(int id, int idx);
int randomizer_get_motion_length(int id);

/* Mod routes */
int randomizer_add_mod_route(void *route);   /* opaque pointer, forwarded to mod_matrix */
int randomizer_remove_mod_route(int idx);
int randomizer_clear_mod_routes(void);

/* Undo */
int randomizer_undo_last_public(void);

/* Pattern generation */
int randomize_generate_pattern(int part, int steps_count, ft_step_t *steps_out, int section_bar);
int randomize_and_write_pattern_paged(int part, int steps_count, int section, int page);
int randomize_and_write_pattern_paged_simple(int part, int steps_count, ft_step_t *steps_out);

/* Euclid API (exposed for NRPN) */
void randomizer_euclid_stage_channel(int ch);
void randomizer_euclid_stage_slot(int slot);
void randomizer_euclid_stage_pulses(int p);
void randomizer_euclid_stage_steps(int s);
void randomizer_euclid_stage_rotation(int r);
void randomizer_euclid_stage_probability(int p);
void randomizer_euclid_stage_mode(uint8_t m);
void randomizer_euclid_commit(void);
void randomizer_euclid_set_enabled(int ch, int slot, int en);
void randomizer_euclid_live_rotate(int ch, int slot, int delta);

/* Query euclid compiled value */
int randomizer_get_euclid_value_public(int ch, int slot_id, int step_index);

/* Misc */
void randomizer_init_default(void);
void randomizer_tick_once(void);

/* Public Euclid storage */
extern eu_channel_t g_eu_channels[RANDOMIZER_MAX_CHANNELS];

/* NRPN router compatibility (Variant A) */
extern int eu_stage_channel;
extern int eu_stage_slot;

#endif /* RANDOMIZER_H */

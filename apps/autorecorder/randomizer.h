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

/* ========= STEP REPEATER ENGINE-STATE ========= */
#define STEP_REPEAT_MIN 1
#define STEP_REPEAT_MAX 8

/* ========= POLICY FLAGS (Composer → Randomizer Bias) =========
   Bitlayout matches CP_FLAG_* in composer_policy.h
*/
typedef uint16_t randomizer_policy_flags_t;

void randomizer_set_policy_flags(randomizer_policy_flags_t flags);
randomizer_policy_flags_t randomizer_get_policy_flags(void);

/* ========= EUCLID MODES ========= */
typedef enum {
    EU_MODE_OFF = 0,
    EU_MODE_STANDARD,
    EU_MODE_FILL,
    EU_MODE_PROB
} eu_mode_t;

/* ========= MOTION STRUCT ========= */
typedef struct {
    int  length;
    bool enabled;
    int  values[RANDOMIZER_MAX_MOTION_LEN];
} motion_lane_t;

/* ========= EUCLID SLOT ========= */
typedef struct {
    int pulses;
    int steps;
    int rotation;
    int probability; /* 0..127 */
    eu_mode_t mode;
    bool enabled;
    uint8_t compiled[RANDOMIZER_MAX_STEPS];
} eu_slot_t;

typedef struct {
    eu_slot_t slots[RANDOMIZER_MAX_EU_SLOTS_PER_CH];
} eu_channel_t;

/* ========= UNDO ========= */
typedef struct {
    int part;
    int page;
    int n;
    ft_step_t steps[RANDOMIZER_MAX_STEPS];
} randomizer_undo_entry_t;

/* ========= CORE ========= */
void randomizer_init_default(void);
void randomizer_tick_once(void);

void randomizer_set_seed(int seed);
void randomizer_set_density(int pct);
void randomizer_set_variation(int v);
void randomizer_set_freeze(int en);
void randomizer_set_section(int s);

int  randomizer_get_section(void);
int  randomizer_get_variation(void);

/* ========= PART STATE ========= */
/* Part usage tracking (safe / non-RAM-scan) */
int  randomizer_part_in_use(uint8_t part);
void randomizer_mark_part_used(uint8_t part);
void randomizer_reset_part_usage(uint8_t part);

/* ========= STEP REPEATER ========= */
void randomizer_set_step_repeat(int part, int step, int repeat);
int  randomizer_get_step_repeat(int part, int step);

/* ========= PATTERN GENERATION ========= */
int randomize_generate_pattern(
    int part,
    int steps_count,
    ft_step_t *steps_out,
    int section_bar
);

int randomize_and_write_pattern_paged(
    int part,
    int steps_count,
    int section,
    int page
);

int randomize_and_write_pattern_paged_simple(
    int part,
    int steps_count,
    ft_step_t *steps_out
);

/* ========= EUCLID ========= */
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
int  randomizer_get_euclid_value_public(int ch, int slot_id, int step_index);

/* ========= MOTION ========= */
int randomizer_create_motion_lane(int id, int length);
int randomizer_set_motion_value(int id, int idx, int val);
int randomizer_set_motion_length(int id, int length);
int randomizer_set_motion_enabled(int id, int en);

/* These were used by mod_matrix.c (fix: add to header) */
int randomizer_get_motion_value(int id, int idx);
int randomizer_get_motion_length(int id);

/* ========= MOD MATRIX ========= */
int randomizer_add_mod_route(void *route);
int randomizer_remove_mod_route(int idx);
int randomizer_clear_mod_routes(void);

/* ========= UNDO ========= */
int randomizer_undo_last_public(void);

/* ========= PUBLIC ========= */
extern eu_channel_t g_eu_channels[RANDOMIZER_MAX_CHANNELS];
extern int eu_stage_channel;
extern int eu_stage_slot;

#endif /* RANDOMIZER_H */

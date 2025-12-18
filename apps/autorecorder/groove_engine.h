#ifndef GROOVE_ENGINE_H
#define GROOVE_ENGINE_H

#include <stdint.h>

#define GROOVE_MAX_PARTS 16

/* Preset IDs (0..127 möglich) */
typedef enum {
    GROOVE_PRESET_OFF = 0,
    GROOVE_PRESET_MPC_LIGHT = 1,
    GROOVE_PRESET_MPC_HARD = 2,
    GROOVE_PRESET_SHUFFLE_57 = 3,
    GROOVE_PRESET_SHUFFLE_62 = 4,
    GROOVE_PRESET_HUMAN_LIGHT = 5,
    GROOVE_PRESET_HUMAN_HARD = 6
} groove_preset_t;

/* Init */
void groove_init(void);

/* Staging (NRPN-friendly) */
void groove_stage_part(int part);
int  groove_get_staged_part(void);

/* Core params (0..127) */
void groove_set_microtiming(int part, int amount);      /* timing feel */
void groove_set_velocity_swing(int part, int amount);   /* velocity feel */
void groove_set_pattern_aware(int part, int en);        /* 0/1 */

/* Presets */
void groove_preset_select(int preset_id);
int  groove_get_selected_preset(void);
void groove_preset_apply_to_part(int part);

/* Runtime helpers for playback engines */
int  groove_apply_velocity(int part, int base_vel, int step, int sub_idx, int sub_total);
int  groove_get_timing_offset_ticks(int part, int step, int step_len_ticks, int sub_idx, int sub_total);

/* Debug */
void groove_debug_enable(int on);
int  groove_debug_is_enabled(void);
void groove_debug_dump_part(int part);
void groove_debug_dump_staged(void);

#endif /* GROOVE_ENGINE_H */

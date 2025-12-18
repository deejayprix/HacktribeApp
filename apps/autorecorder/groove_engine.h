#ifndef GROOVE_ENGINE_H
#define GROOVE_ENGINE_H

#include <stdint.h>

/* ============================================================
   GROOVE ENGINE – PUBLIC API
   Phase 3.2.3.13.4 (Final Defaults & Lock)
   ============================================================ */

/* Init */
void groove_init(void);

/* Master enable (hard lock: if 0 => everything is NO-OP) */
void    groove_set_enabled(uint8_t en);
uint8_t groove_get_enabled(void);

/* One-Knob Macro (0..127) */
void    groove_set_macro(uint8_t v);
uint8_t groove_get_macro(void);

/* Router compatibility aliases */
void groove_set_curve(uint8_t v);

/* Curve shape helpers (sync_live.c) */
int groove_curve_timing_shape(int phase);     /* phase 0..127 -> signed shape */
int groove_curve_velocity_shape(int phase);   /* phase 0..127 -> signed shape */

/* Base curves by step index (0..63 typically) */
int groove_get_timing_curve(int step);
int groove_get_velocity_curve(int step);

/* Pattern-aware application */
int groove_apply_timing(int step, int curve_val);
int groove_apply_velocity(int step, int curve_val);

/* ============================================================
   NRPN MAP (MSB 51)
   ------------------------------------------------------------
   LSB  3 : Micro-Timing Amount        (0..127)
   LSB  4 : Velocity Swing Amount      (0..127)
   LSB 20 : One-Knob Macro             (0..127)
   LSB 21 : Groove Enable              (0/1)
   ============================================================ */

void groove_set_timing_amount(uint8_t v);
void groove_set_velocity_amount(uint8_t v);
uint8_t groove_get_timing_amount(void);
uint8_t groove_get_velocity_amount(void);

#endif /* GROOVE_ENGINE_H */

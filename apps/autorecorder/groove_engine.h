#pragma once
#include <stdint.h>

/* ============================================================
   GROOVE ENGINE – PUBLIC API
   Phase 3.2.3 (Freeze-final)
   ============================================================ */

void    groove_init(void);

/* Enable */
void    groove_set_enabled(uint8_t on);
uint8_t groove_is_enabled(void);

/* One-Knob Macro */
void    groove_set_macro(uint8_t value);
uint8_t groove_get_macro(void);

/* Curve selection */
void    groove_set_timing_curve(uint8_t curve);
void    groove_set_velocity_curve(uint8_t curve);

/* Amount (0..127) */
void    groove_set_timing_amount(uint8_t amt);
void    groove_set_velocity_amount(uint8_t amt);

/* Curve evaluation (used by sync_live) */
int16_t groove_curve_timing_shape(uint8_t phase);
int16_t groove_curve_velocity_shape(uint8_t phase);

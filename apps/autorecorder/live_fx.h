#ifndef LIVE_FX_H
#define LIVE_FX_H

#include <stdint.h>

/*
 * Live FX engine — Fill, Gate-LFO, etc.
 * Clean and compatible with randomizer + mod_matrix.
 */

typedef struct {
    int fill_strength;      // 0..127
    int gate_lfo_period;    // number of ticks for a full LFO cycle
    int gate_lfo_depth;     // 0..127
    int gate_lfo_enabled;   // boolean 0/1
} live_fx_state_t;

/* Global state (defined in live_fx.c) */
extern live_fx_state_t g_live_fx;

/* Init */
void live_fx_init(void);

/* Tick */
void live_fx_tick(void);

/* Fill FX */
void live_fx_set_fill(int strength);
int  live_fx_get_fill(void);

/* Gate LFO */
void live_fx_set_gate_lfo(int period, int depth, int enable);

/* NEW: getters used by mod_matrix */
int live_fx_get_fill_state(void);
int live_fx_get_gate_lfo_value(void);

/* Optional processing hook */
struct ft_step; /* forward declaration */
void live_fx_process_cycle(int part, struct ft_step *buffer, int count);
void live_fx_set_variation_boost(int v);
void live_fx_trigger_fill_now(void);
void live_fx_set_mutation(int v);

void live_fx_set_variation_boost(int v);
void live_fx_trigger_fill_now(void);
void live_fx_set_mutation(int m);

#endif /* LIVE_FX_H */

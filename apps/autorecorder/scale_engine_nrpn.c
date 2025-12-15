/*
 * scale_engine_nrpn.c
 *
 * Thin NRPN staging wrappers for the scale engine.
 * If your existing scale_engine provides functions with different names,
 * you can either modify these wrappers or forward directly in your scale module.
 *
 * Defensive behavior: if the external functions are declared elsewhere, we'll call them.
 * If they are not present at link time, these wrappers still compile and are no-ops.
 */

#include "scale_engine_nrpn.h"
#include <stddef.h>

/* Stage storage (kept internal) */
static int staged_channel = 0;
static int staged_type    = 0;
static int staged_tonic   = 0;

/* If your scale_engine provides these functions, declare them as extern here.
 * They will be optional and the linker will error only if you remove the wrappers.
 * If the real scale engine exists, it should provide:
 *
 *   int scale_engine_set_channel_scale(int ch, int type, int tonic);
 *   int scale_engine_get_channel_scale(int ch, int *type, int *tonic);
 *   void scale_engine_commit_channel(int ch);
 *   void scale_engine_reset_channel(int ch);
 *
 * Adjust names if your scale engine uses other identifiers.
 */

extern int scale_engine_set_channel_scale(int ch, int type, int tonic);
extern int scale_engine_get_channel_scale(int ch, int *type, int *tonic);
extern void scale_engine_commit_channel(int ch);
extern void scale_engine_reset_channel(int ch);

/* Stage setters */
void nrpn_scale_stage_channel(int ch) {
    staged_channel = ch;
}

void nrpn_scale_stage_type(int t) {
    staged_type = t;
}

void nrpn_scale_stage_tonic(int tonic) {
    staged_tonic = tonic;
}

void nrpn_scale_commit(void) {
    /* Try to call the real engine if present */
    if (&scale_engine_set_channel_scale) {
        (void)scale_engine_set_channel_scale(staged_channel, staged_type, staged_tonic);
    }
    if (&scale_engine_commit_channel) {
        scale_engine_commit_channel(staged_channel);
    }
}

void nrpn_scale_reset(void) {
    if (&scale_engine_reset_channel) {
        scale_engine_reset_channel(staged_channel);
    }
}

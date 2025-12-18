#ifndef RANDOMIZER_EUCLID_H
#define RANDOMIZER_EUCLID_H

#include <stdint.h>

/*
   NOTE:
   This header exists in the project, but the current build uses randomizer.h
   as the primary API surface. We keep this file consistent and compatible,
   without removing existing declarations.
*/

/* Public getters used by mod_matrix / other modules */
int randomizer_get_euclid_value_public(int ch, int slot, int step_index);

/* NRPN staging helpers used by nrpn_router.c */
void randomizer_euclid_stage_channel(int ch);
void randomizer_euclid_stage_slot(int slot);
void randomizer_euclid_stage_pulses(int p);
void randomizer_euclid_stage_steps(int s);
void randomizer_euclid_stage_rotation(int r);
void randomizer_euclid_stage_probability(int p);
void randomizer_euclid_stage_mode(uint8_t m);
void randomizer_euclid_commit(void);

/* Enable / live operations */
void randomizer_euclid_set_enabled(int ch, int slot, int en);
void randomizer_euclid_live_rotate(int ch, int slot, int delta);

/* Extern staging variables (nrpn_router may reference) */
extern int eu_stage_channel;
extern int eu_stage_slot;

#endif /* RANDOMIZER_EUCLID_H */

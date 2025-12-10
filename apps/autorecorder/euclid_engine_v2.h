#ifndef EUCLID_ENGINE_V2_H
#define EUCLID_ENGINE_V2_H

#include <stdint.h>
#include <stdbool.h>

/* Wichtig: randomizer.h enthält die echten eu_slot_t / eu_channel_t */
#include "randomizer.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================
   API: Core Euclid Math
   ============================================================ */

int euclid_generate(int steps, int pulses, int rotation, uint8_t *out_gates);
void euclid_rotate(uint8_t *buf, int len, int amount);

/* ============================================================
   API: Probability + Fill Helpers
   ============================================================ */

int euclid_probability_pass(int probability);
int euclid_fill_mode_gate(int step_index, int steps);

/* ============================================================
   API: Compile runtime Euclid structures
   ============================================================ */

void euclid_compile_slot(eu_slot_t *slot);
void euclid_compile_channel(eu_channel_t *channel);
int  euclid_get_gate(const eu_channel_t *channel, int slot, int step);

#ifdef __cplusplus
}
#endif

#endif /* EUCLID_ENGINE_V2_H */

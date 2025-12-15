#ifndef SCALE_ENGINE_H
#define SCALE_ENGINE_H

#include <stdint.h>

typedef enum {
    SCALE_CHROMATIC = 0,
    SCALE_MAJOR,
    SCALE_NATURAL_MINOR,
    SCALE_PENT_MAJOR,
    SCALE_PENT_MINOR,
    SCALE_DORIAN,
    SCALE_MIXOLYDIAN,
    SCALE_LOCRIAN,
    SCALE_HARM_MINOR,
    SCALE_MELODIC_MINOR,
    SCALE_CUSTOM
} scale_type_t;

void scale_engine_init(void);

int randomizer_set_channel_custom_mask(int ch, uint16_t mask);
uint16_t randomizer_get_channel_custom_mask(int ch);

int randomizer_map_pitch_to_scale(int ch, int pitch);

/* NRPN staging */
void nrpn_scale_stage_channel(int ch);
void nrpn_scale_stage_type(int type);
void nrpn_scale_stage_tonic(int tonic);
void nrpn_scale_commit(void);
void nrpn_scale_reset(void);

void scale_engine_commit_channel(int ch);
void scale_engine_reset_channel(int ch);

#endif

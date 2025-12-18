#include "composer_padmap.h"

uint8_t composer_drum_note(uint8_t idx)
{
    static const uint8_t map[8] = {
        DRUM_KICK,
        DRUM_SNARE,
        DRUM_CLAP,
        DRUM_CH,
        DRUM_OH,
        DRUM_PERC,
        DRUM_RIDE,
        DRUM_FX
    };
    return map[idx & 7u];
}

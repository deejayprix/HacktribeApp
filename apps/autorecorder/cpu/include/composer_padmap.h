#ifndef COMPOSER_PADMAP_H
#define COMPOSER_PADMAP_H

#include <stdint.h>

/* Project-wide Drum Map (fixed) */
#define DRUM_KICK   36 /* C1 */
#define DRUM_SNARE  38 /* D1 */
#define DRUM_CLAP   44 /* G#1 */
#define DRUM_CH     42 /* F#1 */
#define DRUM_OH     46 /* A#1 */
#define DRUM_PERC   51 /* D#2 */
#define DRUM_RIDE   57 /* A2 */
#define DRUM_FX     61 /* C#3 */

uint8_t composer_drum_note(uint8_t idx);

#endif

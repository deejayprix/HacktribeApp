#ifndef FT_TYPES_H
#define FT_TYPES_H

#include <stdint.h>

/* ================================================================
   ft_step_t — Reconstructed Electribe/Freetribe Step Definition
   ================================================================ */

typedef struct {
    /* Position */
    uint8_t part;          /* 0..15  */
    uint8_t step;          /* 0..63  */

    /* Core musical data */
    uint8_t pitch;         /* 0..127 MIDI note     */
    uint8_t velocity;      /* 0..127               */
    uint8_t gate;          /* 0/1                  */
    uint8_t length;        /* step length 0..127   */

    /* Additional flags (tie, accent, mute, cond, etc.) */
    uint8_t flags;

    /* Reserved future fields to avoid crashes */
    uint8_t reserved1;
    uint8_t reserved2;

} ft_step_t;

#endif /* FT_TYPES_H */

#include "composer_utils.h"

/* ------------------------------------------------------------
   PART GROUPS (0..15)
   Harmonics: 0..7  (Pads 1..8)
   Drums:     8..15 (Pads 9..16)
   ------------------------------------------------------------ */

#define PARTMASK_HARMONICS  ((composer_partmask_t)0x00FFu) /* bits 0..7  */
#define PARTMASK_DRUMS      ((composer_partmask_t)0xFF00u) /* bits 8..15 */

/* Individual drum bits (0-based part index) */
#define P_KICK   (1u << 8)
#define P_SNARE  (1u << 9)
#define P_CLAP   (1u << 10)
#define P_CHH    (1u << 11)
#define P_OHH    (1u << 12)
#define P_PERC   (1u << 13)
#define P_RIDE   (1u << 14)
#define P_DFX    (1u << 15)

/* Individual harmonic bits */
#define P_BASS   (1u << 0)
#define P_LEAD   (1u << 1)
#define P_CHORD  (1u << 2)
#define P_ARP    (1u << 3)
#define P_PAD    (1u << 4)
#define P_STABS  (1u << 5)
#define P_PLUCK  (1u << 6)
#define P_HFX    (1u << 7)

/* Clamp segment 0..3 */
static uint8_t seg4(uint8_t s) { return (s > 3) ? 3 : s; }

/* ------------------------------------------------------------
   DECISION TABLE (simple but musical)
   segment: 0=A,1=B,2=C,3=D within section
   ------------------------------------------------------------ */
composer_partmask_t composer_decide_partmask(composer_section_t section,
                                             uint8_t segment)
{
    segment = seg4(segment);

    switch (section)
    {
        case SECTION_INTRO:
            /* Build-in over A..D */
            if (segment == 0) return (composer_partmask_t)(P_KICK | P_CHH | P_BASS | P_PAD);
            if (segment == 1) return (composer_partmask_t)(P_KICK | P_CHH | P_SNARE | P_BASS | P_PAD);
            if (segment == 2) return (composer_partmask_t)(P_KICK | P_CHH | P_SNARE | P_CLAP | P_BASS | P_CHORD | P_PAD);
            return (composer_partmask_t)(P_KICK | P_CHH | P_SNARE | P_CLAP | P_BASS | P_CHORD | P_ARP | P_PAD);

        case SECTION_MAIN:
            /* Full groove, keep D a bit richer */
            if (segment < 3)
                return (composer_partmask_t)(PARTMASK_DRUMS | (P_BASS | P_CHORD | P_ARP | P_LEAD | P_PAD));
            return (composer_partmask_t)(PARTMASK_DRUMS | (P_BASS | P_CHORD | P_ARP | P_LEAD | P_STABS | P_PLUCK | P_PAD));

        case SECTION_BREAK:
            /* Drop kick, focus on harmonics + hats/percs */
            if (segment == 0) return (composer_partmask_t)(P_CHH | P_OHH | P_PERC | (P_PAD | P_CHORD));
            if (segment == 1) return (composer_partmask_t)(P_CHH | P_PERC | (P_PAD | P_CHORD | P_ARP));
            if (segment == 2) return (composer_partmask_t)(P_CHH | P_OHH | P_PERC | (P_PAD | P_CHORD | P_ARP | P_LEAD));
            return (composer_partmask_t)(P_CHH | P_OHH | P_PERC | P_SNARE | (P_PAD | P_CHORD | P_ARP | P_LEAD));

        case SECTION_PEAK:
            /* Everything on */
            return (composer_partmask_t)(PARTMASK_HARMONICS | PARTMASK_DRUMS);

        case SECTION_OUTRO:
            /* Reduce over time */
            if (segment == 0) return (composer_partmask_t)(P_KICK | P_CHH | P_SNARE | P_BASS | P_CHORD | P_PAD);
            if (segment == 1) return (composer_partmask_t)(P_KICK | P_CHH | P_BASS | P_PAD);
            if (segment == 2) return (composer_partmask_t)(P_CHH | P_BASS | P_PAD);
            return (composer_partmask_t)(P_PAD);

        default:
            return (composer_partmask_t)(PARTMASK_HARMONICS | PARTMASK_DRUMS);
    }
}

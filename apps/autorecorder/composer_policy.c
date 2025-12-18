#include "composer_policy.h"

#include "randomizer.h"
#include "composer.h"

/* Helper: clamp */
static int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* =============================================================
   POLICY TABLES: [SECTION][SEGMENT]
   Segment: A,B,C,D => 0..3
   Break/Peak use only A,B (0..1)
   ============================================================= */

/* ---------------- ACID TECHNO ---------------- */
static const composer_policy_segment_t g_acid[][4] = {
    /* INTRO */
    {{20,10, 3, 0,FILL_NONE},{30,15, 4, 0,FILL_GROOVE},{40,18, 5, 1,FILL_GROOVE},{50,22, 6, 1,FILL_BUILD}},
    /* MAIN */
    {{55,25, 7, 0,FILL_GROOVE},{65,30, 8, 0,FILL_GROOVE},{75,35, 9, 1,FILL_BUILD},{80,40,10, 2,FILL_PUNCTUATION}},
    /* BREAK */
    {{35,20, 4,-1,FILL_PUNCTUATION},{45,25, 5, 0,FILL_BUILD},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* PEAK */
    {{85,45,11, 1,FILL_BUILD},{90,50,12, 2,FILL_PUNCTUATION},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* OUTRO */
    {{60,30, 6, 0,FILL_GROOVE},{45,22, 5, 0,FILL_NONE},{30,15, 4,-1,FILL_NONE},{15, 8, 3,-1,FILL_NONE}}
};

/* ---------------- RAVE ---------------- */
static const composer_policy_segment_t g_rave[][4] = {
    {{25,12, 4,0,FILL_NONE},{35,18, 5,0,FILL_GROOVE},{45,24, 6,1,FILL_BUILD},{55,28, 7,1,FILL_BUILD}},
    {{65,32, 8,0,FILL_GROOVE},{75,38, 9,1,FILL_BUILD},{85,44,11,2,FILL_BUILD},{90,50,12,2,FILL_PUNCTUATION}},
    {{30,18, 3,-1,FILL_PUNCTUATION},{40,22, 4,0,FILL_BUILD},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    {{92,55,13,1,FILL_BUILD},{95,60,14,2,FILL_PUNCTUATION},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    {{60,28, 6,0,FILL_GROOVE},{45,20, 5,0,FILL_NONE},{35,14, 4,-1,FILL_NONE},{20,10, 3,-1,FILL_NONE}}
};

/* ---------------- GABBER ---------------- */
static const composer_policy_segment_t g_gabber[][4] = {
    /* INTRO */
    {{30,18, 6,0,FILL_NONE},{45,25, 8,0,FILL_BUILD},{60,30,10,1,FILL_BUILD},{75,35,12,1,FILL_PUNCTUATION}},
    /* MAIN */
    {{85,40,14,0,FILL_GROOVE},{92,50,15,0,FILL_BUILD},{96,60,16,1,FILL_BUILD},{98,70,16,2,FILL_PUNCTUATION}},
    /* BREAK */
    {{40,22, 6,-1,FILL_PUNCTUATION},{55,28, 8,0,FILL_BUILD},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* PEAK */
    {{98,75,16,1,FILL_BUILD},{100,80,16,2,FILL_PUNCTUATION},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* OUTRO */
    {{70,30,12,0,FILL_GROOVE},{55,22,10,0,FILL_NONE},{40,18, 8,-1,FILL_NONE},{25,12, 6,-1,FILL_NONE}}
};

/* ---------------- FRENCHCORE ---------------- */
static const composer_policy_segment_t g_frenchcore[][4] = {
    /* INTRO */
    {{25,15, 5,0,FILL_NONE},{40,22, 7,0,FILL_BUILD},{55,30, 9,1,FILL_BUILD},{70,38,11,1,FILL_PUNCTUATION}},
    /* MAIN */
    {{80,45,12,0,FILL_GROOVE},{88,55,13,1,FILL_BUILD},{94,65,15,1,FILL_BUILD},{98,75,16,2,FILL_PUNCTUATION}},
    /* BREAK */
    {{35,18, 4,-1,FILL_PUNCTUATION},{50,25, 6,0,FILL_BUILD},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* PEAK */
    {{96,72,16,1,FILL_BUILD},{100,80,16,2,FILL_PUNCTUATION},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* OUTRO */
    {{65,30,10,0,FILL_GROOVE},{50,22, 8,0,FILL_NONE},{35,15, 6,-1,FILL_NONE},{20,10, 4,-1,FILL_NONE}}
};

/* ---------------- HAPPY HARDCORE ---------------- */
static const composer_policy_segment_t g_hhc[][4] = {
    /* INTRO */
    {{20,12, 4,0,FILL_NONE},{35,18, 6,0,FILL_GROOVE},{50,25, 8,1,FILL_BUILD},{60,30, 9,1,FILL_BUILD}},
    /* MAIN */
    {{70,35,10,0,FILL_GROOVE},{80,40,11,0,FILL_GROOVE},{88,45,12,1,FILL_BUILD},{92,55,13,2,FILL_PUNCTUATION}},
    /* BREAK */
    {{30,16, 3,-1,FILL_PUNCTUATION},{40,20, 4,0,FILL_BUILD},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* PEAK */
    {{94,60,14,1,FILL_BUILD},{98,70,15,2,FILL_PUNCTUATION},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* OUTRO */
    {{55,25, 7,0,FILL_GROOVE},{40,18, 5,0,FILL_NONE},{30,12, 4,-1,FILL_NONE},{18,10, 3,-1,FILL_NONE}}
};

/* ---------------- TECH TRANCE ---------------- */
static const composer_policy_segment_t g_techtrance[][4] = {
    /* INTRO */
    {{18,10, 3,0,FILL_NONE},{28,14, 4,0,FILL_GROOVE},{40,18, 5,1,FILL_BUILD},{52,22, 6,1,FILL_BUILD}},
    /* MAIN */
    {{62,28, 7,0,FILL_GROOVE},{72,34, 8,1,FILL_GROOVE},{82,40,10,1,FILL_BUILD},{88,48,11,2,FILL_PUNCTUATION}},
    /* BREAK */
    {{26,14, 3,-1,FILL_PUNCTUATION},{38,18, 4,0,FILL_BUILD},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* PEAK */
    {{90,55,12,1,FILL_BUILD},{95,60,13,2,FILL_PUNCTUATION},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* OUTRO */
    {{55,22, 6,0,FILL_GROOVE},{40,16, 5,0,FILL_NONE},{28,12, 4,-1,FILL_NONE},{16, 8, 3,-1,FILL_NONE}}
};

/* ---------------- TEKKNO ---------------- */
static const composer_policy_segment_t g_tekkno[][4] = {
    /* INTRO */
    {{22,12, 4,0,FILL_NONE},{34,18, 5,0,FILL_GROOVE},{48,24, 7,1,FILL_BUILD},{60,30, 8,1,FILL_PUNCTUATION}},
    /* MAIN */
    {{70,34, 9,0,FILL_GROOVE},{80,40,10,1,FILL_BUILD},{90,50,12,1,FILL_BUILD},{95,60,13,2,FILL_PUNCTUATION}},
    /* BREAK */
    {{32,18, 4,-1,FILL_PUNCTUATION},{45,25, 6,0,FILL_BUILD},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* PEAK */
    {{96,65,14,1,FILL_BUILD},{100,75,16,2,FILL_PUNCTUATION},{0,0,0,0,FILL_NONE},{0,0,0,0,FILL_NONE}},
    /* OUTRO */
    {{62,28, 8,0,FILL_GROOVE},{48,22, 6,0,FILL_NONE},{34,15, 5,-1,FILL_NONE},{20,10, 4,-1,FILL_NONE}}
};

static const composer_policy_segment_t* get_policy(uint8_t genre_id,
                                                   composer_section_t section,
                                                   uint8_t segment)
{
    if (segment > 3) segment = 3;

    switch (genre_id)
    {
        case GENRE_ACID_TECHNO:     return &g_acid[section][segment];
        case GENRE_RAVE:           return &g_rave[section][segment];
        case GENRE_GABBER:         return &g_gabber[section][segment];
        case GENRE_FRENCHCORE:     return &g_frenchcore[section][segment];
        case GENRE_HAPPY_HARDCORE: return &g_hhc[section][segment];
        case GENRE_TECH_TRANCE:    return &g_techtrance[section][segment];
        case GENRE_TEKKNO:         return &g_tekkno[section][segment];
        default:                   return 0;
    }
}

void composer_apply_policy(uint8_t genre_id,
                           composer_section_t section,
                           uint8_t segment)
{
    const composer_policy_segment_t *p = get_policy(genre_id, section, segment);
    if (!p) return;

    /* Publish fill-state (SongMode / LiveFX consumers) */
    composer_set_current_fill(p->fill);

    /* Randomizer policy ONLY */
    randomizer_set_section((int)section);
    randomizer_set_density(clampi(p->density, 0, 100));
    randomizer_set_variation(clampi(p->variation, 0, 127));

    /*
     * IMPORTANT:
     * Euclid + Humanizer are applied later in the pipeline:
     *
     * Pattern → Randomizer → Euclid → Humanizer
     *
     * Composer never talks to those engines directly.
     */
}
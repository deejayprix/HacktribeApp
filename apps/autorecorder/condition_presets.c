#include "condition_presets.h"

#include <string.h>

#include "condition_engine.h"
#include "ft_api.h"

/* ============================================================
   IMPORTANT:
   We do NOT depend on composer SECTION_* symbols here.
   We define our own section IDs, matching the common mapping:
     0 Intro, 1 Main, 2 Break, 3 Peak, 4 Outro
   ============================================================ */
enum {
    SEC_INTRO = 0,
    SEC_MAIN  = 1,
    SEC_BREAK = 2,
    SEC_PEAK  = 3,
    SEC_OUTRO = 4
};

/* ============================================================
   Preset IDs
   ============================================================ */
typedef enum {
    PRESET_ALWAYS = 0,
    PRESET_NEVER,

    /* Prob presets */
    PRESET_PROB_PARAM,      /* param = 0..127 */
    PRESET_PROB_25,
    PRESET_PROB_50,
    PRESET_PROB_75,

    /* Section presets (exact match) */
    PRESET_SECTION_PARAM,   /* param = 0..4 */
    PRESET_SECTION_INTRO,
    PRESET_SECTION_MAIN,
    PRESET_SECTION_BREAK,
    PRESET_SECTION_PEAK,
    PRESET_SECTION_OUTRO,

    /* Bar presets (exact match) */
    PRESET_BAR_PARAM,       /* param = 0..127 (we clamp to 0..63 typical) */

    /* Combined examples */
    PRESET_INTRO_AND_PROB_PARAM, /* AND( section=intro, prob=param ) */
    PRESET_MAIN_AND_PROB_PARAM,
    PRESET_NOT_BREAK,            /* NOT( section=break ) */

    PRESET_COUNT
} preset_id_t;

/* ============================================================
   Staging state (browser)
   ============================================================ */
static int g_preset_id = PRESET_ALWAYS;
static int g_preset_param = 64; /* default for PROB param etc. */

/* ============================================================
   Helpers: create nodes
   ============================================================ */
static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static int create_basic(cond_basic_t type, int param)
{
    return randomizer_create_condition_node(type, param);
}

/* Combine a left node with op/right:
   - This uses randomizer_set_condition_node_combine(), which copies
     the current node into left internally if needed.
*/
static int combine_node(int left_node, combine_op_t op, int right_node)
{
    if (left_node < 0) return -1;
    return randomizer_set_condition_node_combine(left_node, op, right_node);
}

/* ============================================================
   Names
   ============================================================ */
int condition_preset_count(void)
{
    return (int)PRESET_COUNT;
}

const char* condition_preset_name(int preset_id)
{
    switch ((preset_id_t)preset_id)
    {
        case PRESET_ALWAYS:                 return "Always (no condition)";
        case PRESET_NEVER:                  return "Never (gate off)";
        case PRESET_PROB_PARAM:             return "Probability = Param";
        case PRESET_PROB_25:                return "Probability 25%";
        case PRESET_PROB_50:                return "Probability 50%";
        case PRESET_PROB_75:                return "Probability 75%";

        case PRESET_SECTION_PARAM:          return "Section = Param";
        case PRESET_SECTION_INTRO:          return "Section = Intro";
        case PRESET_SECTION_MAIN:           return "Section = Main";
        case PRESET_SECTION_BREAK:          return "Section = Break";
        case PRESET_SECTION_PEAK:           return "Section = Peak";
        case PRESET_SECTION_OUTRO:          return "Section = Outro";

        case PRESET_BAR_PARAM:              return "Bar = Param";

        case PRESET_INTRO_AND_PROB_PARAM:   return "Intro AND Prob(Param)";
        case PRESET_MAIN_AND_PROB_PARAM:    return "Main AND Prob(Param)";
        case PRESET_NOT_BREAK:              return "NOT(Break)";

        default:                            return "Unknown";
    }
}

/* ============================================================
   Public API
   ============================================================ */

void condition_preset_select(int preset_id)
{
    g_preset_id = clampi(preset_id, 0, PRESET_COUNT - 1);
}

void condition_preset_set_param(int param)
{
    g_preset_param = clampi(param, 0, 127);
}

/* Build node graph for current preset.
   Returns:
     node_id >= 0  => complex node root
     -1            => special meaning "ALWAYS"
     -2            => special meaning "NEVER" (we represent as PROB 0)
*/
static int build_preset_node(void)
{
    switch ((preset_id_t)g_preset_id)
    {
        case PRESET_ALWAYS:
            return -1;

        case PRESET_NEVER:
            return -2;

        case PRESET_PROB_PARAM:
            return create_basic(COND_PROB, g_preset_param);

        case PRESET_PROB_25:
            return create_basic(COND_PROB, 32);   /* ~25% of 127 */

        case PRESET_PROB_50:
            return create_basic(COND_PROB, 64);   /* ~50% */

        case PRESET_PROB_75:
            return create_basic(COND_PROB, 96);   /* ~75% */

        case PRESET_SECTION_PARAM:
            return create_basic(COND_SECTION, clampi(g_preset_param, 0, 4));

        case PRESET_SECTION_INTRO:
            return create_basic(COND_SECTION, SEC_INTRO);

        case PRESET_SECTION_MAIN:
            return create_basic(COND_SECTION, SEC_MAIN);

        case PRESET_SECTION_BREAK:
            return create_basic(COND_SECTION, SEC_BREAK);

        case PRESET_SECTION_PEAK:
            return create_basic(COND_SECTION, SEC_PEAK);

        case PRESET_SECTION_OUTRO:
            return create_basic(COND_SECTION, SEC_OUTRO);

        case PRESET_BAR_PARAM:
            /* engine supports equality only; clamp typical bar range */
            return create_basic(COND_BAR, clampi(g_preset_param, 0, 63));

        case PRESET_INTRO_AND_PROB_PARAM:
        {
            int root = create_basic(COND_SECTION, SEC_INTRO);
            int prob = create_basic(COND_PROB, g_preset_param);
            if (root < 0 || prob < 0) return -1;
            (void)combine_node(root, COMB_AND, prob);
            return root;
        }

        case PRESET_MAIN_AND_PROB_PARAM:
        {
            int root = create_basic(COND_SECTION, SEC_MAIN);
            int prob = create_basic(COND_PROB, g_preset_param);
            if (root < 0 || prob < 0) return -1;
            (void)combine_node(root, COMB_AND, prob);
            return root;
        }

        case PRESET_NOT_BREAK:
        {
            int root = create_basic(COND_SECTION, SEC_BREAK);
            if (root < 0) return -1;
            (void)combine_node(root, COMB_NOT, -1);
            return root;
        }

        default:
            return -1;
    }
}

/* Apply to staged step:
   uses condition_engine staging (part/step already set via NRPN 50:90/91)
*/
void condition_preset_apply_to_staged_step(void)
{
    int part = condition_get_staged_part();
    int step = condition_get_staged_step();

    /* Build node graph */
    int node = build_preset_node();

    if (node == -1)
    {
        /* ALWAYS => clear condition */
        (void)randomizer_clear_step_condition(part, step);
        return;
    }

    if (node == -2)
    {
        /* NEVER => simple PROB 0 */
        step_condition_ext_t c;
        memset(&c, 0, sizeof(c));
        c.use_complex = 0;
        c.simple.type = COND_PROB;
        c.simple.param = 0;
        c.simple.threshold = 0;
        (void)randomizer_assign_condition_to_step(part, step, &c);
        return;
    }

    /* Complex condition */
    step_condition_ext_t c;
    memset(&c, 0, sizeof(c));
    c.use_complex = 1;
    c.complex_node = node;
    (void)randomizer_assign_condition_to_step(part, step, &c);
}

void condition_preset_dump(void)
{
    int part = condition_get_staged_part();
    int step = condition_get_staged_step();

    ft_print("[COND PRESET] id=%d name=%s param=%d -> staged P%d S%d\n",
             g_preset_id, condition_preset_name(g_preset_id),
             g_preset_param, part, step);
}

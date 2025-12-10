/* condition_engine.c
   Minimal condition-engine stubs used by randomizer.
*/

#include "condition_engine.h"
#include "randomizer.h"   /* <-- FIX: brings RANDOMIZER_MAX_CHANNELS / STEPS */
#include <string.h>
#include <stdint.h>
#include "ft_types.h"


/* Table for step conditions */
static step_condition_ext_t
    g_conditions[RANDOMIZER_MAX_CHANNELS][RANDOMIZER_MAX_STEPS];

/* assign / clear */
int assign_step_condition(int part, int step, const step_condition_ext_t *cond)
{
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return -1;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS) return -2;

    if (!cond) {
        memset(&g_conditions[part][step], 0, sizeof(step_condition_ext_t));
        return 0;
    }

    memcpy(&g_conditions[part][step], cond, sizeof(step_condition_ext_t));
    return 0;
}

int clear_step_condition(int part, int step)
{
    return assign_step_condition(part, step, NULL);
}

/* ============================================================
   CONDITION ENGINE v2 – PUBLIC API
   ============================================================ */

#include "condition_engine.h"
#include <string.h>   /* for memset */

/* Internes Condition-Memory */
static step_condition_ext_t g_conditions[RANDOMIZER_MAX_CHANNELS][RANDOMIZER_MAX_STEPS];



/* ============================================================
   NRPN WRAPPER FUNCTIONS (called from nrpn_router.c)
   ============================================================ */

void nrpn_condition_stage_part(int part)
{
    condition_stage_part(part);
}

void nrpn_condition_stage_step(int step)
{
    condition_stage_step(step);
}

void nrpn_condition_stage_node(int node)
{
    condition_stage_node(node);
}

void nrpn_condition_commit(void)
{
    condition_commit();
}

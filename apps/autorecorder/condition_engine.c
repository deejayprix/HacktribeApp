/*
 * condition_engine.c — Condition Engine v2 (Baseline + NRPN Node Editing)
 *
 * Phase 2 – Step 10:
 * - NRPN: create/edit/delete nodes via MSB50 LSB93..99
 */

#include <stdint.h>
#include <string.h>

#include "condition_engine.h"
#include "randomizer.h"
#include "rng.h"

/* =========================
   CONFIG
   ========================= */
#define COND_MAX_NODES  64

/* =========================
   CONDITION MEMORY
   ========================= */
static step_condition_ext_t g_conditions[RANDOMIZER_MAX_CHANNELS][RANDOMIZER_MAX_STEPS];

/* =========================
   NODE POOL
   ========================= */
static condition_node_t g_nodes[COND_MAX_NODES];

/* =========================
   NRPN STAGING STATE
   ========================= */
static int g_stage_part = 0;
static int g_stage_step = 0;
static int g_stage_node = -1;          /* current node target */
static cond_basic_t g_stage_type = COND_NONE;
static int g_stage_param = 0;

/* =========================
   HELPERS
   ========================= */
static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static void clear_step_cond(step_condition_ext_t *c)
{
    if (!c) return;
    memset(c, 0, sizeof(*c));
    c->use_complex = 0;
    c->simple.type = COND_NONE;
    c->simple.param = 0;
    c->simple.threshold = 0;
    c->complex_node = -1;
}

static int node_valid(int id)
{
    return (id >= 0 && id < COND_MAX_NODES && g_nodes[id].used);
}

static int eval_basic(cond_basic_t type, int param, int bar, int section)
{
    switch (type)
    {
        case COND_NONE:
            return 1;

        case COND_SECTION:
            return (section == param) ? 1 : 0;

        case COND_BAR:
            return (bar == param) ? 1 : 0;

        case COND_PROB:
        case COND_CHANCE:
        {
            int p = clampi(param, 0, 127);
            int r = (int)(rng_get() & 0x7F);
            return (r < p) ? 1 : 0;
        }

        default:
            return 1;
    }
}

static int eval_node(int node_id, int bar, int section)
{
    if (!node_valid(node_id)) return 1;

    condition_node_t *n = &g_nodes[node_id];

    if (!n->is_combine)
        return eval_basic(n->basic_type, n->param, bar, section);

    int left_ok  = eval_node(n->left, bar, section);
    int right_ok = eval_node(n->right, bar, section);

    switch (n->op)
    {
        case COMB_AND: return (left_ok && right_ok) ? 1 : 0;
        case COMB_OR:  return (left_ok || right_ok) ? 1 : 0;
        case COMB_NOT: return (!left_ok) ? 1 : 0;
        default:       return 1;
    }
}

/* =========================
   ENGINE API
   ========================= */

int condition_engine_init(void)
{
    for (int p = 0; p < RANDOMIZER_MAX_CHANNELS; ++p)
        for (int s = 0; s < RANDOMIZER_MAX_STEPS; ++s)
            clear_step_cond(&g_conditions[p][s]);

    memset(g_nodes, 0, sizeof(g_nodes));

    g_stage_part = 0;
    g_stage_step = 0;
    g_stage_node = -1;
    g_stage_type = COND_NONE;
    g_stage_param = 0;

    return 0;
}

int ensure_step_condition_size(int steps)
{
    if (steps <= 0 || steps > RANDOMIZER_MAX_STEPS) return -1;
    return 0;
}

int evaluate_step_condition(
        int part,
        int step,
        int prev_gate,
        int bar,
        int section,
        const ft_step_t *other)
{
    (void)prev_gate;
    (void)other;

    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return 1;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS) return 1;

    step_condition_ext_t *c = &g_conditions[part][step];

    if (!c->use_complex && c->simple.type == COND_NONE)
        return 1;

    if (c->use_complex)
        return eval_node(c->complex_node, bar, section);

    return eval_basic(c->simple.type, c->simple.param, bar, section);
}

/* =========================
   NODE MANAGEMENT
   ========================= */

int randomizer_create_condition_node(cond_basic_t type, int param)
{
    for (int i = 0; i < COND_MAX_NODES; ++i)
    {
        if (!g_nodes[i].used)
        {
            g_nodes[i].used = 1;
            g_nodes[i].is_combine = 0;
            g_nodes[i].basic_type = type;
            g_nodes[i].param = param;
            g_nodes[i].op = COMB_AND;
            g_nodes[i].left = -1;
            g_nodes[i].right = -1;
            return i;
        }
    }
    return -1;
}

int randomizer_set_condition_node_basic(int node_id, cond_basic_t type, int param)
{
    if (!node_valid(node_id)) return -1;
    condition_node_t *n = &g_nodes[node_id];
    n->is_combine = 0;
    n->basic_type = type;
    n->param = param;
    n->left = -1;
    n->right = -1;
    return 0;
}

int randomizer_set_condition_node_combine(int node_id, combine_op_t op, int right_node_id)
{
    if (!node_valid(node_id)) return -1;
    if (right_node_id != -1 && !node_valid(right_node_id)) return -2;

    condition_node_t *n = &g_nodes[node_id];

    /* ensure LEFT exists: copy current basic into a new node */
    if (!n->is_combine)
    {
        int left_copy = randomizer_create_condition_node(n->basic_type, n->param);
        if (left_copy < 0) return -3;
        n->left = left_copy;
    }

    n->is_combine = 1;
    n->op = op;
    n->right = (op == COMB_NOT) ? -1 : right_node_id;

    return 0;
}

int randomizer_remove_condition_node(int node_id)
{
    if (node_id < 0 || node_id >= COND_MAX_NODES) return -1;
    memset(&g_nodes[node_id], 0, sizeof(g_nodes[node_id]));
    return 0;
}

/* =========================
   STEP ASSIGN / CLEAR
   ========================= */

int randomizer_assign_condition_to_step(int part, int step, const step_condition_ext_t *cond)
{
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return -1;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS) return -2;

    if (!cond)
    {
        clear_step_cond(&g_conditions[part][step]);
        return 0;
    }

    g_conditions[part][step] = *cond;

    if (g_conditions[part][step].use_complex)
    {
        if (!node_valid(g_conditions[part][step].complex_node))
            clear_step_cond(&g_conditions[part][step]);
    }

    return 0;
}

int randomizer_clear_step_condition(int part, int step)
{
    return randomizer_assign_condition_to_step(part, step, NULL);
}

/* =========================
   NRPN STAGING (Step assign)
   ========================= */

void condition_stage_part(int part)
{
    g_stage_part = clampi(part, 0, RANDOMIZER_MAX_CHANNELS - 1);
}

void condition_stage_step(int step)
{
    g_stage_step = clampi(step, 0, RANDOMIZER_MAX_STEPS - 1);
}

void condition_stage_node(int node)
{
    g_stage_node = node;
}

void condition_commit(void)
{
    if (g_stage_node < 0)
    {
        randomizer_clear_step_condition(g_stage_part, g_stage_step);
        return;
    }

    step_condition_ext_t c;
    clear_step_cond(&c);

    if (node_valid(g_stage_node))
    {
        c.use_complex = 1;
        c.complex_node = g_stage_node;
        randomizer_assign_condition_to_step(g_stage_part, g_stage_step, &c);
        return;
    }

    /* fallback: treat as simple PROB value (0..127) */
    c.use_complex = 0;
    c.simple.type = COND_PROB;
    c.simple.param = clampi(g_stage_node, 0, 127);
    randomizer_assign_condition_to_step(g_stage_part, g_stage_step, &c);
}

/* =========================
   NRPN NODE EDITING (Step 10)
   ========================= */

void nrpn_condition_node_create(int basic_type)
{
    g_stage_type = (cond_basic_t)clampi(basic_type, 0, (int)COND_BASIC_MAX - 1);
    /* create node now, store id into g_stage_node */
    int id = randomizer_create_condition_node(g_stage_type, g_stage_param);
    g_stage_node = id;
}

void nrpn_condition_node_set_param(int param)
{
    g_stage_param = clampi(param, 0, 127);

    /* if a node is currently selected and is basic, update it */
    if (node_valid(g_stage_node) && !g_nodes[g_stage_node].is_combine)
        randomizer_set_condition_node_basic(g_stage_node, g_nodes[g_stage_node].basic_type, g_stage_param);
}

void nrpn_condition_node_to_and(int right_node)
{
    if (!node_valid(g_stage_node)) return;
    if (!node_valid(right_node)) return;
    (void)randomizer_set_condition_node_combine(g_stage_node, COMB_AND, right_node);
}

void nrpn_condition_node_to_or(int right_node)
{
    if (!node_valid(g_stage_node)) return;
    if (!node_valid(right_node)) return;
    (void)randomizer_set_condition_node_combine(g_stage_node, COMB_OR, right_node);
}

void nrpn_condition_node_to_not(void)
{
    if (!node_valid(g_stage_node)) return;
    (void)randomizer_set_condition_node_combine(g_stage_node, COMB_NOT, -1);
}

void nrpn_condition_node_delete(int node_id)
{
    (void)randomizer_remove_condition_node(node_id);
    if (g_stage_node == node_id)
        g_stage_node = -1;
}

/* =========================
   NRPN WRAPPERS (router calls)
   ========================= */

void nrpn_condition_stage_part(int part) { condition_stage_part(part); }
void nrpn_condition_stage_step(int step) { condition_stage_step(step); }
void nrpn_condition_stage_node(int node) { condition_stage_node(node); }
void nrpn_condition_commit(void) { condition_commit(); }


/* ============================================================
   DEBUG / INTROSPECTION STUBS (Phase 2 – Step 11)
   ============================================================ */

int condition_debug_node_count(void)
{
    /* no real node graph yet */
    return 0;
}

void condition_debug_dump_current(void)
{
    /* intentionally empty (debug stub) */
}

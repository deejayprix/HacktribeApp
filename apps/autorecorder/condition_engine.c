/* 
 * condition_engine.c — Condition Engine v2
 *
 * Phase 2 – Step 10:
 * - NRPN Node Editing (MSB50 LSB93..99)
 *
 * Phase 3.1.5:
 * - Debug Visualizer (Text / Tree Dump)
 *
 * Phase 3.2.1:
 * - Per-Step Probability API
 */

#include <stdint.h>
#include <string.h>

#include "condition_engine.h"
#include "randomizer.h"
#include "rng.h"
#include "ft_api.h"

/* ============================================================
   CONFIG
   ============================================================ */

#define COND_MAX_NODES_LOCAL 64
#if (COND_MAX_NODES_LOCAL != COND_MAX_NODES)
#error "COND_MAX_NODES mismatch"
#endif

#define DEBUG_MAX_DEPTH 12

/* ============================================================
   FORWARD DECLARATIONS
   ============================================================ */

static void dbg_dump_node(int id, int depth);

/* =========================
   DEBUG STATE (GLOBAL)
   ========================= */

static int g_debug_enabled = 0;
static int g_debug_part = 0;
static int g_debug_step = 0;

/* ============================================================
   CONDITION MEMORY
   ============================================================ */

static step_condition_ext_t
    g_conditions[RANDOMIZER_MAX_CHANNELS][RANDOMIZER_MAX_STEPS];

/* ============================================================
   NODE POOL
   ============================================================ */

static condition_node_t g_nodes[COND_MAX_NODES];

/* ============================================================
   NRPN STAGING STATE
   ============================================================ */

static int g_stage_part  = 0;
static int g_stage_step  = 0;
static int g_stage_node  = -1;
static cond_basic_t g_stage_type = COND_NONE;
static int g_stage_param = 0;

/* ============================================================
   HELPERS
   ============================================================ */

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

/* ============================================================
   DEBUG HELPERS
   ============================================================ */

static const char* cond_basic_name(cond_basic_t t)
{
    switch (t)
    {
        case COND_NONE:    return "NONE";
        case COND_PROB:    return "PROB";
        case COND_SECTION: return "SECTION";
        case COND_BAR:     return "BAR";
        case COND_CHANCE:  return "CHANCE";
        default:           return "UNKNOWN";
    }
}

static const char* comb_name(combine_op_t op)
{
    switch (op)
    {
        case COMB_AND: return "AND";
        case COMB_OR:  return "OR";
        case COMB_NOT: return "NOT";
        default:       return "?";
    }
}

/* ============================================================
   EVALUATION
   ============================================================ */

static int eval_basic(cond_basic_t type, int param, int bar, int section)
{
    switch (type)
    {
        case COND_NONE: return 1;
        case COND_SECTION: return (section == param);
        case COND_BAR: return (bar == param);
        case COND_PROB:
        case COND_CHANCE:
        {
            int p = clampi(param, 0, 127);
            return ((rng_get() & 0x7F) < p);
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

    int l = eval_node(n->left, bar, section);
    int r = eval_node(n->right, bar, section);

    switch (n->op)
    {
        case COMB_AND: return l && r;
        case COMB_OR:  return l || r;
        case COMB_NOT: return !l;
        default:       return 1;
    }
}

/* ============================================================
   ENGINE API
   ============================================================ */

int condition_engine_init(void)
{
    memset(g_conditions, 0, sizeof(g_conditions));
    memset(g_nodes, 0, sizeof(g_nodes));

    g_stage_part = 0;
    g_stage_step = 0;
    g_stage_node = -1;
    g_stage_type = COND_NONE;
    g_stage_param = 0;

    return 0;
}

int evaluate_step_condition(
    int part, int step, int prev_gate,
    int bar, int section, const ft_step_t *other)
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

/* ============================================================
   NODE MANAGEMENT
   ============================================================ */

int randomizer_create_condition_node(cond_basic_t type, int param)
{
    for (int i = 0; i < COND_MAX_NODES; i++)
        if (!g_nodes[i].used)
        {
            g_nodes[i].used = 1;
            g_nodes[i].is_combine = 0;
            g_nodes[i].basic_type = type;
            g_nodes[i].param = param;
            g_nodes[i].left = -1;
            g_nodes[i].right = -1;
            return i;
        }
    return -1;
}

int randomizer_set_condition_node_basic(int id, cond_basic_t t, int p)
{
    if (!node_valid(id)) return -1;
    g_nodes[id].is_combine = 0;
    g_nodes[id].basic_type = t;
    g_nodes[id].param = p;
    g_nodes[id].left = -1;
    g_nodes[id].right = -1;
    return 0;
}

int randomizer_set_condition_node_combine(int id, combine_op_t op, int right)
{
    if (!node_valid(id)) return -1;

    condition_node_t *n = &g_nodes[id];

    if (!n->is_combine)
    {
        int left = randomizer_create_condition_node(
            n->basic_type, n->param);
        if (left < 0) return -2;
        n->left = left;
    }

    n->is_combine = 1;
    n->op = op;
    n->right = (op == COMB_NOT) ? -1 : right;
    return 0;
}

int randomizer_remove_condition_node(int id)
{
    if (id < 0 || id >= COND_MAX_NODES) return -1;
    memset(&g_nodes[id], 0, sizeof(condition_node_t));
    return 0;
}

/* ============================================================
   STEP ASSIGN
   ============================================================ */

int randomizer_assign_condition_to_step(
    int part, int step, const step_condition_ext_t *c)
{
    if (!c)
    {
        clear_step_cond(&g_conditions[part][step]);
        return 0;
    }

    g_conditions[part][step] = *c;
    if (c->use_complex && !node_valid(c->complex_node))
        clear_step_cond(&g_conditions[part][step]);

    return 0;
}

int randomizer_clear_step_condition(int part, int step)
{
    return randomizer_assign_condition_to_step(part, step, NULL);
}

/* ============================================================
   STAGING API
   ============================================================ */

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
    }
    else
    {
        c.simple.type = COND_PROB;
        c.simple.param = clampi(g_stage_node, 0, 127);
    }

    randomizer_assign_condition_to_step(g_stage_part, g_stage_step, &c);
}

/* ============================================================
   PHASE 3.2.1 – PER-STEP PROBABILITY
   ============================================================ */

void condition_set_step_probability(int part, int step, int prob)
{
    prob = clampi(prob, 0, 127);

    if (prob >= 127)
    {
        randomizer_clear_step_condition(part, step);
        return;
    }

    step_condition_ext_t c;
    clear_step_cond(&c);
    c.simple.type = COND_PROB;
    c.simple.param = prob;

    randomizer_assign_condition_to_step(part, step, &c);
}

/* ============================================================
   DEBUG VISUALIZER (Phase 3.1.5)
   ============================================================ */

static void dbg_indent(int d)
{
    while (d--) ft_print("  ");
}

static void dbg_dump_node(int id, int d)
{
    if (!node_valid(id) || d > DEBUG_MAX_DEPTH)
        return;

    condition_node_t *n = &g_nodes[id];
    dbg_indent(d);

    if (!n->is_combine)
    {
        ft_print("NODE %d BASIC %s param=%d\n",
                 id, cond_basic_name(n->basic_type), n->param);
        return;
    }

    ft_print("NODE %d COMB %s\n", id, comb_name(n->op));
    dbg_dump_node(n->left, d + 1);
    if (n->op != COMB_NOT)
        dbg_dump_node(n->right, d + 1);
}

void condition_debug_dump_current(void)
{
    step_condition_ext_t *c =
        &g_conditions[g_stage_part][g_stage_step];

    ft_print("\n[COND DBG] part=%d step=%d\n",
             g_stage_part, g_stage_step);

    if (!c->use_complex && c->simple.type == COND_NONE)
    {
        ft_print("  <NO CONDITION>\n");
        return;
    }

    if (!c->use_complex)
    {
        ft_print("  SIMPLE %s param=%d\n",
                 cond_basic_name(c->simple.type),
                 c->simple.param);
        return;
    }

    ft_print("  COMPLEX root=%d\n", c->complex_node);
    dbg_dump_node(c->complex_node, 1);
}

/* ============================================================
   NRPN + DEBUG WRAPPERS
   ============================================================ */

int condition_get_staged_part(void) { return g_stage_part; }
int condition_get_staged_step(void) { return g_stage_step; }

void nrpn_condition_stage_part(int part) { condition_stage_part(part); }
void nrpn_condition_stage_step(int step) { condition_stage_step(step); }
void nrpn_condition_stage_node(int node) { condition_stage_node(node); }
void nrpn_condition_commit(void) { condition_commit(); }

void condition_debug_enable(int on)
{
    g_debug_enabled = (on != 0);
}

void condition_debug_select(int part, int step)
{
    g_debug_part = clampi(part, 0, RANDOMIZER_MAX_CHANNELS - 1);
    g_debug_step = clampi(step, 0, RANDOMIZER_MAX_STEPS - 1);
}

void condition_debug_dump_step(void)
{
    if (!g_debug_enabled) return;

    step_condition_ext_t *c =
        &g_conditions[g_debug_part][g_debug_step];

    ft_print("[COND DBG] Part %d Step %d\n",
             g_debug_part, g_debug_step);

    if (!c->use_complex)
    {
        ft_print("  Simple: type=%d param=%d\n",
                 c->simple.type, c->simple.param);
        return;
    }

    ft_print("  Complex node id=%d\n", c->complex_node);
}

void condition_debug_dump_node(int node_id)
{
    if (!g_debug_enabled) return;

    ft_print("[COND DBG] Dump node %d\n", node_id);
    dbg_dump_node(node_id, 0);
}
/* ============================================================
   NRPN CONDITION NODE EDITING
   (Phase 2 – Step 10)
   ============================================================ */

void nrpn_condition_node_create(int basic_type)
{
    int node = randomizer_create_condition_node(
        (cond_basic_t)basic_type, 0);

    g_stage_node = node;
}

void nrpn_condition_node_set_param(int param)
{
    if (g_stage_node < 0) return;

    randomizer_set_condition_node_basic(
        g_stage_node,
        g_nodes[g_stage_node].basic_type,
        clampi(param, 0, 127));
}

void nrpn_condition_node_to_and(int right_node)
{
    if (g_stage_node < 0) return;
    randomizer_set_condition_node_combine(
        g_stage_node, COMB_AND, right_node);
}

void nrpn_condition_node_to_or(int right_node)
{
    if (g_stage_node < 0) return;
    randomizer_set_condition_node_combine(
        g_stage_node, COMB_OR, right_node);
}

void nrpn_condition_node_to_not(void)
{
    if (g_stage_node < 0) return;
    randomizer_set_condition_node_combine(
        g_stage_node, COMB_NOT, -1);
}

void nrpn_condition_node_delete(int node_id)
{
    randomizer_remove_condition_node(node_id);
    if (g_stage_node == node_id)
        g_stage_node = -1;
}

#ifndef CONDITION_ENGINE_H
#define CONDITION_ENGINE_H

#include <stdint.h>
#include "ft_types.h"

/* ============================================================
   CONSTANTS
   ============================================================ */

#define COND_MAX_NODES 64

/* ============================================================
   BASIC CONDITION TYPES
   ============================================================ */

typedef enum {
    COND_NONE = 0,
    COND_PROB,
    COND_SECTION,
    COND_BAR,
    COND_CHANCE,
    COND_BASIC_MAX
} cond_basic_t;

/* ============================================================
   COMBINE OPERATORS
   ============================================================ */

typedef enum {
    COMB_AND = 0,
    COMB_OR,
    COMB_NOT
} combine_op_t;

/* ============================================================
   CONDITION NODE (ID-BASED, INTERNAL GRAPH)
   ============================================================ */

typedef struct {
    uint8_t used;          /* slot in use */
    uint8_t is_combine;    /* 0 = basic, 1 = combine */

    /* basic node */
    cond_basic_t basic_type;
    int          param;

    /* combine node */
    combine_op_t op;
    int          left;     /* node id */
    int          right;    /* node id */
} condition_node_t;

/* ============================================================
   STEP CONDITION CONTAINER
   ============================================================ */

typedef struct {
    int use_complex;

    struct {
        cond_basic_t type;
        int param;
        int threshold;
    } simple;

    int complex_node;   /* node id, NOT pointer */
} step_condition_ext_t;

/* ============================================================
   CORE ENGINE API
   ============================================================ */

int  condition_engine_init(void);

int  ensure_step_condition_size(int steps);

int  evaluate_step_condition(
        int part,
        int step,
        int prev_gate,
        int bar,
        int section,
        const ft_step_t *other);

/* ============================================================
   NODE MANAGEMENT (Randomizer / NRPN)
   ============================================================ */

int randomizer_create_condition_node(cond_basic_t type, int param);

int randomizer_set_condition_node_basic(
        int node_id,
        cond_basic_t type,
        int param);

int randomizer_set_condition_node_combine(
        int node_id,
        combine_op_t op,
        int right_node_id);

int randomizer_remove_condition_node(int node_id);

/* ============================================================
   STEP ASSIGNMENT
   ============================================================ */

int randomizer_assign_condition_to_step(
        int part,
        int step,
        const step_condition_ext_t *cond);

int randomizer_clear_step_condition(int part, int step);

/* ============================================================
   NRPN STAGING
   ============================================================ */

void nrpn_condition_stage_part(int part);
void nrpn_condition_stage_step(int step);
void nrpn_condition_stage_node(int node);
void nrpn_condition_commit(void);

/* ============================================================
   STAGING API (ENGINE SIDE)
   ============================================================ */

void condition_stage_part(int part);
void condition_stage_step(int step);
void condition_stage_node(int node);
void condition_commit(void);

/* ============================================================
   DEBUG / INTROSPECTION (Phase 2 – Step 11)
   ============================================================ */

int  condition_debug_node_count(void);
void condition_debug_dump_current(void);

#endif /* CONDITION_ENGINE_H */

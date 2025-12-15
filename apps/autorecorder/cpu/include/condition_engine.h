#ifndef CONDITION_ENGINE_H
#define CONDITION_ENGINE_H

#include <stdint.h>
#include "ft_types.h"

/*
 * Condition primitives
 */
typedef enum {
    COND_NONE = 0,
    COND_PROB,
    COND_SECTION,
    COND_BAR,
    COND_CHANCE,
    COND_BASIC_MAX
} cond_basic_t;

typedef enum {
    COMB_AND = 0,
    COMB_OR,
    COMB_NOT
} combine_op_t;

/* Nodes for complex conditions */
typedef struct condition_node {
    cond_basic_t type;
    int param;
    struct condition_node *left;
    struct condition_node *right;
} condition_node_t;

/* Step condition container */
typedef struct step_condition_ext {
    int use_complex;

    struct {
        cond_basic_t type;
        int param;
        int threshold;
    } simple;

    condition_node_t *complex;
} step_condition_ext_t;

/* API */
int  condition_engine_init(void);

int  ensure_step_condition_size(int steps);
int  evaluate_step_condition(
        int part,
        int step,
        int prev_gate,
        int bar,
        int section,
        const ft_step_t *other);

/* Node management */
int randomizer_create_condition_node(cond_basic_t type, int param);
int randomizer_set_condition_node_basic(int node_id, cond_basic_t type, int param);
int randomizer_set_condition_node_combine(int node_id, combine_op_t op, int right_node_id);
int randomizer_remove_condition_node(int node_id);

/* Assign/remove condition on step */
int randomizer_assign_condition_to_step(int part, int step, const step_condition_ext_t *cond);
int randomizer_clear_step_condition(int part, int step);

/* NRPN staging */
void nrpn_condition_stage_part(int part);
void nrpn_condition_stage_step(int step);
void nrpn_condition_stage_node(int node);
void nrpn_condition_commit(void);

/* Public API */
void condition_stage_part(int part);
void condition_stage_step(int step);
void condition_stage_node(int node);
void condition_commit(void);

/* NRPN wrappers used by nrpn_router */
void nrpn_condition_stage_part(int part);
void nrpn_condition_stage_step(int step);
void nrpn_condition_stage_node(int node);
void nrpn_condition_commit(void);

#endif

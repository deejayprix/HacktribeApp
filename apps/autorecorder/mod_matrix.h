#ifndef MOD_MATRIX_H
#define MOD_MATRIX_H

#include <stdint.h>
#include "ft_types.h"        // <-- FIX: jetzt ft_step_t bekannt

#define MOD_MATRIX_MAX_ROUTES 32

/* ===== SOURCES ===== */
typedef enum {
    MOD_SRC_NONE = 0,
    MOD_SRC_EUCLID_GATE = 1,
    MOD_SRC_MOTION = 2,
    MOD_SRC_RANDOM = 3
} mod_source_t;

/* ===== DESTINATIONS ===== */
typedef enum {
    MOD_DST_VELOCITY = 0,
    MOD_DST_PITCH    = 1,
    MOD_DST_GATE     = 2
} mod_dest_t;

/* ===== MOD ROUTE ===== */
typedef struct {
    mod_source_t src;
    mod_dest_t   dst;
    int          arg;     /* lane / slot / channel index */
    int          amount;  /* -127..+127 */
} mod_route_t;

/* ===== STAGED ROUTE ===== */
extern mod_route_t g_staged_route;

/* ===== API ===== */
void mod_matrix_init(void);

void mod_matrix_stage_source(int src);
void mod_matrix_stage_destination(int dst);
void mod_matrix_stage_argument(int a);
void mod_matrix_stage_amount(int amt);
void mod_matrix_commit_route(void);

int  mod_matrix_add(const mod_route_t *r);
int  mod_matrix_remove(int idx);
int  mod_matrix_clear(void);

void mod_matrix_apply(ft_step_t *s, int ch, int step);

#endif

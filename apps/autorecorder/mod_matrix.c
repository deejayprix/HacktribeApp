#include "mod_matrix.h"
#include "randomizer.h"
#include "rng.h"          // <-- FIX: rng_get is here
#include "ft_types.h"

mod_route_t g_staged_route;

static mod_route_t g_routes[MOD_MATRIX_MAX_ROUTES];
static int g_route_count = 0;

/* INIT */
void mod_matrix_init(void)
{
    g_route_count = 0;

    g_staged_route.src    = MOD_SRC_NONE;
    g_staged_route.dst    = MOD_DST_VELOCITY;
    g_staged_route.arg    = 0;
    g_staged_route.amount = 0;
}

/* STAGE BUILDERS */
void mod_matrix_stage_source(int src)         { g_staged_route.src = src; }
void mod_matrix_stage_destination(int dst)    { g_staged_route.dst = dst; }
void mod_matrix_stage_argument(int a)         { g_staged_route.arg = a; }
void mod_matrix_stage_amount(int amt)         { g_staged_route.amount = amt; }

/* COMMIT ROUTE */
void mod_matrix_commit_route(void)
{
    if (g_staged_route.src == MOD_SRC_NONE) return;
    if (g_route_count >= MOD_MATRIX_MAX_ROUTES) return;

    g_routes[g_route_count++] = g_staged_route;

    g_staged_route.src    = MOD_SRC_NONE;
    g_staged_route.dst    = MOD_DST_VELOCITY;
    g_staged_route.arg    = 0;
    g_staged_route.amount = 0;
}

/* REMOVE */
int mod_matrix_add(const mod_route_t *r)
{
    if (g_route_count >= MOD_MATRIX_MAX_ROUTES)
        return -1;

    g_routes[g_route_count] = *r;
    return g_route_count++;
}

int mod_matrix_remove(int idx)
{
    if (idx < 0 || idx >= g_route_count)
        return -1;

    for (int i = idx; i < g_route_count - 1; i++)
        g_routes[i] = g_routes[i + 1];

    g_route_count--;
    return 0;
}

int mod_matrix_clear(void)
{
    g_route_count = 0;
    return 0;
}

/* APPLY */
static inline int clamp(int v, int lo, int hi)
{
    return (v < lo) ? lo : (v > hi ? hi : v);
}

void mod_matrix_apply(ft_step_t *s, int ch, int step)
{
    for (int i = 0; i < g_route_count; i++) {
        const mod_route_t *r = &g_routes[i];
        int src_val = 0;

        switch (r->src)
        {
            case MOD_SRC_EUCLID_GATE:
                src_val = randomizer_get_euclid_value_public(ch, r->arg, step);
                break;

            case MOD_SRC_MOTION:
                src_val = randomizer_get_motion_value(r->arg, step);
                break;

            case MOD_SRC_RANDOM:
                src_val = (rng_get() & 0x7F);
                break;

            default:
                continue;
        }

        int delta = (src_val * r->amount) / 127;

        switch (r->dst)
        {
            case MOD_DST_VELOCITY:
                s->velocity = clamp(s->velocity + delta, 0, 127);
                break;

            case MOD_DST_PITCH:
                s->pitch = clamp(s->pitch + delta, 0, 127);
                break;

            case MOD_DST_GATE:
                s->gate = clamp(s->gate + delta, 0, 1);
                break;
        }
    }
}

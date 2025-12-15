#include "humanizer.h"
#include "rng.h"
#include <stdlib.h>
#include <string.h>

int humanizer_apply_timing(ft_step_t *steps, int nsteps, int jitter_range)
{
    if (!steps || nsteps <= 0 || jitter_range <= 0) return 0;

    /* temporary containers for result */
    uint8_t *gates = (uint8_t*)calloc((size_t)nsteps, 1);
    uint8_t *vels  = (uint8_t*)calloc((size_t)nsteps, 1);
    uint8_t *pitches = (uint8_t*)calloc((size_t)nsteps, 1);
    if (!gates || !vels || !pitches) {
        free(gates); free(vels); free(pitches);
        return 0;
    }

    for (int i = 0; i < nsteps; ++i) {
        if (steps[i].gate) {
            int shift = rng_int(jitter_range * 2 + 1) - jitter_range; /* [-j..+j] */
            int dest = i + shift;
            if (dest < 0) dest += nsteps;
            if (dest >= nsteps) dest -= nsteps;
            gates[dest] = 1;
            vels[dest] = steps[i].velocity ? steps[i].velocity : 1;
            pitches[dest] = steps[i].pitch;
        }
    }

    /* copy back */
    for (int i = 0; i < nsteps; ++i) {
        steps[i].gate = gates[i];
        if (gates[i]) {
            steps[i].velocity = vels[i];
            steps[i].pitch = pitches[i];
        } else {
            steps[i].velocity = 0;
        }
    }

    free(gates); free(vels); free(pitches);
    return nsteps;
}

int humanizer_apply_velocity(ft_step_t *steps, int nsteps, int vel_range, int mode)
{
    if (!steps || nsteps <= 0 || vel_range <= 0) return 0;

    for (int i = 0; i < nsteps; ++i) {
        if (!steps[i].gate) continue;
        int base = steps[i].velocity ? steps[i].velocity : 1;
        if (mode == 0) {
            int delta = rng_int(vel_range * 2 + 1) - vel_range;
            int nv = base + delta;
            if (nv < 1) nv = 1;
            if (nv > 127) nv = 127;
            steps[i].velocity = (uint8_t)nv;
        } else {
            int lo = base - vel_range; if (lo < 1) lo = 1;
            int hi = base + vel_range; if (hi > 127) hi = 127;
            int nv = lo + rng_int(hi - lo + 1);
            steps[i].velocity = (uint8_t)nv;
        }
    }
    return nsteps;
}

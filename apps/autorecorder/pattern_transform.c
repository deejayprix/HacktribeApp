#include "pattern_transform.h"
#include "pattern_writer.h"   /* FIX: makes paging/read/write explicit */
#include <string.h>
#include <stdlib.h>

/* get step count dynamically */
static int get_step_count_for_part(int part)
{
    (void)part;
    int ps = pattern_get_paging_page_size();
    if (ps <= 0) ps = 64;
    return ps;
}

void transform_rotate(int part, int amount)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;
    amount = (amount % n + n) % n;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    ft_step_t *src = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf || !src) { free(buf); free(src); return; }

    pattern_read_steps(part, src, n);

    for (int i = 0; i < n; ++i)
        buf[(i + amount) % n] = src[i];

    pattern_write_steps(part, buf, n);

    free(buf); free(src);
}

void transform_mirror(int part)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    ft_step_t *src = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf || !src) { free(buf); free(src); return; }

    pattern_read_steps(part, src, n);

    for (int i = 0; i < n; ++i)
        buf[i] = src[n - 1 - i];

    pattern_write_steps(part, buf, n);

    free(buf); free(src);
}

void transform_invert(int part)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf) return;

    pattern_read_steps(part, buf, n);

    for (int i = 0; i < n; ++i)
        buf[i].gate = (buf[i].gate > 0) ? 0 : 100;

    pattern_write_steps(part, buf, n);

    free(buf);
}

void transform_scale_steps(int part, int scale)
{
    if (scale <= 0) return;

    int old = get_step_count_for_part(part);
    if (old <= 0) return;

    int new_count = old * scale;

    ft_step_t *src = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)old);
    ft_step_t *dst = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)new_count);
    if (!src || !dst) { free(src); free(dst); return; }

    pattern_read_steps(part, src, old);

    for (int i = 0; i < new_count; ++i)
        dst[i] = src[i / scale];

    pattern_write_steps(part, dst, new_count);

    free(src); free(dst);
}

void transform_humanize(int part, int vel_amt, int pitch_amt)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf) return;

    pattern_read_steps(part, buf, n);

    for (int i = 0; i < n; ++i) {
        if (vel_amt > 0) buf[i].velocity += (rand() % vel_amt) - vel_amt/2;
        if (pitch_amt > 0) buf[i].pitch  += (rand() % pitch_amt) - pitch_amt/2;
    }

    pattern_write_steps(part, buf, n);
    free(buf);
}

void transform_euclidean(int part, int fills, int total_steps)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf) return;

    memset(buf, 0, sizeof(ft_step_t) * (size_t)n);

    if (fills < 0) fills = 0;
    if (total_steps <= 0) total_steps = n;

    for (int i = 0; i < fills; ++i) {
        int idx = (i * total_steps) / (fills ? fills : 1);
        if (idx >= 0 && idx < n) {
            buf[idx].part = (uint8_t)part;
            buf[idx].step = (uint8_t)idx;
            buf[idx].gate = 100;
        }
    }

    pattern_write_steps(part, buf, n);
    free(buf);
}

/* Apply global transform pipeline */
void pattern_transform_apply(int part, ft_step_t *steps, int count)
{
    (void)part;
    (void)steps;
    (void)count;
    /* reserved */
}

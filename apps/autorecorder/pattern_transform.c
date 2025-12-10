#include "pattern_transform.h"
#include "pattern_ram_map.h"
#include <string.h>
#include <stdlib.h>

/* get step count dynamically */
static int get_step_count_for_part(int part)
{
    int ps = pattern_get_paging_page_size();
    if (ps <= 0) ps = 64;
    return ps;
}

void transform_rotate(int part, int amount)
{
    int n = get_step_count_for_part(part);
    amount = (amount % n + n) % n;

    ft_step_t *buf = malloc(sizeof(ft_step_t)*n);
    ft_step_t *src = malloc(sizeof(ft_step_t)*n);

    pattern_read_steps(part, src, n);

    for (int i = 0; i < n; ++i)
        buf[(i + amount) % n] = src[i];

    pattern_write_steps(part, buf, n);

    free(buf); free(src);
}

void transform_mirror(int part)
{
    int n = get_step_count_for_part(part);

    ft_step_t *buf = malloc(sizeof(ft_step_t)*n);
    ft_step_t *src = malloc(sizeof(ft_step_t)*n);

    pattern_read_steps(part, src, n);

    for (int i = 0; i < n; ++i)
        buf[i] = src[n - 1 - i];

    pattern_write_steps(part, buf, n);

    free(buf); free(src);
}

void transform_invert(int part)
{
    int n = get_step_count_for_part(part);

    ft_step_t *buf = malloc(sizeof(ft_step_t)*n);
    pattern_read_steps(part, buf, n);

    for (int i = 0; i < n; ++i) {
        buf[i].gate = (buf[i].gate > 0) ? 0 : 100;
    }

    pattern_write_steps(part, buf, n);

    free(buf);
}

void transform_scale_steps(int part, int scale)
{
    int old = get_step_count_for_part(part);
    int new_count = old * scale;

    ft_step_t *src = malloc(sizeof(ft_step_t)*old);
    ft_step_t *dst = malloc(sizeof(ft_step_t)*new_count);

    pattern_read_steps(part, src, old);

    for (int i = 0; i < new_count; ++i)
        dst[i] = src[i / scale];

    pattern_write_steps(part, dst, new_count);
    free(src); free(dst);
}

void transform_humanize(int part, int vel_amt, int pitch_amt)
{
    int n = get_step_count_for_part(part);

    ft_step_t *buf = malloc(sizeof(ft_step_t)*n);
    pattern_read_steps(part, buf, n);

    for (int i = 0; i < n; ++i) {
        buf[i].velocity += (rand() % vel_amt) - vel_amt/2;
        buf[i].pitch    += (rand() % pitch_amt) - pitch_amt/2;
    }

    pattern_write_steps(part, buf, n);
    free(buf);
}

void transform_euclidean(int part, int fills, int total_steps)
{
    int n = get_step_count_for_part(part);

    ft_step_t *buf = malloc(sizeof(ft_step_t)*n);
    memset(buf,0,sizeof(ft_step_t)*n);

    for (int i = 0; i < fills; ++i) {
        int idx = (i * total_steps) / fills;
        if (idx < n) buf[idx].gate = 100;
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
    /* reserved for integrated transformations before write-pattern */
}

#include "pattern_writer.h"

/* Weak fallback:
   Real implementation may live in freetribe_save_bundle.c (strong symbol).
   If real one is linked, this will be ignored automatically. */

__attribute__((weak))
int pattern_write_pattern(int part, const ft_step_t *steps, int count)
{
    (void)part; (void)steps; (void)count;
    return -1;
}

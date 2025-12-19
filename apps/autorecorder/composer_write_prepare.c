#include "composer_write_prepare.h"
#include "pattern_writer.h"
#include <string.h>

#define MAX_WRITE_BLOCKS 250

static composer_write_block_t g_blocks[MAX_WRITE_BLOCKS];
static int g_block_count = 0;

int composer_write_prepare(uint16_t slot_base)
{
    g_block_count = 0;

    uint16_t total_bars = composer_timeline_get_total_bars();
    if (total_bars == 0)
        return 0;

    for (uint16_t bar = 0; bar < total_bars; bar += COMPOSER_PATTERN_BARS)
    {
        if (g_block_count >= MAX_WRITE_BLOCKS)
            break;

        uint16_t block_idx = bar / COMPOSER_PATTERN_BARS;

        composer_write_block_t *b = &g_blocks[g_block_count];
        memset(b, 0, sizeof(*b));

        b->slot      = slot_base + block_idx;
        b->bar_start = bar;

        /* Collect 4 bars → 64 steps */
        for (uint16_t bi = 0; bi < COMPOSER_PATTERN_BARS; bi++)
        {
            uint16_t abs_bar = bar + bi;
            if (abs_bar >= total_bars)
                break;

            for (uint16_t step = 0; step < COMPOSER_STEPS_PER_BAR; step++)
            {
                uint16_t dst =
                    (bi * COMPOSER_STEPS_PER_BAR) + step;

                /* Preview already wrote the pattern into RAM map,
                   so we just read from current page = preview truth */
                pattern_read_page(
                    0, /* part is set later */
                    &b->steps[dst],
                    1,
                    abs_bar
                );

                b->steps[dst].step = (uint8_t)dst;
            }
        }

        g_block_count++;
    }

    return g_block_count;
}

int composer_write_get_block_count(void)
{
    return g_block_count;
}

const composer_write_block_t *composer_write_get_block(int idx)
{
    if (idx < 0 || idx >= g_block_count)
        return NULL;
    return &g_blocks[idx];
}

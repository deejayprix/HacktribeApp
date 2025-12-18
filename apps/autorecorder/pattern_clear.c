#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "randomizer.h"
#include "ft_types.h"
#include <stdint.h>
#include <string.h>

/* ============================================================
   PATTERN CLEAR UTILITY – BULK VERSION
   ============================================================ */

int pattern_clear_part(int part)
{
    int n = pattern_get_paging_page_size();
    if (n <= 0)
        return 0;

    ft_step_t buf[n];

    for (int i = 0; i < n; ++i)
    {
        memset(&buf[i], 0, sizeof(ft_step_t));
        buf[i].part = (uint8_t)part;
        buf[i].step = (uint8_t)i;

        /* Step repeater is engine-state -> reset to default */
        randomizer_set_step_repeat(part, i, STEP_REPEAT_MIN);
    }

    return pattern_write_steps(part, buf, n);
}

int pattern_clear_all_parts(void)
{
    int total = 0;
    for (int part = 0; part < 16; ++part)
        total += pattern_clear_part(part);
    return total;
}

int pattern_clear_page(int pat)
{
    pattern_set_active_page(pat);
    return pattern_clear_all_parts();
}

int pattern_clear_nrpn(int part)
{
    if (part < 0)
        return pattern_clear_all_parts();
    if (part >= 16)
        return 0;
    return pattern_clear_part(part);
}

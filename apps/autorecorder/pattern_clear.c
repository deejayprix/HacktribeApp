#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "ft_types.h"
#include <string.h>

/* ============================================================
   PATTERN CLEAR UTILITY – BULK VERSION
   ------------------------------------------------------------
   - One buffer per part
   - One write per part
   - Deterministic & fast
   ============================================================ */


/* ------------------------------------------------------------
   Clear all steps of a part on the currently active page
   ------------------------------------------------------------ */
int pattern_clear_part(int part)
{
    int n = pattern_get_paging_page_size();
    if (n <= 0)
        return 0;

    ft_step_t buf[n];

    /* Build blank pattern in RAM */
    for (int i = 0; i < n; ++i)
    {
        memset(&buf[i], 0, sizeof(ft_step_t));
        buf[i].part = (uint8_t)part;
        buf[i].step = (uint8_t)i;
    }

    /* Single bulk write */
    return pattern_write_steps(part, buf, n);
}


/* ------------------------------------------------------------
   Clear ALL parts on the current active page
   ------------------------------------------------------------ */
int pattern_clear_all_parts(void)
{
    int total = 0;

    for (int part = 0; part < 16; ++part)
        total += pattern_clear_part(part);

    return total;
}


/* ------------------------------------------------------------
   Clear a whole page (pattern number)
   ------------------------------------------------------------ */
int pattern_clear_page(int pat)
{
    pattern_set_active_page(pat);
    return pattern_clear_all_parts();
}


/* ------------------------------------------------------------
   NRPN-Compatible Clear Command
   (MSB 41 → LSB 50)
   ------------------------------------------------------------
   part:
     <0   → clear ALL parts
     0–15 → clear specific part
   ------------------------------------------------------------ */
int pattern_clear_nrpn(int part)
{
    if (part < 0)
        return pattern_clear_all_parts();

    if (part >= 16)
        return 0;

    return pattern_clear_part(part);
}

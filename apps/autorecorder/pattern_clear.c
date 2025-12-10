#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "ft_types.h"
#include <string.h>

/* ============================================================
   PATTERN CLEAR UTILITY
   ------------------------------------------------------------
   Diese Datei stellt eine saubere Reset-/Clear-Lösung bereit,
   kompatibel mit:
     • pattern_writer
     • RAM-Backend
     • Randomizer
     • Song Mode
     • NRPN (MSB 41, LSB 50)
   ============================================================ */


/* ------------------------------------------------------------
   Clear all steps of a part on the currently active page
   ------------------------------------------------------------ */
int pattern_clear_part(int part)
{
    int n = pattern_get_paging_page_size();
    if (n <= 0) return 0;

    ft_step_t blank;

    for (int i = 0; i < n; i++) {
        memset(&blank, 0, sizeof(ft_step_t));
        blank.part = (uint8_t)part;
        blank.step = (uint8_t)i;

        /* Write blank step */
        pattern_write_step(part, i, 0, 0, 0);
    }

    return n;
}


/* ------------------------------------------------------------
   Clear ALL parts on the current active page
   ------------------------------------------------------------ */
int pattern_clear_all_parts(void)
{
    int n = pattern_get_paging_page_size();
    if (n <= 0) return 0;

    for (int part = 0; part < 16; part++)
        pattern_clear_part(part);

    return n * 16;
}


/* ------------------------------------------------------------
   Clear a whole page (pattern number)
   This sets active page to pat and clears all parts.
   ------------------------------------------------------------ */
int pattern_clear_page(int pat)
{
    pattern_set_active_page(pat);
    return pattern_clear_all_parts();
}


/* ------------------------------------------------------------
   NRPN-Compatible Clear Command
   (from your NRPN spec: MSB 41 → LSB 50)
   ------------------------------------------------------------
   lsb_value:
      -1  → clear ALL parts
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

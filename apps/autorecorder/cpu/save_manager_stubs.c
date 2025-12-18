/*
 * cpu/save_manager_stubs.c
 *
 * PRE-STEP 0 (Build-Stabilisierung):
 * - Provide weak fallback symbols for save_manager_* API
 * - Prevent undefined references when save_manager module is not linked yet
 *
 * IMPORTANT:
 * - Header-independent (no include dependency on save_manager.h paths)
 * - Real save system will override these weak symbols later.
 */

#include <stdint.h>
#include "ft_api.h"

/* Signatures must match the real API that callers expect. */
__attribute__((weak))
int save_manager_request_save(uint8_t mode, const char *name)
{
    (void)mode;
    (void)name;
    ft_print("[WARN] save_manager_request_save: stub active (no-op)\n");
    return 0;
}

__attribute__((weak))
void save_manager_confirm(int accept)
{
    (void)accept;
    ft_print("[WARN] save_manager_confirm: stub active (no-op)\n");
}

__attribute__((weak))
void save_manager_init(void)
{
    /* no-op */
}

__attribute__((weak))
void save_manager_stream_name_byte(uint8_t b)
{
    (void)b;
    /* no-op */
}

__attribute__((weak))
void save_manager_send_status(uint8_t status_code)
{
    (void)status_code;
    /* no-op */
}

__attribute__((weak))
void save_manager_trigger_ui_save(uint8_t mode)
{
    (void)mode;
    /* no-op */
}

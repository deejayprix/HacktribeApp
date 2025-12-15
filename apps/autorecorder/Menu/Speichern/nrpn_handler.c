#include "save_nrpn.h"
#include "save_manager.h"
#include "nrpn_router.h" /* falls nötig */


/* this module receives NRPN LSBs for MSB == NRPN_SAVE_MSB */


static uint8_t g_filename_buf[64];
static int g_filename_pos = 0;


void nrpn_save_init(void) {
g_filename_pos = 0;
}


void nrpn_save_handle(uint8_t lsb, uint16_t value) {
switch (lsb) {
case NRPN_SAVE_MODE_LSB:
/* value selects mode */
if (value <= 2) {
save_manager_set_mode((uint8_t)value);
ui_show_message("NRPN: SAVE_REQUEST geladen");
/* Optionally send a status back */
}
break;


case NRPN_SAVE_EXEC_LSB:
/* Trigger the save process (execute) */
save_request_start(save_manager_get_mode());
break;


case NRPN_SAVE_FILENAME_LSB:
/* value is 7-bit ASCII byte (0-127) */
if (g_filename_pos < (int)sizeof(g_filename_buf)-1) {
g_filename_buf[g_filename_pos++] = (uint8_t)(value & 0x7F);
}
break;


case NRPN_SAVE_FILENAME_END:
/* terminate & pass name */
g_filename_buf[g_filename_pos] = '\0';
save_manager_set_name((const char *)g_filename_buf);
g_filename_pos = 0;
ui_show_message("NRPN: Dateiname empfangen");
break;


case NRPN_SAVE_STATUS_LSB:
/* Query status - handled by save_manager */
{
uint8_t st = save_manager_get_status();
/* report via NRPN back or via log */
nrpn_send(NRPN_SAVE_MSB, NRPN_SAVE_STATUS_LSB, st);
}
break;


default:
break;
}
}


/* helper to send simple NRPN reply (uses existing nrpn routing helper) */
void nrpn_send(uint8_t msb, uint8_t lsb, uint16_t value) {
/* Delegate to whatever NRPN transmitter the project uses */
nrpn_handle_out(msb, lsb, value);
}
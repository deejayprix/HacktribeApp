/* apps/autorecorder/Menu/Speichern/save_nrpn.h */
#ifndef SAVE_NRPN_H
#define SAVE_NRPN_H

#include <stdint.h>

/* Panel MSB for Menü = 0 */
#define SAVE_NRPN_MSB 0

/* LSB codes (see NRPN doc) */
#define SAVE_LSB_REQUEST        64  /* 0x40 */
#define SAVE_LSB_CONFIRM        65  /* 0x41 */
#define SAVE_LSB_STATUS         66  /* 0x42 */
#define SAVE_LSB_NAME_STREAM    67  /* 0x43 */
#define SAVE_LSB_MODE_SET       68  /* 0x44 */
#define SAVE_LSB_ICON_REQ       69  /* 0x45 */

/* Save modes */
#define SAVE_MODE_SYSEX_E2PAT 1
#define SAVE_MODE_E2PAT       2
#define SAVE_MODE_SYSEX       3

/* Exported from save_manager.c */
void save_manager_init(void);

/* mode: 1/2/3 as above. name may be NULL */
int save_manager_request_save(uint8_t mode, const char *name);

/* Confirm or cancel pending save (0 = cancel, 1 = confirm) */
void save_manager_confirm(int accept);

/* stream byte for name streaming (called per NRPN byte) */
void save_manager_stream_name_byte(uint8_t b);

/* send status to host via NRPN or nrpn_handle_out */
void save_manager_send_status(uint8_t status_code);

#endif /* SAVE_NRPN_H */

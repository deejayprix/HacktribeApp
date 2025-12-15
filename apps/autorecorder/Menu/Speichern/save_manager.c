/* notwendige Annahmen / Prototypes (falls nicht in header verfügbar) */
extern int sysex_build_full_bundle(uint8_t *out_buf, int out_len); 
extern int sysex_send(const uint8_t *buf, int len);
extern int e2pat_build_current_pattern(uint8_t *out_buf, int out_len);
extern int e2pat_writer_commit(const uint8_t *buf, int len);
extern void nrpn_handle_out(uint16_t msb, uint16_t lsb, uint16_t value); /* send NRPN out */
extern void ui_show_message(const char *msg); /* UI hook, Deutsch */
extern void ui_show_icon(const uint8_t *bitmap, int w, int h);

/* File: apps/autorecorder/Menu/Speichern/save_manager.c */

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "save_nrpn.h"
#include "sysex_helper.h" // existing in repo
#include "e2pat_writer.h" // existing in repo
#include "pattern_writer.h"
#include "ui.h" // ui_show_message

/* Internal buffer sizes */
#define SAVE_BUF_SIZE 2048
static uint8_t save_buf[SAVE_BUF_SIZE];

/* Pending save state */
static int pending_mode = 0;
static char pending_name[33]; /* max 32 chars + null */
static int name_pos = 0;
static int is_pending = 0;

void save_manager_init(void)
{
    pending_mode = 0;
    pending_name[0] = '\0';
    name_pos = 0;
    is_pending = 0;
}

/* Helper: send NRPN status out */
void save_manager_send_status(uint8_t status_code)
{
    /* report back using NRPN out; host will get it as NRPN MSB=0, LSB=SAVE_LSB_STATUS */
    nrpn_handle_out(SAVE_NRPN_MSB, SAVE_LSB_STATUS, status_code);
}

/* Stream bytes (from NRPN) into name buffer */
void save_manager_stream_name_byte(uint8_t b)
{
    if (name_pos < (int)(sizeof(pending_name)-1)) {
        pending_name[name_pos++] = (char)b;
        pending_name[name_pos] = '\0';
    }
    /* If terminator */
    if (b == 0) {
        /* autoconfirm? we wait for explicit SAVE_CONFIRM */
    }
}

/* Called to request save (from UI or NRPN) */
int save_manager_request_save(uint8_t mode, const char *name)
{
    if (mode < SAVE_MODE_SYSEX_E2PAT || mode > SAVE_MODE_SYSEX) {
        return -1;
    }

    /* set pending mode */
    pending_mode = mode;
    is_pending = 1;
    name_pos = 0;
    pending_name[0] = '\0';
    if (name && name[0]) {
        strncpy(pending_name, name, sizeof(pending_name)-1);
        pending_name[sizeof(pending_name)-1] = '\0';
        name_pos = strlen(pending_name);
    }

    /* UI */
    ui_show_message("NRPN: SAVE_REQUEST geladen"); /* Deutsch */
    ui_show_icon(icon_save_16x16, 16, 16);

    /* notify host */
    save_manager_send_status(1); /* 1 = Saving requested */

    return 0;
}

/* Confirm or cancel pending save */
void save_manager_confirm(int accept)
{
    if (!is_pending) {
        ui_show_message("Kein Save aktiv");
        return;
    }

    if (!accept) {
        /* cancelled */
        ui_show_message("Abgebrochen");
        is_pending = 0;
        pending_mode = 0;
        pending_name[0] = '\0';
        save_manager_send_status(0); /* 0 = idle / cancelled */
        return;
    }

    /* start save workflow */
    ui_show_message("Speichere...");
    save_manager_send_status(2); /* 2 = saving in progress */

    int rv = 0;

    if (pending_mode == SAVE_MODE_E2PAT || pending_mode == SAVE_MODE_SYSEX_E2PAT) {
        /* build e2pat */
        int len = e2pat_build_current_pattern(save_buf, SAVE_BUF_SIZE);
        if (len > 0) {
            rv = e2pat_writer_commit(save_buf, len);
            if (rv != 0) {
                ui_show_message("Fehler beim e2pat Schreiben");
                save_manager_send_status(3); /* 3 = error */
                is_pending = 0;
                return;
            }
        } else {
            /* no pattern data */
        }
    }

    if (pending_mode == SAVE_MODE_SYSEX || pending_mode == SAVE_MODE_SYSEX_E2PAT) {
        /* build and send sysex */
        int len = sysex_build_full_bundle(save_buf, SAVE_BUF_SIZE);
        if (len > 0) {
            int send_ok = sysex_send(save_buf, len);
            if (!send_ok) {
                ui_show_message("Fehler bei Sysex Senden");
                save_manager_send_status(3);
                is_pending = 0;
                return;
            }
        }
    }

    /* success */
    ui_show_message("Gespeichert!");
    ui_show_icon(icon_confirm_16x16, 16, 16);

    /* inform host */
    /* we also send NRPN log: "NRPN: SAVE_CONFIRM gespeichert" as status 2-> confirm  */
    nrpn_handle_out(SAVE_NRPN_MSB, SAVE_LSB_CONFIRM, 1); /* 1 = saved */
    save_manager_send_status(2); /* 2 = saved */

    /* clear pending */
    is_pending = 0;
    pending_mode = 0;
    pending_name[0] = '\0';
}

/* Simple API for UI code to trigger save (e.g., button pressed) */
void save_manager_trigger_ui_save(uint8_t mode)
{
    save_manager_request_save(mode, NULL);
    /* For UI flow, add modal confirm dialog if required */
}

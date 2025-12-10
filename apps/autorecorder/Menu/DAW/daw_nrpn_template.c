#include "daw_nrpn_template.h"
#include "save_nrpn.h"

const daw_nrpn_entry_t g_daw_nrpn_map[] = {

    /* SAVE SYSTEM --------------------------------------- */

    {
        NRPN_MSB_FREETRIBE,
        NRPN_SAVE_SLOT,
        "Speicher-Slot wählen (0–250)",
        "→ In DAW als Integer / Encoder abbilden"
    },
    {
        NRPN_MSB_FREETRIBE,
        NRPN_SAVE_TYPE,
        "Speicherformat wählen (1=Sysex+e2pat, 2=e2pat, 3=Sysex)",
        "→ DAW Dropdown oder 3 Buttons"
    },
    {
        NRPN_MSB_FREETRIBE,
        NRPN_SAVE_REQUEST,
        "Speichervorgang starten",
        "→ DAW Button: 'Speichern'"
    },
    {
        NRPN_MSB_FREETRIBE,
        NRPN_SAVE_CONFIRM,
        "Speichern bestätigen",
        "→ DAW sendet Wert 1"
    },
    {
        NRPN_MSB_FREETRIBE,
        NRPN_SAVE_CANCEL,
        "Speichern abbrechen",
        "→ DAW Button: 'Cancel'"
    },

    /* END ----------------------------------------------- */
    {0,0,NULL,NULL}
};

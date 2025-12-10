#ifndef FT_CONFIG_H
#define FT_CONFIG_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* -------------------
   Panel handler addresses (aus Disassembly/Reports)
   These are used to trigger PLAY/REC/STOP/WRITE safely.
   See PAKET4 reports for origins. :contentReference[oaicite:6]{index=6}
   ------------------- */
#define ADDR_PLAY_HANDLER    ((void*)0x80170658)   /* panel play handler (reported) */
#define ADDR_RECORD_HANDLER  ((void*)0x801706A8)   /* panel record handler (reported) */
#define ADDR_STOP_HANDLER    ((void*)0x801706D8)   /* panel stop handler (reported) */
#define ADDR_WRITE_HANDLER   ((void*)0x80170770)   /* panel write handler (reported) */

/* -------------------
   Pattern / RAM / FW hooks (DEFAULT = 0 => fallback-safe)
   - Set these only after you verify addresses via disassembly / hex-dump.
   ------------------- */

/* Direct firmware pattern-step write function (if identified) */
#define ADDR_FW_PATTERN_WRITE        ((void*)0x0) /* set to fw addr if found */

/* Optional batch / bulk writer (if discovered) */
#define ADDR_FW_PATTERN_WRITE_BATCH  ((void*)0x0) /* set to fw addr if found */

/* Function to set current pattern number (example reported in notes) */
#define ADDR_PATTERN_SET             ((void*)0x80083EB0) /* example from reports — VERIFY before use */ 
/* NOTE: example address above comes from earlier disassembly notes — verify via Ghidra. :contentReference[oaicite:7]{index=7} */

/* Pattern RAM base — MUST be discovered before enabling RAM mapping */
#define ADDR_PATTERN_RAM_BASE        ((void*)0x0) /* fill after VSB analysis */

/* MIDI send hook (firmware TX scheduler) — optional */
#define ADDR_MIDI_SEND               ((void*)0x800406ec) /* scheduler / TX wrapper from reports (example). :contentReference[oaicite:8]{index=8} */

/* BPM hook: firmware function that returns BPM (0 if unknown) */
#define ADDR_GET_BPM_FUNC            ((void*)0x0) /* fill after analysis */

/* Flags - keep default OFF until addresses are verified */
#define FT_USE_DIRECT_FW_WRITES      0
#define FT_USE_FW_BATCH_WRITES       0
#define FT_USE_FW_GET_BPM            0

/* Defaults / limits */
#define FT_DEFAULT_BPM               120
#define FT_DEFAULT_PAGE_SIZE         64
#define FT_DEFAULT_NUM_PAGES         1
#define FT_MAX_PATTERN_STEPS         256

#endif // FT_CONFIG_H

/*
=== FILE: pattern_writer.h ===
*/

#ifndef PATTERN_WRITER_H
#define PATTERN_WRITER_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Forward-declared project type - must match your project's definition
// ft_step_t should be defined in your existing headers (pattern_writer.h expects it)
#ifndef FT_STEP_DEFINED_EXTERN
typedef struct ft_step_s {
    int8_t gate;    // 0/1
    int8_t note;    // 0..127
    int8_t vel;     // 0..127
    int8_t legato;  // optional
    // add other fields if your project's ft_step_t differs
} ft_step_t;
#endif

// Write a pattern into the project's pattern memory (or staging buffer).
// Returns 0 on success, negative on error.
int pattern_write_pattern(int part, const ft_step_t *steps, int count);

// Build and send a Sysex dump for `part`. Returns 0 on success.
int pattern_save_sysex(int part);

// Serialize and save as host .e2pat file. Provide `filename` or NULL to auto-generate.
// Returns 0 on success.
int pattern_save_e2pat(int part, const char *filename);

#ifdef __cplusplus
}
#endif

#endif // PATTERN_WRITER_H


/*
=== FILE: sysex_helper.h ===
*/

#ifndef SYSEX_HELPER_H
#define SYSEX_HELPER_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Manufacturer / Model constants - adapt as needed for Electribe/Freetribe
#define FT_SYSEX_MANUF_1 0x00
#define FT_SYSEX_MANUF_2 0x20
#define FT_SYSEX_MANUF_3 0x6B
#define FT_SYSEX_DEVICE_ID 0x7F  // 0x7F = broadcast / all devices - change to specific id if desired

// Build a sysex pattern dump into out_buf. out_len receives produced length.
// out_buf must be at least (count * 8 + 128) bytes - caller responsibility.
// Returns 0 on success, negative on error.
int sysex_build_pattern(int part, const ft_step_t *steps, int count, uint8_t *out_buf, size_t *out_len);

// Blocking send of a sysex buffer via the platform MIDI transmit function.
// Returns 0 on success.
int sysex_send(const uint8_t *buf, size_t len);

#ifdef __cplusplus
}
#endif

#endif // SYSEX_HELPER_H


/*
=== FILE: e2pat_writer.h ===
*/

#ifndef E2PAT_WRITER_H
#define E2PAT_WRITER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Write a simple .e2pat file for host consumption. The file format produced here is
// intentionally simple and documented in comments; adapt to your host if you have a
// specific e2pat spec. Returns 0 on success.
int e2pat_write_file(const char *filename, int part, const ft_step_t *steps, int count);

#ifdef __cplusplus
}
#endif

#endif // E2PAT_WRITER_H


/*
=== FILE: pattern_writer.c ===
*/

#include "pattern_writer.h"
#include "sysex_helper.h"
#include "e2pat_writer.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Small staging buffer to hold the most recent pattern write (non-persistent)
// Sized conservatively; adjust RANDOMIZER_MAX_STEPS from your project if available.
#ifndef RANDOMIZER_MAX_STEPS
#define RANDOMIZER_MAX_STEPS 256
#endif

static ft_step_t g_staged_pattern[RANDOMIZER_MAX_STEPS];
static int g_staged_count = 0;
static int g_staged_part = -1;

int pattern_write_pattern(int part, const ft_step_t *steps, int count) {
    if (!steps || count <= 0 || count > RANDOMIZER_MAX_STEPS) return -1;
    // copy into staging buffer
    memcpy(g_staged_pattern, steps, sizeof(ft_step_t) * count);
    g_staged_count = count;
    g_staged_part = part;
    // In a real project you'd also call into platform-specific pattern RAM writer
    // e.g. device_pattern_write(part, g_staged_pattern, g_staged_count);
    return 0;
}

int pattern_save_sysex(int part) {
    if (g_staged_part != part) return -2; // nothing staged for this part
    uint8_t buf[2048];
    size_t len = 0;
    int r = sysex_build_pattern(part, g_staged_pattern, g_staged_count, buf, &len);
    if (r) return -3;
    return sysex_send(buf, len);
}

int pattern_save_e2pat(int part, const char *filename) {
    if (g_staged_part != part) return -2;
    // If filename==NULL generate timestamped name
    char tmpname[128];
    const char *fn = filename;
    if (!fn) {
        // Simple auto name. In embedded builds you may instead send to host over MIDI
        snprintf(tmpname, sizeof(tmpname), "freetribe_part%d.e2pat", part);
        fn = tmpname;
    }
    return e2pat_write_file(fn, part, g_staged_pattern, g_staged_count);
}


/*
=== FILE: sysex_helper.c ===
*/

#include "sysex_helper.h"
#include <string.h>
#include <stdio.h>

// Platform must provide this MIDI byte sender. Provide your own implementation
// that writes to TRS MIDI out hardware. Return 0 on success.
// e.g. int midi_send_byte(uint8_t b) { uart_send(b); }
extern int midi_send_byte(uint8_t b);

// Helper: checksum simple 7-bit sum (mod 128) - many devices use different checksums.
static uint8_t ft_sysex_checksum(const uint8_t *data, size_t len) {
    uint32_t s = 0;
    for (size_t i = 0; i < len; ++i) s += data[i] & 0x7F;
    return (uint8_t)(s & 0x7F);
}

int sysex_build_pattern(int part, const ft_step_t *steps, int count, uint8_t *out_buf, size_t *out_len) {
    if (!steps || count <= 0 || !out_buf || !out_len) return -1;

    // Layout (simple, explicit):
    // 0xF0, MANUF(3), DEVICE_ID, TYPE_BYTE(0x01 pattern dump), PART, COUNT, [STEP PACKETS...], CHECKSUM(7bit), 0xF7

    size_t idx = 0;
    out_buf[idx++] = 0xF0;
    out_buf[idx++] = FT_SYSEX_MANUF_1 & 0x7F;
    out_buf[idx++] = FT_SYSEX_MANUF_2 & 0x7F;
    out_buf[idx++] = FT_SYSEX_MANUF_3 & 0x7F;
    out_buf[idx++] = FT_SYSEX_DEVICE_ID & 0x7F;
    out_buf[idx++] = 0x01; // type: pattern dump
    out_buf[idx++] = (uint8_t)(part & 0x7F);
    out_buf[idx++] = (uint8_t)(count & 0x7F);

    // For each step we encode a compact representation: gate(1), note(7), vel(7)
    // Because sysex bytes must be 7-bit, split as necessary.
    for (int i = 0; i < count; ++i) {
        const ft_step_t *s = &steps[i];
        uint8_t gate = (uint8_t)((s->gate) ? 1 : 0) & 0x01;
        uint8_t note = (uint8_t)(s->note & 0x7F);
        uint8_t vel  = (uint8_t)(s->vel & 0x7F);
        out_buf[idx++] = gate;
        out_buf[idx++] = note;
        out_buf[idx++] = vel;
    }

    // checksum covers everything except 0xF0 and checksum byte and 0xF7
    uint8_t cs = ft_sysex_checksum(&out_buf[1], idx - 1);
    out_buf[idx++] = cs & 0x7F;
    out_buf[idx++] = 0xF7;

    *out_len = idx;
    return 0;
}

int sysex_send(const uint8_t *buf, size_t len) {
    if (!buf || len == 0) return -1;
    // simple blocking send
    for (size_t i = 0; i < len; ++i) {
        int r = midi_send_byte(buf[i]);
        if (r != 0) return -2;
    }
    return 0;
}


/*
=== FILE: e2pat_writer.c ===
*/

#include "e2pat_writer.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Basic e2pat writer: simple binary header + raw steps. Host tools can be adapted to
// read this simple format. Format:
//  - 4 bytes magic 'E2PT'
//  - uint8_t part
//  - uint16_t count (big endian)
//  - for each step: gate(1), note(1), vel(1)

int e2pat_write_file(const char *filename, int part, const ft_step_t *steps, int count) {
    if (!steps || count <= 0 || !filename) return -1;
    FILE *f = fopen(filename, "wb");
    if (!f) return -2;

    // header
    fwrite("E2PT", 1, 4, f);
    uint8_t p = (uint8_t)part;
    fwrite(&p, 1, 1, f);
    uint16_t cbe = (uint16_t)count;
    // write count as little-endian for simplicity
    fwrite(&cbe, sizeof(uint16_t), 1, f);

    for (int i = 0; i < count; ++i) {
        uint8_t gate = (uint8_t)((steps[i].gate) ? 1 : 0);
        uint8_t note = (uint8_t)(steps[i].note & 0x7F);
        uint8_t vel  = (uint8_t)(steps[i].vel  & 0x7F);
        fwrite(&gate, 1, 1, f);
        fwrite(&note, 1, 1, f);
        fwrite(&vel, 1, 1, f);
    }

    fclose(f);
    return 0;
}

/*
=== END OF BUNDLE ===
*/

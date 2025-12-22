# Mega Source Export

**Root:** `C:\Users\deeja\Desktop\HacktribeApp`  

**Dateien:** 126  


---

## Index

### SRC
- [`app_common.mk`](#appcommonmk)
- [`apps/autorecorder/composer.c`](#appsautorecordercomposerc)
- [`apps/autorecorder/composer_bridge.c`](#appsautorecordercomposerbridgec)
- [`apps/autorecorder/composer_padmap.c`](#appsautorecordercomposerpadmapc)
- [`apps/autorecorder/composer_policy.c`](#appsautorecordercomposerpolicyc)
- [`apps/autorecorder/composer_preview.c`](#appsautorecordercomposerpreviewc)
- [`apps/autorecorder/composer_preview.h`](#appsautorecordercomposerpreviewh)
- [`apps/autorecorder/composer_timeline.c`](#appsautorecordercomposertimelinec)
- [`apps/autorecorder/composer_timeline.h`](#appsautorecordercomposertimelineh)
- [`apps/autorecorder/composer_utils.c`](#appsautorecordercomposerutilsc)
- [`apps/autorecorder/composer_write_export.c`](#appsautorecordercomposerwriteexportc)
- [`apps/autorecorder/composer_write_export.h`](#appsautorecordercomposerwriteexporth)
- [`apps/autorecorder/composer_write_prepare.c`](#appsautorecordercomposerwritepreparec)
- [`apps/autorecorder/composer_write_prepare.h`](#appsautorecordercomposerwriteprepareh)
- [`apps/autorecorder/condition_engine.c`](#appsautorecorderconditionenginec)
- [`apps/autorecorder/condition_presets.c`](#appsautorecorderconditionpresetsc)
- [`apps/autorecorder/cpu/ft_api.c`](#appsautorecordercpuftapic)
- [`apps/autorecorder/cpu/include/composer.h`](#appsautorecordercpuincludecomposerh)
- [`apps/autorecorder/cpu/include/composer_bridge.h`](#appsautorecordercpuincludecomposerbridgeh)
- [`apps/autorecorder/cpu/include/composer_padmap.h`](#appsautorecordercpuincludecomposerpadmaph)
- [`apps/autorecorder/cpu/include/composer_policy.h`](#appsautorecordercpuincludecomposerpolicyh)
- [`apps/autorecorder/cpu/include/composer_utils.h`](#appsautorecordercpuincludecomposerutilsh)
- [`apps/autorecorder/cpu/include/condition_engine.h`](#appsautorecordercpuincludeconditionengineh)
- [`apps/autorecorder/cpu/include/condition_presets.h`](#appsautorecordercpuincludeconditionpresetsh)
- [`apps/autorecorder/cpu/include/ft_api.h`](#appsautorecordercpuincludeftapih)
- [`apps/autorecorder/cpu/include/ft_types.h`](#appsautorecordercpuincludefttypesh)
- [`apps/autorecorder/cpu/include/pattern_writer.h`](#appsautorecordercpuincludepatternwriterh)
- [`apps/autorecorder/cpu/include/rng.h`](#appsautorecordercpuincluderngh)
- [`apps/autorecorder/cpu/include/syscalls.h`](#appsautorecordercpuincludesyscallsh)
- [`apps/autorecorder/cpu/linker.ld`](#appsautorecordercpulinkerld)
- [`apps/autorecorder/cpu/Makefile`](#appsautorecordercpumakefile)
- [`apps/autorecorder/cpu/save_manager_stubs.c`](#appsautorecordercpusavemanagerstubsc)
- [`apps/autorecorder/e2pat_writer.c`](#appsautorecordere2patwriterc)
- [`apps/autorecorder/e2pat_writer.h`](#appsautorecordere2patwriterh)
- [`apps/autorecorder/euclid_engine_v2.c`](#appsautorecordereuclidenginev2c)
- [`apps/autorecorder/euclid_engine_v2.h`](#appsautorecordereuclidenginev2h)
- [`apps/autorecorder/euclid_nrpn_stubs.c`](#appsautorecordereuclidnrpnstubsc)
- [`apps/autorecorder/freetribe_recorder.c`](#appsautorecorderfreetriberecorderc)
- [`apps/autorecorder/freetribe_save_bundle.c`](#appsautorecorderfreetribesavebundlec)
- [`apps/autorecorder/ft_config.h`](#appsautorecorderftconfigh)
- [`apps/autorecorder/groove_engine.c`](#appsautorecordergrooveenginec)
- [`apps/autorecorder/groove_engine.h`](#appsautorecordergrooveengineh)
- [`apps/autorecorder/humanizer.c`](#appsautorecorderhumanizerc)
- [`apps/autorecorder/humanizer.h`](#appsautorecorderhumanizerh)
- [`apps/autorecorder/live_fx.c`](#appsautorecorderlivefxc)
- [`apps/autorecorder/live_fx.h`](#appsautorecorderlivefxh)
- [`apps/autorecorder/Makefile`](#appsautorecordermakefile)
- [`apps/autorecorder/Menu/Button/button_handler.c`](#appsautorecordermenubuttonbuttonhandlerc)
- [`apps/autorecorder/Menu/Button/button_handler.h`](#appsautorecordermenubuttonbuttonhandlerh)
- [`apps/autorecorder/Menu/DAW/daw_nrpn_template.c`](#appsautorecordermenudawdawnrpntemplatec)
- [`apps/autorecorder/Menu/DAW/daw_nrpn_template.h`](#appsautorecordermenudawdawnrpntemplateh)
- [`apps/autorecorder/Menu/Display/display_manager.c`](#appsautorecordermenudisplaydisplaymanagerc)
- [`apps/autorecorder/Menu/Display/display_manager.h`](#appsautorecordermenudisplaydisplaymanagerh)
- [`apps/autorecorder/Menu/Speichern/icons.h`](#appsautorecordermenuspeicherniconsh)
- [`apps/autorecorder/Menu/Speichern/nrpn_handler.c`](#appsautorecordermenuspeichernnrpnhandlerc)
- [`apps/autorecorder/Menu/Speichern/save_manager.c`](#appsautorecordermenuspeichernsavemanagerc)
- [`apps/autorecorder/Menu/Speichern/save_manager.h`](#appsautorecordermenuspeichernsavemanagerh)
- [`apps/autorecorder/Menu/Speichern/save_nrpn.h`](#appsautorecordermenuspeichernsavenrpnh)
- [`apps/autorecorder/midi_out.c`](#appsautorecordermidioutc)
- [`apps/autorecorder/midi_out.h`](#appsautorecordermidiouth)
- [`apps/autorecorder/mod_matrix.c`](#appsautorecordermodmatrixc)
- [`apps/autorecorder/mod_matrix.h`](#appsautorecordermodmatrixh)
- [`apps/autorecorder/nrpn_router.c`](#appsautorecordernrpnrouterc)
- [`apps/autorecorder/nrpn_router.h`](#appsautorecordernrpnrouterh)
- [`apps/autorecorder/panel_hooks.h`](#appsautorecorderpanelhooksh)
- [`apps/autorecorder/pattern_clear.c`](#appsautorecorderpatternclearc)
- [`apps/autorecorder/pattern_ram_map.c`](#appsautorecorderpatternrammapc)
- [`apps/autorecorder/pattern_ram_map.h`](#appsautorecorderpatternrammaph)
- [`apps/autorecorder/pattern_stubs.c`](#appsautorecorderpatternstubsc)
- [`apps/autorecorder/pattern_transform.c`](#appsautorecorderpatterntransformc)
- [`apps/autorecorder/pattern_transform.h`](#appsautorecorderpatterntransformh)
- [`apps/autorecorder/pattern_write_dummy.c`](#appsautorecorderpatternwritedummyc)
- [`apps/autorecorder/pattern_writer.c`](#appsautorecorderpatternwriterc)
- [`apps/autorecorder/randomizer.c`](#appsautorecorderrandomizerc)
- [`apps/autorecorder/randomizer.h`](#appsautorecorderrandomizerh)
- [`apps/autorecorder/randomizer_euclid.c`](#appsautorecorderrandomizereuclidc)
- [`apps/autorecorder/randomizer_euclid.h`](#appsautorecorderrandomizereuclidh)
- [`apps/autorecorder/rng.c`](#appsautorecorderrngc)
- [`apps/autorecorder/scale_engine.c`](#appsautorecorderscaleenginec)
- [`apps/autorecorder/scale_engine.h`](#appsautorecorderscaleengineh)
- [`apps/autorecorder/scale_engine_nrpn.c`](#appsautorecorderscaleenginenrpnc)
- [`apps/autorecorder/scale_engine_nrpn.h`](#appsautorecorderscaleenginenrpnh)
- [`apps/autorecorder/song_mode.c`](#appsautorecordersongmodec)
- [`apps/autorecorder/song_mode.h`](#appsautorecordersongmodeh)
- [`apps/autorecorder/sync.c`](#appsautorecordersyncc)
- [`apps/autorecorder/sync_live.c`](#appsautorecordersynclivec)
- [`apps/autorecorder/sync_live.h`](#appsautorecordersyncliveh)
- [`apps/autorecorder/syscalls.c`](#appsautorecordersyscallsc)
- [`apps/autorecorder/sysex_helper.c`](#appsautorecordersysexhelperc)
- [`apps/autorecorder/sysex_helper.h`](#appsautorecordersysexhelperh)
- [`apps/autorecorder/ui/ui_display.c`](#appsautorecorderuiuidisplayc)
- [`apps/autorecorder/ui/ui_display.h`](#appsautorecorderuiuidisplayh)
- [`apps/autorecorder/ui_messages.c`](#appsautorecorderuimessagesc)
- [`apps/autorecorder/ui_messages.h`](#appsautorecorderuimessagesh)
- [`apps/Makefile`](#appsmakefile)
- [`export_mega_source.py`](#exportmegasourcepy)
- [`Makefile`](#makefile)
- [`scripts/e2-backup-bootloader.py`](#scriptse2-backup-bootloaderpy)
- [`scripts/e2-firmware-patch.py`](#scriptse2-firmware-patchpy)
- [`scripts/e2-header.py`](#scriptse2-headerpy)
- [`scripts/e2-init-pat.py`](#scriptse2-init-patpy)
- [`scripts/e2_add_header.py`](#scriptse2addheaderpy)
- [`scripts/e2_groove_template.py`](#scriptse2groovetemplatepy)
- [`scripts/e2_merge_patterns.py`](#scriptse2mergepatternspy)
- [`scripts/e2_recode_sample_pat.py`](#scriptse2recodesamplepatpy)
- [`scripts/e2_sample_all_to_wav.py`](#scriptse2samplealltowavpy)
- [`scripts/e2_syx_codec.py`](#scriptse2syxcodecpy)
- [`scripts/e2_update_pat_samples.py`](#scriptse2updatepatsamplespy)
- [`scripts/e2all2pat.py`](#scriptse2all2patpy)
- [`scripts/e2ev.py`](#scriptse2evpy)
- [`scripts/e2pat2all.py`](#scriptse2pat2allpy)
- [`scripts/e2pat2syx.py`](#scriptse2pat2syxpy)
- [`scripts/e2pat_convert.py`](#scriptse2patconvertpy)
- [`scripts/e2pat_shift.py`](#scriptse2patshiftpy)
- [`scripts/e2s_sample_lister.py`](#scriptse2ssamplelisterpy)
- [`scripts/e2seqrot.py`](#scriptse2seqrotpy)
- [`scripts/e2sysex.py`](#scriptse2sysexpy)
- [`scripts/e2syx2pat.py`](#scriptse2syx2patpy)
- [`scripts/execute_freetribe.py`](#scriptsexecutefreetribepy)
- [`scripts/hacktribe-tutorial.sh`](#scriptshacktribe-tutorialsh)
- [`scripts/ht_splash_screen.py`](#scriptshtsplashscreenpy)

### DOCS
- [`apps/autorecorder/composer_policy.md`](#appsautorecordercomposerpolicymd)
- [`apps/autorecorder/Menu/Speichern/NRPN_SAVE_MAPPING.md`](#appsautorecordermenuspeichernnrpnsavemappingmd)
- [`LICENSE.txt`](#licensetxt)
- [`README.md`](#readmemd)
- [`scripts/README.md`](#scriptsreadmemd)


---

## SRC

### app_common.mk
<a name="appcommonmk"></a>

- **Name:** `app_common.mk`
- **Pfad:** `app_common.mk`
- **SHA256:** `41cd9dcde12fc811ae8c965967d21e201ab1961a26f97fe2d0a7e7e3ca44ff00`

```
# ============================================================================
#   app_common.mk - Build-System für Freetribe CPU-Apps (ARM Bare Metal)
# ============================================================================

DEBUG ?= 1

ifeq ($(DEBUG),1)
CFLAGS += -g -O0 -DDEBUG
else
CFLAGS += -Os
endif

APP_DIR := $(CURDIR)
BUILD_DIR := $(APP_DIR)/build

# Toolchain
CC      := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy

# Flags
CFLAGS  := -Os -Wall -Wno-unused-function -Wno-unused-variable -std=c11

# ✔ Keine -nostdlib mehr!
# ✔ libc + libm + libgcc explizit linken
LDFLAGS := -nostartfiles -Wl,--gc-sections -lc -lm -lgcc

# SOURCES
C_SRCS_APP := $(notdir $(wildcard $(APP_DIR)/*.c))
C_SRCS_CPU := $(notdir $(wildcard $(APP_DIR)/cpu/*.c))
ASM_SRCS   := $(notdir $(wildcard $(APP_DIR)/cpu/*.s))

SRCS := $(C_SRCS_APP) $(C_SRCS_CPU) $(ASM_SRCS)

# OBJECTS
OBJS := $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
OBJS := $(OBJS:.s=.o)

# Linker Script
LDSCRIPT := $(APP_DIR)/cpu/linker.ld

# Targets
TARGET_ELF := $(BUILD_DIR)/$(APP_NAME).elf
TARGET_BIN := $(BUILD_DIR)/$(APP_NAME).bin

# ============================================================================

all: $(TARGET_BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# C compiler (App files)
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(APP_DIR) -I$(APP_DIR)/cpu/include -c $< -o $@

# C compiler (CPU files)
$(BUILD_DIR)/%.o: cpu/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(APP_DIR) -I$(APP_DIR)/cpu/include -c $< -o $@

# ASM compiler
$(BUILD_DIR)/%.o: cpu/%.s | $(BUILD_DIR)
	$(CC) -c $< -o $@

# Linker
$(TARGET_ELF): $(OBJS)
	$(CC) -T$(LDSCRIPT) -o $@ $(OBJS) $(LDFLAGS)

# Binary export
$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) -O binary $< $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

```

### apps/autorecorder/composer.c
<a name="appsautorecordercomposerc"></a>

- **Name:** `composer.c`
- **Pfad:** `apps/autorecorder/composer.c`
- **SHA256:** `8118e30d468fbe0702418328529a915a2dd57dfc09f092ea150d20b5d32aeede`

```
#include "composer.h"
#include "composer_policy.h"

#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "live_fx.h"
#include "randomizer.h"
#include "composer_utils.h"
#include "composer_bridge.h"

#include <string.h>

/* ------------------------------------------------------------
   Global Composer State (Policy-Level Only)
   ------------------------------------------------------------ */

static uint8_t g_genre = GENRE_ACID_TECHNO;
static composer_fill_t g_fill = FILL_NONE;

/* ------------------------------------------------------------
   Init / State Access
   ------------------------------------------------------------ */

void composer_init(void)
{
    g_genre = GENRE_ACID_TECHNO;
    g_fill  = FILL_NONE;
}

void composer_set_genre(uint8_t genre_id)
{
    if (genre_id >= GENRE_COUNT)
        genre_id = GENRE_ACID_TECHNO;

    g_genre = genre_id;
}

uint8_t composer_get_genre(void)
{
    return g_genre;
}

composer_fill_t composer_get_current_fill(void)
{
    return g_fill;
}

void composer_set_current_fill(composer_fill_t f)
{
    g_fill = f;
}

/* ------------------------------------------------------------
   Option 4: Preset Recall (Policy only, non-destructive)
   ------------------------------------------------------------ */

void composer_preset_recall(uint8_t genre_id,
                            composer_section_t section,
                            uint8_t segment)
{
    composer_set_genre(genre_id);
    composer_apply_policy(genre_id, section, segment);
}

/* ------------------------------------------------------------
   Option 3: Song Mode Hook
   ------------------------------------------------------------ */

void composer_songmode_on_section(uint8_t section, uint8_t segment)
{
    composer_apply_policy(composer_get_genre(),
                          (composer_section_t)section,
                          (uint8_t)segment);

    switch (composer_get_current_fill())
    {
        case FILL_GROOVE:
            live_fx_set_variation_boost(20);
            break;

        case FILL_BUILD:
            live_fx_set_variation_boost(40);
            live_fx_trigger_fill_now();
            break;

        case FILL_PUNCTUATION:
            live_fx_set_variation_boost(30);
            live_fx_trigger_fill_now();
            break;

        default:
            live_fx_set_variation_boost(0);
            break;
    }
}

/* ------------------------------------------------------------
   Pattern Generation
   ------------------------------------------------------------ */

#define BARS_PER_PATTERN 4
#define STEPS_PER_BAR    16
#define SEG_STEPS        (BARS_PER_PATTERN * STEPS_PER_BAR)

static void write_empty_pattern(uint8_t part, uint8_t page)
{
    ft_step_t steps[SEG_STEPS];
    memset(steps, 0, sizeof(steps));

    for (int i = 0; i < SEG_STEPS; i++)
    {
        steps[i].part = part;
        steps[i].step = i;
    }

    pattern_write_page(part, steps, SEG_STEPS, page);
}

/* ------------------------------------------------------------
   Generate ONE segment (A/B/C/D)
   ------------------------------------------------------------ */

void composer_generate_segment(uint8_t genre_id,
                               composer_section_t section,
                               uint8_t segment,
                               uint8_t target_page)
{
    for (uint8_t part = 0; part < 16; part++)
        write_empty_pattern(part, target_page);

    composer_preset_recall(genre_id, section, segment);

    /* ✅ FIX: neue Signatur */
    composer_fill_missing_parts(
        target_page,
        section,
        segment
    );
}

/* ------------------------------------------------------------
   Generate ONE section
   ------------------------------------------------------------ */

void composer_generate_section(uint8_t genre_id,
                               composer_section_t section,
                               uint8_t start_page)
{
    uint8_t segments =
        (section == SECTION_BREAK || section == SECTION_PEAK) ? 2 : 4;

    for (uint8_t s = 0; s < segments; s++)
        composer_generate_segment(genre_id,
                                  section,
                                  s,
                                  start_page + s);
}

/* ------------------------------------------------------------
   Generate FULL song
   ------------------------------------------------------------ */

void composer_generate_song(uint8_t genre_id,
                            uint8_t start_page)
{
    uint8_t page = start_page;

    composer_generate_section(genre_id, SECTION_INTRO, page);
    page += 4;

    composer_generate_section(genre_id, SECTION_MAIN, page);
    page += 4;

    composer_generate_section(genre_id, SECTION_BREAK, page);
    page += 2;

    composer_generate_section(genre_id, SECTION_PEAK, page);
    page += 2;

    composer_generate_section(genre_id, SECTION_OUTRO, page);
}

```

### apps/autorecorder/composer_bridge.c
<a name="appsautorecordercomposerbridgec"></a>

- **Name:** `composer_bridge.c`
- **Pfad:** `apps/autorecorder/composer_bridge.c`
- **SHA256:** `78241639c2d4272f3a242fa5991b6b4e48f03b0a8308440de57c50d814a574bb`

```
#include "composer_bridge.h"
#include "composer_utils.h"
#include "randomizer.h"

/* ------------------------------------------------------------
   DEFAULT LOCK BEHAVIOR
   If you have a real lock system, replace this implementation.
   ------------------------------------------------------------ */
int composer_part_is_locked(uint8_t part, composer_section_t section)
{
    (void)part;
    (void)section;
    return 0; /* default: nothing locked */
}

/* ------------------------------------------------------------
   Composer triggers generation decisions.
   Randomizer generates (only if empty).
   ------------------------------------------------------------ */
void composer_fill_missing_parts(uint8_t target_page,
                                 composer_section_t section,
                                 uint8_t segment)
{
    (void)target_page; /* keep for later: page-aware in_use checks */

    composer_partmask_t want = composer_decide_partmask(section, segment);

    for (uint8_t part = 0; part < 16; ++part)
    {
        if (!composer_mask_has_part(want, part))
            continue;

        if (composer_part_is_locked(part, section))
            continue;

        /* IMPORTANT: Randomizer decides emptiness */
        if (randomizer_part_in_use(part))
            continue;

        /* Trigger generation for this part.
           Keep it minimal: generate one pattern page for this part.
           steps_count: usually 64 on electribe-style patterns.
        */
        (void)randomize_and_write_pattern_paged(part, 64, (int)section, (int)target_page);

        /* After writing, randomizer_part_in_use() should become true
           (either via your in-use scan OR via a usage-bit update). */
    }
}

```

### apps/autorecorder/composer_padmap.c
<a name="appsautorecordercomposerpadmapc"></a>

- **Name:** `composer_padmap.c`
- **Pfad:** `apps/autorecorder/composer_padmap.c`
- **SHA256:** `efa373f447e7b717e1ac731f9112685edb3b5a632171e758ca14eac5d2a44439`

```
#include "composer_padmap.h"

uint8_t composer_drum_note(uint8_t idx)
{
    static const uint8_t map[8] = {
        DRUM_KICK,
        DRUM_SNARE,
        DRUM_CLAP,
        DRUM_CH,
        DRUM_OH,
        DRUM_PERC,
        DRUM_RIDE,
        DRUM_FX
    };
    return map[idx & 7u];
}

```

### apps/autorecorder/composer_policy.c
<a name="appsautorecordercomposerpolicyc"></a>

- **Name:** `composer_policy.c`
- **Pfad:** `apps/autorecorder/composer_policy.c`
- **SHA256:** `9f2a45031cbb560dac88054d648c566db89221d510a7df5b348f4fa7aa988641`

```
#include "composer_policy.h"

#include "randomizer.h"
#include "composer.h"

/* Helper: clamp */
static int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* =============================================================
   POLICY TABLES: [SECTION][SEGMENT]
   Segment: A,B,C,D => 0..3
   Break/Peak use only A,B (0..1)
   ============================================================= */

/* ---------------- ACID TECHNO ---------------- */
static const composer_policy_segment_t g_acid[][4] = {

    /* ================= INTRO ================= */
    {
        {20,10,3,0,FILL_NONE,         CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER | CP_FLAG_STRAIGHT},
        {30,15,4,0,FILL_GROOVE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER | CP_FLAG_STRAIGHT},
        {40,18,5,1,FILL_GROOVE,       CP_FLAG_BUILDING | CP_FLAG_LOW_REGISTER | CP_FLAG_STRAIGHT},
        {50,22,6,1,FILL_BUILD,        CP_FLAG_BUILDING | CP_FLAG_STRAIGHT}
    },

    /* ================= MAIN ================= */
    {
        {55,25,7,0,FILL_GROOVE,       CP_FLAG_DENSE | CP_FLAG_STRAIGHT},
        {65,30,8,0,FILL_GROOVE,       CP_FLAG_DENSE | CP_FLAG_SYNCOPATED},
        {75,35,9,1,FILL_BUILD,        CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED},
        {80,40,10,2,FILL_PUNCTUATION, CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_SYNCOPATED}
    },

    /* ================= BREAK ================= */
    {
        {35,20,4,-1,FILL_PUNCTUATION, CP_FLAG_SPARSE | CP_FLAG_RELEASE | CP_FLAG_LOW_REGISTER},
        {45,25,5,0,FILL_BUILD,        CP_FLAG_BUILDING | CP_FLAG_LOW_REGISTER},
        {0,0,0,0,FILL_NONE,           CP_FLAG_NONE},
        {0,0,0,0,FILL_NONE,           CP_FLAG_NONE}
    },

    /* ================= PEAK ================= */
    {
        {85,45,11,1,FILL_BUILD,       CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_STRAIGHT},
        {90,50,12,2,FILL_PUNCTUATION, CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED},
        {0,0,0,0,FILL_NONE,           CP_FLAG_NONE},
        {0,0,0,0,FILL_NONE,           CP_FLAG_NONE}
    },

    /* ================= OUTRO ================= */
    {
        {60,30,6,0,FILL_GROOVE,       CP_FLAG_RELEASE | CP_FLAG_LOW_REGISTER},
        {45,22,5,0,FILL_NONE,         CP_FLAG_RELEASE | CP_FLAG_LOW_REGISTER},
        {30,15,4,-1,FILL_NONE,        CP_FLAG_SPARSE | CP_FLAG_RELEASE},
        {15,8,3,-1,FILL_NONE,         CP_FLAG_SPARSE | CP_FLAG_RELEASE}
    }
};



/* ---------------- RAVE ---------------- */
static const composer_policy_segment_t g_rave[][4] = {
    /* INTRO */
    {
      {25,12,4,0,FILL_NONE,        CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER | CP_FLAG_STRAIGHT},
      {35,18,5,0,FILL_GROOVE,      CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER | CP_FLAG_STRAIGHT},
      {45,24,6,1,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_STRAIGHT},
      {55,28,7,1,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED}
    },
    /* MAIN */
    {
      {65,32,8,0,FILL_GROOVE,      CP_FLAG_DENSE | CP_FLAG_STRAIGHT | CP_FLAG_PERCUSSIVE},
      {75,38,9,1,FILL_BUILD,       CP_FLAG_DENSE | CP_FLAG_SYNCOPATED | CP_FLAG_PERCUSSIVE},
      {85,44,11,2,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED},
      {90,50,12,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE}
    },
    /* BREAK */
    {
      {30,18,3,-1,FILL_PUNCTUATION,CP_FLAG_SPARSE | CP_FLAG_RELEASE | CP_FLAG_SUSTAINED},
      {40,22,4,0,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SUSTAINED},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* PEAK */
    {
      {92,55,13,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {95,60,14,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* OUTRO */
    {
      {60,28,6,0,FILL_GROOVE,      CP_FLAG_RELEASE | CP_FLAG_STRAIGHT},
      {45,20,5,0,FILL_NONE,        CP_FLAG_RELEASE | CP_FLAG_SPARSE},
      {35,14,4,-1,FILL_NONE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER},
      {20,10,3,-1,FILL_NONE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER}
    }
};

/* ---------------- GABBER ---------------- */
static const composer_policy_segment_t g_gabber[][4] = {
    /* INTRO */
    {
      {30,18,6,0,FILL_NONE,        CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER | CP_FLAG_STRAIGHT | CP_FLAG_PERCUSSIVE},
      {45,25,8,0,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_STRAIGHT | CP_FLAG_PERCUSSIVE},
      {60,30,10,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {75,35,12,1,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_PERCUSSIVE}
    },
    /* MAIN */
    {
      {85,40,14,0,FILL_GROOVE,     CP_FLAG_DENSE | CP_FLAG_STRAIGHT | CP_FLAG_PERCUSSIVE},
      {92,50,15,0,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {96,60,16,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {98,70,16,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_PERCUSSIVE | CP_FLAG_HIGH_REGISTER}
    },
    /* BREAK */
    {
      {40,22,6,-1,FILL_PUNCTUATION,CP_FLAG_SPARSE | CP_FLAG_RELEASE | CP_FLAG_SUSTAINED},
      {55,28,8,0,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* PEAK */
    {
      {98,75,16,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {100,80,16,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_PERCUSSIVE | CP_FLAG_HIGH_REGISTER},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* OUTRO */
    {
      {70,30,12,0,FILL_GROOVE,     CP_FLAG_RELEASE | CP_FLAG_PERCUSSIVE},
      {55,22,10,0,FILL_NONE,       CP_FLAG_RELEASE | CP_FLAG_SPARSE},
      {40,18,8,-1,FILL_NONE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER},
      {25,12,6,-1,FILL_NONE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER}
    }
};

/* ---------------- FRENCHCORE ---------------- */
static const composer_policy_segment_t g_frenchcore[][4] = {
    /* INTRO */
    {
      {25,15,5,0,FILL_NONE,        CP_FLAG_SPARSE | CP_FLAG_STRAIGHT | CP_FLAG_LOW_REGISTER},
      {40,22,7,0,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED},
      {55,30,9,1,FILL_BUILD,       CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED},
      {70,38,11,1,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_PERCUSSIVE | CP_FLAG_SYNCOPATED}
    },
    /* MAIN */
    {
      {80,45,12,0,FILL_GROOVE,     CP_FLAG_DENSE | CP_FLAG_SYNCOPATED | CP_FLAG_PERCUSSIVE},
      {88,55,13,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED},
      {94,65,15,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {98,75,16,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE}
    },
    /* BREAK */
    {
      {35,18,4,-1,FILL_PUNCTUATION,CP_FLAG_SPARSE | CP_FLAG_RELEASE | CP_FLAG_SUSTAINED},
      {50,25,6,0,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SUSTAINED},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* PEAK */
    {
      {96,72,16,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE},
      {100,80,16,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* OUTRO */
    {
      {65,30,10,0,FILL_GROOVE,     CP_FLAG_RELEASE | CP_FLAG_SYNCOPATED},
      {50,22,8,0,FILL_NONE,        CP_FLAG_RELEASE | CP_FLAG_SPARSE},
      {35,15,6,-1,FILL_NONE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER},
      {20,10,4,-1,FILL_NONE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER}
    }
};

/* ---------------- HAPPY HARDCORE ---------------- */
static const composer_policy_segment_t g_hhc[][4] = {
    /* INTRO */
    {
      {20,12,4,0,FILL_NONE,        CP_FLAG_SPARSE | CP_FLAG_STRAIGHT | CP_FLAG_HIGH_REGISTER},
      {35,18,6,0,FILL_GROOVE,      CP_FLAG_SPARSE | CP_FLAG_STRAIGHT | CP_FLAG_HIGH_REGISTER},
      {50,25,8,1,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_STRAIGHT | CP_FLAG_HIGH_REGISTER},
      {60,30,9,1,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED | CP_FLAG_HIGH_REGISTER}
    },
    /* MAIN */
    {
      {70,35,10,0,FILL_GROOVE,     CP_FLAG_DENSE | CP_FLAG_STRAIGHT | CP_FLAG_HIGH_REGISTER},
      {80,40,11,0,FILL_GROOVE,     CP_FLAG_DENSE | CP_FLAG_SYNCOPATED | CP_FLAG_HIGH_REGISTER},
      {88,45,12,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_HIGH_REGISTER},
      {92,55,13,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_PERCUSSIVE | CP_FLAG_HIGH_REGISTER}
    },
    /* BREAK */
    {
      {30,16,3,-1,FILL_PUNCTUATION,CP_FLAG_SPARSE | CP_FLAG_RELEASE | CP_FLAG_SUSTAINED | CP_FLAG_HIGH_REGISTER},
      {40,20,4,0,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SUSTAINED | CP_FLAG_HIGH_REGISTER},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* PEAK */
    {
      {94,60,14,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE},
      {98,70,15,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* OUTRO */
    {
      {55,25,7,0,FILL_GROOVE,      CP_FLAG_RELEASE | CP_FLAG_HIGH_REGISTER},
      {40,18,5,0,FILL_NONE,        CP_FLAG_RELEASE | CP_FLAG_SPARSE},
      {30,12,4,-1,FILL_NONE,       CP_FLAG_SPARSE},
      {18,10,3,-1,FILL_NONE,       CP_FLAG_SPARSE}
    }
};

/* ---------------- TECH TRANCE ---------------- */
static const composer_policy_segment_t g_techtrance[][4] = {
    /* INTRO */
    {
      {18,10,3,0,FILL_NONE,        CP_FLAG_SPARSE | CP_FLAG_STRAIGHT | CP_FLAG_SUSTAINED},
      {28,14,4,0,FILL_GROOVE,      CP_FLAG_SPARSE | CP_FLAG_STRAIGHT | CP_FLAG_SUSTAINED},
      {40,18,5,1,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED | CP_FLAG_SUSTAINED},
      {52,22,6,1,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED}
    },
    /* MAIN */
    {
      {62,28,7,0,FILL_GROOVE,      CP_FLAG_DENSE | CP_FLAG_STRAIGHT | CP_FLAG_SUSTAINED},
      {72,34,8,1,FILL_GROOVE,      CP_FLAG_DENSE | CP_FLAG_SYNCOPATED | CP_FLAG_SUSTAINED},
      {82,40,10,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED},
      {88,48,11,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE}
    },
    /* BREAK */
    {
      {26,14,3,-1,FILL_PUNCTUATION,CP_FLAG_SPARSE | CP_FLAG_RELEASE | CP_FLAG_SUSTAINED},
      {38,18,4,0,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SUSTAINED},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* PEAK */
    {
      {90,55,12,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_HIGH_REGISTER},
      {95,60,13,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* OUTRO */
    {
      {55,22,6,0,FILL_GROOVE,      CP_FLAG_RELEASE | CP_FLAG_SUSTAINED},
      {40,16,5,0,FILL_NONE,        CP_FLAG_RELEASE | CP_FLAG_SPARSE | CP_FLAG_SUSTAINED},
      {28,12,4,-1,FILL_NONE,       CP_FLAG_SPARSE},
      {16, 8,3,-1,FILL_NONE,       CP_FLAG_SPARSE}
    }
};

/* ---------------- TEKKNO ---------------- */
static const composer_policy_segment_t g_tekkno[][4] = {
    /* INTRO */
    {
      {22,12,4,0,FILL_NONE,        CP_FLAG_SPARSE | CP_FLAG_STRAIGHT | CP_FLAG_PERCUSSIVE},
      {34,18,5,0,FILL_GROOVE,      CP_FLAG_SPARSE | CP_FLAG_SYNCOPATED | CP_FLAG_PERCUSSIVE},
      {48,24,7,1,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED | CP_FLAG_PERCUSSIVE},
      {60,30,8,1,FILL_PUNCTUATION, CP_FLAG_DENSE | CP_FLAG_PERCUSSIVE | CP_FLAG_BUILDING}
    },
    /* MAIN */
    {
      {70,34,9,0,FILL_GROOVE,      CP_FLAG_DENSE | CP_FLAG_SYNCOPATED | CP_FLAG_PERCUSSIVE},
      {80,40,10,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {90,50,12,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_SYNCOPATED},
      {95,60,13,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_HIGH_REGISTER | CP_FLAG_PERCUSSIVE}
    },
    /* BREAK */
    {
      {32,18,4,-1,FILL_PUNCTUATION,CP_FLAG_SPARSE | CP_FLAG_RELEASE | CP_FLAG_SUSTAINED},
      {45,25,6,0,FILL_BUILD,       CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* PEAK */
    {
      {96,65,14,1,FILL_BUILD,      CP_FLAG_DENSE | CP_FLAG_BUILDING | CP_FLAG_PERCUSSIVE | CP_FLAG_HIGH_REGISTER},
      {100,75,16,2,FILL_PUNCTUATION,CP_FLAG_DENSE | CP_FLAG_PERCUSSIVE | CP_FLAG_HIGH_REGISTER},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE},
      {0,0,0,0,FILL_NONE,          CP_FLAG_NONE}
    },
    /* OUTRO */
    {
      {62,28,8,0,FILL_GROOVE,      CP_FLAG_RELEASE | CP_FLAG_PERCUSSIVE},
      {48,22,6,0,FILL_NONE,        CP_FLAG_RELEASE | CP_FLAG_SPARSE},
      {34,15,5,-1,FILL_NONE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER},
      {20,10,4,-1,FILL_NONE,       CP_FLAG_SPARSE | CP_FLAG_LOW_REGISTER}
    }
};




static const composer_policy_segment_t* get_policy(uint8_t genre_id,
                                                  composer_section_t section,
                                                  uint8_t segment)
{
    if (segment > 3) segment = 3;

    switch (genre_id)
    {
        case GENRE_ACID_TECHNO:     return &g_acid[section][segment];
        case GENRE_RAVE:           return &g_rave[section][segment];
        case GENRE_GABBER:         return &g_gabber[section][segment];
        case GENRE_FRENCHCORE:     return &g_frenchcore[section][segment];
        case GENRE_HAPPY_HARDCORE: return &g_hhc[section][segment];
        case GENRE_TECH_TRANCE:    return &g_techtrance[section][segment];
        case GENRE_TEKKNO:         return &g_tekkno[section][segment];
        default:                   return 0;
    }
}

void composer_apply_policy(uint8_t genre_id,
                           composer_section_t section,
                           uint8_t segment)
{
    const composer_policy_segment_t *p =
        get_policy(genre_id, section, segment);
    if (!p) return;

    /* Publish fill-state */
    composer_set_current_fill(p->fill);

    /* Randomizer base policy */
    randomizer_set_section((int)section);
    randomizer_set_density(clampi(p->density, 0, 100));
    randomizer_set_variation(clampi(p->variation, 0, 127));

    /* <<< PHASE 3.5.1.1 >>> */
    randomizer_set_policy_flags(p->flags);
}


```

### apps/autorecorder/composer_preview.c
<a name="appsautorecordercomposerpreviewc"></a>

- **Name:** `composer_preview.c`
- **Pfad:** `apps/autorecorder/composer_preview.c`
- **SHA256:** `a6538c2d133b2cbf3db2d2e39cff14e5720c84dde57e7421358a565b0417ab9b`

```
#include "composer_preview.h"
#include "composer_timeline.h"
#include "composer.h"
#include "randomizer.h"

static uint8_t  g_preview_active = 0;
static uint16_t g_preview_bar    = 0;
static uint16_t g_last_bar       = 0xFFFF;

/* ------------------------------------------------------------ */

void composer_preview_enable(uint8_t enable)
{
    g_preview_active = enable ? 1 : 0;

    if (!g_preview_active)
        g_last_bar = 0xFFFF;
}

uint8_t composer_preview_is_active(void)
{
    return g_preview_active;
}

void composer_preview_reset(void)
{
    g_preview_bar = 0;
    g_last_bar    = 0xFFFF;
}

void composer_preview_set_bar(uint16_t bar)
{
    g_preview_bar = bar;
    g_last_bar    = 0xFFFF;
}

uint16_t composer_preview_get_bar(void)
{
    return g_preview_bar;
}

/* ------------------------------------------------------------
   MAIN PREVIEW TICK
   ------------------------------------------------------------ */

void composer_preview_tick(void)
{
    if (!g_preview_active)
        return;

    /* Nur bei Bar-Wechsel reagieren */
    if (g_preview_bar != g_last_bar)
    {
        composer_section_t section =
            composer_timeline_get_section_at_bar(g_preview_bar);

        uint8_t segment =
            composer_timeline_get_segment_at_bar(g_preview_bar);

        /* Policy anwenden (NON-DESTRUCTIVE) */
        composer_preset_recall(
            composer_get_genre(),
            section,
            segment
        );

        g_last_bar = g_preview_bar;
    }

    /* Weiterlaufen */
    g_preview_bar++;

    if (g_preview_bar >= composer_timeline_get_total_bars())
        g_preview_bar = 0;
}

```

### apps/autorecorder/composer_preview.h
<a name="appsautorecordercomposerpreviewh"></a>

- **Name:** `composer_preview.h`
- **Pfad:** `apps/autorecorder/composer_preview.h`
- **SHA256:** `9cd71d17aa13e341efe4f9d4eb7646301b1240ad96dfdace8b50f26cb8779218`

```
#ifndef COMPOSER_PREVIEW_H
#define COMPOSER_PREVIEW_H

#include <stdint.h>

/* ------------------------------------------------------------
   Composer Preview (virtuelles Probe-Playback)
   ------------------------------------------------------------ */

/* Enable / Disable preview mode */
void composer_preview_enable(uint8_t enable);

/* Reset preview playhead */
void composer_preview_reset(void);

/* Manuell auf einen Bar springen */
void composer_preview_set_bar(uint16_t bar);

/* Tick – wird von Sync / Live Clock aufgerufen */
void composer_preview_tick(void);

/* Query */
uint8_t  composer_preview_is_active(void);
uint16_t composer_preview_get_bar(void);

#endif /* COMPOSER_PREVIEW_H */

```

### apps/autorecorder/composer_timeline.c
<a name="appsautorecordercomposertimelinec"></a>

- **Name:** `composer_timeline.c`
- **Pfad:** `apps/autorecorder/composer_timeline.c`
- **SHA256:** `d3fa6b56d345f11098ac4fb36b1654e7bc134953f5f2cb18368357c93167ea85`

```
#include "composer_timeline.h"
#include <string.h>

/* ============================================================
   GLOBAL TIMELINE
   ============================================================ */

static composer_timeline_t g_tl;

/* ============================================================
   INTERNAL HELPERS
   ============================================================ */

static uint16_t clamp_u16(uint16_t v, uint16_t lo, uint16_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static int bar_in_section(uint16_t bar, const composer_timeline_section_t *s)
{
    if (!s) return 0;
    if (bar < s->bar_start) return 0;
    if (bar >= (uint16_t)(s->bar_start + s->bar_length)) return 0;
    return 1;
}

/* ============================================================
   INIT
   ============================================================ */

void composer_timeline_init(uint16_t total_bars)
{
    memset(&g_tl, 0, sizeof(g_tl));

    if (total_bars == 0)
        total_bars = 1;

    if (total_bars > COMPOSER_MAX_BARS)
        total_bars = COMPOSER_MAX_BARS;

    g_tl.total_bars = total_bars;
}

/* ============================================================
   SECTION SETUP
   ============================================================ */

int composer_timeline_add_section(composer_section_t section,
                                  uint16_t bar_start,
                                  uint16_t bar_length)
{
    if (g_tl.section_count >= COMPOSER_MAX_SECTIONS)
        return -1;

    if (bar_length == 0)
        return -2;

    /* clamp into timeline range */
    if (g_tl.total_bars == 0)
        g_tl.total_bars = 1;

    bar_start  = clamp_u16(bar_start, 0, (uint16_t)(g_tl.total_bars - 1));
    bar_length = clamp_u16(bar_length, 1, g_tl.total_bars);

    /* ensure section doesn't exceed total bars */
    if ((uint32_t)bar_start + (uint32_t)bar_length > (uint32_t)g_tl.total_bars)
    {
        bar_length = (uint16_t)(g_tl.total_bars - bar_start);
        if (bar_length == 0) return -3;
    }

    composer_timeline_section_t *s = &g_tl.sections[g_tl.section_count++];
    s->section    = section;
    s->bar_start  = bar_start;
    s->bar_length = bar_length;

    return 0;
}

/* ============================================================
   PLAYBACK (optional)
   ============================================================ */

void composer_timeline_play(void)
{
    g_tl.playing = 1;
    g_tl.playhead_bar  = 0;
    g_tl.playhead_step = 0;
}

void composer_timeline_stop(void)
{
    g_tl.playing = 0;
}

void composer_timeline_tick(void)
{
    if (!g_tl.playing)
        return;

    g_tl.playhead_step++;

    if (g_tl.playhead_step >= COMPOSER_STEPS_PER_BAR)
    {
        g_tl.playhead_step = 0;
        g_tl.playhead_bar++;

        if (g_tl.total_bars == 0)
            g_tl.total_bars = 1;

        if (g_tl.playhead_bar >= g_tl.total_bars)
            g_tl.playhead_bar = 0;
    }
}

/* ============================================================
   QUERY (playhead-based)
   ============================================================ */

composer_section_t composer_timeline_get_active_section(void)
{
    return composer_timeline_get_section_at_bar(g_tl.playhead_bar);
}

uint16_t composer_timeline_get_playhead_bar(void)
{
    return g_tl.playhead_bar;
}

uint16_t composer_timeline_get_playhead_step(void)
{
    return g_tl.playhead_step;
}

/* ============================================================
   QUERY (bar-based) — REQUIRED by composer_preview.c
   ============================================================ */

uint16_t composer_timeline_get_total_bars(void)
{
    return (g_tl.total_bars == 0) ? 1 : g_tl.total_bars;
}

composer_section_t composer_timeline_get_section_at_bar(uint16_t bar)
{
    /* if no sections defined, default MAIN */
    if (g_tl.section_count == 0)
        return SECTION_MAIN;

    for (uint8_t i = 0; i < g_tl.section_count; i++)
    {
        const composer_timeline_section_t *s = &g_tl.sections[i];
        if (bar_in_section(bar, s))
            return s->section;
    }

    /* not covered -> default MAIN */
    return SECTION_MAIN;
}

uint8_t composer_timeline_get_segment_at_bar(uint16_t bar)
{
    /* Default: map bar to 4-bar segments A/B/C/D (0..3) */
    const uint16_t seg_len = (COMPOSER_BARS_PER_SEGMENT == 0) ? 4 : COMPOSER_BARS_PER_SEGMENT;

    /* If we find the section that owns this bar, segment is relative to section start */
    if (g_tl.section_count != 0)
    {
        for (uint8_t i = 0; i < g_tl.section_count; i++)
        {
            const composer_timeline_section_t *s = &g_tl.sections[i];
            if (bar_in_section(bar, s))
            {
                uint16_t rel = (uint16_t)(bar - s->bar_start);
                uint8_t seg = (uint8_t)((rel / seg_len) & 0x03u);
                return seg; /* 0..3 */
            }
        }
    }

    /* fallback: global bar mapping */
    return (uint8_t)(((bar / seg_len) & 0x03u));
}

```

### apps/autorecorder/composer_timeline.h
<a name="appsautorecordercomposertimelineh"></a>

- **Name:** `composer_timeline.h`
- **Pfad:** `apps/autorecorder/composer_timeline.h`
- **SHA256:** `b9843e1fbac99845c3fa98585eab5e28cfe317dacc2bb4b37bf8cb26c6ffa9cb`

```
#ifndef COMPOSER_TIMELINE_H
#define COMPOSER_TIMELINE_H

#include <stdint.h>
#include "composer.h"

/* ============================================================
   Timeline Layout
   ============================================================ */

/* Max number of timeline sections stored */
#ifndef COMPOSER_MAX_SECTIONS
#define COMPOSER_MAX_SECTIONS 8
#endif

/* Max bars supported by timeline (storage + safety) */
#ifndef COMPOSER_MAX_BARS
#define COMPOSER_MAX_BARS 512
#endif

/* Steps per bar (Electribe style: 16 steps per bar) */
#ifndef COMPOSER_STEPS_PER_BAR
#define COMPOSER_STEPS_PER_BAR 16
#endif

/* Policy segments are A/B/C/D -> 0..3
   We map segments as 4 bars each by default. */
#ifndef COMPOSER_BARS_PER_SEGMENT
#define COMPOSER_BARS_PER_SEGMENT 4
#endif

typedef struct {
    composer_section_t section;   /* INTRO/MAIN/BREAK/PEAK/OUTRO */
    uint16_t bar_start;           /* inclusive */
    uint16_t bar_length;          /* number of bars */
} composer_timeline_section_t;

typedef struct {
    uint16_t total_bars;

    composer_timeline_section_t sections[COMPOSER_MAX_SECTIONS];
    uint8_t  section_count;

    /* playhead (optional realtime usage) */
    uint8_t  playing;
    uint16_t playhead_bar;
    uint16_t playhead_step;
} composer_timeline_t;

/* ============================================================
   API
   ============================================================ */

void     composer_timeline_init(uint16_t total_bars);

/* Adds a section block starting at bar_start for bar_length bars */
int      composer_timeline_add_section(composer_section_t section,
                                       uint16_t bar_start,
                                       uint16_t bar_length);

/* Optional transport */
void     composer_timeline_play(void);
void     composer_timeline_stop(void);
void     composer_timeline_tick(void);

/* Query (playhead-based) */
composer_section_t composer_timeline_get_active_section(void);
uint16_t composer_timeline_get_playhead_bar(void);
uint16_t composer_timeline_get_playhead_step(void);

/* Query (bar-based) — REQUIRED by composer_preview.c */
composer_section_t composer_timeline_get_section_at_bar(uint16_t bar);
uint8_t            composer_timeline_get_segment_at_bar(uint16_t bar);
uint16_t           composer_timeline_get_total_bars(void);

#endif /* COMPOSER_TIMELINE_H */

```

### apps/autorecorder/composer_utils.c
<a name="appsautorecordercomposerutilsc"></a>

- **Name:** `composer_utils.c`
- **Pfad:** `apps/autorecorder/composer_utils.c`
- **SHA256:** `00703cd2dc6d0f2ff8a679dbf5b5ee4207ffab4a5e129de200ab3f323ada0f9b`

```
#include "composer_utils.h"

/* ------------------------------------------------------------
   PART GROUPS (0..15)
   Harmonics: 0..7  (Pads 1..8)
   Drums:     8..15 (Pads 9..16)
   ------------------------------------------------------------ */

#define PARTMASK_HARMONICS  ((composer_partmask_t)0x00FFu) /* bits 0..7  */
#define PARTMASK_DRUMS      ((composer_partmask_t)0xFF00u) /* bits 8..15 */

/* Individual drum bits (0-based part index) */
#define P_KICK   (1u << 8)
#define P_SNARE  (1u << 9)
#define P_CLAP   (1u << 10)
#define P_CHH    (1u << 11)
#define P_OHH    (1u << 12)
#define P_PERC   (1u << 13)
#define P_RIDE   (1u << 14)
#define P_DFX    (1u << 15)

/* Individual harmonic bits */
#define P_BASS   (1u << 0)
#define P_LEAD   (1u << 1)
#define P_CHORD  (1u << 2)
#define P_ARP    (1u << 3)
#define P_PAD    (1u << 4)
#define P_STABS  (1u << 5)
#define P_PLUCK  (1u << 6)
#define P_HFX    (1u << 7)

/* Clamp segment 0..3 */
static uint8_t seg4(uint8_t s) { return (s > 3) ? 3 : s; }

/* ------------------------------------------------------------
   DECISION TABLE (simple but musical)
   segment: 0=A,1=B,2=C,3=D within section
   ------------------------------------------------------------ */
composer_partmask_t composer_decide_partmask(composer_section_t section,
                                             uint8_t segment)
{
    segment = seg4(segment);

    switch (section)
    {
        case SECTION_INTRO:
            /* Build-in over A..D */
            if (segment == 0) return (composer_partmask_t)(P_KICK | P_CHH | P_BASS | P_PAD);
            if (segment == 1) return (composer_partmask_t)(P_KICK | P_CHH | P_SNARE | P_BASS | P_PAD);
            if (segment == 2) return (composer_partmask_t)(P_KICK | P_CHH | P_SNARE | P_CLAP | P_BASS | P_CHORD | P_PAD);
            return (composer_partmask_t)(P_KICK | P_CHH | P_SNARE | P_CLAP | P_BASS | P_CHORD | P_ARP | P_PAD);

        case SECTION_MAIN:
            /* Full groove, keep D a bit richer */
            if (segment < 3)
                return (composer_partmask_t)(PARTMASK_DRUMS | (P_BASS | P_CHORD | P_ARP | P_LEAD | P_PAD));
            return (composer_partmask_t)(PARTMASK_DRUMS | (P_BASS | P_CHORD | P_ARP | P_LEAD | P_STABS | P_PLUCK | P_PAD));

        case SECTION_BREAK:
            /* Drop kick, focus on harmonics + hats/percs */
            if (segment == 0) return (composer_partmask_t)(P_CHH | P_OHH | P_PERC | (P_PAD | P_CHORD));
            if (segment == 1) return (composer_partmask_t)(P_CHH | P_PERC | (P_PAD | P_CHORD | P_ARP));
            if (segment == 2) return (composer_partmask_t)(P_CHH | P_OHH | P_PERC | (P_PAD | P_CHORD | P_ARP | P_LEAD));
            return (composer_partmask_t)(P_CHH | P_OHH | P_PERC | P_SNARE | (P_PAD | P_CHORD | P_ARP | P_LEAD));

        case SECTION_PEAK:
            /* Everything on */
            return (composer_partmask_t)(PARTMASK_HARMONICS | PARTMASK_DRUMS);

        case SECTION_OUTRO:
            /* Reduce over time */
            if (segment == 0) return (composer_partmask_t)(P_KICK | P_CHH | P_SNARE | P_BASS | P_CHORD | P_PAD);
            if (segment == 1) return (composer_partmask_t)(P_KICK | P_CHH | P_BASS | P_PAD);
            if (segment == 2) return (composer_partmask_t)(P_CHH | P_BASS | P_PAD);
            return (composer_partmask_t)(P_PAD);

        default:
            return (composer_partmask_t)(PARTMASK_HARMONICS | PARTMASK_DRUMS);
    }
}

```

### apps/autorecorder/composer_write_export.c
<a name="appsautorecordercomposerwriteexportc"></a>

- **Name:** `composer_write_export.c`
- **Pfad:** `apps/autorecorder/composer_write_export.c`
- **SHA256:** `11044da07ba1849860df4f9408806512bde392948de831ce55863d542608aafc`

```
#include "composer_write_export.h"
#include "composer_write_prepare.h"
#include "pattern_writer.h"
#include "e2pat_writer.h"
#include "sysex_helper.h"
#include "midi_out.h"

bool composer_write_export_e2pat(void)
{
    uint8_t buf[4096];

    int len = e2pat_build_file(buf, sizeof(buf));
    if (len < 0)
        return false;

    return e2pat_save_to_media(buf, len);
}

bool composer_write_export_sysex(void)
{
    uint8_t buf[4096];

    int len = sysex_build_full_dump(buf, sizeof(buf));
    if (len <= 0)
        return false;

    return sysex_send_dump(buf, len);
}

```

### apps/autorecorder/composer_write_export.h
<a name="appsautorecordercomposerwriteexporth"></a>

- **Name:** `composer_write_export.h`
- **Pfad:** `apps/autorecorder/composer_write_export.h`
- **SHA256:** `fd5c1dc38ee9bc16fbd100afe5e011a4f76761e435faaea4bddc467f46f37814`

```
#ifndef COMPOSER_WRITE_EXPORT_H
#define COMPOSER_WRITE_EXPORT_H

#include <stdbool.h>

/* Export prepared patterns */
bool composer_write_export_e2pat(void);
bool composer_write_export_sysex(void);

#endif

```

### apps/autorecorder/composer_write_prepare.c
<a name="appsautorecordercomposerwritepreparec"></a>

- **Name:** `composer_write_prepare.c`
- **Pfad:** `apps/autorecorder/composer_write_prepare.c`
- **SHA256:** `e09129d6265c9b1e7310e8b375eaf91ea87c07370e942d42863a623acff45d40`

```
#include "composer_write_prepare.h"
#include "pattern_writer.h"
#include <string.h>

#define MAX_WRITE_BLOCKS 250

static composer_write_block_t g_blocks[MAX_WRITE_BLOCKS];
static int g_block_count = 0;

int composer_write_prepare(uint16_t slot_base)
{
    g_block_count = 0;

    uint16_t total_bars = composer_timeline_get_total_bars();
    if (total_bars == 0)
        return 0;

    for (uint16_t bar = 0; bar < total_bars; bar += COMPOSER_PATTERN_BARS)
    {
        if (g_block_count >= MAX_WRITE_BLOCKS)
            break;

        uint16_t block_idx = bar / COMPOSER_PATTERN_BARS;

        composer_write_block_t *b = &g_blocks[g_block_count];
        memset(b, 0, sizeof(*b));

        b->slot      = slot_base + block_idx;
        b->bar_start = bar;

        /* Collect 4 bars → 64 steps */
        for (uint16_t bi = 0; bi < COMPOSER_PATTERN_BARS; bi++)
        {
            uint16_t abs_bar = bar + bi;
            if (abs_bar >= total_bars)
                break;

            for (uint16_t step = 0; step < COMPOSER_STEPS_PER_BAR; step++)
            {
                uint16_t dst =
                    (bi * COMPOSER_STEPS_PER_BAR) + step;

                /* Preview already wrote the pattern into RAM map,
                   so we just read from current page = preview truth */
                pattern_read_page(
                    0, /* part is set later */
                    &b->steps[dst],
                    1,
                    abs_bar
                );

                b->steps[dst].step = (uint8_t)dst;
            }
        }

        g_block_count++;
    }

    return g_block_count;
}

int composer_write_get_block_count(void)
{
    return g_block_count;
}

const composer_write_block_t *composer_write_get_block(int idx)
{
    if (idx < 0 || idx >= g_block_count)
        return NULL;
    return &g_blocks[idx];
}

```

### apps/autorecorder/composer_write_prepare.h
<a name="appsautorecordercomposerwriteprepareh"></a>

- **Name:** `composer_write_prepare.h`
- **Pfad:** `apps/autorecorder/composer_write_prepare.h`
- **SHA256:** `9e03f2f86e201ca68609d25e5b9c5f05931907d338e00c4830808bf0468fe459`

```
#ifndef COMPOSER_WRITE_PREPARE_H
#define COMPOSER_WRITE_PREPARE_H

#include <stdint.h>
#include "ft_types.h"
#include "composer_timeline.h"

#define COMPOSER_PATTERN_BARS   4
#define COMPOSER_STEPS_PER_BAR 16
#define COMPOSER_PATTERN_STEPS 64   /* 4 × 16 */

typedef struct {
    uint16_t slot;              /* 1..250 */
    uint16_t bar_start;         /* absolute bar */
    ft_step_t steps[COMPOSER_PATTERN_STEPS];
} composer_write_block_t;

/* Prepare all pattern blocks for writing */
int composer_write_prepare(uint16_t slot_base);

/* Access prepared blocks */
int composer_write_get_block_count(void);
const composer_write_block_t *composer_write_get_block(int idx);

#endif

```

### apps/autorecorder/condition_engine.c
<a name="appsautorecorderconditionenginec"></a>

- **Name:** `condition_engine.c`
- **Pfad:** `apps/autorecorder/condition_engine.c`
- **SHA256:** `e903375ddbe870e554854cfdaa6ef5c53351d2c1b7bf2fa5dc495a6004fec3c3`

```
/* 
 * condition_engine.c — Condition Engine v2
 *
 * Phase 2 – Step 10:
 * - NRPN Node Editing (MSB50 LSB93..99)
 *
 * Phase 3.1.5:
 * - Debug Visualizer (Text / Tree Dump)
 *
 * Phase 3.2.1:
 * - Per-Step Probability API
 */

#include <stdint.h>
#include <string.h>

#include "condition_engine.h"
#include "randomizer.h"
#include "rng.h"
#include "ft_api.h"

/* ============================================================
   CONFIG
   ============================================================ */

#define COND_MAX_NODES_LOCAL 64
#if (COND_MAX_NODES_LOCAL != COND_MAX_NODES)
#error "COND_MAX_NODES mismatch"
#endif

#define DEBUG_MAX_DEPTH 12

/* ============================================================
   FORWARD DECLARATIONS
   ============================================================ */

static void dbg_dump_node(int id, int depth);

/* =========================
   DEBUG STATE (GLOBAL)
   ========================= */

static int g_debug_enabled = 0;
static int g_debug_part = 0;
static int g_debug_step = 0;

/* ============================================================
   CONDITION MEMORY
   ============================================================ */

static step_condition_ext_t
    g_conditions[RANDOMIZER_MAX_CHANNELS][RANDOMIZER_MAX_STEPS];

/* ============================================================
   NODE POOL
   ============================================================ */

static condition_node_t g_nodes[COND_MAX_NODES];

/* ============================================================
   NRPN STAGING STATE
   ============================================================ */

static int g_stage_part  = 0;
static int g_stage_step  = 0;
static int g_stage_node  = -1;
static cond_basic_t g_stage_type = COND_NONE;
static int g_stage_param = 0;

/* ============================================================
   HELPERS
   ============================================================ */

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static void clear_step_cond(step_condition_ext_t *c)
{
    if (!c) return;
    memset(c, 0, sizeof(*c));
    c->use_complex = 0;
    c->simple.type = COND_NONE;
    c->simple.param = 0;
    c->simple.threshold = 0;
    c->complex_node = -1;
}

static int node_valid(int id)
{
    return (id >= 0 && id < COND_MAX_NODES && g_nodes[id].used);
}

/* ============================================================
   DEBUG HELPERS
   ============================================================ */

static const char* cond_basic_name(cond_basic_t t)
{
    switch (t)
    {
        case COND_NONE:    return "NONE";
        case COND_PROB:    return "PROB";
        case COND_SECTION: return "SECTION";
        case COND_BAR:     return "BAR";
        case COND_CHANCE:  return "CHANCE";
        default:           return "UNKNOWN";
    }
}

static const char* comb_name(combine_op_t op)
{
    switch (op)
    {
        case COMB_AND: return "AND";
        case COMB_OR:  return "OR";
        case COMB_NOT: return "NOT";
        default:       return "?";
    }
}

/* ============================================================
   EVALUATION
   ============================================================ */

static int eval_basic(cond_basic_t type, int param, int bar, int section)
{
    switch (type)
    {
        case COND_NONE: return 1;
        case COND_SECTION: return (section == param);
        case COND_BAR: return (bar == param);
        case COND_PROB:
        case COND_CHANCE:
        {
            int p = clampi(param, 0, 127);
            return ((rng_get() & 0x7F) < p);
        }
        default:
            return 1;
    }
}

static int eval_node(int node_id, int bar, int section)
{
    if (!node_valid(node_id)) return 1;

    condition_node_t *n = &g_nodes[node_id];

    if (!n->is_combine)
        return eval_basic(n->basic_type, n->param, bar, section);

    int l = eval_node(n->left, bar, section);
    int r = eval_node(n->right, bar, section);

    switch (n->op)
    {
        case COMB_AND: return l && r;
        case COMB_OR:  return l || r;
        case COMB_NOT: return !l;
        default:       return 1;
    }
}

/* ============================================================
   ENGINE API
   ============================================================ */

int condition_engine_init(void)
{
    memset(g_conditions, 0, sizeof(g_conditions));
    memset(g_nodes, 0, sizeof(g_nodes));

    g_stage_part = 0;
    g_stage_step = 0;
    g_stage_node = -1;
    g_stage_type = COND_NONE;
    g_stage_param = 0;

    return 0;
}

int evaluate_step_condition(
    int part, int step, int prev_gate,
    int bar, int section, const ft_step_t *other)
{
    (void)prev_gate;
    (void)other;

    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return 1;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS) return 1;

    step_condition_ext_t *c = &g_conditions[part][step];

    if (!c->use_complex && c->simple.type == COND_NONE)
        return 1;

    if (c->use_complex)
        return eval_node(c->complex_node, bar, section);

    return eval_basic(c->simple.type, c->simple.param, bar, section);
}

/* ============================================================
   NODE MANAGEMENT
   ============================================================ */

int randomizer_create_condition_node(cond_basic_t type, int param)
{
    for (int i = 0; i < COND_MAX_NODES; i++)
        if (!g_nodes[i].used)
        {
            g_nodes[i].used = 1;
            g_nodes[i].is_combine = 0;
            g_nodes[i].basic_type = type;
            g_nodes[i].param = param;
            g_nodes[i].left = -1;
            g_nodes[i].right = -1;
            return i;
        }
    return -1;
}

int randomizer_set_condition_node_basic(int id, cond_basic_t t, int p)
{
    if (!node_valid(id)) return -1;
    g_nodes[id].is_combine = 0;
    g_nodes[id].basic_type = t;
    g_nodes[id].param = p;
    g_nodes[id].left = -1;
    g_nodes[id].right = -1;
    return 0;
}

int randomizer_set_condition_node_combine(int id, combine_op_t op, int right)
{
    if (!node_valid(id)) return -1;

    condition_node_t *n = &g_nodes[id];

    if (!n->is_combine)
    {
        int left = randomizer_create_condition_node(
            n->basic_type, n->param);
        if (left < 0) return -2;
        n->left = left;
    }

    n->is_combine = 1;
    n->op = op;
    n->right = (op == COMB_NOT) ? -1 : right;
    return 0;
}

int randomizer_remove_condition_node(int id)
{
    if (id < 0 || id >= COND_MAX_NODES) return -1;
    memset(&g_nodes[id], 0, sizeof(condition_node_t));
    return 0;
}

/* ============================================================
   STEP ASSIGN
   ============================================================ */

int randomizer_assign_condition_to_step(
    int part, int step, const step_condition_ext_t *c)
{
    if (!c)
    {
        clear_step_cond(&g_conditions[part][step]);
        return 0;
    }

    g_conditions[part][step] = *c;
    if (c->use_complex && !node_valid(c->complex_node))
        clear_step_cond(&g_conditions[part][step]);

    return 0;
}

int randomizer_clear_step_condition(int part, int step)
{
    return randomizer_assign_condition_to_step(part, step, NULL);
}

/* ============================================================
   STAGING API
   ============================================================ */

void condition_stage_part(int part)
{
    g_stage_part = clampi(part, 0, RANDOMIZER_MAX_CHANNELS - 1);
}

void condition_stage_step(int step)
{
    g_stage_step = clampi(step, 0, RANDOMIZER_MAX_STEPS - 1);
}

void condition_stage_node(int node)
{
    g_stage_node = node;
}

void condition_commit(void)
{
    if (g_stage_node < 0)
    {
        randomizer_clear_step_condition(g_stage_part, g_stage_step);
        return;
    }

    step_condition_ext_t c;
    clear_step_cond(&c);

    if (node_valid(g_stage_node))
    {
        c.use_complex = 1;
        c.complex_node = g_stage_node;
    }
    else
    {
        c.simple.type = COND_PROB;
        c.simple.param = clampi(g_stage_node, 0, 127);
    }

    randomizer_assign_condition_to_step(g_stage_part, g_stage_step, &c);
}

/* ============================================================
   PHASE 3.2.1 – PER-STEP PROBABILITY
   ============================================================ */

void condition_set_step_probability(int part, int step, int prob)
{
    prob = clampi(prob, 0, 127);

    if (prob >= 127)
    {
        randomizer_clear_step_condition(part, step);
        return;
    }

    step_condition_ext_t c;
    clear_step_cond(&c);
    c.simple.type = COND_PROB;
    c.simple.param = prob;

    randomizer_assign_condition_to_step(part, step, &c);
}

/* ============================================================
   DEBUG VISUALIZER (Phase 3.1.5)
   ============================================================ */

static void dbg_indent(int d)
{
    while (d--) ft_print("  ");
}

static void dbg_dump_node(int id, int d)
{
    if (!node_valid(id) || d > DEBUG_MAX_DEPTH)
        return;

    condition_node_t *n = &g_nodes[id];
    dbg_indent(d);

    if (!n->is_combine)
    {
        ft_print("NODE %d BASIC %s param=%d\n",
                 id, cond_basic_name(n->basic_type), n->param);
        return;
    }

    ft_print("NODE %d COMB %s\n", id, comb_name(n->op));
    dbg_dump_node(n->left, d + 1);
    if (n->op != COMB_NOT)
        dbg_dump_node(n->right, d + 1);
}

void condition_debug_dump_current(void)
{
    step_condition_ext_t *c =
        &g_conditions[g_stage_part][g_stage_step];

    ft_print("\n[COND DBG] part=%d step=%d\n",
             g_stage_part, g_stage_step);

    if (!c->use_complex && c->simple.type == COND_NONE)
    {
        ft_print("  <NO CONDITION>\n");
        return;
    }

    if (!c->use_complex)
    {
        ft_print("  SIMPLE %s param=%d\n",
                 cond_basic_name(c->simple.type),
                 c->simple.param);
        return;
    }

    ft_print("  COMPLEX root=%d\n", c->complex_node);
    dbg_dump_node(c->complex_node, 1);
}

/* ============================================================
   NRPN + DEBUG WRAPPERS
   ============================================================ */

int condition_get_staged_part(void) { return g_stage_part; }
int condition_get_staged_step(void) { return g_stage_step; }

void nrpn_condition_stage_part(int part) { condition_stage_part(part); }
void nrpn_condition_stage_step(int step) { condition_stage_step(step); }
void nrpn_condition_stage_node(int node) { condition_stage_node(node); }
void nrpn_condition_commit(void) { condition_commit(); }

void condition_debug_enable(int on)
{
    g_debug_enabled = (on != 0);
}

void condition_debug_select(int part, int step)
{
    g_debug_part = clampi(part, 0, RANDOMIZER_MAX_CHANNELS - 1);
    g_debug_step = clampi(step, 0, RANDOMIZER_MAX_STEPS - 1);
}

void condition_debug_dump_step(void)
{
    if (!g_debug_enabled) return;

    step_condition_ext_t *c =
        &g_conditions[g_debug_part][g_debug_step];

    ft_print("[COND DBG] Part %d Step %d\n",
             g_debug_part, g_debug_step);

    if (!c->use_complex)
    {
        ft_print("  Simple: type=%d param=%d\n",
                 c->simple.type, c->simple.param);
        return;
    }

    ft_print("  Complex node id=%d\n", c->complex_node);
}

void condition_debug_dump_node(int node_id)
{
    if (!g_debug_enabled) return;

    ft_print("[COND DBG] Dump node %d\n", node_id);
    dbg_dump_node(node_id, 0);
}
/* ============================================================
   NRPN CONDITION NODE EDITING
   (Phase 2 – Step 10)
   ============================================================ */

void nrpn_condition_node_create(int basic_type)
{
    int node = randomizer_create_condition_node(
        (cond_basic_t)basic_type, 0);

    g_stage_node = node;
}

void nrpn_condition_node_set_param(int param)
{
    if (g_stage_node < 0) return;

    randomizer_set_condition_node_basic(
        g_stage_node,
        g_nodes[g_stage_node].basic_type,
        clampi(param, 0, 127));
}

void nrpn_condition_node_to_and(int right_node)
{
    if (g_stage_node < 0) return;
    randomizer_set_condition_node_combine(
        g_stage_node, COMB_AND, right_node);
}

void nrpn_condition_node_to_or(int right_node)
{
    if (g_stage_node < 0) return;
    randomizer_set_condition_node_combine(
        g_stage_node, COMB_OR, right_node);
}

void nrpn_condition_node_to_not(void)
{
    if (g_stage_node < 0) return;
    randomizer_set_condition_node_combine(
        g_stage_node, COMB_NOT, -1);
}

void nrpn_condition_node_delete(int node_id)
{
    randomizer_remove_condition_node(node_id);
    if (g_stage_node == node_id)
        g_stage_node = -1;
}

```

### apps/autorecorder/condition_presets.c
<a name="appsautorecorderconditionpresetsc"></a>

- **Name:** `condition_presets.c`
- **Pfad:** `apps/autorecorder/condition_presets.c`
- **SHA256:** `f785926cb2bd33f5d41efc7da91b23bdb23486cb6528eff4c43d9adaab826514`

```
#include "condition_presets.h"

#include <string.h>

#include "condition_engine.h"
#include "ft_api.h"

/* ============================================================
   IMPORTANT:
   We do NOT depend on composer SECTION_* symbols here.
   We define our own section IDs, matching the common mapping:
     0 Intro, 1 Main, 2 Break, 3 Peak, 4 Outro
   ============================================================ */
enum {
    SEC_INTRO = 0,
    SEC_MAIN  = 1,
    SEC_BREAK = 2,
    SEC_PEAK  = 3,
    SEC_OUTRO = 4
};

/* ============================================================
   Preset IDs
   ============================================================ */
typedef enum {
    PRESET_ALWAYS = 0,
    PRESET_NEVER,

    /* Prob presets */
    PRESET_PROB_PARAM,      /* param = 0..127 */
    PRESET_PROB_25,
    PRESET_PROB_50,
    PRESET_PROB_75,

    /* Section presets (exact match) */
    PRESET_SECTION_PARAM,   /* param = 0..4 */
    PRESET_SECTION_INTRO,
    PRESET_SECTION_MAIN,
    PRESET_SECTION_BREAK,
    PRESET_SECTION_PEAK,
    PRESET_SECTION_OUTRO,

    /* Bar presets (exact match) */
    PRESET_BAR_PARAM,       /* param = 0..127 (we clamp to 0..63 typical) */

    /* Combined examples */
    PRESET_INTRO_AND_PROB_PARAM, /* AND( section=intro, prob=param ) */
    PRESET_MAIN_AND_PROB_PARAM,
    PRESET_NOT_BREAK,            /* NOT( section=break ) */

    PRESET_COUNT
} preset_id_t;

/* ============================================================
   Staging state (browser)
   ============================================================ */
static int g_preset_id = PRESET_ALWAYS;
static int g_preset_param = 64; /* default for PROB param etc. */

/* ============================================================
   Helpers: create nodes
   ============================================================ */
static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static int create_basic(cond_basic_t type, int param)
{
    return randomizer_create_condition_node(type, param);
}

/* Combine a left node with op/right:
   - This uses randomizer_set_condition_node_combine(), which copies
     the current node into left internally if needed.
*/
static int combine_node(int left_node, combine_op_t op, int right_node)
{
    if (left_node < 0) return -1;
    return randomizer_set_condition_node_combine(left_node, op, right_node);
}

/* ============================================================
   Names
   ============================================================ */
int condition_preset_count(void)
{
    return (int)PRESET_COUNT;
}

const char* condition_preset_name(int preset_id)
{
    switch ((preset_id_t)preset_id)
    {
        case PRESET_ALWAYS:                 return "Always (no condition)";
        case PRESET_NEVER:                  return "Never (gate off)";
        case PRESET_PROB_PARAM:             return "Probability = Param";
        case PRESET_PROB_25:                return "Probability 25%";
        case PRESET_PROB_50:                return "Probability 50%";
        case PRESET_PROB_75:                return "Probability 75%";

        case PRESET_SECTION_PARAM:          return "Section = Param";
        case PRESET_SECTION_INTRO:          return "Section = Intro";
        case PRESET_SECTION_MAIN:           return "Section = Main";
        case PRESET_SECTION_BREAK:          return "Section = Break";
        case PRESET_SECTION_PEAK:           return "Section = Peak";
        case PRESET_SECTION_OUTRO:          return "Section = Outro";

        case PRESET_BAR_PARAM:              return "Bar = Param";

        case PRESET_INTRO_AND_PROB_PARAM:   return "Intro AND Prob(Param)";
        case PRESET_MAIN_AND_PROB_PARAM:    return "Main AND Prob(Param)";
        case PRESET_NOT_BREAK:              return "NOT(Break)";

        default:                            return "Unknown";
    }
}

/* ============================================================
   Public API
   ============================================================ */

void condition_preset_select(int preset_id)
{
    g_preset_id = clampi(preset_id, 0, PRESET_COUNT - 1);
}

void condition_preset_set_param(int param)
{
    g_preset_param = clampi(param, 0, 127);
}

/* Build node graph for current preset.
   Returns:
     node_id >= 0  => complex node root
     -1            => special meaning "ALWAYS"
     -2            => special meaning "NEVER" (we represent as PROB 0)
*/
static int build_preset_node(void)
{
    switch ((preset_id_t)g_preset_id)
    {
        case PRESET_ALWAYS:
            return -1;

        case PRESET_NEVER:
            return -2;

        case PRESET_PROB_PARAM:
            return create_basic(COND_PROB, g_preset_param);

        case PRESET_PROB_25:
            return create_basic(COND_PROB, 32);   /* ~25% of 127 */

        case PRESET_PROB_50:
            return create_basic(COND_PROB, 64);   /* ~50% */

        case PRESET_PROB_75:
            return create_basic(COND_PROB, 96);   /* ~75% */

        case PRESET_SECTION_PARAM:
            return create_basic(COND_SECTION, clampi(g_preset_param, 0, 4));

        case PRESET_SECTION_INTRO:
            return create_basic(COND_SECTION, SEC_INTRO);

        case PRESET_SECTION_MAIN:
            return create_basic(COND_SECTION, SEC_MAIN);

        case PRESET_SECTION_BREAK:
            return create_basic(COND_SECTION, SEC_BREAK);

        case PRESET_SECTION_PEAK:
            return create_basic(COND_SECTION, SEC_PEAK);

        case PRESET_SECTION_OUTRO:
            return create_basic(COND_SECTION, SEC_OUTRO);

        case PRESET_BAR_PARAM:
            /* engine supports equality only; clamp typical bar range */
            return create_basic(COND_BAR, clampi(g_preset_param, 0, 63));

        case PRESET_INTRO_AND_PROB_PARAM:
        {
            int root = create_basic(COND_SECTION, SEC_INTRO);
            int prob = create_basic(COND_PROB, g_preset_param);
            if (root < 0 || prob < 0) return -1;
            (void)combine_node(root, COMB_AND, prob);
            return root;
        }

        case PRESET_MAIN_AND_PROB_PARAM:
        {
            int root = create_basic(COND_SECTION, SEC_MAIN);
            int prob = create_basic(COND_PROB, g_preset_param);
            if (root < 0 || prob < 0) return -1;
            (void)combine_node(root, COMB_AND, prob);
            return root;
        }

        case PRESET_NOT_BREAK:
        {
            int root = create_basic(COND_SECTION, SEC_BREAK);
            if (root < 0) return -1;
            (void)combine_node(root, COMB_NOT, -1);
            return root;
        }

        default:
            return -1;
    }
}

/* Apply to staged step:
   uses condition_engine staging (part/step already set via NRPN 50:90/91)
*/
void condition_preset_apply_to_staged_step(void)
{
    int part = condition_get_staged_part();
    int step = condition_get_staged_step();

    /* Build node graph */
    int node = build_preset_node();

    if (node == -1)
    {
        /* ALWAYS => clear condition */
        (void)randomizer_clear_step_condition(part, step);
        return;
    }

    if (node == -2)
    {
        /* NEVER => simple PROB 0 */
        step_condition_ext_t c;
        memset(&c, 0, sizeof(c));
        c.use_complex = 0;
        c.simple.type = COND_PROB;
        c.simple.param = 0;
        c.simple.threshold = 0;
        (void)randomizer_assign_condition_to_step(part, step, &c);
        return;
    }

    /* Complex condition */
    step_condition_ext_t c;
    memset(&c, 0, sizeof(c));
    c.use_complex = 1;
    c.complex_node = node;
    (void)randomizer_assign_condition_to_step(part, step, &c);
}

void condition_preset_dump(void)
{
    int part = condition_get_staged_part();
    int step = condition_get_staged_step();

    ft_print("[COND PRESET] id=%d name=%s param=%d -> staged P%d S%d\n",
             g_preset_id, condition_preset_name(g_preset_id),
             g_preset_param, part, step);
}

```

### apps/autorecorder/cpu/ft_api.c
<a name="appsautorecordercpuftapic"></a>

- **Name:** `ft_api.c`
- **Pfad:** `apps/autorecorder/cpu/ft_api.c`
- **SHA256:** `110abf011ad869338aa7e9a658d05511c613c9f99ddcfa1e365c4709909101bc`

```
/*
 * ft_api.c
 *
 * Wrapper zwischen App und Electribe Firmwarefunktionen.
 * Diese Version ist kompiliersicher und enthält nur FW-Hooks,
 * KEINE local Pattern-Writer Fallbacks.
 */

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>    // struct stat fix

#include "ft_api.h"
#include "sync_live.h"
#include "syscalls.h"

/* -------------------------------------------------------------
   Firmware Function Pointer (Platzhalter)
   ------------------------------------------------------------- */
static void (*fw_write_step)(const ft_step_t*)     = 0;
static int  (*fw_get_step_count)(void)             = 0;
static void (*fw_print)(const char *fmt, ...)      = 0;

/* g_live darf NICHT hier definiert werden → wird in sync_live.c definiert */
extern live_sync_state_t g_live;

/* -------------------------------------------------------------
   INIT – muss beim Start aufgerufen werden
   ------------------------------------------------------------- */
void ft_api_init_from_fw(void)
{
    /* Diese Adressen werden später durch echte Firmware-Offsets ersetzt */

    fw_write_step     = (void*)0x080F1234;
    fw_get_step_count = (void*)0x080F12A8;
    fw_print          = (void*)0x080F1ABC;
}

/* -------------------------------------------------------------
   Schritt schreiben
   ------------------------------------------------------------- */
int ft_write_step(const ft_step_t *s)
{
    if (!s)
        return 0;

    if (fw_write_step) {
        fw_write_step(s);
        return 1;
    }

    return 0;
}

/* -------------------------------------------------------------
   Patternlänge abfragen
   ------------------------------------------------------------- */
int ft_get_pattern_step_count(void)
{
    if (fw_get_step_count)
        return fw_get_step_count();

    return 64; /* Electribe Default */
}

/* -------------------------------------------------------------
   Firmware-Print Wrapper
   ------------------------------------------------------------- */
void ft_print(const char *fmt, ...)
{
    if (!fmt)
        return;

    char buf[256];

    va_list va;
    va_start(va, fmt);
    vsnprintf(buf, sizeof(buf), fmt, va);
    va_end(va);

    if (fw_print)
        fw_print("%s", buf);
}

/* -------------------------------------------------------------
   Ticks aus Syscalls
   ------------------------------------------------------------- */
uint32_t ft_get_ticks(void)
{
    return syscall_get_ticks();
}

/* -------------------------------------------------------------
   FEHLENDE API FUNKTIONEN FÜR sync_live.c
   ------------------------------------------------------------- */

int ft_get_current_pattern(void)
{
    return g_live.pattern;
}

int ft_get_play_position(void)
{
    return g_live.step;
}

/* NOTE:
   ft_get_bpm() wird im Projekt bereits in sync.c bereitgestellt.
   Damit es keine "multiple definition" Linker-Fehler gibt,
   wird ft_get_bpm() hier NICHT noch einmal definiert.
*/

```

### apps/autorecorder/cpu/include/composer.h
<a name="appsautorecordercpuincludecomposerh"></a>

- **Name:** `composer.h`
- **Pfad:** `apps/autorecorder/cpu/include/composer.h`
- **SHA256:** `1b7ff2c80e399cd9bbdc0ad7a5bf766d5c67ec6c6f62fbb31a90f8bcf2b9bbd3`

```
#ifndef COMPOSER_H
#define COMPOSER_H

#include <stdint.h>
#include "ft_types.h"

/* ============================================================
   SECTION IDs (stabil)
   ============================================================ */
typedef enum {
    SECTION_INTRO = 0,
    SECTION_MAIN,
    SECTION_BREAK,
    SECTION_PEAK,
    SECTION_OUTRO
} composer_section_t;

/* ============================================================
   GENRE IDs (stabil, maschinenlesbar)
   ============================================================ */
typedef enum {
    GENRE_ACID_TECHNO = 0,
    GENRE_RAVE,
    GENRE_GABBER,
    GENRE_FRENCHCORE,
    GENRE_HAPPY_HARDCORE,
    GENRE_TECH_TRANCE,
    GENRE_TEKKNO,
    GENRE_COUNT
} composer_genre_t;

/* ============================================================
   FILL TYPES (Policy only)
   ============================================================ */
typedef enum {
    FILL_NONE = 0,
    FILL_GROOVE,
    FILL_BUILD,
    FILL_PUNCTUATION
} composer_fill_t;

/* ============================================================
   Composer State API
   ============================================================ */
void composer_init(void);

/* selected genre (for SongMode hooks / preset recall) */
void composer_set_genre(uint8_t genre_id);
uint8_t composer_get_genre(void);

/* current policy state (published for Conditions/SongMode) */
composer_fill_t composer_get_current_fill(void);
void composer_set_current_fill(composer_fill_t f);

/* ------------------------------------------------------------
   Preset Recall (Option 4)
   Apply policy ONLY (no generation / no write)
   ------------------------------------------------------------ */
void composer_preset_recall(uint8_t genre_id,
                            composer_section_t section,
                            uint8_t segment);

/* ------------------------------------------------------------
   Generation (optional / existing usage)
   ------------------------------------------------------------ */
void composer_generate_segment(uint8_t genre_id,
                               composer_section_t section,
                               uint8_t segment,
                               uint8_t target_page);

void composer_generate_section(uint8_t genre_id,
                               composer_section_t section,
                               uint8_t start_page);

void composer_generate_song(uint8_t genre_id,
                            uint8_t start_page);

/* ------------------------------------------------------------
   Song Mode Auto-Fill hook (Option 3)
   Call when a section/segment becomes active.
   Non-destructive: triggers Live-FX fill / boosts only.
   ------------------------------------------------------------ */
void composer_songmode_on_section(uint8_t section,
                                  uint8_t segment);

#endif /* COMPOSER_H */

```

### apps/autorecorder/cpu/include/composer_bridge.h
<a name="appsautorecordercpuincludecomposerbridgeh"></a>

- **Name:** `composer_bridge.h`
- **Pfad:** `apps/autorecorder/cpu/include/composer_bridge.h`
- **SHA256:** `2fedc92c7c4ea52d8e6a044cfa2a9f36c1a7d709a5b43afd28dfe0c79501cc39`

```
#ifndef COMPOSER_BRIDGE_H
#define COMPOSER_BRIDGE_H

#include <stdint.h>
#include "composer.h"

/* If you already have a lock system somewhere else, keep the signature. */
int composer_part_is_locked(uint8_t part, composer_section_t section);

/* NEW: decisions-driven fill */
void composer_fill_missing_parts(uint8_t target_page,
                                 composer_section_t section,
                                 uint8_t segment);

#endif /* COMPOSER_BRIDGE_H */

```

### apps/autorecorder/cpu/include/composer_padmap.h
<a name="appsautorecordercpuincludecomposerpadmaph"></a>

- **Name:** `composer_padmap.h`
- **Pfad:** `apps/autorecorder/cpu/include/composer_padmap.h`
- **SHA256:** `7b44f7d9cfa0fc006c1e90f570ae743c3f2cc7817428bde7aab26f56d6eb3fb1`

```
#ifndef COMPOSER_PADMAP_H
#define COMPOSER_PADMAP_H

#include <stdint.h>

/* Project-wide Drum Map (fixed) */
#define DRUM_KICK   36 /* C1 */
#define DRUM_SNARE  38 /* D1 */
#define DRUM_CLAP   44 /* G#1 */
#define DRUM_CH     42 /* F#1 */
#define DRUM_OH     46 /* A#1 */
#define DRUM_PERC   51 /* D#2 */
#define DRUM_RIDE   57 /* A2 */
#define DRUM_FX     61 /* C#3 */

uint8_t composer_drum_note(uint8_t idx);

#endif

```

### apps/autorecorder/cpu/include/composer_policy.h
<a name="appsautorecordercpuincludecomposerpolicyh"></a>

- **Name:** `composer_policy.h`
- **Pfad:** `apps/autorecorder/cpu/include/composer_policy.h`
- **SHA256:** `0f6e999f275e1c32d997b66bfc36b9a475da330fc70bec8979c9cd1ef1872cfc`

```
#ifndef COMPOSER_POLICY_H
#define COMPOSER_POLICY_H

#include <stdint.h>
#include "composer.h"

/* ============================================================
   Decision Flags (Composer → Randomizer Bias)
   ============================================================ */

typedef uint16_t composer_policy_flags_t;

/* Flags */
#define CP_FLAG_NONE            0x0000
#define CP_FLAG_SPARSE          0x0001
#define CP_FLAG_DENSE           0x0002
#define CP_FLAG_LOW_REGISTER    0x0004
#define CP_FLAG_HIGH_REGISTER   0x0008
#define CP_FLAG_STRAIGHT        0x0010
#define CP_FLAG_SYNCOPATED      0x0020
#define CP_FLAG_SUSTAINED       0x0040
#define CP_FLAG_PERCUSSIVE      0x0080
#define CP_FLAG_BUILDING        0x0100
#define CP_FLAG_RELEASE         0x0200

/* ============================================================
   Policy Segment
   ============================================================ */

typedef struct {
    uint8_t density;          /* 0–100 */
    uint8_t variation;        /* 0–127 */
    uint8_t euclid_pulses;
    int8_t  euclid_rotation;
    composer_fill_t fill;

    composer_policy_flags_t flags; /* <<< NEU */
} composer_policy_segment_t;

/* ============================================================
   API
   ============================================================ */

void composer_apply_policy(uint8_t genre_id,
                           composer_section_t section,
                           uint8_t segment);

#endif /* COMPOSER_POLICY_H */

```

### apps/autorecorder/cpu/include/composer_utils.h
<a name="appsautorecordercpuincludecomposerutilsh"></a>

- **Name:** `composer_utils.h`
- **Pfad:** `apps/autorecorder/cpu/include/composer_utils.h`
- **SHA256:** `8005d531373b1dcae961df3d589f69979e1d08ae7696087e65da583f4b8781fd`

```
#ifndef COMPOSER_UTILS_H
#define COMPOSER_UTILS_H

#include <stdint.h>
#include "composer.h"

/* 16-bit mask: bit0 = part0 ... bit15 = part15 */
typedef uint16_t composer_partmask_t;

/* Decision: which parts SHOULD exist in this section/segment */
composer_partmask_t composer_decide_partmask(composer_section_t section,
                                             uint8_t segment);

/* Convenience helpers */
static inline int composer_mask_has_part(composer_partmask_t m, uint8_t part)
{
    return (part < 16) ? ((m >> part) & 1u) : 0;
}

#endif /* COMPOSER_UTILS_H */

```

### apps/autorecorder/cpu/include/condition_engine.h
<a name="appsautorecordercpuincludeconditionengineh"></a>

- **Name:** `condition_engine.h`
- **Pfad:** `apps/autorecorder/cpu/include/condition_engine.h`
- **SHA256:** `688ec4a9a2f2c01b487eb3f1204d34c9faeee0c9f219057c32a2b40782fdfb43`

```
#ifndef CONDITION_ENGINE_H
#define CONDITION_ENGINE_H

#include <stdint.h>
#include "ft_types.h"

/* ============================================================
   CONSTANTS
   ============================================================ */

#define COND_MAX_NODES 64

/* ============================================================
   BASIC CONDITION TYPES
   ============================================================ */

typedef enum {
    COND_NONE = 0,
    COND_PROB,
    COND_SECTION,
    COND_BAR,
    COND_CHANCE,
    COND_BASIC_MAX
} cond_basic_t;

/* ============================================================
   COMBINE OPERATORS
   ============================================================ */

typedef enum {
    COMB_AND = 0,
    COMB_OR,
    COMB_NOT
} combine_op_t;

/* ============================================================
   CONDITION NODE (ID-BASED, INTERNAL GRAPH)
   ============================================================ */

typedef struct {
    uint8_t used;          /* slot in use */
    uint8_t is_combine;    /* 0 = basic, 1 = combine */

    /* basic node */
    cond_basic_t basic_type;
    int          param;

    /* combine node */
    combine_op_t op;
    int          left;     /* node id */
    int          right;    /* node id */
} condition_node_t;

/* ============================================================
   STEP CONDITION CONTAINER
   ============================================================ */

typedef struct {
    int use_complex;

    struct {
        cond_basic_t type;
        int param;
        int threshold;
    } simple;

    int complex_node;   /* node id, NOT pointer */
} step_condition_ext_t;

/* ============================================================
   CORE ENGINE API
   ============================================================ */

int condition_engine_init(void);

int ensure_step_condition_size(int steps);

int evaluate_step_condition(
        int part,
        int step,
        int prev_gate,
        int bar,
        int section,
        const ft_step_t *other);

/* ============================================================
   NODE MANAGEMENT (Randomizer / Internal)
   ============================================================ */

int randomizer_create_condition_node(cond_basic_t type, int param);

int randomizer_set_condition_node_basic(
        int node_id,
        cond_basic_t type,
        int param);

int randomizer_set_condition_node_combine(
        int node_id,
        combine_op_t op,
        int right_node_id);

int randomizer_remove_condition_node(int node_id);

/* ============================================================
   STEP ASSIGNMENT
   ============================================================ */

int randomizer_assign_condition_to_step(
        int part,
        int step,
        const step_condition_ext_t *cond);

int randomizer_clear_step_condition(int part, int step);

/* ============================================================
   STAGING API (ENGINE SIDE)
   ============================================================ */

void condition_stage_part(int part);
void condition_stage_step(int step);
void condition_stage_node(int node);
void condition_commit(void);

/* ============================================================
   STAGING GETTERS (Preset Browser / Debug)
   ============================================================ */

int condition_get_staged_part(void);
int condition_get_staged_step(void);

/* ============================================================
   NRPN WRAPPERS (Router-facing API)
   ============================================================ */

void nrpn_condition_stage_part(int part);
void nrpn_condition_stage_step(int step);
void nrpn_condition_stage_node(int node);
void nrpn_condition_commit(void);

void nrpn_condition_node_create(int basic_type);
void nrpn_condition_node_set_param(int param);
void nrpn_condition_node_to_and(int right_node);
void nrpn_condition_node_to_or(int right_node);
void nrpn_condition_node_to_not(void);
void nrpn_condition_node_delete(int node_id);

/* ============================================================
   DEBUG / VISUALIZER (Phase 3.1)
   ============================================================ */

/* Enable / disable debug output */
void condition_debug_enable(int on);

/* Select debug scope */
void condition_debug_select(int part, int step);

/* Dump current step condition */
void condition_debug_dump_step(void);

/* Dump node graph starting at node_id */
void condition_debug_dump_node(int node_id);

/* Extended debug */
void condition_debug_set_mode(int mode);   /* 0..2 */
int  condition_debug_node_count(void);
void condition_debug_dump_current(void);

/* ============================================================
   Phase 3.2.1 – Per-Step Probability
   ============================================================ */

void condition_set_step_probability(int part, int step, int prob);

#endif /* CONDITION_ENGINE_H */

```

### apps/autorecorder/cpu/include/condition_presets.h
<a name="appsautorecordercpuincludeconditionpresetsh"></a>

- **Name:** `condition_presets.h`
- **Pfad:** `apps/autorecorder/cpu/include/condition_presets.h`
- **SHA256:** `04add4a719c98a2b0459a5d6ed891ca1a97342b7c7e56f24573759427df0fcfc`

```
#ifndef CONDITION_PRESETS_H
#define CONDITION_PRESETS_H

#include <stdint.h>

/* ============================================================
   Condition Preset Browser (NRPN)
   Phase 3.1.5
   - Policy-only
   - builds node graphs + assigns to staged step
   ============================================================ */

/* Select preset id (0..N-1) */
void condition_preset_select(int preset_id);

/* Set preset parameter (meaning depends on preset) */
void condition_preset_set_param(int param);

/* Apply selected preset to currently staged step (condition_engine staging) */
void condition_preset_apply_to_staged_step(void);

/* Debug: print current preset and its resolved node */
void condition_preset_dump(void);

/* Helper: count and name for UI/debug */
int  condition_preset_count(void);
const char* condition_preset_name(int preset_id);

#endif /* CONDITION_PRESETS_H */

```

### apps/autorecorder/cpu/include/ft_api.h
<a name="appsautorecordercpuincludeftapih"></a>

- **Name:** `ft_api.h`
- **Pfad:** `apps/autorecorder/cpu/include/ft_api.h`
- **SHA256:** `745cffd9f890f51c3e0c5069bc0ae848252cd0f3f5b16c59bba6ab5b3933495f`

```
#ifndef FT_API_H
#define FT_API_H

#include <stdint.h>
#include "ft_types.h"

/* -------------------------------------------------------------
   Core print/debug interface
   ------------------------------------------------------------- */
void ft_print(const char *fmt, ...);
void ft_puts(const char *s);
void set_pattern_number(int pat);

/* -------------------------------------------------------------
   Pattern read/write
   ------------------------------------------------------------- */
int ft_write_step(const ft_step_t *s);

/* -------------------------------------------------------------
   Sequencer info (dummy in Autorecorder)
   ------------------------------------------------------------- */
int ft_get_current_pattern(void);
int ft_get_play_position(void);
int ft_get_current_bar(void);
int ft_get_pattern_step_count(void);
int ft_get_bpm(void);

/* -------------------------------------------------------------
   Ticks (ms) – used for NRPN timeout/transactions
   ------------------------------------------------------------- */
uint32_t ft_get_ticks(void);

/* -------------------------------------------------------------
   Initialization
   ------------------------------------------------------------- */
void ft_api_init_from_fw(void);

#endif /* FT_API_H */

```

### apps/autorecorder/cpu/include/ft_types.h
<a name="appsautorecordercpuincludefttypesh"></a>

- **Name:** `ft_types.h`
- **Pfad:** `apps/autorecorder/cpu/include/ft_types.h`
- **SHA256:** `45c77236f83c181dbe7dd80c669312fc26efb8af839e5b38f047f742abf78fbc`

```
#ifndef FT_TYPES_H
#define FT_TYPES_H

#include <stdint.h>

/* ================================================================
   ft_step_t — Reconstructed Electribe/Freetribe Step Definition
   ================================================================ */

typedef struct {
    /* Position */
    uint8_t part;          /* 0..15  */
    uint8_t step;          /* 0..63  */

    /* Core musical data */
    uint8_t pitch;         /* 0..127 MIDI note     */
    uint8_t velocity;      /* 0..127               */
    uint8_t gate;          /* 0/1                  */
    uint8_t length;        /* step length 0..127   */

    /* Additional flags (tie, accent, mute, cond, etc.) */
    uint8_t flags;

    /* Reserved future fields to avoid crashes */
    uint8_t reserved1;
    uint8_t reserved2;

} ft_step_t;

#endif /* FT_TYPES_H */

```

### apps/autorecorder/cpu/include/pattern_writer.h
<a name="appsautorecordercpuincludepatternwriterh"></a>

- **Name:** `pattern_writer.h`
- **Pfad:** `apps/autorecorder/cpu/include/pattern_writer.h`
- **SHA256:** `53aa0a769f29511cf2965d3be706e06b59d58ed5ea47b4729768b8640ecdccc6`

```
#ifndef PATTERN_WRITER_H
#define PATTERN_WRITER_H

#include <stdint.h>
#include "ft_types.h"

/* ---------------------------------------------------------------------
   HIGH-LEVEL STEP READ/WRITE
   --------------------------------------------------------------------- */

/* Read N steps from the current active page */
int pattern_read_steps(int part, ft_step_t *dst, int n);

/* Write N steps to the current active page */
int pattern_write_steps(int part, const ft_step_t *src, int n);

/* Write ONE step (writes to exact step index!) */
int pattern_write_step(int part, int step, int pitch, int velocity, int gate);


/* ---------------------------------------------------------------------
   FULL PATTERN WRITE (legacy)
   --------------------------------------------------------------------- */
int pattern_write_pattern(int part, const ft_step_t *steps, int count);


/* ---------------------------------------------------------------------
   RLE + COMPRESSED WRITERS (optional)
   --------------------------------------------------------------------- */
int pattern_write_rle_batch(int part,
                            const ft_step_t *steps,
                            int nsteps,
                            int target_page);

int pattern_write_compressed(int part,
                             const ft_step_t *steps,
                             int nsteps,
                             int target_page);


/* ---------------------------------------------------------------------
   PAGING SYSTEM
   --------------------------------------------------------------------- */

/* Set current page number (returns active page) */
int pattern_set_current_page(int page);

/* Set active page (used by Song Mode and NRPN Clear) */
void pattern_set_active_page(int page);

/* Get active page */
int pattern_get_active_page(void);

/* Typically 16, 64, 128 — configurable */
int pattern_get_paging_page_size(void);


/* ---------------------------------------------------------------------
   DIRECT PAGE ACCESS
   --------------------------------------------------------------------- */

/* Read N steps from a specific page */
int pattern_read_page(int part, ft_step_t *dst, int nsteps, int page);

/* Write N steps to a specific page */
int pattern_write_page(int part, const ft_step_t *src, int nsteps, int page);


/* ---------------------------------------------------------------------
   CLEAR / RESET UTILITIES
   --------------------------------------------------------------------- */
int pattern_clear_part(int part);
int pattern_clear_all_parts(void);
int pattern_clear_page(int pat);
int pattern_clear_nrpn(int part);


/* ---------------------------------------------------------------------
   DEPRECATED / INTERNAL (still used by ft_api)
   --------------------------------------------------------------------- */
void set_pattern_number(int pat);

#endif /* PATTERN_WRITER_H */

```

### apps/autorecorder/cpu/include/rng.h
<a name="appsautorecordercpuincluderngh"></a>

- **Name:** `rng.h`
- **Pfad:** `apps/autorecorder/cpu/include/rng.h`
- **SHA256:** `93a2f9ced695492e4ed39ed7f100eba38c7f2bcfe391ea48f5480f7598055c79`

```
#ifndef RNG_H
#define RNG_H

#include <stdint.h>

/* Seed the RNG. If seed == 0 a default nonzero seed will be used. */
void rng_seed(uint32_t seed);

/* Return next 32-bit random value. */
uint32_t rng_get(void);

/* Convenience: return random integer in [0, max-1]. If max <= 0 returns 0. */
int rng_int(int max);

#endif /* RNG_H */

```

### apps/autorecorder/cpu/include/syscalls.h
<a name="appsautorecordercpuincludesyscallsh"></a>

- **Name:** `syscalls.h`
- **Pfad:** `apps/autorecorder/cpu/include/syscalls.h`
- **SHA256:** `42891b7ca39aae34ea6c8b3b4ac407ad16ea73fee434de367286db9b72540871`

```
#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>     // for uint32_t
#include <stddef.h>     // for ptrdiff_t
#include <sys/types.h>  // for off_t
#include <sys/stat.h>   // for struct stat

/* --------------------------------------------------------------------
   Global Tick Counter Interface (used by ft_api.c)
   -------------------------------------------------------------------- */

extern volatile uint32_t system_ticks;

/* Provided by syscalls.c */
uint32_t syscall_get_ticks(void);


/* --------------------------------------------------------------------
   Memory / Syscall Stubs required by newlib
   -------------------------------------------------------------------- */

void *_sbrk(ptrdiff_t incr);

int _open(const char *name, int flags, int mode);
int _close(int file);

int _fstat(int file, struct stat *st);
int _isatty(int file);

off_t _lseek(int file, off_t ptr, int dir);

int _write(int file, char *ptr, int len);
int _read(int file, char *ptr, int len);

int _kill(int pid, int sig);
int _getpid(void);
void _exit(int status);

#endif /* SYSCALLS_H */

```

### apps/autorecorder/cpu/linker.ld
<a name="appsautorecordercpulinkerld"></a>

- **Name:** `linker.ld`
- **Pfad:** `apps/autorecorder/cpu/linker.ld`
- **SHA256:** `eda3539d81ab6631a18677ef67c98fbcee7a546667b6b4f4d76c13db76535d92`

```
ENTRY(_start)

MEMORY
{
    rom (rx)  : ORIGIN = 0x80000000, LENGTH = 256K
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
    /* ---------------------------------------------------------
       CODE & READ-ONLY DATA
       --------------------------------------------------------- */
    .text : ALIGN(4)
    {
        KEEP(*(.vectors))      /* Startup / Interrupt Table */
        *(.text*)
        *(.rodata*)
    } > rom

    /* ---------------------------------------------------------
       INITIALIZED DATA (RAM, load from ROM)
       --------------------------------------------------------- */
    .data : ALIGN(4)
    {
        _data_start = .;
        *(.data*)
        _data_end = .;
    } > ram AT > rom

    /* Load address of .data in ROM */
    _data_load = LOADADDR(.data);

    /* ---------------------------------------------------------
       BSS SECTION (zeroed RAM)
       --------------------------------------------------------- */
    .bss : ALIGN(4)
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > ram

    /* ---------------------------------------------------------
       HEAP STARTS HERE
       newlib benötigt _end für _sbrk()
       --------------------------------------------------------- */
    _end = _bss_end;

    /* ---------------------------------------------------------
       STACK SECTION (at the top of RAM)
       ARM requires a defined stack symbol
       --------------------------------------------------------- */
    .stack (NOLOAD) :
    {
        . = ALIGN(8);
        _stack_start = .;
        . = ORIGIN(ram) + LENGTH(ram);
        _stack_end = .;
    } > ram

    /* Startup-Code uses this as initial SP */
    _estack = ORIGIN(ram) + LENGTH(ram);
}

```

### apps/autorecorder/cpu/Makefile
<a name="appsautorecordercpumakefile"></a>

- **Name:** `Makefile`
- **Pfad:** `apps/autorecorder/cpu/Makefile`
- **SHA256:** `e91fb81aa47da619be758ebf070962b061e66d441dcd32582ffc3be7a6bd19cf`

```
# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)

APP ?= demo

TARGET_EXEC := cpu.elf
TARGET_BIN := cpu.bin

# Library paths.
LIB_C ?= /usr/arm-none-eabi/lib
LIB_GCC ?= /lib/gcc/arm-none-eabi/14.2.0/

LPATH := -L"${LIB_C}" \
      	 -L"${LIB_GCC}"

NEWLIB ?= /usr/arm-none-eabi/include/
INC_DIRS := $(NEWLIB)

BUILD_DIR := ./build
SRC_DIR := ./src
LIB_DIR := ./lib
APP_DIR ?= $(SRC_DIR)/apps/$(APP)

# Defining the cross compiler tool prefix.
PREFIX := arm-none-eabi-

# Compiler, Linker and Archiver with respect to the toolchain.
CC=${PREFIX}gcc
CXX=${PREFIX}gcc
LD=${PREFIX}ld
BIN=$(PREFIX)objcopy

# C compilation options.
NEST_INT ?= 0
OPTIMISE ?= -g3 -Og
# OPTIMISE ?= -O3
CPU ?= arm926ej-s
CFLAGS := -mcpu=$(CPU) $(OPTIMISE) -fdata-sections -ffunction-sections -fanalyzer -fstack-usage -Wstack-usage=128 -Wall 

# Assembly compilation options.
ASM_FLAGS := -x assembler-with-cpp

# Linker options.
LDFLAGS := -e start -u start -u __aeabi_uidiv -u __aeabi_idiv $(LPATH) -lm -lc -lgcc  \
					 -T cpu.lds -Xlinker -Map -Xlinker $(BUILD_DIR)/boot.map -specs=picolibc.specs \
					 -Wl,--gc-sections,--print-memory-usage,--no-warn-rwx-segments 
# Binary options.
BIN_FLAGS := -O binary


# Find all the C, C++ and assembly files we want to compile.
# Note the single quotes around the * expressions.
# The shell will incorrectly expand these otherwise,
# but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIR)  \( -name '*.cpp' -or -name '*.c' -or -name '*.S' \) \
		-not -path "$(SRC_DIR)/apps/*")


SRCS += $(shell find $(LIB_DIR)  \( -name '*.cpp' -or -name '*.c' -or -name '*.S' \) \
		-not -path "$(LIB_DIR)/LEAF/*")

SRCS += $(shell find $(LIB_DIR)/LEAF/leaf/  -name '*.cpp' -or -name '*.c' -or -name '*.S')

SRCS += $(shell find $(APP_DIR)  -name '*.cpp' -or -name '*.c' -or -name '*.S')

# Prepends BUILD_DIR and appends .o to every src file.
# As an example, ./your_dir/hello.cpp turns into: ./build/./your_dir/hello.cpp.o 
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into: ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files.
INC_DIRS += $(shell find $(SRC_DIR) -type d -not -path "$(SRC_DIR)/apps/*" )

INC_DIRS += $(shell find $(LIB_DIR) -type d -not -path "$(SRC_DIR)/LEAF/*" )


INC_DIRS += $(shell find $(LIB_DIR)/LEAF/leaf/ -type d)

INC_DIRS += $(shell find $(APP_DIR) -type d)

# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag.
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us.
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP -DNESTED_INTERRUPTS=${NEST_INT}

# TODO: AISGen.

# Extract binary from ELF.
$(BUILD_DIR)/$(TARGET_BIN): $(BUILD_DIR)/$(TARGET_EXEC)
	$(BIN) $(BIN_FLAGS) $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/$(TARGET_BIN)

# Link.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	# $(LD) $(OBJS) -o $@ $(LDFLAGS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step ASM source.
$(BUILD_DIR)/%.S.o: %.S
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(ASM_FLAGS) -c $< -o $@

# Build step for C source.
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source.
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Include the .d makefiles. The - at the front suppresses
# the errors of missing Makefiles. 
# Initially, all the .d files will be missing, 
# and we don't want those errors to show up.
-include $(DEPS) 

```

### apps/autorecorder/cpu/save_manager_stubs.c
<a name="appsautorecordercpusavemanagerstubsc"></a>

- **Name:** `save_manager_stubs.c`
- **Pfad:** `apps/autorecorder/cpu/save_manager_stubs.c`
- **SHA256:** `fabbd4709b644aa60bb04779f737f9d4a4f42f0df56dce0e53ba6dac38d77016`

```
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

```

### apps/autorecorder/e2pat_writer.c
<a name="appsautorecordere2patwriterc"></a>

- **Name:** `e2pat_writer.c`
- **Pfad:** `apps/autorecorder/e2pat_writer.c`
- **SHA256:** `a3cfd4d80a03e89c1d4117123ae8bf7bd25228932a25c4537e00f70bff1b4528`

```
#include "e2pat_writer.h"
/* leer – alle Funktionen sind inline */

```

### apps/autorecorder/e2pat_writer.h
<a name="appsautorecordere2patwriterh"></a>

- **Name:** `e2pat_writer.h`
- **Pfad:** `apps/autorecorder/e2pat_writer.h`
- **SHA256:** `6a2c299a0ed64b2b9e2e593fd42744eff7a56626dcc49adc8f1056ba1c13380e`

```
#ifndef E2PAT_WRITER_H
#define E2PAT_WRITER_H

#include <stdint.h>
#include <stdbool.h>

/* ======================================================================
   E2PAT WRITER – Platzhalter
   Diese Datei dient als Stub, bis das echte Electribe-e2pat Format
   implementiert ist.
   ====================================================================== */

/* Speicherung eines Pattern-Dumps in E2PAT-kompatiblem Format.
 * Rückgabe:
 *   >=0 : Länge der erzeugten Datei
 *    <0 : Fehler
 */
static inline int e2pat_build_file(uint8_t *out, int maxlen)
{
    /* TODO:
       - Offizielles e2pat-Format implementieren
       - Parameter-Map
       - Steps / Motion-Seq Encoding
       - Checksummen
    */

    if (!out || maxlen <= 0) return -1;

    /* Dummy-Datei: 0 Bytes erzeugt */
    return 0;
}

/* Dummy: Speichern auf externes Medium */
static inline bool e2pat_save_to_media(const uint8_t *data, int len)
{
    /* TODO:
       - SD / USB / PC Stream implementieren
       - Status nach NRPN zurückmelden
    */

    (void)data;
    (void)len;
    return true;
}

#endif /* E2PAT_WRITER_H */

```

### apps/autorecorder/euclid_engine_v2.c
<a name="appsautorecordereuclidenginev2c"></a>

- **Name:** `euclid_engine_v2.c`
- **Pfad:** `apps/autorecorder/euclid_engine_v2.c`
- **SHA256:** `f4b90fd586c0fe069df085913fa3ba57069e090164dde7d56597aac1a57a558c`

```
#include "euclid_engine_v2.h"
#include "rng.h"
#include <stdint.h>
#include <stdbool.h>

/* ============================================================
   Fallback Limits
   ============================================================ */

/* If not provided by header, define safe maximum */
#ifndef EUCLID_MAX_STEPS
#define EUCLID_MAX_STEPS 64
#endif

/* ============================================================
   Helpers
   ============================================================ */

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ============================================================
   Probability helper
   ============================================================ */
/*
 * Contract (from header):
 *   int euclid_probability_pass(int probability);
 *
 * probability: 0..127
 * return: 1 = pass, 0 = block
 */
int euclid_probability_pass(int probability)
{
    probability &= 0x7F; /* MIDI-safe */

    int r = (int)(rng_get() & 0x7F);
    return (r < probability) ? 1 : 0;
}

/* ============================================================
   Core Euclid generator
   ============================================================ */
/*
 * steps    : number of steps
 * pulses  : number of hits
 * rotation: rotation offset
 * out     : buffer [steps] → 0/1
 */
int euclid_generate(int steps, int pulses, int rotation, uint8_t *out)
{
    if (!out) return -1;

    steps  = clampi(steps, 1, EUCLID_MAX_STEPS);
    pulses = clampi(pulses, 0, steps);

    /* trivial cases */
    if (pulses == 0)
    {
        for (int i = 0; i < steps; i++)
            out[i] = 0;
        return steps;
    }

    if (pulses >= steps)
    {
        for (int i = 0; i < steps; i++)
            out[i] = 1;
        return steps;
    }

    /* --------------------------------------------------------
       Deterministic Euclid distribution (Bjorklund-lite)
       -------------------------------------------------------- */
    int bucket = 0;

    for (int i = 0; i < steps; i++)
    {
        bucket += pulses;
        if (bucket >= steps)
        {
            bucket -= steps;
            out[i] = 1;
        }
        else
        {
            out[i] = 0;
        }
    }

    /* --------------------------------------------------------
       Rotation
       -------------------------------------------------------- */
    if (rotation != 0)
    {
        rotation = ((rotation % steps) + steps) % steps;

        uint8_t tmp[EUCLID_MAX_STEPS];

        for (int i = 0; i < steps; i++)
            tmp[(i + rotation) % steps] = out[i];

        for (int i = 0; i < steps; i++)
            out[i] = tmp[i];
    }

    return steps;
}

```

### apps/autorecorder/euclid_engine_v2.h
<a name="appsautorecordereuclidenginev2h"></a>

- **Name:** `euclid_engine_v2.h`
- **Pfad:** `apps/autorecorder/euclid_engine_v2.h`
- **SHA256:** `5d91e6e2693b2ee7ee63258a4bca962ea9860bc0bf8a94c9e4ce256581a102d7`

```
#ifndef EUCLID_ENGINE_V2_H
#define EUCLID_ENGINE_V2_H

#include <stdint.h>
#include <stdbool.h>

/* Wichtig: randomizer.h enthält die echten eu_slot_t / eu_channel_t */
#include "randomizer.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================
   API: Core Euclid Math
   ============================================================ */

int euclid_generate(int steps, int pulses, int rotation, uint8_t *out_gates);
void euclid_rotate(uint8_t *buf, int len, int amount);

/* ============================================================
   API: Probability + Fill Helpers
   ============================================================ */

int euclid_probability_pass(int probability);
int euclid_fill_mode_gate(int step_index, int steps);

/* ============================================================
   API: Compile runtime Euclid structures
   ============================================================ */

void euclid_compile_slot(eu_slot_t *slot);
void euclid_compile_channel(eu_channel_t *channel);
int  euclid_get_gate(const eu_channel_t *channel, int slot, int step);

#ifdef __cplusplus
}
#endif

#endif /* EUCLID_ENGINE_V2_H */

```

### apps/autorecorder/euclid_nrpn_stubs.c
<a name="appsautorecordereuclidnrpnstubsc"></a>

- **Name:** `euclid_nrpn_stubs.c`
- **Pfad:** `apps/autorecorder/euclid_nrpn_stubs.c`
- **SHA256:** `d56da8c35f3351e9c209f5816770698acec3b0fc75f51a78428b1eca5c74effe`

```
/* euclid_nrpn_stubs.c
   Keep this file only as a fallback helper.
   IMPORTANT: Do NOT define eu_stage_channel/eu_stage_slot here as strong globals.
*/

#include <stdint.h>
#include "randomizer.h"

/* If nrpn_router.c expects extern staging vars, they must be defined EXACTLY ONCE.
   Preferred: define them in randomizer_euclid.c (real module).
   Here we only provide weak fallback definitions. */

__attribute__((weak)) int eu_stage_channel = 0;
__attribute__((weak)) int eu_stage_slot    = 0;

/* Optional: weak fallbacks for any missing functions (usually not needed if randomizer_euclid.c is linked) */
__attribute__((weak)) void randomizer_euclid_stage_channel(int ch) { eu_stage_channel = ch; }
__attribute__((weak)) void randomizer_euclid_stage_slot(int slot)  { eu_stage_slot = slot; }

```

### apps/autorecorder/freetribe_recorder.c
<a name="appsautorecorderfreetriberecorderc"></a>

- **Name:** `freetribe_recorder.c`
- **Pfad:** `apps/autorecorder/freetribe_recorder.c`
- **SHA256:** `32d3a14b0d46502e962d844f4dec9a17c7849a599ba1a21d517dcd8475763e9f`

```
/*
 * freetribe_recorder.c
 *
 * Core app logic for AutoRecorder / Extended Pattern Engine
 * Integrates:
 *  - Randomizer Engine
 *  - NRPN Router
 *  - Live FX Overlay
 *  - Live Sync Layer (Phase 4.1)
 *  - Song Mode Hooks
 */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/* App-specific headers */
#include "ft_api.h"
#include "randomizer.h"
#include "nrpn_router.h"
#include "live_fx.h"
#include "song_mode.h"
#include "sync_live.h"

#include "pattern_writer.h"
#include "pattern_ram_map.h"

#include "Menu/Speichern/save_nrpn.h"
#include "Menu/Speichern/save_manager.h"
#include "Menu/Speichern/icons.h"
#include "ui_messages.h"



/* --------------------------------------------------------------------
   Internal State
   -------------------------------------------------------------------- */

static uint8_t g_record_armed = 0;
static uint8_t g_is_playing   = 0;

/* --------------------------------------------------------------------
   INIT
   -------------------------------------------------------------------- */

void app_init(void)
{
    /* LiveSync System (Phase 4.1) */
    live_sync_init();

    /* Randomizer defaults */
    randomizer_init_default();

    /* Song mode (if enabled) */
    song_mode_init();

    /* Initialize Live-FX subsystem */
    live_fx_init();

    g_record_armed = 0;
    g_is_playing = 0;
}

/* --------------------------------------------------------------------
   PLAY / STOP Hooks
   -------------------------------------------------------------------- */

void app_on_play(void)
{
    g_is_playing = 1;
    live_sync_on_start();
}

void app_on_stop(void)
{
    g_is_playing = 0;
    live_sync_on_stop();
}

/* --------------------------------------------------------------------
   RECORD ARM / DISARM
   -------------------------------------------------------------------- */

void recorder_arm(void)      { g_record_armed = 1; }
void recorder_disarm(void)   { g_record_armed = 0; }
uint8_t recorder_is_armed(void) { return g_record_armed; }

/* --------------------------------------------------------------------
   Main Tick — called every app cycle (≈1ms)
   -------------------------------------------------------------------- */

void app_tick(void)
{
    live_sync_tick();
    song_mode_tick();
    nrpn_router_tick();
    randomizer_tick_once();
    live_fx_tick();
}

/* --------------------------------------------------------------------
   Auto Pattern Generation
   -------------------------------------------------------------------- */

void recorder_generate_pattern(uint8_t part, uint8_t page)
{
    int steps = ft_get_pattern_step_count();

    if (steps <= 0)
        steps = 64;

    randomize_and_write_pattern_paged(part, steps, g_live.bar, page);
}

/* --------------------------------------------------------------------
   Manual Step Recording
   -------------------------------------------------------------------- */

void recorder_write_step(uint8_t part, uint8_t step, uint8_t pitch, uint8_t vel)
{
    if (!g_record_armed)
        return;

    ft_step_t s;
    s.part     = part;
    s.step     = step;
    s.pitch    = pitch;
    s.velocity = vel;
    s.gate     = (vel > 0) ? 1 : 0;

    ft_write_step(&s);
}

/* --------------------------------------------------------------------
   NRPN + MIDI CC handling
   -------------------------------------------------------------------- */

void app_handle_nrpn(uint16_t msb, uint16_t lsb, uint16_t value)
{
    nrpn_handle(msb, lsb, value);
}


void app_handle_midi_cc(uint8_t cc, uint8_t value)
{
    static int nrpn_msb = -1;
    static int nrpn_lsb = -1;

    switch (cc)
    {
        case 99: nrpn_msb = value; break; /* NRPN MSB */
        case 98: nrpn_lsb = value; break; /* NRPN LSB */

        case 6:  /* DATA ENTRY */
            if (nrpn_msb >= 0 && nrpn_lsb >= 0)
                nrpn_handle(nrpn_msb, nrpn_lsb, value);
            break;

        default:
            break;
    }
}

/* --------------------------------------------------------------------
   Debug
   -------------------------------------------------------------------- */

void app_debug_print_state(void)
{
    ft_print("LIVE SYNC:\n");
    ft_print("  step=%d bar=%d pattern=%d bpm=%.2f\n",
             g_live.step,
             g_live.bar,
             g_live.pattern,
             g_live.bpm_x100 / 100.0);
}

/* --------------------------------------------------------------------
   Main Entry
   -------------------------------------------------------------------- */

void app_main(void)
{
    ft_api_init_from_fw();

    for (;;) {
        /* idle mainloop */
    }
}
/* Beispiel-Handler, der vom Hardware-Button-ISR oder Poller aufgerufen wird.
   Bitte hooke diese Funktion an deinen Button-Event (ft_api / HW layer).
*/
void recorder_on_write_button(int shift_pressed)
{
    if (shift_pressed) {
        /* Write + Shift => Save-as (speichere unter neuem Namen)
           Wir starten Save-Request mit Mode=1 (Sysex + e2Pat) — du kannst ändern.
        */
        save_manager_request_save(SAVE_MODE_SYSEX_E2PAT, NULL);
        /* direkt in "Name eingeben" UI wechseln (UI-Flow nicht implementiert hier) */
        ui_show_message("Name eingeben");
        /* host may stream name via NRPN afterwards */
    } else {
        /* normal Write = quick-save using current defaults */
        save_manager_request_save(SAVE_MODE_SYSEX_E2PAT, NULL);
        /* automatically confirm for quick-save */
        save_manager_confirm(1);
    }
}
```

### apps/autorecorder/freetribe_save_bundle.c
<a name="appsautorecorderfreetribesavebundlec"></a>

- **Name:** `freetribe_save_bundle.c`
- **Pfad:** `apps/autorecorder/freetribe_save_bundle.c`
- **SHA256:** `d00db6ea1884ce20e3b32dde1de445ba9ee0903dbd49c09f09253becba95c278`

```
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

```

### apps/autorecorder/ft_config.h
<a name="appsautorecorderftconfigh"></a>

- **Name:** `ft_config.h`
- **Pfad:** `apps/autorecorder/ft_config.h`
- **SHA256:** `3943d0621dfc096f5b752e838f31befb948f89188245bfdd98d1182105151979`

```
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

```

### apps/autorecorder/groove_engine.c
<a name="appsautorecordergrooveenginec"></a>

- **Name:** `groove_engine.c`
- **Pfad:** `apps/autorecorder/groove_engine.c`
- **SHA256:** `94e6a8f5d41f8f47b28214e79aacb0e159cf9ce8c197f91f0b58f00cbefae920`

```
#include "groove_engine.h"

/* ============================================================
   INTERNAL STATE
   ============================================================ */

typedef struct
{
    uint8_t enabled;

    uint8_t macro;

    uint8_t timing_curve;
    uint8_t velocity_curve;

    uint8_t timing_amount;     /* 0..127 */
    uint8_t velocity_amount;   /* 0..127 */

} groove_state_t;

static groove_state_t g_groove;

/* ============================================================
   CURVE SHAPES (signed, centered)
   ============================================================ */

static int16_t curve_linear(uint8_t p)
{
    return (int16_t)p - 64;
}

static int16_t curve_swing(uint8_t p)
{
    int16_t x = (int16_t)p - 64;
    return (x * x) / 64 * (x < 0 ? -1 : 1);
}

static int16_t curve_push(uint8_t p)
{
    int16_t x = (int16_t)p - 64;
    return x > 0 ? (x * 2) : x;
}

/* ============================================================
   PUBLIC API
   ============================================================ */

void groove_init(void)
{
    g_groove.enabled = 1;

    g_groove.macro = 0;

    g_groove.timing_curve   = 0;
    g_groove.velocity_curve = 0;

    g_groove.timing_amount   = 64;
    g_groove.velocity_amount = 64;
}

/* ------------------------------------------------------------ */

void groove_set_enabled(uint8_t on)
{
    g_groove.enabled = on ? 1 : 0;
}

uint8_t groove_is_enabled(void)
{
    return g_groove.enabled;
}

/* ------------------------------------------------------------
   Macro
   ------------------------------------------------------------ */

void groove_set_macro(uint8_t value)
{
    g_groove.macro = value & 0x7F;

    /* deterministic mapping */
    g_groove.timing_curve =
        (value < 42) ? 0 : (value < 85) ? 1 : 2;

    g_groove.velocity_curve =
        (value < 64) ? 0 : 1;

    g_groove.timing_amount   = value;
    g_groove.velocity_amount = value;
}

uint8_t groove_get_macro(void)
{
    return g_groove.macro;
}

/* ------------------------------------------------------------
   Curve select
   ------------------------------------------------------------ */

void groove_set_timing_curve(uint8_t curve)
{
    g_groove.timing_curve = curve;
}

void groove_set_velocity_curve(uint8_t curve)
{
    g_groove.velocity_curve = curve;
}

/* ------------------------------------------------------------
   Amount
   ------------------------------------------------------------ */

void groove_set_timing_amount(uint8_t amt)
{
    g_groove.timing_amount = amt & 0x7F;
}

void groove_set_velocity_amount(uint8_t amt)
{
    g_groove.velocity_amount = amt & 0x7F;
}

/* ------------------------------------------------------------
   Evaluation
   ------------------------------------------------------------ */

int16_t groove_curve_timing_shape(uint8_t phase)
{
    if (!g_groove.enabled)
        return 0;

    int16_t shape;

    switch (g_groove.timing_curve)
    {
        default:
        case 0: shape = curve_linear(phase); break;
        case 1: shape = curve_swing(phase);  break;
        case 2: shape = curve_push(phase);   break;
    }

    return (shape * g_groove.timing_amount) / 127;
}

int16_t groove_curve_velocity_shape(uint8_t phase)
{
    if (!g_groove.enabled)
        return 0;

    int16_t shape;

    switch (g_groove.velocity_curve)
    {
        default:
        case 0: shape = curve_linear(phase); break;
        case 1: shape = curve_swing(phase);  break;
    }

    return (shape * g_groove.velocity_amount) / 127;
}

```

### apps/autorecorder/groove_engine.h
<a name="appsautorecordergrooveengineh"></a>

- **Name:** `groove_engine.h`
- **Pfad:** `apps/autorecorder/groove_engine.h`
- **SHA256:** `9e0f7ebc21fecb0446db38468953ea4373f6d6830cb5f636540405dc6b11cdb7`

```
#pragma once
#include <stdint.h>

/* ============================================================
   GROOVE ENGINE – PUBLIC API
   Phase 3.2.3 (Freeze-final)
   ============================================================ */

void    groove_init(void);

/* Enable */
void    groove_set_enabled(uint8_t on);
uint8_t groove_is_enabled(void);

/* One-Knob Macro */
void    groove_set_macro(uint8_t value);
uint8_t groove_get_macro(void);

/* Curve selection */
void    groove_set_timing_curve(uint8_t curve);
void    groove_set_velocity_curve(uint8_t curve);

/* Amount (0..127) */
void    groove_set_timing_amount(uint8_t amt);
void    groove_set_velocity_amount(uint8_t amt);

/* Curve evaluation (used by sync_live) */
int16_t groove_curve_timing_shape(uint8_t phase);
int16_t groove_curve_velocity_shape(uint8_t phase);

```

### apps/autorecorder/humanizer.c
<a name="appsautorecorderhumanizerc"></a>

- **Name:** `humanizer.c`
- **Pfad:** `apps/autorecorder/humanizer.c`
- **SHA256:** `e62eb2048397d4478cb5c2ccff9652ddacdbad1562344ddddf4327736668f715`

```
/* ============================================================
   apps/autorecorder/humanizer.c
   ============================================================ */
#include "humanizer.h"

/* ------------------------------------------------------------
   Internal state (deterministisch, keine RNG hier)
   ------------------------------------------------------------ */
static uint8_t g_enabled = 0;
static int g_timing_ticks = 0;   /* 0..N */
static int g_vel_amount   = 0;   /* 0..N */

void humanizer_set_enabled(int en)
{
    g_enabled = en ? 1 : 0;
}

int humanizer_get_enabled(void)
{
    return (int)g_enabled;
}

void humanizer_set_timing_amount_ticks(int ticks)
{
    if (ticks < 0) ticks = 0;
    if (ticks > 16) ticks = 16; /* hard cap */
    g_timing_ticks = ticks;
}

int humanizer_get_timing_amount_ticks(void)
{
    return g_timing_ticks;
}

void humanizer_set_velocity_amount(int amount)
{
    if (amount < 0) amount = 0;
    if (amount > 64) amount = 64; /* hard cap */
    g_vel_amount = amount;
}

int humanizer_get_velocity_amount(void)
{
    return g_vel_amount;
}

```

### apps/autorecorder/humanizer.h
<a name="appsautorecorderhumanizerh"></a>

- **Name:** `humanizer.h`
- **Pfad:** `apps/autorecorder/humanizer.h`
- **SHA256:** `eb78542dc707475459752dcb22081e9c0e8d67d4c72561f2f77981d085c326be`

```
/* ============================================================
   apps/autorecorder/humanizer.h
   ============================================================ */
#ifndef HUMANIZER_H
#define HUMANIZER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------
   Humanizer – Public API

   Wir halten es bewusst minimal:
   - enabled
   - timing amount (ticks)
   - velocity amount
   ------------------------------------------------------------ */

void humanizer_set_enabled(int en);
int  humanizer_get_enabled(void);

/* timing jitter (0..N ticks) */
void humanizer_set_timing_amount_ticks(int ticks);
int  humanizer_get_timing_amount_ticks(void);

/* velocity jitter (0..N) */
void humanizer_set_velocity_amount(int amount);
int  humanizer_get_velocity_amount(void);

#ifdef __cplusplus
}
#endif

#endif /* HUMANIZER_H */

```

### apps/autorecorder/live_fx.c
<a name="appsautorecorderlivefxc"></a>

- **Name:** `live_fx.c`
- **Pfad:** `apps/autorecorder/live_fx.c`
- **SHA256:** `312cb87b5bfb8476c193ebf34595d21c05d23d853cfbf6677085fc8deafbbfa7`

```
#include "live_fx.h"
#include <stdint.h>

/* Global FX state */
live_fx_state_t g_live_fx = {
    .fill_strength = 0,
    .gate_lfo_period = 0,
    .gate_lfo_depth = 0,
    .gate_lfo_enabled = 0
};

static uint32_t g_lfo_phase = 0;

/* ------------------------------------------------------------- */
void live_fx_init(void)
{
    g_live_fx.fill_strength = 0;
    g_live_fx.gate_lfo_period = 0;
    g_live_fx.gate_lfo_depth = 0;
    g_live_fx.gate_lfo_enabled = 0;
    g_lfo_phase = 0;
}

/* ------------------------------------------------------------- */
void live_fx_tick(void)
{
    g_lfo_phase++;
}

/* ------------------------------------------------------------- */
void live_fx_set_fill(int strength)
{
    if (strength < 0) strength = 0;
    if (strength > 127) strength = 127;
    g_live_fx.fill_strength = strength;
}

int live_fx_get_fill(void)
{
    return g_live_fx.fill_strength;
}

/* ------------------------------------------------------------- */
void live_fx_set_gate_lfo(int period, int depth, int enable)
{
    if (period < 0) period = 0;
    if (depth < 0) depth = 0;
    if (depth > 127) depth = 127;

    g_live_fx.gate_lfo_period  = period;
    g_live_fx.gate_lfo_depth   = depth;
    g_live_fx.gate_lfo_enabled = enable ? 1 : 0;
}

/* ------------------------------------------------------------- */
/* NEW: Mod-Matrix compatible getters */
int live_fx_get_fill_state(void)
{
    return g_live_fx.fill_strength & 0x7F;
}

int live_fx_get_gate_lfo_value(void)
{
    if (!g_live_fx.gate_lfo_enabled || g_live_fx.gate_lfo_period <= 0)
        return 0;

    uint32_t period = g_live_fx.gate_lfo_period;
    uint32_t phase = g_lfo_phase % period;

    int depth = g_live_fx.gate_lfo_depth;
    int v;

    if (phase < period / 2)
        v = (phase * 127) / (period / 2);
    else
        v = ((period - phase) * 127) / (period / 2);

    v = (v * depth) / 127;

    return v & 0x7F;
}

/* ------------------------------------------------------------- */
/* Weak default implementation */
__attribute__((weak))
void live_fx_process_cycle(int part, struct ft_step *buffer, int count)
{
    (void) part;
    (void) buffer;
    (void) count;
}
/* ============================================================
   Minimal API used by NRPN Router
   ============================================================ */
void live_fx_set_variation_boost(int v)
{
    /* TODO: hook into your FX engine */
    (void)v;
}

void live_fx_trigger_fill_now(void)
{
    /* TODO: trigger FX fill mode */
}

void live_fx_set_mutation(int m)
{
    /* TODO: apply mutation to FX engine */
    (void)m;
}

```

### apps/autorecorder/live_fx.h
<a name="appsautorecorderlivefxh"></a>

- **Name:** `live_fx.h`
- **Pfad:** `apps/autorecorder/live_fx.h`
- **SHA256:** `526ab064c8521be7571e54728281864f1bb04802fbb301f9dac54b0a8b8c89af`

```
#ifndef LIVE_FX_H
#define LIVE_FX_H

#include <stdint.h>

/*
 * Live FX engine — Fill, Gate-LFO, etc.
 * Clean and compatible with randomizer + mod_matrix.
 */

typedef struct {
    int fill_strength;      // 0..127
    int gate_lfo_period;    // number of ticks for a full LFO cycle
    int gate_lfo_depth;     // 0..127
    int gate_lfo_enabled;   // boolean 0/1
} live_fx_state_t;

/* Global state (defined in live_fx.c) */
extern live_fx_state_t g_live_fx;

/* Init */
void live_fx_init(void);

/* Tick */
void live_fx_tick(void);

/* Fill FX */
void live_fx_set_fill(int strength);
int  live_fx_get_fill(void);

/* Gate LFO */
void live_fx_set_gate_lfo(int period, int depth, int enable);

/* NEW: getters used by mod_matrix */
int live_fx_get_fill_state(void);
int live_fx_get_gate_lfo_value(void);

/* Optional processing hook */
struct ft_step; /* forward declaration */
void live_fx_process_cycle(int part, struct ft_step *buffer, int count);
void live_fx_set_variation_boost(int v);
void live_fx_trigger_fill_now(void);
void live_fx_set_mutation(int v);

void live_fx_set_variation_boost(int v);
void live_fx_trigger_fill_now(void);
void live_fx_set_mutation(int m);

#endif /* LIVE_FX_H */

```

### apps/autorecorder/Makefile
<a name="appsautorecordermakefile"></a>

- **Name:** `Makefile`
- **Pfad:** `apps/autorecorder/Makefile`
- **SHA256:** `d3b70464dc45a557d183ec358f2364906f2bf6beb7ebbf6b9447864a81e970b1`

```
APP_NAME := autorecorder

SRCS := \
    freetribe_recorder.c \
    freetribe_save_bundle.c \
    pattern_writer.c \
    pattern_clear.c \
    pattern_ram_map.c \
    pattern_transform.c \
    pattern_stubs.c \
    randomizer.c \
    randomizer_euclid.c \
    euclid_engine_v2.c \
    humanizer.c \
    rng.c \
    scale_engine.c \
    scale_engine_nrpn.c \
    mod_matrix.c \
    nrpn_router.c \
    live_fx.c \
    midi_out.c \
    sync.c \
    sync_live.c \
    syscalls.c \
    sysex_helper.c \
    ui_messages.c \
    condition_engine.c \
    condition_presets.c \
    euclid_nrpn_stubs.c \
    pattern_write_dummy.c \
    composer_timeline.c \
    composer_padmap.c \
    composer_policy.c \
    composer.c \
    composer_utils.c \
    composer_bridge.c \
    composer_preview.c \
    composer_write_prepare.c \
    composer_write_export.c \
    groove_engine.c \
    cpu/save_manager_stubs.c \
    cpu/startup.s \
    cpu/vectors.s \
    cpu/ft_api.c

include ../../app_common.mk

```

### apps/autorecorder/Menu/Button/button_handler.c
<a name="appsautorecordermenubuttonbuttonhandlerc"></a>

- **Name:** `button_handler.c`
- **Pfad:** `apps/autorecorder/Menu/Button/button_handler.c`
- **SHA256:** `8dbb6507b29d4bac72947553bac3c67c4fc61a43decc8c23625ef0d7997c9765`

```
#include "button_handler.h"
#include "save_manager.h"
#include "display_manager.h"
#include "ft_log.h"

/* -----------------------------------------------------------
   Konfiguration / Platzhalter
   ----------------------------------------------------------- */

/*
    TODO:
    - Debounce-Time definieren
    - Doubleclick-Zeit definieren
    - Longpress-Zeit definieren
*/
static const int DOUBLECLICK_MS = 300;
static const int LONGPRESS_MS   = 600;

/*
    TODO:
    - Falls Hardware via GPIO ISR geliefert wird:
      -> button_process() in GPIO-Callback aufrufen
*/

/* -----------------------------------------------------------
   Button States
   ----------------------------------------------------------- */
typedef struct {
    bool pressed;
    uint32_t last_time;
    uint32_t press_start;
} button_state_t;

static button_state_t btn_state[BTN_NONE];

/* Platzhalter: Timer-Funktion */
extern uint32_t ft_millis(void);

/* -----------------------------------------------------------
    MAIN ENTRY: button_process()
----------------------------------------------------------- */

void button_process(button_id_t btn, bool pressed)
{
    if (btn >= BTN_NONE) return;

    button_state_t *st = &btn_state[btn];
    uint32_t now = ft_millis();

    if (pressed && !st->pressed) {
        // FIRST PRESS
        st->pressed = true;
        st->press_start = now;

        /* TODO:
            - Aktionen bei Button-Down
            - akustisches Feedback?
        */
    }
    else if (!pressed && st->pressed) {
        // RELEASE
        st->pressed = false;
        uint32_t held = now - st->press_start;

        if (held >= LONGPRESS_MS) {
            button_handle_long(btn);
        }
        else {
            // check for double
            if (now - st->last_time < DOUBLECLICK_MS) {
                button_handle_double(btn);
            } else {
                button_handle_single(btn);
            }
            st->last_time = now;
        }
    }
}

/* -----------------------------------------------------------
    BUTTON-ACTIONS / Platzhalter für Funktionen
----------------------------------------------------------- */

void button_handle_single(button_id_t btn)
{
    switch (btn)
    {
        case BTN_WRITE:
            /* WRITE = Save Confirm */
            save_confirm();
            display_show("Gespeichert (WRITE)", 900);
            break;

        case BTN_EXIT:
            /* EXIT cancelt Save */
            save_cancel();
            display_show("Abgebrochen (EXIT)", 900);
            break;

        case BTN_STOP:
            /* TODO STOP */
            display_show("STOP gedrückt", 600);
            break;

        default:
            break;
    }
}

void button_handle_double(button_id_t btn)
{
    /* TODO:
        - doubleclick functions eintragen
        - z.B. Save sofort ohne Nachfrage?
    */
    display_show("Doppelklick erkannt", 600);
}

void button_handle_long(button_id_t btn)
{
    /* TODO:
        - longpress functions eintragen
        - Hold WRITE → Quick-Save?
        - Hold EXIT → Hard-Abbruch?
    */
    display_show("Lange gedrückt", 600);
}

```

### apps/autorecorder/Menu/Button/button_handler.h
<a name="appsautorecordermenubuttonbuttonhandlerh"></a>

- **Name:** `button_handler.h`
- **Pfad:** `apps/autorecorder/Menu/Button/button_handler.h`
- **SHA256:** `ef6abfcd8777fadd38e68d5715f02dc153cca2872b60757629e50ff67c39354e`

```
#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include <stdint.h>
#include <stdbool.h>

// Enum für interne Tasten
typedef enum {
    BTN_WRITE,
    BTN_EXIT,
    BTN_STOP,
    BTN_PLAY,
    BTN_SHIFT,
    BTN_NONE
} button_id_t;

// Wird vom Hardware-ISR oder Polling aufgerufen
void button_process(button_id_t btn, bool pressed);

// Interne Funktionen
void button_handle_single(button_id_t btn);
void button_handle_double(button_id_t btn);
void button_handle_long(button_id_t btn);

#endif

```

### apps/autorecorder/Menu/DAW/daw_nrpn_template.c
<a name="appsautorecordermenudawdawnrpntemplatec"></a>

- **Name:** `daw_nrpn_template.c`
- **Pfad:** `apps/autorecorder/Menu/DAW/daw_nrpn_template.c`
- **SHA256:** `da6c68ad0696bd3cde99cd303c02d920a852c26cace739acb5e45fb8285e794f`

```
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

```

### apps/autorecorder/Menu/DAW/daw_nrpn_template.h
<a name="appsautorecordermenudawdawnrpntemplateh"></a>

- **Name:** `daw_nrpn_template.h`
- **Pfad:** `apps/autorecorder/Menu/DAW/daw_nrpn_template.h`
- **SHA256:** `3484c58f353f01a84dbc89ad597712451f25276a9bfeb59639207c090f27d6ab`

```
#ifndef DAW_NRPN_TEMPLATE_H
#define DAW_NRPN_TEMPLATE_H

#include <stdint.h>

/*
    DAW NRPN Template
    =================

    Dieses Template beschreibt:

    - Welche NRPNs DAWs senden müssen
    - Wie Parameter gemappt werden
    - Welche Messages zurückkommen
*/

typedef struct {
    uint16_t nrpn_msb;
    uint16_t nrpn_lsb;
    const char *description;     /* Deutsch */
    const char *daw_hint;        /* DAW-spezifischer Hinweis */
} daw_nrpn_entry_t;

extern const daw_nrpn_entry_t g_daw_nrpn_map[];

#endif

```

### apps/autorecorder/Menu/Display/display_manager.c
<a name="appsautorecordermenudisplaydisplaymanagerc"></a>

- **Name:** `display_manager.c`
- **Pfad:** `apps/autorecorder/Menu/Display/display_manager.c`
- **SHA256:** `051c21fb5ae2db459e88776d6eb2749e11085526db84389c9f9b39e14622bbce`

```
#include "display_manager.h"

/* TODO: Hardware-spezifische Display-Funktionen eintragen */
extern void hw_display_clear(void);
extern void hw_display_text(const char *txt);
extern uint32_t ft_millis(void);

static uint32_t display_timeout = 0;
static display_page_t current_page = DISP_MAIN;

void display_show(const char *msg, uint16_t ms)
{
    hw_display_clear();
    hw_display_text(msg);
    display_timeout = ft_millis() + ms;
}

void display_set_page(display_page_t page)
{
    current_page = page;

    /* TODO: deutschsprachige Texte */
    switch (page) {
        case DISP_SAVE_CONFIRM:
            display_show("Speichern?  (WRITE)", 1200);
            break;

        case DISP_SAVE_SUCCESS:
            display_show("Speichern erfolgreich!", 1200);
            break;

        case DISP_SAVE_ERROR:
            display_show("Fehler beim Speichern!", 1500);
            break;

        case DISP_WARNING:
            display_show("Achtung!", 1000);
            break;

        default:
            break;
    }
}

void display_update(void)
{
    if (display_timeout && ft_millis() > display_timeout) {
        display_timeout = 0;
        hw_display_clear();
        current_page = DISP_MAIN;

        /* TODO: MAIN-SCREEN zeichnen */
    }
}

```

### apps/autorecorder/Menu/Display/display_manager.h
<a name="appsautorecordermenudisplaydisplaymanagerh"></a>

- **Name:** `display_manager.h`
- **Pfad:** `apps/autorecorder/Menu/Display/display_manager.h`
- **SHA256:** `90af3382852f4821a2f7e69947ec65011e27ec25f1c28a1dac3341cd924b3363`

```
#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <stdint.h>

void display_show(const char *msg, uint16_t ms);

/*
    TODO:
    - Display-Seiten Enums ergänzen
    - Menüstrukturen definieren
*/

typedef enum {
    DISP_MAIN,
    DISP_SAVE_CONFIRM,
    DISP_SAVE_SUCCESS,
    DISP_SAVE_ERROR,
    DISP_WARNING,
    DISP_CUSTOM
} display_page_t;

void display_set_page(display_page_t page);
void display_update(void);

#endif

```

### apps/autorecorder/Menu/Speichern/icons.h
<a name="appsautorecordermenuspeicherniconsh"></a>

- **Name:** `icons.h`
- **Pfad:** `apps/autorecorder/Menu/Speichern/icons.h`
- **SHA256:** `57faf6a60fc2279ae85072027716ba656c02299646dbbbe13aee6003a37b3401`

```
/* apps/autorecorder/Menu/Speichern/icons.h */
#ifndef SAVE_ICONS_H
#define SAVE_ICONS_H
#include <stdint.h>

/* 16x16 monochrome icon: Save (Floppy) */
static const uint8_t icon_save_16x16[] = {
    0x00,0x00,
    0x07,0xE0,
    0x08,0x10,
    0x10,0x08,
    0x10,0x08,
    0x10,0x08,
    0x10,0x08,
    0x10,0x08,
    0x10,0x08,
    0x10,0x08,
    0x10,0x08,
    0x10,0x08,
    0x08,0x10,
    0x07,0xE0,
    0x00,0x00,
    0x00,0x00
};

/* 16x16 monochrome icon: Confirm (check) */
static const uint8_t icon_confirm_16x16[] = {
    0x00,0x00,
    0x00,0x80,
    0x01,0xC0,
    0x03,0xE0,
    0x07,0xF0,
    0x0F,0xF8,
    0x1E,0xF8,
    0x3C,0x78,
    0x78,0x38,
    0x70,0x18,
    0x60,0x0C,
    0x40,0x06,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00
};

/* 16x16 monochrome icon: Cancel (X) */
static const uint8_t icon_cancel_16x16[] = {
    0x80,0x01,0xC0,0x03,0x60,0x06,0x30,0x0C,0x18,0x18,0x0C,0x30,0x06,0x60,0x03,0xC0,
    0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#endif /* SAVE_ICONS_H */

```

### apps/autorecorder/Menu/Speichern/nrpn_handler.c
<a name="appsautorecordermenuspeichernnrpnhandlerc"></a>

- **Name:** `nrpn_handler.c`
- **Pfad:** `apps/autorecorder/Menu/Speichern/nrpn_handler.c`
- **SHA256:** `829392e05ab2a8534830f627ea2c23447dad6e3a8080578034dee46bc0a6f3dd`

```
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
```

### apps/autorecorder/Menu/Speichern/save_manager.c
<a name="appsautorecordermenuspeichernsavemanagerc"></a>

- **Name:** `save_manager.c`
- **Pfad:** `apps/autorecorder/Menu/Speichern/save_manager.c`
- **SHA256:** `7caf2ac95fe735da257bc33592f3699c47b4523376a754f4574882074c6b1e20`

```
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

```

### apps/autorecorder/Menu/Speichern/save_manager.h
<a name="appsautorecordermenuspeichernsavemanagerh"></a>

- **Name:** `save_manager.h`
- **Pfad:** `apps/autorecorder/Menu/Speichern/save_manager.h`
- **SHA256:** `7dda2f1bfdada6c0fa106695410a0cb26308435ba12dee3f48124f2a3b05bea9`

```
#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include <stdint.h>

void save_manager_init(void);
int save_manager_request_save(uint8_t mode, const char *name);
void save_manager_confirm(int accept);
void save_manager_stream_name_byte(uint8_t b);
void save_manager_send_status(uint8_t status_code);
void save_manager_trigger_ui_save(uint8_t mode);

#endif /* SAVE_MANAGER_H */
```

### apps/autorecorder/Menu/Speichern/save_nrpn.h
<a name="appsautorecordermenuspeichernsavenrpnh"></a>

- **Name:** `save_nrpn.h`
- **Pfad:** `apps/autorecorder/Menu/Speichern/save_nrpn.h`
- **SHA256:** `c4afb18323ee6771e2b53206ddae3b74824c005f6579ce5de682bb955c6ed076`

```
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

```

### apps/autorecorder/midi_out.c
<a name="appsautorecordermidioutc"></a>

- **Name:** `midi_out.c`
- **Pfad:** `apps/autorecorder/midi_out.c`
- **SHA256:** `d1a2e01edd4367d4d85b2428afea7ad7679bec3e881960ddd27a18c6c03a5e85`

```
#include "midi_out.h"

/* Dummy-Ausgabe — später ersetzen durch echte UART/USART Ausgabe */
void midi_send_byte(uint8_t b)
{
    (void)b;
    /* TODO: Hardware UART Implementierung */
}

```

### apps/autorecorder/midi_out.h
<a name="appsautorecordermidiouth"></a>

- **Name:** `midi_out.h`
- **Pfad:** `apps/autorecorder/midi_out.h`
- **SHA256:** `57aad9208219f84b2d5fa66714ef6a778a289a701ddd4efa974b9787781aa3df`

```
#ifndef MIDI_OUT_H
#define MIDI_OUT_H

#include <stdint.h>

/* Placeholder: sendet ein einzelnes MIDI-Byte (TRS MIDI OUT) */
void midi_send_byte(uint8_t b);

#endif

```

### apps/autorecorder/mod_matrix.c
<a name="appsautorecordermodmatrixc"></a>

- **Name:** `mod_matrix.c`
- **Pfad:** `apps/autorecorder/mod_matrix.c`
- **SHA256:** `8ee5d493f5a1213097b81a3652d08588f23e378fe1dcc601048354f4acd171e3`

```
#include "mod_matrix.h"
#include "randomizer.h"
#include "rng.h"          // <-- FIX: rng_get is here
#include "ft_types.h"

mod_route_t g_staged_route;

static mod_route_t g_routes[MOD_MATRIX_MAX_ROUTES];
static int g_route_count = 0;

/* INIT */
void mod_matrix_init(void)
{
    g_route_count = 0;

    g_staged_route.src    = MOD_SRC_NONE;
    g_staged_route.dst    = MOD_DST_VELOCITY;
    g_staged_route.arg    = 0;
    g_staged_route.amount = 0;
}

/* STAGE BUILDERS */
void mod_matrix_stage_source(int src)         { g_staged_route.src = src; }
void mod_matrix_stage_destination(int dst)    { g_staged_route.dst = dst; }
void mod_matrix_stage_argument(int a)         { g_staged_route.arg = a; }
void mod_matrix_stage_amount(int amt)         { g_staged_route.amount = amt; }

/* COMMIT ROUTE */
void mod_matrix_commit_route(void)
{
    if (g_staged_route.src == MOD_SRC_NONE) return;
    if (g_route_count >= MOD_MATRIX_MAX_ROUTES) return;

    g_routes[g_route_count++] = g_staged_route;

    g_staged_route.src    = MOD_SRC_NONE;
    g_staged_route.dst    = MOD_DST_VELOCITY;
    g_staged_route.arg    = 0;
    g_staged_route.amount = 0;
}

/* REMOVE */
int mod_matrix_add(const mod_route_t *r)
{
    if (g_route_count >= MOD_MATRIX_MAX_ROUTES)
        return -1;

    g_routes[g_route_count] = *r;
    return g_route_count++;
}

int mod_matrix_remove(int idx)
{
    if (idx < 0 || idx >= g_route_count)
        return -1;

    for (int i = idx; i < g_route_count - 1; i++)
        g_routes[i] = g_routes[i + 1];

    g_route_count--;
    return 0;
}

int mod_matrix_clear(void)
{
    g_route_count = 0;
    return 0;
}

/* APPLY */
static inline int clamp(int v, int lo, int hi)
{
    return (v < lo) ? lo : (v > hi ? hi : v);
}

void mod_matrix_apply(ft_step_t *s, int ch, int step)
{
    for (int i = 0; i < g_route_count; i++) {
        const mod_route_t *r = &g_routes[i];
        int src_val = 0;

        switch (r->src)
        {
            case MOD_SRC_EUCLID_GATE:
                src_val = randomizer_get_euclid_value_public(ch, r->arg, step);
                break;

            case MOD_SRC_MOTION:
                src_val = randomizer_get_motion_value(r->arg, step);
                break;

            case MOD_SRC_RANDOM:
                src_val = (rng_get() & 0x7F);
                break;

            default:
                continue;
        }

        int delta = (src_val * r->amount) / 127;

        switch (r->dst)
        {
            case MOD_DST_VELOCITY:
                s->velocity = clamp(s->velocity + delta, 0, 127);
                break;

            case MOD_DST_PITCH:
                s->pitch = clamp(s->pitch + delta, 0, 127);
                break;

            case MOD_DST_GATE:
                s->gate = clamp(s->gate + delta, 0, 1);
                break;
        }
    }
}

```

### apps/autorecorder/mod_matrix.h
<a name="appsautorecordermodmatrixh"></a>

- **Name:** `mod_matrix.h`
- **Pfad:** `apps/autorecorder/mod_matrix.h`
- **SHA256:** `5407847b4133d74cc94c6c5a720289b9fac24539bd6c4806fc658ca2feec975f`

```
#ifndef MOD_MATRIX_H
#define MOD_MATRIX_H

#include <stdint.h>
#include "ft_types.h"        // <-- FIX: jetzt ft_step_t bekannt

#define MOD_MATRIX_MAX_ROUTES 32

/* ===== SOURCES ===== */
typedef enum {
    MOD_SRC_NONE = 0,
    MOD_SRC_EUCLID_GATE = 1,
    MOD_SRC_MOTION = 2,
    MOD_SRC_RANDOM = 3
} mod_source_t;

/* ===== DESTINATIONS ===== */
typedef enum {
    MOD_DST_VELOCITY = 0,
    MOD_DST_PITCH    = 1,
    MOD_DST_GATE     = 2
} mod_dest_t;

/* ===== MOD ROUTE ===== */
typedef struct {
    mod_source_t src;
    mod_dest_t   dst;
    int          arg;     /* lane / slot / channel index */
    int          amount;  /* -127..+127 */
} mod_route_t;

/* ===== STAGED ROUTE ===== */
extern mod_route_t g_staged_route;

/* ===== API ===== */
void mod_matrix_init(void);

void mod_matrix_stage_source(int src);
void mod_matrix_stage_destination(int dst);
void mod_matrix_stage_argument(int a);
void mod_matrix_stage_amount(int amt);
void mod_matrix_commit_route(void);

int  mod_matrix_add(const mod_route_t *r);
int  mod_matrix_remove(int idx);
int  mod_matrix_clear(void);

void mod_matrix_apply(ft_step_t *s, int ch, int step);

#endif

```

### apps/autorecorder/nrpn_router.c
<a name="appsautorecordernrpnrouterc"></a>

- **Name:** `nrpn_router.c`
- **Pfad:** `apps/autorecorder/nrpn_router.c`
- **SHA256:** `8b7d0b7de22db9ffe2a23f9900b4c19d3b561d27219ec37ef87509a99ab36ed3`

```
/* ============================================================
   apps/autorecorder/nrpn_router.c   (vollständig)
   + 3.2.3.13.4 – Final Defaults & Phase-3-Lock
   + 3.5.0.1    – Composer-NRPN-Mapping (MSB 52)
   ============================================================ */
#include <stdint.h>
#include <stdio.h>

#include "nrpn_router.h"
#include "randomizer.h"
#include "mod_matrix.h"
#include "condition_engine.h"
#include "condition_presets.h"
#include "live_fx.h"
#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "song_mode.h"
#include "ft_api.h"
#include "scale_engine.h"
#include "composer.h"
#include "groove_engine.h"
#include "composer_preview.h"


/* ============================================================
   NRPN TRANSACTION GUARD
   ============================================================ */

#define NRPN_TX_TIMEOUT_TICKS   5
#define NRPN_MIN_GAP_TICKS     25

typedef struct {
    int msb;
    int lsb;
    uint32_t last_tick;
    uint8_t active;
} nrpn_tx_state_t;

static nrpn_tx_state_t g_nrpn = {
    .msb = -1,
    .lsb = -1,
    .last_tick = 0,
    .active = 0
};

/* Condition staging */
static int g_cond_part = 0;
static int g_cond_step = 0;

/* Composer staging (3.5.0.1) */
static uint8_t g_cmp_section   = 0;   /* 0..4 */
static uint8_t g_cmp_segment   = 0;   /* 0..3 */
static uint8_t g_cmp_startpage = 0;   /* 0..127 */

/* ============================================================
   INTERNAL HELPERS
   ============================================================ */

static inline void nrpn_tx_reset(void)
{
    g_nrpn.msb = -1;
    g_nrpn.lsb = -1;
    g_nrpn.active = 0;
}

static inline void nrpn_tx_check_timeout(uint32_t now)
{
    if (g_nrpn.active &&
        (now - g_nrpn.last_tick) > NRPN_TX_TIMEOUT_TICKS)
    {
        nrpn_tx_reset();
    }
}

static inline uint16_t nrpn_build_id(void)
{
    if (g_nrpn.msb < 0 || g_nrpn.lsb < 0)
        return 0xFFFF;

    return (uint16_t)((g_nrpn.msb << 7) | g_nrpn.lsb);
}

static inline uint8_t clamp_u8(int v, int lo, int hi)
{
    if (v < lo) return (uint8_t)lo;
    if (v > hi) return (uint8_t)hi;
    return (uint8_t)v;
}

/* ============================================================
   NRPN DISPATCH
   ============================================================ */

static void nrpn_dispatch(uint16_t nrpn, int value)
{
    uint8_t msb = (uint8_t)(nrpn >> 7);
    uint8_t lsb = (uint8_t)(nrpn & 0x7F);

    /* --------------------------------------------------------
       MSB 40 — Randomizer Core
       -------------------------------------------------------- */
    if (msb == 40)
    {
        switch (lsb)
        {
            case 10: randomizer_set_density(value);   return;
            case 11: randomizer_set_variation(value); return;
            case 15: randomizer_set_freeze(value);    return;
            case 20: randomizer_set_section(value);   return;
            case 80: randomizer_set_seed(value);      return;
        }
        return;
    }

    /* --------------------------------------------------------
       MSB 41 — Global / Write / Song / Clear
       -------------------------------------------------------- */
    if (msb == 41)
    {
        switch (lsb)
        {
            case 0:
                if (value == 1)
                {
                    int ps = pattern_get_paging_page_size();
                    int pg = pattern_get_active_page();
                    for (int p = 0; p < RANDOMIZER_MAX_CHANNELS; ++p)
                        randomize_and_write_pattern_paged(
                            p, ps,
                            randomizer_get_section(),
                            pg
                        );
                }
                return;

            case 3:
                randomize_and_write_pattern_paged(
                    value,
                    pattern_get_paging_page_size(),
                    randomizer_get_section(),
                    pattern_get_active_page()
                );
                return;

            case 6:
                if (value == 1)
                    randomizer_undo_last_public();
                return;

            case 30:
                song_mode_handle_nrpn(70, value);
                return;

            case 50:
                pattern_clear_nrpn(value == 127 ? -1 : value);
                return;
        }
        return;
    }

    /* --------------------------------------------------------
       MSB 50 — Condition / Randomizer Extensions / Debug
       -------------------------------------------------------- */
    if (msb == 50)
    {
        switch (lsb)
        {
            /* Condition addressing */
            case 90: g_cond_part = value; nrpn_condition_stage_part(value); return;
            case 91: g_cond_step = value; nrpn_condition_stage_step(value); return;

            /* Node staging */
            case 92: nrpn_condition_stage_node(value); return;
            case 94: nrpn_condition_commit(); return;

            /* Node editing */
            case 93: nrpn_condition_node_create(value); return;
            case 95: nrpn_condition_node_set_param(value); return;
            case 96: nrpn_condition_node_to_and(value); return;
            case 97: nrpn_condition_node_to_or(value); return;
            case 98: nrpn_condition_node_to_not(); return;
            case 99: nrpn_condition_node_delete(value); return;

            /* Phase 3.2.1 — Per-Step Probability */
            case 110:
                condition_set_step_probability(
                    g_cond_part,
                    g_cond_step,
                    value
                );
                return;

            /* Phase 3.2.2 — Step Repeater */
            case 111:
                randomizer_set_step_repeat(
                    g_cond_part,
                    g_cond_step,
                    value
                );
                return;

            /* Phase 3.1.5 — Condition Preset Browser */
            case 112: condition_preset_select(value); return;
            case 113: condition_preset_set_param(value); return;
            case 114: if (value == 1) condition_preset_apply_to_staged_step(); return;
            case 115: if (value == 1) condition_preset_dump(); return;

            /* Debug Visualizer */
            case 120: condition_debug_enable(value); return;
            case 121: condition_debug_select(value, g_cond_step); return;
            case 122: condition_debug_select(g_cond_part, value); return;
            case 123: condition_debug_dump_step(); return;
            case 124: condition_debug_dump_node(value); return;

            /* Live FX */
            case 60: live_fx_set_variation_boost(value); return;
            case 61: live_fx_trigger_fill_now(); return;
            case 62: live_fx_set_mutation(value); return;
        }
        return;
    }

    /* --------------------------------------------------------
       MSB 51 — Groove Engine
       -------------------------------------------------------- */
    if (msb == 51)
    {
        switch (lsb)
        {
            /* 3.2.3.2 Micro-Timing Amount */
            case 3:
                groove_set_timing_amount((uint8_t)(value & 0x7F));
                return;

            /* 3.2.3.3 Velocity Swing Amount */
            case 4:
                groove_set_velocity_amount((uint8_t)(value & 0x7F));
                return;

            /* 3.2.3.12 One-Knob Macro */
            case 20:
                groove_set_macro((uint8_t)(value & 0x7F));
                return;

            /* 3.2.3.13.4 Phase-3 Lock (Enable) */
            case 21:
                groove_set_enabled((uint8_t)(value ? 1 : 0));
                return;
        }
        return;
    }

/* --------------------------------------------------------
   MSB 52 — Composer Engine
   -------------------------------------------------------- */
if (msb == 52)
{
    static uint8_t c_section = SECTION_MAIN;
    static uint8_t c_segment = 0;

    switch (lsb)
    {
        case 0: /* Genre */
            composer_set_genre(value);
            return;

        case 1: /* Section */
            if (value <= SECTION_OUTRO)
                c_section = (composer_section_t)value;
            return;

        case 2: /* Segment */
            c_segment = value & 0x03;
            return;

        case 10: /* Generate Segment */
            if (value == 1)
                composer_generate_segment(
                    composer_get_genre(),
                    c_section,
                    c_segment,
                    pattern_get_active_page()
                );
            return;

        case 11: /* Generate Section */
            if (value == 1)
                composer_generate_section(
                    composer_get_genre(),
                    c_section,
                    pattern_get_active_page()
                );
            return;

        case 12: /* Generate Song */
            if (value == 1)
                composer_generate_song(
                    composer_get_genre(),
                    pattern_get_active_page()
                );
            return;

        case 20: /* Preset Recall (Policy only) */
            if (value == 1)
                composer_preset_recall(
                    composer_get_genre(),
                    c_section,
                    c_segment
                );
            return;

        case 30: composer_preview_enable(value); return;
        case 31: if (value == 1) composer_preview_reset(); return;
        case 32: composer_preview_set_bar(value); return;


    }
    return;
}
}

/* ============================================================
   PUBLIC MIDI CC → NRPN ENTRY
   ============================================================ */

void nrpn_handle(int channel, int cc, int value)
{
    (void)channel;

    uint32_t now = ft_get_ticks();
    nrpn_tx_check_timeout(now);

    if (cc == 99)
    {
        g_nrpn.msb = value & 0x7F;
        g_nrpn.active = 1;
        g_nrpn.last_tick = now;
        return;
    }

    if (cc == 98 && g_nrpn.active)
    {
        g_nrpn.lsb = value & 0x7F;
        g_nrpn.last_tick = now;
        return;
    }

    if ((cc == 6 || cc == 38) && g_nrpn.active)
    {
        uint16_t id = nrpn_build_id();
        if (id != 0xFFFF)
            nrpn_dispatch(id, value & 0x7F);

        nrpn_tx_reset();
    }
}

void nrpn_router_tick(void)
{
    /* reserved */
}

```

### apps/autorecorder/nrpn_router.h
<a name="appsautorecordernrpnrouterh"></a>

- **Name:** `nrpn_router.h`
- **Pfad:** `apps/autorecorder/nrpn_router.h`
- **SHA256:** `bd4580e9b385c56dd715ce156a0fbddebf0609d7c79cbb68f4a69afe07852b7d`

```
#ifndef NRPN_ROUTER_H
#define NRPN_ROUTER_H

#include <stdint.h>

/*
 * NRPN Router – Transaction-safe
 *
 * Unterstützt 2 Aufrufarten (ohne API-Sprung):
 *
 *  A) CC-Stream (empfohlen, DAW: CC99/CC98/CC6 (+CC38)):
 *     nrpn_handle(channel, cc, value)
 *     → erkennt automatisch CC99/98/6/38 und verwaltet Transaction-State.
 *
 *  B) Direkt (bereits dekodiertes NRPN):
 *     nrpn_handle(msb, lsb, value)
 *     → wenn "cc" NICHT 99/98/6/38 ist, wird es als (msb,lsb,value) interpretiert.
 *
 * Fail-safe:
 *  - unvollständige Sequenzen werden verworfen (Timeout)
 *  - keine halben Commits
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Polymorpher Entry: siehe Kommentar oben */
void nrpn_handle(int a, int b, int c);

/* Optional tick hook (z.B. 1x pro Frame), um Timeouts abzuräumen */
void nrpn_router_tick(void);

#ifdef __cplusplus
}
#endif

#endif /* NRPN_ROUTER_H */

```

### apps/autorecorder/panel_hooks.h
<a name="appsautorecorderpanelhooksh"></a>

- **Name:** `panel_hooks.h`
- **Pfad:** `apps/autorecorder/panel_hooks.h`
- **SHA256:** `0809928ee642de397af904dd876fc8eb3951339fc37724425cb568d67fc3b732`

```
#ifndef PANEL_HOOKS_H
#define PANEL_HOOKS_H

#include <stdint.h>
#include "ft_config.h"

// Firmware panel handler signature
typedef void (*panel_handler_t)(unsigned char *pkt, int len, unsigned int a, unsigned int b);

// Send any raw panel event to firmware
static inline void panel_send_raw(void* handler, uint8_t code, uint8_t arg1, uint8_t arg2)
{
    panel_handler_t h = (panel_handler_t)handler;
    if (!h) return;

    unsigned char pkt[12] = {0};
    pkt[0] = code;
    pkt[1] = arg1;
    pkt[2] = arg2;

    h(pkt, sizeof(pkt), 0, 0);
}

// ==========================
// OFFIZIELLE ELECTRIBE BUTTONS
// ==========================
static inline void panel_play(void)
{
    panel_send_raw(ADDR_PLAY_HANDLER, 0x50, 0, 0);
}

static inline void panel_record(void)
{
    panel_send_raw(ADDR_RECORD_HANDLER, 0x52, 0, 0);
}

static inline void panel_stop(void)
{
    panel_send_raw(ADDR_STOP_HANDLER, 0x53, 0, 0);
}

static inline void panel_write(void)
{
    panel_send_raw(ADDR_WRITE_HANDLER, 0x57, 0, 0);
}

// ==========================
// VERSTECKTE CUSTOM PANEL SLOTS (0x52–0x57)
// ==========================
// Diese existieren laut Disassembly & Paket4
static inline void panel_custom(uint8_t panel_id, uint8_t a, uint8_t b)
{
    if (panel_id < 0x52 || panel_id > 0x57)
        return;

    panel_send_raw(ADDR_RECORD_HANDLER, panel_id, a, b);
}

#endif

```

### apps/autorecorder/pattern_clear.c
<a name="appsautorecorderpatternclearc"></a>

- **Name:** `pattern_clear.c`
- **Pfad:** `apps/autorecorder/pattern_clear.c`
- **SHA256:** `8aabeb81d8c1a993a0f6330e682e38117790c4ce1303cb1262704d8b8bd62531`

```
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

```

### apps/autorecorder/pattern_ram_map.c
<a name="appsautorecorderpatternrammapc"></a>

- **Name:** `pattern_ram_map.c`
- **Pfad:** `apps/autorecorder/pattern_ram_map.c`
- **SHA256:** `0150fd0e306bf41f1d520c91905d5c88d28459c978c4a1a7eb131be1b3d4c987`

```
#include "pattern_ram_map.h"
#include "ft_types.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
 * Pattern RAM Mapper (Hardened Version)
 *
 * Goals:
 *  - Always write/read full ft_step_t
 *  - Prevent out-of-bounds access via capacity tracking
 *  - Keep API stable (only additive helper function)
 *  - Optional debug guard prints (compile-time)
 */

/* =========================
   CONFIG: Debug Guards
   ========================= */
#ifndef PATTERN_RAM_MAP_DEBUG
#define PATTERN_RAM_MAP_DEBUG 0
#endif

#if PATTERN_RAM_MAP_DEBUG
#include "ft_api.h"
#define PRM_DBG(...) ft_print(__VA_ARGS__)
#else
#define PRM_DBG(...) do{}while(0)
#endif

/* =========================
   INTERNAL STATE
   ========================= */
static bool     g_enabled      = true;
static uint8_t *g_base         = NULL;
static size_t   g_step_size    = 0;      /* should be sizeof(ft_step_t) */
static size_t   g_capacity_b   = 0;      /* size of RAM region in bytes */

/* fallback buffer (default) */
#define FALLBACK_STEPS 1024

/* =========================
   INTERNAL HELPERS
   ========================= */
static inline size_t step_size_safe(void)
{
    return (g_step_size != 0) ? g_step_size : sizeof(ft_step_t);
}

static inline size_t max_steps_safe(void)
{
    size_t ss = step_size_safe();
    if (!g_base || ss == 0 || g_capacity_b < ss) return 0;
    return g_capacity_b / ss;
}

static inline bool idx_in_range(int idx)
{
    if (idx < 0) return false;
    size_t maxs = max_steps_safe();
    return ((size_t)idx < maxs);
}

/* =========================
   PUBLIC API
   ========================= */
void pattern_ram_map_init(void)
{
    g_step_size = sizeof(ft_step_t);

    /* Provide fallback storage if not set */
    if (!g_base)
    {
        static uint8_t fallback_ram[sizeof(ft_step_t) * FALLBACK_STEPS];
        g_base = fallback_ram;
        g_capacity_b = sizeof(fallback_ram);
    }
    else
    {
        /* If base is already set but capacity not, we cannot safely bounds-check.
           Keep available, but warn in debug mode. */
        if (g_capacity_b == 0)
            PRM_DBG("[pattern_ram_map] WARN: base set without capacity; bounds checks limited.\n");
    }

    g_enabled = true;
}

bool pattern_ram_map_is_available(void)
{
    return g_enabled && (g_base != NULL);
}

void pattern_ram_map_set_base(void *addr)
{
    g_base = (uint8_t *)addr;
    /* legacy setter: capacity unknown -> no hard bounds possible unless user calls set_base_ex */
    g_capacity_b = 0;
#if PATTERN_RAM_MAP_DEBUG
    PRM_DBG("[pattern_ram_map] set_base(addr=%p) capacity=UNKNOWN\n", addr);
#endif
}

/* NEW (additive, safe): set base + size */
void pattern_ram_map_set_base_ex(void *addr, size_t bytes)
{
    g_base = (uint8_t *)addr;
    g_capacity_b = bytes;
#if PATTERN_RAM_MAP_DEBUG
    PRM_DBG("[pattern_ram_map] set_base_ex(addr=%p, bytes=%u)\n", addr, (unsigned)bytes);
#endif
}

void pattern_ram_map_enable(bool enable)
{
    g_enabled = enable;
}

size_t pattern_ram_step_size(void)
{
    return step_size_safe();
}

size_t pattern_ram_max_steps(void)
{
    return max_steps_safe();
}

uint8_t *pattern_ram_step_address(int idx)
{
    if (!g_enabled || !g_base)
        return NULL;

    /* If capacity unknown, we can only compute address (legacy behavior).
       If capacity known, enforce bounds. */
    if (g_capacity_b != 0)
    {
        if (!idx_in_range(idx))
        {
            PRM_DBG("[pattern_ram_map] OOB step_address idx=%d (max=%u)\n",
                    idx, (unsigned)max_steps_safe());
            return NULL;
        }
    }
    else
    {
        /* Capacity unknown: cannot bounds-check */
        if (idx < 0) return NULL;
    }

    size_t ss = step_size_safe();
    return g_base + ((size_t)idx * ss);
}

/* Write full ft_step_t to RAM */
int pattern_ram_write_step(int part, int idx, const ft_step_t *s)
{
    (void)part;

    if (!g_enabled || !g_base || !s)
        return 0;

    /* If we know capacity, enforce bounds strictly */
    if (g_capacity_b != 0 && !idx_in_range(idx))
    {
        PRM_DBG("[pattern_ram_map] OOB write idx=%d (max=%u)\n",
                idx, (unsigned)max_steps_safe());
        return 0;
    }

    /* Legacy mode (capacity unknown): best effort but still require non-negative index */
    if (g_capacity_b == 0 && idx < 0)
        return 0;

    uint8_t *p = pattern_ram_step_address(idx);
    if (!p)
        return 0;

    memcpy(p, s, sizeof(ft_step_t));
    return 1;
}

/* NEW (additive): Read full ft_step_t from RAM */
int pattern_ram_read_step(int idx, ft_step_t *out)
{
    if (!g_enabled || !g_base || !out)
        return 0;

    if (g_capacity_b != 0 && !idx_in_range(idx))
    {
        PRM_DBG("[pattern_ram_map] OOB read idx=%d (max=%u)\n",
                idx, (unsigned)max_steps_safe());
        return 0;
    }

    if (g_capacity_b == 0 && idx < 0)
        return 0;

    uint8_t *p = pattern_ram_step_address(idx);
    if (!p)
        return 0;

    memcpy(out, p, sizeof(ft_step_t));
    return 1;
}
typedef struct {
    uint8_t gate;
    uint8_t velocity;
    uint8_t repeat;   // 1 = normal, >1 = Step Repeater
} ft_step_ext_t;

```

### apps/autorecorder/pattern_ram_map.h
<a name="appsautorecorderpatternrammaph"></a>

- **Name:** `pattern_ram_map.h`
- **Pfad:** `apps/autorecorder/pattern_ram_map.h`
- **SHA256:** `8f504d5bd091ba3ae731be2708f667b4ee4d7b1032cef1f991d7a528bf571da7`

```
#ifndef PATTERN_RAM_MAP_H
#define PATTERN_RAM_MAP_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "ft_types.h"

/*
 * Pattern RAM Map API
 *
 * - Legacy compatible:
 *   pattern_ram_map_set_base(void*)
 *
 * - Hardened optional:
 *   pattern_ram_map_set_base_ex(void*, size_t bytes)
 *   pattern_ram_max_steps()
 *   pattern_ram_read_step()
 */

void   pattern_ram_map_init(void);
bool   pattern_ram_map_is_available(void);

void   pattern_ram_map_set_base(void *addr);

/* NEW (additive, recommended): provide RAM region size for bounds checks */
void   pattern_ram_map_set_base_ex(void *addr, size_t bytes);

void   pattern_ram_map_enable(bool enable);

size_t pattern_ram_step_size(void);

/* NEW (additive): known max steps if capacity provided, else 0 */
size_t pattern_ram_max_steps(void);

uint8_t *pattern_ram_step_address(int physical_index);

int    pattern_ram_write_step(int part, int physical_index, const ft_step_t *s);

/* NEW (additive): safe read helper */
int    pattern_ram_read_step(int physical_index, ft_step_t *out);

#endif /* PATTERN_RAM_MAP_H */

```

### apps/autorecorder/pattern_stubs.c
<a name="appsautorecorderpatternstubsc"></a>

- **Name:** `pattern_stubs.c`
- **Pfad:** `apps/autorecorder/pattern_stubs.c`
- **SHA256:** `7791c937c75d7e8c50407d02465e908e18eef8769afb6a3d88176bf7efb3ba5f`

```
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "ft_api.h"
#include "pattern_writer.h"

/* ===================================================================
   Correct Stub/Fallback Implementation Matching pattern_writer.h
   ===================================================================
   Headers declare:

      int pattern_write_rle_batch(int part,
                                  const ft_step_t *steps,
                                  int nsteps,
                                  int target_page);

      int pattern_write_compressed(int part,
                                   const ft_step_t *steps,
                                   int nsteps,
                                   int target_page);

   Therefore we MUST match these exact signatures.
   =================================================================== */


/* ------------------------------------------------------------
   Fallback RLE Writer
   ------------------------------------------------------------ */
__attribute__((weak))
int pattern_write_rle_batch(int part, const ft_step_t *steps, int nsteps, int target_page)
{
    if (!steps || nsteps <= 0) {
        ft_print("[WARN] pattern_write_rle_batch: invalid args\n");
        return -1;
    }

    /* fallback = direct page-write */
    int w = pattern_write_page(part, steps, nsteps, target_page);
    if (w != nsteps) {
        ft_print("[WARN] pattern_write_rle_batch fallback mismatch\n");
    }
    return w;
}


/* ------------------------------------------------------------
   Fallback Compressed Writer
   ------------------------------------------------------------ */
__attribute__((weak))
int pattern_write_compressed(int part, const ft_step_t *steps, int nsteps, int target_page)
{
    if (!steps || nsteps <= 0) {
        ft_print("[WARN] pattern_write_compressed: invalid args\n");
        return -1;
    }

    int w = pattern_write_page(part, steps, nsteps, target_page);
    if (w != nsteps) {
        ft_print("[WARN] pattern_write_compressed fallback mismatch\n");
    }
    return w;
}


/* ------------------------------------------------------------
   Fallback: ft_write_pattern()
   ------------------------------------------------------------ */
__attribute__((weak))
int ft_write_pattern(int part, const ft_step_t *steps, int nsteps)
{
    if (!steps || nsteps <= 0) {
        ft_print("[WARN] ft_write_pattern: invalid args\n");
        return -1;
    }

    int page = pattern_get_active_page();
    int w = pattern_write_page(part, steps, nsteps, page);
    if (w != nsteps) {
        ft_print("[WARN] ft_write_pattern fallback mismatch\n");
    }

    return w;
}

```

### apps/autorecorder/pattern_transform.c
<a name="appsautorecorderpatterntransformc"></a>

- **Name:** `pattern_transform.c`
- **Pfad:** `apps/autorecorder/pattern_transform.c`
- **SHA256:** `2c73899a4740a8b86cbb93785ae1f49c94da0726ba0a3e1fde2b76870b2cf75f`

```
#include "pattern_transform.h"
#include "pattern_writer.h"   /* FIX: makes paging/read/write explicit */
#include <string.h>
#include <stdlib.h>

/* get step count dynamically */
static int get_step_count_for_part(int part)
{
    (void)part;
    int ps = pattern_get_paging_page_size();
    if (ps <= 0) ps = 64;
    return ps;
}

void transform_rotate(int part, int amount)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;
    amount = (amount % n + n) % n;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    ft_step_t *src = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf || !src) { free(buf); free(src); return; }

    pattern_read_steps(part, src, n);

    for (int i = 0; i < n; ++i)
        buf[(i + amount) % n] = src[i];

    pattern_write_steps(part, buf, n);

    free(buf); free(src);
}

void transform_mirror(int part)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    ft_step_t *src = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf || !src) { free(buf); free(src); return; }

    pattern_read_steps(part, src, n);

    for (int i = 0; i < n; ++i)
        buf[i] = src[n - 1 - i];

    pattern_write_steps(part, buf, n);

    free(buf); free(src);
}

void transform_invert(int part)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf) return;

    pattern_read_steps(part, buf, n);

    for (int i = 0; i < n; ++i)
        buf[i].gate = (buf[i].gate > 0) ? 0 : 100;

    pattern_write_steps(part, buf, n);

    free(buf);
}

void transform_scale_steps(int part, int scale)
{
    if (scale <= 0) return;

    int old = get_step_count_for_part(part);
    if (old <= 0) return;

    int new_count = old * scale;

    ft_step_t *src = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)old);
    ft_step_t *dst = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)new_count);
    if (!src || !dst) { free(src); free(dst); return; }

    pattern_read_steps(part, src, old);

    for (int i = 0; i < new_count; ++i)
        dst[i] = src[i / scale];

    pattern_write_steps(part, dst, new_count);

    free(src); free(dst);
}

void transform_humanize(int part, int vel_amt, int pitch_amt)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf) return;

    pattern_read_steps(part, buf, n);

    for (int i = 0; i < n; ++i) {
        if (vel_amt > 0) buf[i].velocity += (rand() % vel_amt) - vel_amt/2;
        if (pitch_amt > 0) buf[i].pitch  += (rand() % pitch_amt) - pitch_amt/2;
    }

    pattern_write_steps(part, buf, n);
    free(buf);
}

void transform_euclidean(int part, int fills, int total_steps)
{
    int n = get_step_count_for_part(part);
    if (n <= 0) return;

    ft_step_t *buf = (ft_step_t *)malloc(sizeof(ft_step_t) * (size_t)n);
    if (!buf) return;

    memset(buf, 0, sizeof(ft_step_t) * (size_t)n);

    if (fills < 0) fills = 0;
    if (total_steps <= 0) total_steps = n;

    for (int i = 0; i < fills; ++i) {
        int idx = (i * total_steps) / (fills ? fills : 1);
        if (idx >= 0 && idx < n) {
            buf[idx].part = (uint8_t)part;
            buf[idx].step = (uint8_t)idx;
            buf[idx].gate = 100;
        }
    }

    pattern_write_steps(part, buf, n);
    free(buf);
}

/* Apply global transform pipeline */
void pattern_transform_apply(int part, ft_step_t *steps, int count)
{
    (void)part;
    (void)steps;
    (void)count;
    /* reserved */
}

```

### apps/autorecorder/pattern_transform.h
<a name="appsautorecorderpatterntransformh"></a>

- **Name:** `pattern_transform.h`
- **Pfad:** `apps/autorecorder/pattern_transform.h`
- **SHA256:** `507cc122c8ece00bd8b181c7a6afdf986b267cc016ecde4b2f06c4cf5c9d0312`

```
#ifndef PATTERN_TRANSFORM_H
#define PATTERN_TRANSFORM_H

#include <stdint.h>
#include "pattern_writer.h"

void transform_rotate(int part, int amount);
void transform_mirror(int part);
void transform_invert(int part);
void transform_scale_steps(int part, int scale);
void transform_humanize(int part, int vel_amt, int pitch_amt);

void transform_euclidean(int part, int fills, int total_steps);

void pattern_transform_apply(int part, ft_step_t *steps, int count);

#endif

```

### apps/autorecorder/pattern_write_dummy.c
<a name="appsautorecorderpatternwritedummyc"></a>

- **Name:** `pattern_write_dummy.c`
- **Pfad:** `apps/autorecorder/pattern_write_dummy.c`
- **SHA256:** `433ddbef6ab71ceabb61bc2807064293d883e2418091d7201bfc7914cd5b56ac`

```
#include "pattern_writer.h"

/* Weak fallback:
   Real implementation may live in freetribe_save_bundle.c (strong symbol).
   If real one is linked, this will be ignored automatically. */

__attribute__((weak))
int pattern_write_pattern(int part, const ft_step_t *steps, int count)
{
    (void)part; (void)steps; (void)count;
    return -1;
}

```

### apps/autorecorder/pattern_writer.c
<a name="appsautorecorderpatternwriterc"></a>

- **Name:** `pattern_writer.c`
- **Pfad:** `apps/autorecorder/pattern_writer.c`
- **SHA256:** `6f7b97eb625240797ab7964ec8c454d01487ba76b7336621a70f6819d113c4ee`

```
#include "pattern_writer.h"
#include "pattern_ram_map.h"
#include "ft_config.h"
#include "ft_api.h"

#include <string.h>
#include <stdlib.h>

/* Active page index */
static int g_active_page = 0;
/* Default page size (may be overridden by firmware calls / config) */
static int g_page_size   = FT_DEFAULT_PAGE_SIZE;

/* -------------------------------------------------------------
   Internal helpers
   ------------------------------------------------------------- */
static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static inline int safe_page_size(void)
{
    int ps = g_page_size;
    if (ps <= 0) ps = 64;
    return ps;
}

/* -------------------------------------------------------------------
   Page helpers
   ------------------------------------------------------------------- */
int pattern_get_paging_page_size(void)
{
    return safe_page_size();
}

int pattern_get_active_page(void)
{
    return g_active_page;
}

void pattern_set_active_page(int page)
{
    if (page < 0) page = 0;
    g_active_page = page;
}

/* Compatibility: some modules call this name and expect int return */
int pattern_set_current_page(int page)
{
    pattern_set_active_page(page);
    return g_active_page;
}

/* -------------------------------------------------------------------
   STEP READ API
   ------------------------------------------------------------------- */

/* Low-level reader for entire page or segment */
int pattern_read_page(int part, ft_step_t *dst, int nsteps, int page)
{
    if (!dst || nsteps <= 0) return 0;

    int ps = safe_page_size();
    if (nsteps > ps) nsteps = ps;
    if (page < 0) page = 0;

    int offset = page * ps;

    /* If RAM map is available, read from RAM */
    if (pattern_ram_map_is_available())
    {
        for (int i = 0; i < nsteps; ++i)
        {
            ft_step_t tmp;
            int ok = 0;

            /* Prefer hardened helper if present */
            ok = pattern_ram_read_step(offset + i, &tmp);

            if (!ok)
            {
                memset(&dst[i], 0, sizeof(ft_step_t));
                dst[i].part = (uint8_t)part;
                dst[i].step = (uint8_t)i;
                continue;
            }

            /* Keep stored values, but enforce caller expectation:
               - correct part
               - step index relative to page (0..ps-1) */
            tmp.part = (uint8_t)part;
            tmp.step = (uint8_t)i;

            dst[i] = tmp;
        }

        return nsteps;
    }

    /* fallback: blank steps */
    memset(dst, 0, sizeof(ft_step_t) * (size_t)nsteps);
    for (int i = 0; i < nsteps; ++i) {
        dst[i].part = (uint8_t)part;
        dst[i].step = (uint8_t)i;
    }
    return nsteps;
}

/* High-level read for current active page */
int pattern_read_steps(int part, ft_step_t *dst, int n)
{
    if (!dst || n <= 0) return 0;
    return pattern_read_page(part, dst, n, g_active_page);
}

/* -------------------------------------------------------------------
   STEP WRITE API
   ------------------------------------------------------------------- */

/* Low-level write to specific page index */
int pattern_write_page(int part, const ft_step_t *src, int nsteps, int page)
{
    if (!src || nsteps <= 0) return 0;

    int ps = safe_page_size();
    if (nsteps > ps) nsteps = ps;
    if (page < 0) page = 0;

    int offset = page * ps;

    /* RAM write if available */
    if (pattern_ram_map_is_available())
    {
        for (int i = 0; i < nsteps; ++i)
        {
            ft_step_t tmp;
            memcpy(&tmp, &src[i], sizeof(ft_step_t));

            /* enforce canonical fields */
            tmp.part = (uint8_t)part;
            tmp.step = (uint8_t)i;

            pattern_ram_write_step(part, offset + i, &tmp);
        }
        return nsteps;
    }

    /* fallback: use firmware write */
    for (int i = 0; i < nsteps; ++i)
    {
        ft_step_t tmp = src[i];
        tmp.part = (uint8_t)part;
        tmp.step = (uint8_t)i;
        (void)ft_write_step(&tmp);
    }

    return nsteps;
}

/* High-level write wrapper (writes a block starting at step 0 of the active page) */
int pattern_write_steps(int part, const ft_step_t *src, int n)
{
    if (!src || n <= 0) return 0;
    return pattern_write_page(part, src, n, g_active_page);
}

/* -------------------------------------------------------------------
   Single-step writer (FIXED)
   IMPORTANT: Must write to the requested step index, not always step 0.
   ------------------------------------------------------------------- */
int pattern_write_step(int part, int step, int pitch, int velocity, int gate)
{
    int ps = safe_page_size();
    step = clampi(step, 0, ps - 1);

    ft_step_t s;
    memset(&s, 0, sizeof(s));
    s.part     = (uint8_t)part;
    s.step     = (uint8_t)step;
    s.pitch    = (uint8_t)pitch;
    s.velocity = (uint8_t)velocity;
    s.gate     = (uint8_t)gate;

    /* If RAM is available, write directly at correct physical index */
    if (pattern_ram_map_is_available())
    {
        int offset = g_active_page * ps;
        return pattern_ram_write_step(part, offset + step, &s);
    }

    /* firmware fallback */
    return (int)ft_write_step(&s);
}

/* -------------------------------------------------------------
   Compatibility shim: set pattern (page) number
   (Some firmware hooks call this)
   ------------------------------------------------------------- */
void set_pattern_number(int pat)
{
    pattern_set_active_page(pat);
}

```

### apps/autorecorder/randomizer.c
<a name="appsautorecorderrandomizerc"></a>

- **Name:** `randomizer.c`
- **Pfad:** `apps/autorecorder/randomizer.c`
- **SHA256:** `be957ef08ef1efeadb40d23f1d3d7b841fb23474b342d191e5356f9dcb125cde`

```
/* randomizer.c  (PHASE 3.5.4 – Step 3+4 merged)
   - Step 3: “Micro-Timing Drift” (Humanizer-reuse, Timeline-Scope)  ✅
     -> implemented as deterministic per-Part/per-Bar drift that modulates
        velocity + gate slightly (no new structure decisions, no RNG bleed).
   - Step 4: Preview == Write == Playback ✅
     -> generation uses an internal deterministic PRNG (does NOT touch rng.c global state),
        so preview/write/playback see identical results for same inputs.
*/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "ft_types.h"
#include "pattern_writer.h"
#include "randomizer.h"

/* ============================================================
   INTERNAL FORWARD DECLS
   ============================================================ */
static void undo_clear_entry(randomizer_undo_entry_t *u);
static void undo_push(int part, int page,
                      const ft_step_t *steps, int n);

/* ============================================================
   GLOBAL STATE
   ============================================================ */

/* Global Euclid storage used by randomizer_euclid.c */
eu_channel_t g_eu_channels[RANDOMIZER_MAX_CHANNELS];

/* Core */
static uint32_t g_seed = 0xC0FFEEu;
static int g_density   = 100;
static int g_variation = 0;
static int g_freeze    = 0;
static int g_section   = 0;

/* Composer → Randomizer policy flags */
static randomizer_policy_flags_t g_policy_flags = 0;

/* Part usage mask */
static uint16_t g_part_used_mask = 0;

/* Undo */
static randomizer_undo_entry_t g_undo[RANDOMIZER_UNDO_SLOTS];
static int g_undo_top = 0;

/* Step repeater */
static uint8_t g_step_repeat
    [RANDOMIZER_MAX_CHANNELS]
    [RANDOMIZER_MAX_STEPS];

/* ============================================================
   HELPERS
   ============================================================ */

static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ============================================================
   DETERMINISTIC LOCAL PRNG (Step 4: Preview == Write == Playback)
   ============================================================ */
/* xorshift32 – fast, deterministic, local state only */
static inline uint32_t prng_next_u32(uint32_t *s)
{
    uint32_t x = *s;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *s = x;
    return x;
}

static inline uint8_t prng_u7(uint32_t *s)
{
    return (uint8_t)(prng_next_u32(s) & 0x7Fu);
}

static inline uint32_t hash_u32(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    /* simple avalanche mix */
    uint32_t x = a ^ (b + 0x9e3779b9u) ^ (c << 6) ^ (c >> 2) ^ (d * 0x85ebca6bu);
    x ^= x >> 16;
    x *= 0x7feb352du;
    x ^= x >> 15;
    x *= 0x846ca68bu;
    x ^= x >> 16;
    return x ? x : 0xA5A5A5A5u;
}

/* ============================================================
   PART BIAS (PHASE 3.5.1.3 – OPTION A)  (already “green” tuned)
   ============================================================ */

typedef struct {
    int density_bias;   /* −40 … +40 */
    int velocity_bias;  /* −32 … +32 */
    int gate_bias;      /* −48 … +48 */
} part_bias_t;

/* Index = part number */
static const part_bias_t g_part_bias[RANDOMIZER_MAX_CHANNELS] = {
    /* 0  Bass */  { +10,  -6, +24 },
    /* 1  Lead */  {  -5, +12, +12 },
    /* 2  Pad  */  { -15,  -6, +36 },
    /* 3  Pad  */  { -15,  -6, +36 },
    /* 4  Synth*/  {  -5,   0, +12 },
    /* 5  FX   */  { -20,  +6, -12 },
    /* 6  FX   */  { -20,  +6, -12 },
    /* 7  FX   */  { -20,  +6, -12 },

    /* 8  Kick */  { +20, +16, -36 },
    /* 9  Snare*/  { +10, +12, -42 },
    /* 10 Hat */  { +25,  +6, -60 },
    /* 11 Hat */  { +25,  +6, -60 },
    /* 12 Perc*/  { +15,  +8, -48 },
    /* 13 Perc*/  { +15,  +8, -48 },
    /* 14 Perc*/  { +10,  +6, -48 },
    /* 15 Perc*/  { +10,  +6, -48 }
};

/* ============================================================
   3.5.4 Step 2 (already done): Velocity Energy Curve per Section
   ============================================================ */
/* Section ids assumed: 0=Intro,1=Main,2=Break,3=Peak,4=Outro
   Curve is conservative: “no new decision logic”, only scaling.
*/
static inline int section_velocity_gain_pct(int section)
{
    switch (section)
    {
        default:
        case 0: return 92;  /* Intro: slightly softer */
        case 1: return 105; /* Main: a bit more forward */
        case 2: return 85;  /* Break: pull back */
        case 3: return 112; /* Peak: push */
        case 4: return 95;  /* Outro: relax */
    }
}

/* ============================================================
   3.5.4 Step 3: Micro-Timing Drift (Humanizer-reuse, Timeline-Scope)
   ============================================================ */
/* We implement “micro timing drift” as a deterministic, slow drift signal
   per (part, bar) that slightly modulates velocity + gate.
   - No new structural decisions (hit pattern unchanged)
   - Deterministic from (global seed, part, section, bar)
   - Stable across preview/write/playback because PRNG is local
*/
static inline int drift_per_part_bar(int part, int section, int bar, int span)
{
    /* span: magnitude in “units” (kept small) */
    uint32_t s = hash_u32(g_seed, (uint32_t)part, (uint32_t)section, (uint32_t)bar);
    int d = (int)(prng_next_u32(&s) % (uint32_t)(span * 2 + 1)) - span;
    return d;
}

/* ============================================================
   POLICY FLAGS API
   ============================================================ */

void randomizer_set_policy_flags(randomizer_policy_flags_t flags)
{
    g_policy_flags = flags;
}

randomizer_policy_flags_t randomizer_get_policy_flags(void)
{
    return g_policy_flags;
}

/* ============================================================
   CORE SETTINGS
   ============================================================ */

void randomizer_set_seed(int seed)
{
    g_seed = (uint32_t)seed;
    /* NOTE: do NOT touch global rng state here (Step 4 requirement). */
}

void randomizer_set_density(int pct)
{
    g_density = clampi(pct, 0, 100);
}

void randomizer_set_variation(int v)
{
    g_variation = clampi(v, 0, 127);
}

void randomizer_set_freeze(int en)
{
    g_freeze = en ? 1 : 0;
}

void randomizer_set_section(int s)
{
    g_section = s;
}

int randomizer_get_section(void)   { return g_section; }
int randomizer_get_variation(void) { return g_variation; }

/* ============================================================
   PART USAGE (PUBLIC)
   ============================================================ */

int randomizer_part_in_use(uint8_t part)
{
    if (part >= RANDOMIZER_MAX_CHANNELS) return 0;
    return (g_part_used_mask & (1u << part)) ? 1 : 0;
}

void randomizer_mark_part_used(uint8_t part)
{
    if (part < RANDOMIZER_MAX_CHANNELS)
        g_part_used_mask |= (1u << part);
}

void randomizer_reset_part_usage(uint8_t part)
{
    if (part < RANDOMIZER_MAX_CHANNELS)
        g_part_used_mask &= ~(1u << part);
}

/* ============================================================
   STEP REPEATER (PUBLIC)
   ============================================================ */

void randomizer_set_step_repeat(int part, int step, int repeat)
{
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS) return;

    g_step_repeat[part][step] =
        (uint8_t)clampi(repeat, STEP_REPEAT_MIN, STEP_REPEAT_MAX);
}

int randomizer_get_step_repeat(int part, int step)
{
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS)
        return STEP_REPEAT_MIN;
    if (step < 0 || step >= RANDOMIZER_MAX_STEPS)
        return STEP_REPEAT_MIN;

    return g_step_repeat[part][step];
}

/* ============================================================
   UNDO (INTERNAL)
   ============================================================ */

static void undo_clear_entry(randomizer_undo_entry_t *u)
{
    if (!u) return;
    u->part = -1;
    u->page = -1;
    u->n    = 0;
}

static void undo_push(int part, int page,
                      const ft_step_t *steps, int n)
{
    int idx = g_undo_top % RANDOMIZER_UNDO_SLOTS;
    randomizer_undo_entry_t *u = &g_undo[idx];

    u->part = part;
    u->page = page;
    u->n    = (n > RANDOMIZER_MAX_STEPS)
                ? RANDOMIZER_MAX_STEPS : n;

    if (steps && u->n > 0)
        memcpy(u->steps, steps, sizeof(ft_step_t) * (size_t)u->n);

    g_undo_top++;
}

int randomizer_undo_last_public(void)
{
    if (g_undo_top == 0) return -1;

    int idx = (g_undo_top - 1) % RANDOMIZER_UNDO_SLOTS;
    randomizer_undo_entry_t *u = &g_undo[idx];

    if (u->part < 0 || u->n == 0) return -1;

    pattern_write_pattern(u->part, u->steps, u->n);
    undo_clear_entry(u);
    return 0;
}

/* ============================================================
   PATTERN GENERATION
   - Part-Bias applied (3.5.1.3)
   - Section energy curve applied (3.5.4 Step 2)
   - Micro drift applied (3.5.4 Step 3)
   - Deterministic local PRNG (3.5.4 Step 4)
   ============================================================ */

int randomize_generate_pattern(int part,
                               int steps_count,
                               ft_step_t *steps_out,
                               int section_bar)
{
    if (!steps_out) return -1;
    if (part < 0 || part >= RANDOMIZER_MAX_CHANNELS) return -1;
    if (steps_count <= 0 || steps_count > RANDOMIZER_MAX_STEPS) return -1;

    /* Freeze = do nothing new (safe) */
    if (g_freeze) return -1;

    /* Local deterministic stream:
       include section_bar to make bar-to-bar evolution deterministic. */
    uint32_t s = hash_u32(g_seed,
                          (uint32_t)part,
                          (uint32_t)g_section,
                          (uint32_t)section_bar);

    const part_bias_t *pb = &g_part_bias[part];

    int eff_density = clampi(g_density + pb->density_bias, 0, 100);
    int vel_gain    = section_velocity_gain_pct(g_section);

    /* Drift is stable per (part, bar) — “timeline scope” */
    int drift_v = drift_per_part_bar(part, g_section, section_bar, 6);  /* ±6 velocity */
    int drift_g = drift_per_part_bar(part, g_section, section_bar, 8);  /* ±8 gate base */

    for (int i = 0; i < steps_count; i++)
    {
        uint8_t r_pitch = prng_u7(&s);
        uint8_t r_vel   = prng_u7(&s);
        uint8_t r_hit   = prng_u7(&s);

        int hit = ((int)(r_hit % 100u) < eff_density) ? 1 : 0;

        /* Base velocity from PRNG + part bias */
        int v = ((int)r_vel) + pb->velocity_bias;

        /* Apply section energy curve (gain in percent) */
        v = (v * vel_gain) / 100;

        /* Apply micro drift (humanizer-style), but only if hit */
        v += drift_v;

        /* Variation subtly increases spread (still deterministic) */
        if (g_variation > 0)
        {
            /* symmetrical small wobble scaled by variation */
            int wob = (int)((prng_next_u32(&s) & 0x1Fu) - 16); /* -16..+15 */
            v += (wob * g_variation) / 256; /* gentle */
        }

        v = clampi(v, 1, 127);

        /* Gate: base + part bias + drift. Keep in 1..127 for hit, else 0 */
        int g = 64 + pb->gate_bias + drift_g;
        g = clampi(g, 1, 127);

        steps_out[i] = (ft_step_t){
            .part     = (uint8_t)part,
            .step     = (uint8_t)i,
            .pitch    = r_pitch,
            .velocity = (uint8_t)(hit ? v : 0),
            .gate     = (uint8_t)(hit ? g : 0)
        };
    }

    undo_push(part, 0, steps_out, steps_count);
    return steps_count;
}

/* ============================================================
   WRITE HELPERS (must exist for linker)
   ============================================================ */

int randomize_and_write_pattern_paged(int part,
                                      int steps_count,
                                      int section,
                                      int page)
{
    (void)page;

    /* Keep generation determinism:
       temporarily set g_section for this call, then restore. */
    int prev_section = g_section;
    g_section = section;

    ft_step_t tmp[RANDOMIZER_MAX_STEPS];
    int n = randomize_generate_pattern(part, steps_count, tmp, section);

    g_section = prev_section;

    return (n > 0) ? pattern_write_pattern(part, tmp, n) : -1;
}

int randomize_and_write_pattern_paged_simple(int part,
                                             int steps_count,
                                             ft_step_t *steps_out)
{
    int n = randomize_generate_pattern(part, steps_count, steps_out, g_section);
    return (n > 0) ? pattern_write_pattern(part, steps_out, n) : -1;
}

/* ============================================================
   INIT
   ============================================================ */

void randomizer_init_default(void)
{
    g_policy_flags   = 0;
    g_part_used_mask = 0;
    g_undo_top       = 0;

    for (int i = 0; i < RANDOMIZER_UNDO_SLOTS; i++)
        undo_clear_entry(&g_undo[i]);

    for (int p = 0; p < RANDOMIZER_MAX_CHANNELS; p++)
        for (int st = 0; st < RANDOMIZER_MAX_STEPS; st++)
            g_step_repeat[p][st] = STEP_REPEAT_MIN;
}

void randomizer_tick_once(void)
{
    /* reserved */
}

```

### apps/autorecorder/randomizer.h
<a name="appsautorecorderrandomizerh"></a>

- **Name:** `randomizer.h`
- **Pfad:** `apps/autorecorder/randomizer.h`
- **SHA256:** `dccfa8c21b4b2e2e259f84b6495f284dcbce1862ac9361288e597864315001c1`

```
#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <stdint.h>
#include <stdbool.h>

#include "ft_types.h"
#include "scale_engine.h"
#include "condition_engine.h"

/* ========= CONSTANTS ========= */
#define RANDOMIZER_MAX_CHANNELS         16
#define RANDOMIZER_MAX_STEPS            64
#define RANDOMIZER_MAX_MOTION_LANES     8
#define RANDOMIZER_MAX_MOTION_LEN       64
#define RANDOMIZER_UNDO_SLOTS           16
#define RANDOMIZER_MAX_EU_SLOTS_PER_CH  4

/* ========= STEP REPEATER ENGINE-STATE ========= */
#define STEP_REPEAT_MIN 1
#define STEP_REPEAT_MAX 8

/* ========= POLICY FLAGS (Composer → Randomizer Bias) =========
   Bitlayout matches CP_FLAG_* in composer_policy.h
*/
typedef uint16_t randomizer_policy_flags_t;

void randomizer_set_policy_flags(randomizer_policy_flags_t flags);
randomizer_policy_flags_t randomizer_get_policy_flags(void);

/* ========= EUCLID MODES ========= */
typedef enum {
    EU_MODE_OFF = 0,
    EU_MODE_STANDARD,
    EU_MODE_FILL,
    EU_MODE_PROB
} eu_mode_t;

/* ========= MOTION STRUCT ========= */
typedef struct {
    int  length;
    bool enabled;
    int  values[RANDOMIZER_MAX_MOTION_LEN];
} motion_lane_t;

/* ========= EUCLID SLOT ========= */
typedef struct {
    int pulses;
    int steps;
    int rotation;
    int probability; /* 0..127 */
    eu_mode_t mode;
    bool enabled;
    uint8_t compiled[RANDOMIZER_MAX_STEPS];
} eu_slot_t;

typedef struct {
    eu_slot_t slots[RANDOMIZER_MAX_EU_SLOTS_PER_CH];
} eu_channel_t;

/* ========= UNDO ========= */
typedef struct {
    int part;
    int page;
    int n;
    ft_step_t steps[RANDOMIZER_MAX_STEPS];
} randomizer_undo_entry_t;

/* ========= CORE ========= */
void randomizer_init_default(void);
void randomizer_tick_once(void);

void randomizer_set_seed(int seed);
void randomizer_set_density(int pct);
void randomizer_set_variation(int v);
void randomizer_set_freeze(int en);
void randomizer_set_section(int s);

int  randomizer_get_section(void);
int  randomizer_get_variation(void);

/* ========= PART STATE ========= */
/* Part usage tracking (safe / non-RAM-scan) */
int  randomizer_part_in_use(uint8_t part);
void randomizer_mark_part_used(uint8_t part);
void randomizer_reset_part_usage(uint8_t part);

/* ========= STEP REPEATER ========= */
void randomizer_set_step_repeat(int part, int step, int repeat);
int  randomizer_get_step_repeat(int part, int step);

/* ========= PATTERN GENERATION ========= */
int randomize_generate_pattern(
    int part,
    int steps_count,
    ft_step_t *steps_out,
    int section_bar
);

int randomize_and_write_pattern_paged(
    int part,
    int steps_count,
    int section,
    int page
);

int randomize_and_write_pattern_paged_simple(
    int part,
    int steps_count,
    ft_step_t *steps_out
);

/* ========= EUCLID ========= */
void randomizer_euclid_stage_channel(int ch);
void randomizer_euclid_stage_slot(int slot);
void randomizer_euclid_stage_pulses(int p);
void randomizer_euclid_stage_steps(int s);
void randomizer_euclid_stage_rotation(int r);
void randomizer_euclid_stage_probability(int p);
void randomizer_euclid_stage_mode(uint8_t m);
void randomizer_euclid_commit(void);

void randomizer_euclid_set_enabled(int ch, int slot, int en);
void randomizer_euclid_live_rotate(int ch, int slot, int delta);
int  randomizer_get_euclid_value_public(int ch, int slot_id, int step_index);

/* ========= MOTION ========= */
int randomizer_create_motion_lane(int id, int length);
int randomizer_set_motion_value(int id, int idx, int val);
int randomizer_set_motion_length(int id, int length);
int randomizer_set_motion_enabled(int id, int en);

/* These were used by mod_matrix.c (fix: add to header) */
int randomizer_get_motion_value(int id, int idx);
int randomizer_get_motion_length(int id);

/* ========= MOD MATRIX ========= */
int randomizer_add_mod_route(void *route);
int randomizer_remove_mod_route(int idx);
int randomizer_clear_mod_routes(void);

/* ========= UNDO ========= */
int randomizer_undo_last_public(void);

/* ========= PUBLIC ========= */
extern eu_channel_t g_eu_channels[RANDOMIZER_MAX_CHANNELS];
extern int eu_stage_channel;
extern int eu_stage_slot;

#endif /* RANDOMIZER_H */

```

### apps/autorecorder/randomizer_euclid.c
<a name="appsautorecorderrandomizereuclidc"></a>

- **Name:** `randomizer_euclid.c`
- **Pfad:** `apps/autorecorder/randomizer_euclid.c`
- **SHA256:** `bd4d10d6f30e8bca037d934422da8870e1f50a5491339c6219cff2b9ec4a0a2d`

```
/* ============================================================
   randomizer_euclid.c
   ------------------------------------------------------------
   Euclid Engine Integration for Randomizer
   Phase 2 – Step 7 (FINAL, BUILD-STABLE)

   Ownership:
   - eu_stage_channel / eu_stage_slot are OWNED by NRPN layer
     (defined once in euclid_nrpn_stubs.c)
   - This file ONLY uses them via extern

   Compatible with:
   - randomizer.c
   - euclid_engine_v2.c
   - nrpn_router.c
   ============================================================ */

#include "randomizer.h"
#include "euclid_engine_v2.h"
#include "rng.h"

#include <stdint.h>
#include <stdbool.h>

/* ------------------------------------------------------------
   Helpers
   ------------------------------------------------------------ */
static inline int clampi(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* ------------------------------------------------------------
   NRPN-owned staging variables (extern, NOT defined here)
   ------------------------------------------------------------ */
extern int eu_stage_channel;
extern int eu_stage_slot;

/* ------------------------------------------------------------
   Local staged parameters (value staging only)
   ------------------------------------------------------------ */
static int       eu_stage_pulses      = 0;
static int       eu_stage_steps       = 16;
static int       eu_stage_rotation    = 0;
static int       eu_stage_probability = 127;
static eu_mode_t eu_stage_mode        = EU_MODE_STANDARD;

/* ------------------------------------------------------------
   Global Euclid storage (defined in randomizer.c)
   ------------------------------------------------------------ */
extern eu_channel_t g_eu_channels[RANDOMIZER_MAX_CHANNELS];

/* ============================================================
   STAGE SETTERS (called from NRPN router)
   ============================================================ */

void randomizer_euclid_stage_channel(int ch)
{
    eu_stage_channel = clampi(ch, 0, RANDOMIZER_MAX_CHANNELS - 1);
}

void randomizer_euclid_stage_slot(int slot)
{
    eu_stage_slot = clampi(slot, 0, RANDOMIZER_MAX_EU_SLOTS_PER_CH - 1);
}

void randomizer_euclid_stage_pulses(int p)
{
    eu_stage_pulses = clampi(p, 0, RANDOMIZER_MAX_STEPS);
}

void randomizer_euclid_stage_steps(int s)
{
    eu_stage_steps = clampi(s, 1, RANDOMIZER_MAX_STEPS);
}

void randomizer_euclid_stage_rotation(int r)
{
    eu_stage_rotation = r;
}

void randomizer_euclid_stage_probability(int p)
{
    eu_stage_probability = clampi(p, 0, 127);
}

void randomizer_euclid_stage_mode(uint8_t m)
{
    if (m > EU_MODE_PROB)
        m = EU_MODE_PROB;

    eu_stage_mode = (eu_mode_t)m;
}

/* ============================================================
   COMMIT — compile Euclid pattern into slot
   ============================================================ */

void randomizer_euclid_commit(void)
{
    if (eu_stage_channel < 0 || eu_stage_channel >= RANDOMIZER_MAX_CHANNELS)
        return;

    if (eu_stage_slot < 0 || eu_stage_slot >= RANDOMIZER_MAX_EU_SLOTS_PER_CH)
        return;

    eu_channel_t *ch  = &g_eu_channels[eu_stage_channel];
    eu_slot_t    *sl  = &ch->slots[eu_stage_slot];

    sl->pulses      = eu_stage_pulses;
    sl->steps       = eu_stage_steps;
    sl->rotation    = eu_stage_rotation;
    sl->probability = eu_stage_probability;
    sl->mode        = eu_stage_mode;

    uint8_t gates[RANDOMIZER_MAX_STEPS] = {0};

    int ret = euclid_generate(
        sl->steps,
        sl->pulses,
        sl->rotation,
        gates
    );

    if (ret > 0)
    {
        for (int i = 0; i < sl->steps; ++i)
            sl->compiled[i] = gates[i];
    }

    sl->enabled = true;
}

/* ============================================================
   Enable / Disable Euclid slot
   ============================================================ */

void randomizer_euclid_set_enabled(int ch, int slot, int en)
{
    if (ch < 0 || ch >= RANDOMIZER_MAX_CHANNELS) return;
    if (slot < 0 || slot >= RANDOMIZER_MAX_EU_SLOTS_PER_CH) return;

    g_eu_channels[ch].slots[slot].enabled = (en != 0);
}

/* ============================================================
   Live rotate (delta-based)
   ============================================================ */

void randomizer_euclid_live_rotate(int ch, int slot, int delta)
{
    if (ch < 0 || ch >= RANDOMIZER_MAX_CHANNELS) return;
    if (slot < 0 || slot >= RANDOMIZER_MAX_EU_SLOTS_PER_CH) return;

    g_eu_channels[ch].slots[slot].rotation += delta;
}

/* ============================================================
   Query compiled gate value
   Used by Randomizer / Mod Matrix
   ============================================================ */

int randomizer_get_euclid_value_public(int ch, int slot, int step)
{
    if (ch < 0 || ch >= RANDOMIZER_MAX_CHANNELS) return 0;
    if (slot < 0 || slot >= RANDOMIZER_MAX_EU_SLOTS_PER_CH) return 0;

    eu_slot_t *s = &g_eu_channels[ch].slots[slot];

    if (!s->enabled) return 0;
    if (step < 0 || step >= s->steps) return 0;

    /* Probability override mode */
    if (s->mode == EU_MODE_PROB)
    {
        int r = (int)(rng_get() & 0x7F);
        return (r < s->probability) ? 1 : 0;
    }

    /* Normal compiled gate */
    return (s->compiled[step] != 0);
}

```

### apps/autorecorder/randomizer_euclid.h
<a name="appsautorecorderrandomizereuclidh"></a>

- **Name:** `randomizer_euclid.h`
- **Pfad:** `apps/autorecorder/randomizer_euclid.h`
- **SHA256:** `a3156eb59d641dbd08bcacf98617b4f48e1f898f03b293b4dfac0439b27329a3`

```
#ifndef RANDOMIZER_EUCLID_H
#define RANDOMIZER_EUCLID_H

#include <stdint.h>

/*
   NOTE:
   This header exists in the project, but the current build uses randomizer.h
   as the primary API surface. We keep this file consistent and compatible,
   without removing existing declarations.
*/

/* Public getters used by mod_matrix / other modules */
int randomizer_get_euclid_value_public(int ch, int slot, int step_index);

/* NRPN staging helpers used by nrpn_router.c */
void randomizer_euclid_stage_channel(int ch);
void randomizer_euclid_stage_slot(int slot);
void randomizer_euclid_stage_pulses(int p);
void randomizer_euclid_stage_steps(int s);
void randomizer_euclid_stage_rotation(int r);
void randomizer_euclid_stage_probability(int p);
void randomizer_euclid_stage_mode(uint8_t m);
void randomizer_euclid_commit(void);

/* Enable / live operations */
void randomizer_euclid_set_enabled(int ch, int slot, int en);
void randomizer_euclid_live_rotate(int ch, int slot, int delta);

/* Extern staging variables (nrpn_router may reference) */
extern int eu_stage_channel;
extern int eu_stage_slot;

#endif /* RANDOMIZER_EUCLID_H */

```

### apps/autorecorder/rng.c
<a name="appsautorecorderrngc"></a>

- **Name:** `rng.c`
- **Pfad:** `apps/autorecorder/rng.c`
- **SHA256:** `63e3eb47214982dd2fdd9daa92c69061334cb6a1584336d86a0dfb39e93658dd`

```
/*
 * rng.c
 *
 * Small xorshift32 RNG wrapper.
 *
 * Public API:
 *   void     rng_seed(uint32_t seed);
 *   uint32_t rng_get(void);
 *   int      rng_int(int max);
 *
 * This RNG is deterministic and very fast; good for embedded usage where
 * cryptographic strength is not required.
 */

#include "rng.h"
#include <stdint.h>

/* Internal state - keep static to limit scope. Non-zero required. */
static uint32_t g_state = 0xA5A5A5A5u;

/* xorshift32 core */
static uint32_t xorshift32(uint32_t *state)
{
    /* xorshift32: simple, small-state generator */
    uint32_t x = *state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x ? x : 0xDEADBEEFu; /* ensure state never becomes 0 */
    return *state;
}

/* Seed the RNG. If user passes 0 we substitute a fixed nonzero seed.
   (0 would break pure xorshift32 because it stays 0). */
void rng_seed(uint32_t seed)
{
    if (seed == 0) seed = 0xC0FFEEu ^ 0x12345678u;
    g_state = seed;
    /* Warm up a few cycles to decorrelate from seed */
    (void)xorshift32(&g_state);
    (void)xorshift32(&g_state);
    (void)xorshift32(&g_state);
}

/* Return next 32-bit random value */
uint32_t rng_get(void)
{
    return xorshift32(&g_state);
}

/* Convenience integer in range [0, max-1]. If max <= 0 returns 0.
   Uses rejection to reduce bias for large ranges, but keeps code simple
   (fine for embedded, small max typical usage). */
int rng_int(int max)
{
    if (max <= 0) return 0;
    /* Use 32-bit random value and map to range */
    uint32_t r = rng_get();
    /* simple reduction — acceptable for small max values */
    return (int)(r % (uint32_t)max);
}

```

### apps/autorecorder/scale_engine.c
<a name="appsautorecorderscaleenginec"></a>

- **Name:** `scale_engine.c`
- **Pfad:** `apps/autorecorder/scale_engine.c`
- **SHA256:** `8bac9adf475766914dc7095b48728cd136965f88ccdebea43972441276900007`

```
/* scale_engine.c
   Minimal implementation for scale engine functions referenced by randomizer.
*/

#include "scale_engine.h"
#include <stdint.h>
#include <string.h>

#define MAX_CHANNELS 16

static scale_type_t g_channel_scale[MAX_CHANNELS];
static int g_channel_tonic[MAX_CHANNELS];
static uint16_t g_channel_mask[MAX_CHANNELS];

int scale_engine_set_channel_scale(int ch, scale_type_t s, int tonic) {
    if (ch < 0 || ch >= MAX_CHANNELS) return -1;
    g_channel_scale[ch] = s;
    g_channel_tonic[ch] = tonic;
    return 0;
}
int scale_engine_get_channel_scale(int ch, scale_type_t *s, int *tonic) {
    if (ch < 0 || ch >= MAX_CHANNELS) return -1;
    if (s) *s = g_channel_scale[ch];
    if (tonic) *tonic = g_channel_tonic[ch];
    return 0;
}

int scale_engine_set_channel_custom_mask(int ch, uint16_t mask) {
    if (ch < 0 || ch >= MAX_CHANNELS) return -1;
    g_channel_mask[ch] = mask;
    return 0;
}
uint16_t scale_engine_get_channel_custom_mask(int ch) {
    if (ch < 0 || ch >= MAX_CHANNELS) return 0x0FFF;
    return g_channel_mask[ch];
}

/* naive mapping: returns same pitch, but clamp to 0..127 */
int scale_engine_map_pitch_to_scale(int ch, int pitch) {
    if (pitch < 0) pitch = 0;
    if (pitch > 127) pitch = 127;
    (void)ch;
    return pitch;
}

void scale_engine_commit_channel(int ch)
{
    (void)ch;
    /* future: store into persistent scale table */
}

void scale_engine_reset_channel(int ch)
{
    (void)ch;
    /* future: reset scale to default */
}

```

### apps/autorecorder/scale_engine.h
<a name="appsautorecorderscaleengineh"></a>

- **Name:** `scale_engine.h`
- **Pfad:** `apps/autorecorder/scale_engine.h`
- **SHA256:** `4aaba0f1896bce58bf4db024fab7f4b039bced2bc02328f887d4ba763abfe354`

```
#ifndef SCALE_ENGINE_H
#define SCALE_ENGINE_H

#include <stdint.h>

typedef enum {
    SCALE_CHROMATIC = 0,
    SCALE_MAJOR,
    SCALE_NATURAL_MINOR,
    SCALE_PENT_MAJOR,
    SCALE_PENT_MINOR,
    SCALE_DORIAN,
    SCALE_MIXOLYDIAN,
    SCALE_LOCRIAN,
    SCALE_HARM_MINOR,
    SCALE_MELODIC_MINOR,
    SCALE_CUSTOM
} scale_type_t;

void scale_engine_init(void);

int randomizer_set_channel_custom_mask(int ch, uint16_t mask);
uint16_t randomizer_get_channel_custom_mask(int ch);

int randomizer_map_pitch_to_scale(int ch, int pitch);

/* NRPN staging */
void nrpn_scale_stage_channel(int ch);
void nrpn_scale_stage_type(int type);
void nrpn_scale_stage_tonic(int tonic);
void nrpn_scale_commit(void);
void nrpn_scale_reset(void);

void scale_engine_commit_channel(int ch);
void scale_engine_reset_channel(int ch);

#endif

```

### apps/autorecorder/scale_engine_nrpn.c
<a name="appsautorecorderscaleenginenrpnc"></a>

- **Name:** `scale_engine_nrpn.c`
- **Pfad:** `apps/autorecorder/scale_engine_nrpn.c`
- **SHA256:** `866166e81f0fcfc2c3c75ee1a9bb77eee732dbce471bb4bc1beb910bb1a160f4`

```
/*
 * scale_engine_nrpn.c
 *
 * Thin NRPN staging wrappers for the scale engine.
 * If your existing scale_engine provides functions with different names,
 * you can either modify these wrappers or forward directly in your scale module.
 *
 * Defensive behavior: if the external functions are declared elsewhere, we'll call them.
 * If they are not present at link time, these wrappers still compile and are no-ops.
 */

#include "scale_engine_nrpn.h"
#include <stddef.h>

/* Stage storage (kept internal) */
static int staged_channel = 0;
static int staged_type    = 0;
static int staged_tonic   = 0;

/* If your scale_engine provides these functions, declare them as extern here.
 * They will be optional and the linker will error only if you remove the wrappers.
 * If the real scale engine exists, it should provide:
 *
 *   int scale_engine_set_channel_scale(int ch, int type, int tonic);
 *   int scale_engine_get_channel_scale(int ch, int *type, int *tonic);
 *   void scale_engine_commit_channel(int ch);
 *   void scale_engine_reset_channel(int ch);
 *
 * Adjust names if your scale engine uses other identifiers.
 */

extern int scale_engine_set_channel_scale(int ch, int type, int tonic);
extern int scale_engine_get_channel_scale(int ch, int *type, int *tonic);
extern void scale_engine_commit_channel(int ch);
extern void scale_engine_reset_channel(int ch);

/* Stage setters */
void nrpn_scale_stage_channel(int ch) {
    staged_channel = ch;
}

void nrpn_scale_stage_type(int t) {
    staged_type = t;
}

void nrpn_scale_stage_tonic(int tonic) {
    staged_tonic = tonic;
}

void nrpn_scale_commit(void) {
    /* Try to call the real engine if present */
    if (&scale_engine_set_channel_scale) {
        (void)scale_engine_set_channel_scale(staged_channel, staged_type, staged_tonic);
    }
    if (&scale_engine_commit_channel) {
        scale_engine_commit_channel(staged_channel);
    }
}

void nrpn_scale_reset(void) {
    if (&scale_engine_reset_channel) {
        scale_engine_reset_channel(staged_channel);
    }
}

```

### apps/autorecorder/scale_engine_nrpn.h
<a name="appsautorecorderscaleenginenrpnh"></a>

- **Name:** `scale_engine_nrpn.h`
- **Pfad:** `apps/autorecorder/scale_engine_nrpn.h`
- **SHA256:** `7d6915d5f0cd055f05727b818562ee4f07b4b288172a8fb1105b147380aacd0b`

```
#ifndef SCALE_ENGINE_NRPN_H
#define SCALE_ENGINE_NRPN_H

#include <stdint.h>

/* wrappers used by nrpn_router.c to stage scale changes.
 * These functions are thin wrappers that call into the project's
 * scale_engine if available; otherwise they are safe no-ops.
 */

void nrpn_scale_stage_channel(int ch);
void nrpn_scale_stage_type(int t);
void nrpn_scale_stage_tonic(int tonic);
void nrpn_scale_commit(void);
void nrpn_scale_reset(void);

#endif /* SCALE_ENGINE_NRPN_H */

```

### apps/autorecorder/song_mode.c
<a name="appsautorecordersongmodec"></a>

- **Name:** `song_mode.c`
- **Pfad:** `apps/autorecorder/song_mode.c`
- **SHA256:** `271b1a9169c4f3b94d8c4661ca150731c4b4cfd6c92b7c2b5fcf4cae38777ae5`

```
// song_mode.c
// Song Mode 2.0 — arranger / sequencer for autorecorder app

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "song_mode.h"
#include "ft_config.h"
#include "panel_hooks.h"
#include "pattern_writer.h"
#include "ft_api.h"


// optional: use firmware BPM if configured
static int song_mode_get_bpm(void)
{
    if ((uintptr_t)ADDR_GET_BPM_FUNC != 0 && FT_USE_FW_GET_BPM) {
        typedef int (*bpm_fn_t)(void);
        bpm_fn_t f = (bpm_fn_t)ADDR_GET_BPM_FUNC;
        if (f) return f();
    }
    return FT_DEFAULT_BPM;
}

// simple busy-wait ms delay (safe fallback)
static void song_mode_delay_ms(int ms)
{
    volatile int i;
    // calibrated previously in recorder; keep same multiplier
    for (i = 0; i < ms * 2000; ++i) {
        __asm__ volatile("nop");
    }
}

// convert bars -> milliseconds (4/4 assumed)
static int song_mode_bars_to_ms(int bars)
{
    int bpm = song_mode_get_bpm();
    if (bpm <= 0) bpm = FT_DEFAULT_BPM;
    int ms_per_beat = 60000 / bpm;
    int ms_per_bar = ms_per_beat * 4;
    return ms_per_bar * bars;
}

/* Internal state */
static song_t g_song;
static bool g_running = false;
static bool g_paused = false;
static int g_current_entry = 0;
static int g_current_repeat = 0;
static int g_current_phase = 0; // 0 idle, 1 playing
static int g_wait_remaining_ms = 0;

/* Helper to set pattern + play + optionally record/write (synchronous) */
static void song_mode_play_entry_once(const song_entry_t *e)
{
    if (!e) return;

    // set pattern number and small delay for GUI settle
    set_pattern_number(e->pattern);
    song_mode_delay_ms(60);

    // start playing
    panel_play();
    song_mode_delay_ms(20);

    // if pattern should be recorded, press record
    // decision: if write_after==true we assume pattern is being recorded live,
    // otherwise simply play the pattern.
    if (e->write_after) {
        panel_record();
    }

    // wait bars
    int wait_ms = song_mode_bars_to_ms(e->bars);
    // wait in smaller chunks to allow pause/stop responsiveness
    int chunk = 100; // 100ms
    int waited = 0;
    while (waited < wait_ms) {
        if (!g_running || g_paused) break;
        int rem = wait_ms - waited;
        int step = (rem < chunk) ? rem : chunk;
        song_mode_delay_ms(step);
        waited += step;
    }

    // stop
    panel_stop();
    song_mode_delay_ms(20);

    // write after if requested (press WRITE)
    if (e->write_after) {
        panel_write();
        song_mode_delay_ms(50);
    }
}

/* Initialize internal structures */
void song_mode_init(void)
{
    memset(&g_song, 0, sizeof(g_song));
    g_running = false;
    g_paused = false;
    g_current_entry = 0;
    g_current_repeat = 0;
    g_current_phase = 0;
    g_wait_remaining_ms = 0;
}

/* Load a song into RAM (copy). Returns 0 on success. */
int song_mode_load_song(const song_t *s)
{
    if (!s) return -1;
    memcpy(&g_song, s, sizeof(song_t));
    if (g_song.entry_count < 0) g_song.entry_count = 0;
    if (g_song.entry_count > SONG_MAX_ENTRIES) g_song.entry_count = SONG_MAX_ENTRIES;
    return 0;
}

void song_mode_clear(void)
{
    memset(&g_song, 0, sizeof(g_song));
    g_current_entry = 0;
    g_current_repeat = 0;
}

/* Start playback from current entry */
void song_mode_start(void)
{
    if (g_song.entry_count <= 0) return;
    g_running = true;
    g_paused = false;
}

/* Stop and reset */
void song_mode_stop(void)
{
    g_running = false;
    g_paused = false;
    g_current_entry = 0;
    g_current_repeat = 0;
    g_current_phase = 0;
}

/* Pause */
void song_mode_pause(void)
{
    if (!g_running) return;
    g_paused = !g_paused;
}

/* Is running? */
bool song_mode_is_running(void)
{
    return g_running && !g_paused;
}

/* Add entry (appends) returns index or -1 */
int song_mode_add_entry(int pattern, int bars, int repeats, bool write_after)
{
    if (g_song.entry_count >= SONG_MAX_ENTRIES) return -1;
    int idx = g_song.entry_count++;
    g_song.entries[idx].pattern = pattern;
    g_song.entries[idx].bars = (bars <= 0) ? 1 : bars;
    g_song.entries[idx].repeats = (repeats <= 0) ? 1 : repeats;
    g_song.entries[idx].write_after = write_after;
    return idx;
}

/* set entry */
void song_mode_set_entry(int idx, int pattern, int bars, int repeats, bool write_after)
{
    if (idx < 0 || idx >= g_song.entry_count) return;
    g_song.entries[idx].pattern = pattern;
    g_song.entries[idx].bars = (bars <= 0) ? 1 : bars;
    g_song.entries[idx].repeats = (repeats <= 0) ? 1 : repeats;
    g_song.entries[idx].write_after = write_after;
}

/* navigation */
void song_mode_next(void)
{
    if (g_song.entry_count <= 0) return;
    g_current_repeat = 0;
    g_current_entry++;
    if (g_current_entry >= g_song.entry_count) g_current_entry = 0;
}
void song_mode_prev(void)
{
    if (g_song.entry_count <= 0) return;
    g_current_repeat = 0;
    g_current_entry--;
    if (g_current_entry < 0) g_current_entry = g_song.entry_count - 1;
}
void song_mode_goto(int entry_index)
{
    if (entry_index < 0 || entry_index >= g_song.entry_count) return;
    g_current_entry = entry_index;
    g_current_repeat = 0;
}

/* simple tick — to be called from app_tick() frequently */
void song_mode_tick(void)
{
    if (!g_running || g_paused) return;
    if (g_song.entry_count <= 0) return;

    // play current entry repeats times
    song_entry_t *e = &g_song.entries[g_current_entry];
    if (!e) return;

    // play one repeat
    song_mode_play_entry_once(e);

    // advance repeat counter
    g_current_repeat++;
    if (g_current_repeat >= e->repeats) {
        // next entry
        g_current_repeat = 0;
        g_current_entry++;
        if (g_current_entry >= g_song.entry_count) {
            // loop back to beginning
            g_current_entry = 0;
            // stop if you prefer non-looping behavior:
            // g_running = false;
        }
    }
}

/* Query functions */
int song_mode_get_current_index(void) { return g_current_entry; }
int song_mode_get_entry_count(void) { return g_song.entry_count; }

/* NRPN handler: map some LSBs to song mode controls
   - 70 = SONG_START (value 1 start, 0 stop)
   - 71 = SONG_NEXT (value 1 -> next)
   - 72 = SONG_PREV (value 1 -> prev)
   - 73 = SONG_GOTO (value = index)
   - 74 = SONG_ADD_ENTRY (value = pattern id; uses 1 bar, 1 repeat, no write)
   - 75 = SONG_CLEAR (value 1 -> clear)
*/
void song_mode_handle_nrpn(int lsb, int value)
{
    switch (lsb) {
        case 70:
            if (value) song_mode_start(); else song_mode_stop();
            break;
        case 71:
            if (value) song_mode_next();
            break;
        case 72:
            if (value) song_mode_prev();
            break;
        case 73:
            song_mode_goto(value);
            break;
        case 74:
            // append pattern=value
            song_mode_add_entry(value, 1, 1, false);
            break;
        case 75:
            if (value) song_mode_clear();
            break;
        default:
            break;
    }
}

```

### apps/autorecorder/song_mode.h
<a name="appsautorecordersongmodeh"></a>

- **Name:** `song_mode.h`
- **Pfad:** `apps/autorecorder/song_mode.h`
- **SHA256:** `24d16c0fd7aef2516e3ebd993de68b0cd1e670cfdff17568448a20a6ccfcfa3c`

```
#ifndef SONG_MODE_H
#define SONG_MODE_H

#include <stdint.h>
#include <stdbool.h>
#include "pattern_writer.h"

/*
 Song Mode API for Freetribe / Hacktribe autorecorder app
 - Simple arranger: chains PatternID + bars + repeats
 - Uses existing Panel Hooks for play/stop/record/write
 - Uses FT_DEFAULT_BPM fallback for timing, but will use firmware BPM if available
*/

/* Max entries in a song */
#define SONG_MAX_ENTRIES 128

/* One song entry: play pattern 'pattern' for 'bars' bars, repeat 'repeats' times.
 * if write_after = true, do panel_write() after playing the bars (useful for auto-record)
 */
typedef struct {
    int pattern;        /* pattern number */
    int bars;           /* bars to play */
    int repeats;        /* repeat count (>=1) */
    bool write_after;   /* write after each repeat */
} song_entry_t;

/* A Song container */
typedef struct {
    char name[32];
    song_entry_t entries[SONG_MAX_ENTRIES];
    int entry_count;
} song_t;

/* Init / tick functions */
void song_mode_init(void);
void song_mode_tick(void); /* call regularly from app_tick */

/* Song control */
int song_mode_load_song(const song_t *s); /* load into RAM, returns 0 ok */
void song_mode_clear(void);
void song_mode_start(void);
void song_mode_stop(void);
void song_mode_pause(void);
bool song_mode_is_running(void);

/* Song editing helpers */
int song_mode_add_entry(int pattern, int bars, int repeats, bool write_after); /* returns index or -1 */
void song_mode_set_entry(int idx, int pattern, int bars, int repeats, bool write_after);

/* Jump / navigation */
void song_mode_next(void);
void song_mode_prev(void);
void song_mode_goto(int entry_index);

/* Query */
int song_mode_get_current_index(void);
int song_mode_get_entry_count(void);

/* NRPN handler hook (call from nrpn_router when MSB=127) */
void song_mode_handle_nrpn(int lsb, int value);

#endif // SONG_MODE_H

```

### apps/autorecorder/sync.c
<a name="appsautorecordersyncc"></a>

- **Name:** `sync.c`
- **Pfad:** `apps/autorecorder/sync.c`
- **SHA256:** `890ffe9dd5ee8495df3784d340e0fbca295598eb2b871cd3778cea111a00f44e`

```
// sync.c — BPM / timing helpers for autorecorder, randomizer & song mode
// Safe with fallback if firmware BPM function not available.

#include "ft_config.h"
#include <stdint.h>

/* Firmware function type */
typedef int (*fw_get_bpm_t)(void);

/* -------------------------------------------------------
   ft_get_bpm()
   - Reads BPM from firmware if ADDR_GET_BPM_FUNC != 0
   - Otherwise returns FT_DEFAULT_BPM safely.
   ------------------------------------------------------- */
int ft_get_bpm(void)
{
    if ((uintptr_t)ADDR_GET_BPM_FUNC != 0 && FT_USE_FW_GET_BPM)
    {
        fw_get_bpm_t f = (fw_get_bpm_t)ADDR_GET_BPM_FUNC;
        if (f)
        {
            int bpm = f();
            if (bpm > 0 && bpm < 400)   // sanity range
                return bpm;
        }
    }

    return FT_DEFAULT_BPM;
}

/* -------------------------------------------------------
   ft_ms_per_beat()
   - convert BPM → ms per beat
   ------------------------------------------------------- */
int ft_ms_per_beat(void)
{
    int bpm = ft_get_bpm();
    if (bpm <= 0) bpm = FT_DEFAULT_BPM;
    return 60000 / bpm;
}

/* -------------------------------------------------------
   ft_ms_per_bar()
   - assumes 4/4 signature for Electribe (true for all E2)
   ------------------------------------------------------- */
int ft_ms_per_bar(void)
{
    return ft_ms_per_beat() * 4;
}

/* -------------------------------------------------------
   ft_wait_ms()
   Safe busy-wait implementation used across project
   (Auto-Recorder, Song Mode, Randomizer operations).
   ------------------------------------------------------- */
void ft_wait_ms(int ms)
{
    volatile int i;
    // calibrated roughly to ARM E2 speed, same as original recorder
    for (i = 0; i < ms * 2000; ++i)
    {
        __asm__ volatile("nop");
    }
}

/* -------------------------------------------------------
   ft_wait_bars()
   Wait N bars using BPM-derived timing.
   Used by Song Mode for pattern playback timing.
   ------------------------------------------------------- */
void ft_wait_bars(int bars)
{
    if (bars <= 0) return;

    int total = bars * ft_ms_per_bar();
    int chunk = 100; // 100 ms → responsive to break conditions
    int waited = 0;

    while (waited < total)
    {
        int rem = total - waited;
        int step = (rem < chunk) ? rem : chunk;
        ft_wait_ms(step);
        waited += step;
    }
}

```

### apps/autorecorder/sync_live.c
<a name="appsautorecordersynclivec"></a>

- **Name:** `sync_live.c`
- **Pfad:** `apps/autorecorder/sync_live.c`
- **SHA256:** `f084626dd24ba169b80c221cc028cd2f1d498197d99d6052a230e3059ede3326`

```
#include "sync_live.h"

#include <stdint.h>
#include <string.h>

#include "ft_api.h"
#include "randomizer.h"
#include "midi_out.h"
#include "groove_engine.h"

/* ============================================================
   LIVE SYNC STATE
   ============================================================ */

live_sync_state_t g_live;

/* ============================================================
   STEP REPEATER
   ============================================================ */

#define MAX_PARTS    16
#define MAX_REPEAT   8

#define NOTE_LENGTH_TICKS_DIV 4   /* gate = step_len / 4 */

typedef struct {
    uint8_t  active;
    uint8_t  repeat;
    uint8_t  fired;
    uint8_t  note_on;

    uint32_t step_start;
    uint32_t step_len;

    uint32_t next_fire;
    uint32_t note_off;
} step_repeat_state_t;

static step_repeat_state_t g_rep[MAX_PARTS];

/* ============================================================
   INTERNAL UTILS
   ============================================================ */

static inline int32_t clampi32(int32_t v, int32_t lo, int32_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static void rep_reset(int p)
{
    memset(&g_rep[p], 0, sizeof(step_repeat_state_t));
}

/* idx: 0..rep */
static uint32_t rep_tick(uint32_t start,
                         uint32_t len,
                         int rep,
                         int idx)
{
    if (rep <= 0) return start;
    return start + ((uint64_t)len * (uint64_t)idx) / (uint64_t)rep;
}

/* Map repeat index -> phase 0..127 */
static uint8_t rep_phase_0_127(int fired, int repeat)
{
    if (repeat <= 1) return 0;

    if (fired < 0) fired = 0;
    if (fired > repeat) fired = repeat;

    return (uint8_t)((fired * 127) / repeat);
}

/* Groove timing offset (bounded inside step) */
static int32_t groove_offset_ticks(uint32_t step_len,
                                   uint8_t phase,
                                   uint8_t amount)
{
    if (amount == 0 || step_len == 0)
        return 0;

    int32_t shape = (int32_t)groove_curve_timing_shape(phase);

    int32_t max_ticks = (int32_t)(step_len / 32);
    if (max_ticks < 1)  max_ticks = 1;
    if (max_ticks > 12) max_ticks = 12;

    int32_t off = (shape * max_ticks) / 32;
    off = (off * (int32_t)amount) / 127;

    int32_t hard = (int32_t)(step_len / 8);
    if (hard < 1) hard = 1;

    return clampi32(off, -hard, hard);
}

static int32_t groove_velocity_delta(uint8_t phase, uint8_t amount)
{
    if (amount == 0)
        return 0;

    int32_t shape = (int32_t)groove_curve_velocity_shape(phase);
    int32_t dv    = (shape * (int32_t)amount) / 127;

    return clampi32(dv, -24, 24);
}

/* ============================================================
   MIDI EMIT
   ============================================================ */

static void emit_note_on(int part, int vel)
{
    midi_send_byte((uint8_t)(0x90 | (part & 0x0F)));
    midi_send_byte(60); /* placeholder note */
    midi_send_byte((uint8_t)(vel & 0x7F));
}

static void emit_note_off(int part)
{
    midi_send_byte((uint8_t)(0x80 | (part & 0x0F)));
    midi_send_byte(60);
    midi_send_byte(0);
}

/* ============================================================
   PUBLIC API
   ============================================================ */

void live_sync_init(void)
{
    memset(&g_live, 0, sizeof(g_live));

    g_live.pattern  = ft_get_current_pattern();
    g_live.bpm_x100 = ft_get_bpm() * 100;

    for (int i = 0; i < MAX_PARTS; ++i)
        rep_reset(i);

    groove_init();
}

void live_sync_on_start(void)
{
    g_live.is_playing = 1;
    g_live.step = 0;
    g_live.bar  = 0;

    for (int i = 0; i < MAX_PARTS; ++i)
        rep_reset(i);
}

void live_sync_on_stop(void)
{
    g_live.is_playing = 0;

    for (int i = 0; i < MAX_PARTS; ++i)
        rep_reset(i);
}

void live_sync_tick(void)
{
    static int      last_step = -1;
    static uint32_t last_step_tick = 0;

    uint32_t now = ++g_live.tick;

    if (!g_live.is_playing)
        return;

    int step = ft_get_play_position();

    g_live.step = step;
    g_live.bar  = (step / 16) & 0x03;

    g_live.pattern  = ft_get_current_pattern();
    g_live.bpm_x100 = ft_get_bpm() * 100;

    /* ========================================================
       STEP CHANGE
       ======================================================== */
    if (step != last_step)
    {
        uint32_t step_len =
            (last_step_tick > 0) ? (now - last_step_tick) : 1;

        if (step_len == 0) step_len = 1;
        last_step_tick = now;

        for (int part = 0; part < MAX_PARTS; ++part)
        {
            int r = randomizer_get_step_repeat(part, step);

            if (r <= 1)
            {
                rep_reset(part);
                continue;
            }

            if (r > MAX_REPEAT) r = MAX_REPEAT;

            step_repeat_state_t *s = &g_rep[part];

            s->active     = 1;
            s->repeat     = (uint8_t)r;
            s->fired      = 0;
            s->note_on    = 0;
            s->step_start = now;
            s->step_len   = step_len;

            uint8_t phase = rep_phase_0_127(0, r);
            uint8_t amt   = groove_get_macro();

            int32_t off = groove_offset_ticks(step_len, phase, amt);
            int32_t t   = (int32_t)rep_tick(now, step_len, r, 0) + off;

            t = clampi32(t,
                         (int32_t)now,
                         (int32_t)(now + step_len - 1));

            s->next_fire = (uint32_t)t;
        }

        last_step = step;
    }

    /* ========================================================
       REPEATER PLAYBACK
       ======================================================== */
    for (int part = 0; part < MAX_PARTS; ++part)
    {
        step_repeat_state_t *s = &g_rep[part];
        if (!s->active)
            continue;

        if (s->note_on && now >= s->note_off)
        {
            emit_note_off(part);
            s->note_on = 0;
        }

        if (now >= s->next_fire && s->fired < s->repeat)
        {
            int rep    = s->repeat;
            int fired  = s->fired;

            int vel = 127 - (fired * (64 / (rep ? rep : 1)));
            if (vel < 20) vel = 20;

            uint8_t phase = rep_phase_0_127(fired, rep);
            vel = clampi32(
                vel + groove_velocity_delta(phase, groove_get_macro()),
                1, 127
            );

            emit_note_on(part, vel);

            s->note_on  = 1;
            s->note_off = now + (s->step_len / NOTE_LENGTH_TICKS_DIV);
            if (s->note_off <= now)
                s->note_off = now + 1;

            s->fired++;

            uint32_t base = rep_tick(s->step_start,
                                     s->step_len,
                                     rep,
                                     s->fired);

            int32_t off = groove_offset_ticks(
                s->step_len,
                rep_phase_0_127(s->fired, rep),
                groove_get_macro()
            );

            int32_t t = (int32_t)base + off;

            int32_t lo = (int32_t)s->step_start;
            int32_t hi = (int32_t)(s->step_start + s->step_len - 1);

            t = clampi32(t, lo, hi);
            if (t <= (int32_t)now) t = (int32_t)now + 1;
            if (t > hi) t = hi;

            s->next_fire = (uint32_t)t;

            if (s->fired >= s->repeat)
                s->active = 0;
        }
    }
}

```

### apps/autorecorder/sync_live.h
<a name="appsautorecordersyncliveh"></a>

- **Name:** `sync_live.h`
- **Pfad:** `apps/autorecorder/sync_live.h`
- **SHA256:** `e4785df5c53fc6bf3a483fc21e23ad639b3694cad42b5f03978366dc92896768`

```
#ifndef SYNC_LIVE_H
#define SYNC_LIVE_H

#include <stdint.h>

typedef struct {
    uint8_t is_playing;      // 1 = Sequencer läuft
    uint16_t step;           // Step Position (0..63 oder erweitert)
    uint8_t bar;             // berechneter Takt 0–3
    uint32_t tick;           // interner globaler Tick
    uint8_t pattern;         // aktuelles Pattern
    uint32_t bpm_x100;       // BPM * 100
} live_sync_state_t;

extern live_sync_state_t g_live;

void live_sync_init(void);
void live_sync_tick(void);
void live_sync_on_start(void);
void live_sync_on_stop(void);

#endif

```

### apps/autorecorder/syscalls.c
<a name="appsautorecordersyscallsc"></a>

- **Name:** `syscalls.c`
- **Pfad:** `apps/autorecorder/syscalls.c`
- **SHA256:** `244b8d5e001b55131360c11a180e02bf9f102d8bffb36063575d1a415e894429`

```
/*
 * syscalls.c
 *
 * Minimal-Implementierung für newlib auf der Electribe-CPU.
 * Stellt Memory-Allocation, Write/Read-Stubs und Tick-System bereit.
 */

#include <sys/stat.h>
#include <errno.h>
#include <stdint.h>
#include <stddef.h>

/* --------------------------------------------------------------------
   Heap für malloc() – vom Linker vorgegeben
   -------------------------------------------------------------------- */

extern uint32_t _end;     // Start des freien RAM (nach BSS)
extern uint32_t _estack;  // Ende des RAM (oberes Limit vom Linker)

static uint8_t *heap_ptr = (uint8_t *)&_end;

void *_sbrk(ptrdiff_t incr)
{
    uint8_t *prev = heap_ptr;
    uint8_t *next = heap_ptr + incr;

    if (next >= (uint8_t *)&_estack) {
        errno = ENOMEM;
        return (void *)-1;
    }

    heap_ptr = next;
    return prev;
}

/* --------------------------------------------------------------------
   newlib Syscalls – Dummy-Implementierungen
   -------------------------------------------------------------------- */

int _open(const char *name, int flags, int mode)
{
    (void)name; (void)flags; (void)mode;
    return -1;       // keine Dateien vorhanden
}

int _close(int file)
{
    (void)file;
    return -1;
}

int _fstat(int file, struct stat *st)
{
    (void)file;
    st->st_mode = S_IFCHR;   // Character device
    return 0;
}

int _isatty(int file)
{
    (void)file;
    return 1;
}

off_t _lseek(int file, off_t ptr, int dir)
{
    (void)file; (void)ptr; (void)dir;
    return 0;
}

/* --------------------------------------------------------------------
   Write: Weiterleitung an ft_puts (falls benötigt)
   -------------------------------------------------------------------- */

extern void ft_puts(const char *s);   // optional

int _write(int file, char *ptr, int len)
{
    (void)file;

    // Optional: Text an Firmware-Print weiterleiten
    // ACHTUNG: ptr ist kein Nullterminierter String
    // Ft_puts akzeptiert nur nullterminierte Strings → also NICHT benutzen.

    return len;   // OK, "geschrieben"
}

/* --------------------------------------------------------------------
   Read: nicht unterstützt
   -------------------------------------------------------------------- */

int _read(int file, char *ptr, int len)
{
    (void)file; (void)ptr; (void)len;
    return 0;
}

/* --------------------------------------------------------------------
   Prozesskontrolle – nicht verwendet
   -------------------------------------------------------------------- */

int _kill(int pid, int sig)
{
    (void)pid; (void)sig;
    return -1;
}

int _getpid(void)
{
    return 1;
}

void _exit(int status)
{
    (void)status;
    while (1) {}   // Soft-Halt
}

/* --------------------------------------------------------------------
   Tick-System – globaler Zeitmesser
   Wird z.B. im SysTick-Interrupt inkrementiert.
   -------------------------------------------------------------------- */

volatile uint32_t system_ticks = 0;

uint32_t syscall_get_ticks(void)
{
    return system_ticks;
}

```

### apps/autorecorder/sysex_helper.c
<a name="appsautorecordersysexhelperc"></a>

- **Name:** `sysex_helper.c`
- **Pfad:** `apps/autorecorder/sysex_helper.c`
- **SHA256:** `f2b7e92cedacd3369f5d2d85ff52e4f525806a23795c2245e34227382e0e4b28`

```
#include "sysex_helper.h"

/* leer – alle Funktionen im Header inline */

```

### apps/autorecorder/sysex_helper.h
<a name="appsautorecordersysexhelperh"></a>

- **Name:** `sysex_helper.h`
- **Pfad:** `apps/autorecorder/sysex_helper.h`
- **SHA256:** `7047b5700846ad4c3c369c7116ec1c5717f0e19877f2b32fb2dd33425058076d`

```
#ifndef SYSEX_HELPER_H
#define SYSEX_HELPER_H

#include <stdint.h>
#include <stdbool.h>

/* ============================================================
   Sysex Helper – Platzhalter
   Funktioniert als Dummy, bis echte Sysex-Logik implementiert wird
   ============================================================ */

/* Beispiel: Erstelle Sysex Dump in Buffer */
static inline int sysex_build_full_dump(uint8_t *out, int maxlen)
{
    /* TODO:
       - Gerätezustand abfragen
       - Original Electribe Strukturen füllen
       - Echte Sysex Formatierung implementieren
    */

    /* Platzhalter: erzeugt leeren Dump */
    if (!out || maxlen <= 0) return 0;
    return 0;
}

/* Beispiel: sende fertigen Sysex-Dump */
static inline bool sysex_send_dump(const uint8_t *data, int len)
{
    /* TODO:
       - UART / MIDI OUT senden
       - CHUNKING 256b
       - NRPN Log: "Sysex Dump gesendet"
    */

    (void)data;
    (void)len;
    return true;
}

#endif /* SYSEX_HELPER_H */

```

### apps/autorecorder/ui/ui_display.c
<a name="appsautorecorderuiuidisplayc"></a>

- **Name:** `ui_display.c`
- **Pfad:** `apps/autorecorder/ui/ui_display.c`
- **SHA256:** `a9a86141765cfcbdc608538229086dc19963f13591fb18327055e5f13653057d`

```
#include "ui_display.h"
#include "app_log.h"
#include "ft_api.h"     /* draw_text(), clear_display() usw. */
#include <string.h>
#include <stdio.h>

typedef struct {
    char text[64];
    uint32_t timer;
    uint8_t active;
} ui_msg_t;

static ui_msg_t msg_queue[4];
static uint8_t queue_head = 0;
static uint8_t queue_tail = 0;

/* interne Hilfsfunktion */
static void ui_queue_push(const char *txt)
{
    uint8_t next = (queue_tail + 1) & 3;
    if (next == queue_head) {
        /* Queue voll, wir verwerfen die älteste Meldung */
        queue_head = (queue_head + 1) & 3;
    }

    strncpy(msg_queue[queue_tail].text, txt, sizeof(msg_queue[queue_tail].text));
    msg_queue[queue_tail].text[sizeof(msg_queue[queue_tail].text) - 1] = '\0';
    msg_queue[queue_tail].timer = UI_MSG_TIMEOUT_MS;
    msg_queue[queue_tail].active = 1;

    queue_tail = next;
}

/* UTF-8 zu Electribe-kompatibel */
static void ui_normalize_text(char *dst, const char *src)
{
    while (*src && strlen(dst) < 63)
    {
        switch (*src)
        {
            case 'ä': strcat(dst, "ae"); break;
            case 'ö': strcat(dst, "oe"); break;
            case 'ü': strcat(dst, "ue"); break;
            case 'Ä': strcat(dst, "Ae"); break;
            case 'Ö': strcat(dst, "Oe"); break;
            case 'Ü': strcat(dst, "Ue"); break;
            case 'ß': strcat(dst, "ss"); break;
            default:
                {
                    size_t len = strlen(dst);
                    dst[len] = *src;
                    dst[len+1] = '\0';
                }
                break;
        }
        src++;
    }
}

/* 1-Zeilen Popup */
void ui_show_message(const char *msg)
{
    char normalized[64] = {0};
    ui_normalize_text(normalized, msg);

    ui_queue_push(normalized);
    app_log(normalized);
}

/* Mehrzeilige Meldungen (automatisch umbrechen) */
void ui_show_message_long(const char *msg)
{
    char tmp[64] = {0};
    ui_normalize_text(tmp, msg);

    /* Hard break nach 16 Zeichen (Electribe Display Breite) */
    char line1[20] = {0}, line2[20] = {0}, line3[20] = {0};
    strncpy(line1, tmp, 16);
    strncpy(line2, tmp + 16, 16);
    strncpy(line3, tmp + 32, 16);

    ui_queue_push(line1);
    if (line2[0]) ui_queue_push(line2);
    if (line3[0]) ui_queue_push(line3);
}

/* Meldung sofort anzeigen (SAVE-Popup) */
void ui_force_message(const char *msg)
{
    char normalized[64] = {0};
    ui_normalize_text(normalized, msg);

    ft_api_clear_display();
    ft_api_draw_text(0, 0, normalized);
    ft_api_refresh();

    app_log(normalized);
}

/* Wird in main loop aufgerufen */
void ui_display_tick(uint32_t ms_elapsed)
{
    if (queue_head == queue_tail)
        return; /* keine Meldung aktiv */

    ui_msg_t *m = &msg_queue[queue_head];

    if (!m->active)
        return;

    ft_api_clear_display();
    ft_api_draw_text(0, 0, m->text);
    ft_api_refresh();

    if (m->timer > ms_elapsed)
        m->timer -= ms_elapsed;
    else
    {
        /* Meldung abgelaufen */
        m->active = 0;
        queue_head = (queue_head + 1) & 3;
    }
}

```

### apps/autorecorder/ui/ui_display.h
<a name="appsautorecorderuiuidisplayh"></a>

- **Name:** `ui_display.h`
- **Pfad:** `apps/autorecorder/ui/ui_display.h`
- **SHA256:** `541d95115ab99aee429e91f0cc08cfdd66f9879acc2ef4f7339ffc722334b9dd`

```
#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <stdint.h>

/* Standarddauer für Popup-Meldungen */
#define UI_MSG_TIMEOUT_MS 1800

/* Eine kurze 1-Zeilen Meldung anzeigen */
void ui_show_message(const char *msg);

/* Mehrzeilige Nachricht (automatische Umbrüche + Timeout) */
void ui_show_message_long(const char *msg);

/* Eine Nachricht erzwingen (ohne Warteschlange) */
void ui_force_message(const char *msg);

/* Wird 1× pro Frame aus main_loop() aufgerufen */
void ui_display_tick(uint32_t ms_elapsed);

#endif

```

### apps/autorecorder/ui_messages.c
<a name="appsautorecorderuimessagesc"></a>

- **Name:** `ui_messages.c`
- **Pfad:** `apps/autorecorder/ui_messages.c`
- **SHA256:** `6e5f6ca8099b00c139215c5d7eeb05843825062e84e920bcfadc1157457593fa`

```
#include "ui_messages.h"
#include "ft_api.h"     /* wegen ft_print – existiert bereits */

void ui_show_message(const char *msg)
{
    /* Placeholder: Ausgabe in UART/Debug-Konsole */
    ft_print("[UI] %s\n", msg);

    /* TODO: Später Display ansteuern */
}

void ui_show_icon(const uint8_t *bitmap, int w, int h)
{
    /* Placeholder: Keine echte Grafik-Ausgabe */
    ft_print("[UI] Icon (%dx%d) angezeigt.\n", w, h);

    /* TODO: Pixel-Draw implementieren */
}

```

### apps/autorecorder/ui_messages.h
<a name="appsautorecorderuimessagesh"></a>

- **Name:** `ui_messages.h`
- **Pfad:** `apps/autorecorder/ui_messages.h`
- **SHA256:** `f6d0fe90537405ad3c92dc60d1e5b86e785947974ab92d645959868edc6e29e8`

```
#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#include <stdint.h>

/*
 * Simple UI abstraction layer for AutoRecorder
 * All messages / icons in DEUTSCH.
 *
 * Diese Funktionen können später auf das echte Display,
 * OLED, LCD oder SysEx-Statusmeldung umgebogen werden.
 */

void ui_show_message(const char *msg);
void ui_show_icon(const uint8_t *bitmap, int w, int h);

#endif /* UI_MESSAGES_H */

```

### apps/Makefile
<a name="appsmakefile"></a>

- **Name:** `Makefile`
- **Pfad:** `apps/Makefile`
- **SHA256:** `610d0384fd24c43ca62bc106241c0f1ca6034231ff9ee9e1e27af696bcb9ecb5`

```
APP ?= autorecorder

.PHONY: all clean $(APP)

all:
	$(MAKE) -C $(APP)

clean:
	$(MAKE) -C $(APP) clean

```

### export_mega_source.py
<a name="exportmegasourcepy"></a>

- **Name:** `export_mega_source.py`
- **Pfad:** `export_mega_source.py`
- **SHA256:** `93c8ecf73edd3c036212329c38c80d01777097f82e2b68656804af7c03a14f22`

```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import hashlib
from pathlib import Path

ROOT_DIR = Path(".").resolve()
OUTPUT_FILE = ROOT_DIR / "MEGA_SOURCE.md"

# ❌ Verzeichnisse komplett ausschließen
EXCLUDE_DIRS = {
    "build",
    ".git",
    ".vscode",
    "__pycache__",
}

# ❌ Dateien ausschließen
EXCLUDE_FILES = {
    "e2pat.all",
}

# ❌ Extensions ausschließen (binär / müll)
EXCLUDE_EXTENSIONS = {
    ".bin", ".elf", ".o", ".a", ".so", ".dll", ".exe",
    ".base64",
}

# ✔️ als Text erlaubte Extensions
TEXT_EXTENSIONS = {
    ".c", ".h", ".hpp", ".cpp",
    ".py", ".sh",
    ".S", ".ld",
    ".md", ".txt",
    ".json", ".yml", ".yaml", ".ini", ".cfg",
    ".mk", ".cmake",
}

SPECIAL_TEXT_FILES = {
    "Makefile",
    "Dockerfile",
}

def sha256_of_file(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(8192), b""):
            h.update(chunk)
    return h.hexdigest()

def is_text_file(path: Path) -> bool:
    if path.name in SPECIAL_TEXT_FILES:
        return True
    return path.suffix.lower() in TEXT_EXTENSIONS

def should_exclude(path: Path) -> bool:
    if path.name in EXCLUDE_FILES:
        return True
    if path.suffix.lower() in EXCLUDE_EXTENSIONS:
        return True
    for part in path.parts:
        if part in EXCLUDE_DIRS:
            return True
    return False

def chapter_of(path: Path) -> str:
    p = path.as_posix().lower()
    if p.startswith("docs/") or path.suffix.lower() in {".md", ".txt"}:
        return "DOCS"
    return "SRC"

def safe_read_text(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        return path.read_text(encoding="utf-8", errors="replace")

def anchor_for(rel_path: str) -> str:
    # GitHub-kompatible Markdown-Anker
    return rel_path.lower().replace("/", "").replace(".", "").replace("_", "")

# ---------------- MAIN ----------------

files = []

for root, dirs, filenames in os.walk(ROOT_DIR):
    # prune excluded dirs
    dirs[:] = [d for d in dirs if d not in EXCLUDE_DIRS]

    for name in filenames:
        p = Path(root) / name
        rel = p.relative_to(ROOT_DIR)

        if should_exclude(rel):
            continue
        if not is_text_file(rel):
            continue

        files.append(rel)

files.sort(key=lambda p: p.as_posix().lower())

chapters = {
    "SRC": [],
    "DOCS": [],
}

for f in files:
    chapters[chapter_of(f)].append(f)

out = []

# Header
out.append("# Mega Source Export\n")
out.append(f"**Root:** `{ROOT_DIR}`  \n")
out.append(f"**Dateien:** {len(files)}  \n")
out.append("\n---\n")

# TOC
out.append("## Index\n")
for ch in ("SRC", "DOCS"):
    out.append(f"### {ch}")
    for f in chapters[ch]:
        anchor = anchor_for(f.as_posix())
        out.append(f"- [`{f.as_posix()}`](#{anchor})")
    out.append("")
out.append("\n---\n")

# Content
for ch in ("SRC", "DOCS"):
    out.append(f"## {ch}\n")
    for f in chapters[ch]:
        abs_path = ROOT_DIR / f
        sha = sha256_of_file(abs_path)
        anchor = anchor_for(f.as_posix())

        out.append(f"### {f.as_posix()}")
        out.append(f"<a name=\"{anchor}\"></a>\n")
        out.append(f"- **Name:** `{f.name}`")
        out.append(f"- **Pfad:** `{f.as_posix()}`")
        out.append(f"- **SHA256:** `{sha}`\n")

        out.append("```")
        out.append(safe_read_text(abs_path))
        out.append("```\n")

OUTPUT_FILE.write_text("\n".join(out), encoding="utf-8")
print(f"✔ MEGA_SOURCE.md erzeugt ({len(files)} Dateien)")

```

### Makefile
<a name="makefile"></a>

- **Name:** `Makefile`
- **Pfad:** `Makefile`
- **SHA256:** `33a5e0a7280dd0394f7b1361df423a600fc6b405c4bae169f151398a797c6313`

```
.PHONY: all apps clean

all: apps

apps:
	cd apps && $(MAKE)

clean:
	cd apps && $(MAKE) clean

```

### scripts/e2-backup-bootloader.py
<a name="scriptse2-backup-bootloaderpy"></a>

- **Name:** `e2-backup-bootloader.py`
- **Pfad:** `scripts/e2-backup-bootloader.py`
- **SHA256:** `fb262ce001f81b440abcd614d953d772a7cbb5fac15a6cfdf40b72cee8ed7a49`

```
import sys
import logging

from e2sysex import *

logging.basicConfig(level=logging.DEBUG)

in_port = None
out_port = None

if len(sys.argv) > 1:
    in_port = sys.argv[1]

if len(sys.argv) > 2:
    out_port = sys.argv[2]

# Read the Secondary Bootloader (SBL) from On-Chip RAM
#   This is not the Application Image Script (AIS) stored in the flash
#   Do not write this data to flash memory

e = E2Sysex(in_port, out_port)

print("Reading SBL from On-Chip RAM")
b = e.read_cpu_ram(0x80000000, 0x1C000)

path = "e2-bootloader.bin"
with open(path, "wb") as f:
    f.write(b)

print("Bootloader saved to", path)
print("Do not write this data to flash memory")

```

### scripts/e2-firmware-patch.py
<a name="scriptse2-firmware-patchpy"></a>

- **Name:** `e2-firmware-patch.py`
- **Pfad:** `scripts/e2-firmware-patch.py`
- **SHA256:** `9bae7c16e8bba9a6b05adbd32f4b22fb40c31c0ccd0a2af6b7a5e90ad7ec56d3`

```
# Hacktribe 2 firmware patcher

import argparse
import hashlib
from bsdiff4 import file_patch

def main():
    parser = argparse.ArgumentParser()	
    parser.add_argument("-s", "--src", dest='src_path', help="path/to/source/SYSTEM.VSB")
    parser.add_argument("-d", "--dst", dest='dst_path', help="path/to/destination/hacked-SYSTEM.VSB")
    parser.add_argument("-p", "--patch", dest='patch_path', help="path/to/hacktribe-2.patch")
    parser.add_argument("-e", "--edit-header", dest='edit_header', action='store_true', help="Edit file header to allow install on e2 synth.")
    parser.set_defaults(edit_header=False)
    
    args = parser.parse_args()

    if args.src_path:
        src_path = args.src_path
    else:
        src_path = 'SYSTEM.VSB'

    if args.dst_path:
        dst_path = args.dst_path
    else:
        dst_path = 'hacked-SYSTEM.VSB'

    if args.patch_path:
        patch_path = args.patch_path
    else:
        patch_path = 'patch/hacktribe-2.patch'
    
    if args.edit_header:
        edit_header = True
        sd_path = 'KORG/electribe/System/SYSTEM.VSB'
        device = 'Electribe 2 Synth'
    else:
        edit_header = False
        sd_path = 'KORG/electribe sampler/System/SYSTEM.VSB'
        device = 'Electribe 2 Sampler'

    
    src_hash = '1d0f0689d5a12c8a8bde9f821f2a59adc5f6cd6012ddb201ebb192b72468a646'

    if edit_header:
         with open ("hash/modified-hacked-SYSTEM.VSB.sha", "r") as f:
            targ_hash=f.readlines()[0].split()[0]       
    else:
        with open ("hash/hacked-SYSTEM.VSB.sha", "r") as f:
            targ_hash=f.readlines()[0].split()[0]


    print('\nHacktribe firmware patcher.\n')
    print('https://github.com/bangcorrupt/hacktribe\n')
    
    print('Source file hash'.ljust(32, ' '), ':', src_hash, '\n')

    if get_digest(src_path) != src_hash:
        print('ERROR: Incorrect source file.')
        print('Electribe 2 Sampler firmware version 2.02 only.')
        print("Download Electribe 2 Sampler firmware version 2.02 and move 'SYSTEM.VSB' to 'hacktribe' directory.\n")
        exit()

    else:
        print('Electribe 2 Sampler firmware version 2.02 found.\n')

    print('Patching firmware for ' +device+ '...\n')

    file_patch(src_path, dst_path, patch_path)

    if edit_header:
        modify_header(dst_path)
    
    dst_hash = get_digest(dst_path)   

    print('Target file hash'.ljust(32, ' '), ':', targ_hash)

    if  dst_hash != targ_hash:
        print('Destination file hash'.ljust(32, ' '), ':', dst_hash, '\n')
        print('ERROR: Patch FAILED.')
        print('Do not install modified firmware.\n')
        exit(1)

    else:
        print('Destination file hash'.ljust(32, ' '), ':', dst_hash, '\n')
        print('Firmware patched successfully.\n')
        print("Copy '" +dst_path+ "' to 'SD:/" +sd_path+ "' and update firmware.\n") 
        exit(0)


def modify_header(path):
    with open(path, 'rb') as f:
        hak = bytearray(f.read())

    print("Modifying header of '" +path+ "'...\n")
    
    # e2
    hak[0x12] = 0x00
    hak[0x2e] = 0x23

    with open(path, 'wb') as f:
        f.write(hak)


def get_digest(path):
    h = hashlib.sha256()

    with open(path, 'rb') as file:
        while True:
            chunk = file.read(h.block_size)
            if not chunk:
                break
            h.update(chunk)

    return h.hexdigest()

if __name__ == '__main__':
    main()

```

### scripts/e2-header.py
<a name="scriptse2-headerpy"></a>

- **Name:** `e2-header.py`
- **Pfad:** `scripts/e2-header.py`
- **SHA256:** `2f5b856377c158490646b70b2972b95b92f1517571293190eecb60c63d979e39`

```
# Modify Electribe 2 Sampler file header for Electribe 2 Synth

import os
import sys

if len(sys.argv) < 3:
    print('Usage:')
    print()
    print('e2-header.py FILE_PATH [synth|sampler]')
    exit()

path = sys.argv[1]
if os.path.exists(path):
    print('Modifying header', os.path.basename(path))


    with open(path, 'rb') as f:
        hak = bytearray(f.read())

    if sys.argv[2] == 'sampler':
        # e2s
        hak[0x12] = 0x53
        hak[0x2e] = 0x24
    
    elif sys.argv[2] == 'synth':
        # e2
        hak[0x12] = 0x00
        hak[0x2e] = 0x23
    
    else:
        print("Incorrect argument:", sys.argv[2] + '.', "Must be either 'synth' or 'sampler'.")
    

    with open(path, 'wb') as f:
        f.write(hak)

else:
    print('File not found')

```

### scripts/e2-init-pat.py
<a name="scriptse2-init-patpy"></a>

- **Name:** `e2-init-pat.py`
- **Pfad:** `scripts/e2-init-pat.py`
- **SHA256:** `008a67ac0fbab2f57be845c794cc06a96574063f065356e9585d5058f83792a1`

```
# Set Electribe 2 Sampler firmware version 2.02 init pattern

import os
import sys

if len(sys.argv) < 3:
    print('Usage:')
    print()
    print('Supports Electribe 2 Sampler firmware version 2.02 only')
    print()
    print('python e2s-init-pat.py SYSTEM.VSB init-pat.e2spat')
    print()
    exit()

print('Supports Electribe 2 Sampler firmware version 2.02 only')

vsb_path = sys.argv[1]
if os.path.exists(vsb_path):

    pat_path = sys.argv[2]
    if os.path.exists(pat_path):
 
        print('Modifying firmware')
        
        with open(vsb_path, 'rb') as f:
            vsb = bytearray(f.read())
        
        with open(pat_path, 'rb') as f:
            pat = bytearray(f.read())[0x100:0x3d00]
        
        assert len(pat) == 0x3c00

        head = vsb[:0x100]
        hak = vsb[0x100:]

        # Sampler v2.02
        hak[0xcff58:0xcff58+0x3c00] = pat

        fw = head + hak
        
        assert len(fw) == 0x200100
        
        with open(vsb_path, 'wb') as f:
            f.write(fw)

    else:
        print('Pattern file not found')

else:
    print('Firmware file not found')

```

### scripts/e2_add_header.py
<a name="scriptse2addheaderpy"></a>

- **Name:** `e2_add_header.py`
- **Pfad:** `scripts/e2_add_header.py`
- **SHA256:** `ffb33013c770e3ba9716fd4cb519eac57c83424ccc39a8e7bf54a06d2e94c090`

```
import argparse
from construct import *


# File format struct defs

# VSB file header format
# Default is SYSTEM.VSB for E2S v2.02
vsb_header = Struct('title' / Default(PaddedString(0x10, 'ascii'), 'KORG SYSTEM FILE'),
                    'dev_name' / Default(PaddedString(0x10, 'ascii'), 'E2S'),
                    'file_id' / Default(PaddedString(0x8, 'ascii'), 'SYSTEM'),
                    'rev' / Default(Int16ub, 1),
                    'maj_ver' / Default(Int8ub, 2),
                    'min_ver' / Default(Int8ub, 2),
                    Padding(1),
                    'dev_id' / Default(Hex(Int16ub), 0x124),
                    Padding(1, pattern=b'\xff'),
                    Padding(4),
                    'src_len' / Default(Hex(Int32ul), 0x200000),
                    Padding(4),
                    'dest_len' / Default(Hex(Int32ul), 0x200000),
                    'unk_int' / Default(Int16ul, 2),
                    Padding(0xbe, pattern=b'\xff')
                   )

def main():
    parser = argparse.ArgumentParser()	
    parser.add_argument("-s", "--src", dest='src_path', help="path/to/source/SYSTEM.VSB")
    parser.add_argument("-d", "--dst", dest='dst_path', help="path/to/destination/hacked-SYSTEM.VSB")
    
    args = parser.parse_args()
    
    if args.src_path:
        src_path = args.src_path
    else:
        src_path = 'test.hacktribe.bin'

    if args.dst_path:
        dst_path = args.dst_path
    else:
        dst_path = 'test.hacktribe.SYSTEM.VSB'

    with open(src_path, 'rb') as f:
        src_bin = f.read()
    
    header = vsb_header.build(dict())
    
    dest_vsb = header + src_bin
    
    with open(dst_path, 'wb') as f:
        f.write(dest_vsb)
    
    
if __name__ == "__main__":
    main()

```

### scripts/e2_groove_template.py
<a name="scriptse2groovetemplatepy"></a>

- **Name:** `e2_groove_template.py`
- **Pfad:** `scripts/e2_groove_template.py`
- **SHA256:** `4e36ef8c5ab397885bab3e9eec890d96b74050872c9f5edc167aa4a4795ed397`

```
from e2sysex import *

def main():
    
    # Instantiate SysEx communication
    e = E2Sysex()
    
    # Create blank groove template
    groove = E2Groove.new()
    
    # Set groove name
    groove.name = "Test groove 1"
    
    # Set groove loop length (re-triggers on pattern loop)
    groove.length = 13
    
    # Move 5th step forward half a step
    groove.edit_step(4, 'trigger', 48)
    
    # Move 13th step backward half a step
    groove.edit_step(12, 'trigger', -48)
    
    # Decrease 1st step velocity by 32
    groove.edit_step(0, 'velocity', -32)
    
    # Set 3rd step velocity to 127
    groove.step[2].velocity = 127
    
    # Set 11th step gate time to 96 (tie)
    groove.step[10].gate = 96
    
    # Send new groove template to 1st position in list
    groove_index = 0
    e.set_groove(groove_index, groove.data)
    

class E2Groove:

    # Returns E2Groove object with initialised parameter values
    def new():
        gv = bytearray(0x140)
        
        # Groove start
        gv[:4] = b'GVST'
        
        # Groove name
        gv[0x10:0x1f] = b'Init Groove'.ljust(0x0f, b'\x00')[:0x0f]
        
        # Groove length
        gv[0x22] = 0x40
        gv[0x23] = 0xff
        
        # Trigger, velocity, gate
        base = 0x30
        leng = 4
        for i in range(0,   0x100, 4):
            offset = base + int(i/4) * leng
            gv[offset] = 0x00
            gv[offset+1] = 0x60
            gv[offset+2] = 0x60
            gv[offset+3] = 0xff

        # Groove end
        gv[-4:] = b'GVED'
        
        return E2Groove(gv)


    # gv_data is bytearray
    def __init__(self, gv_data):
        self.data = gv_data

        self._name = str(self.data[0x10:0x20], 'ascii').strip('\x00')
        self._length = self.data[0x22]
        
        self.step = []
        for i in range(0x40):
            self.step.append(E2GrooveStep(self.data, i))

    
    # Groove name
    @property
    def name(self):
        return self._name
    
    @name.setter
    def name(self, strn):
        self.data[0x10:0x1f] = strn.encode('ascii').ljust(0x0f, b'\x00')[:0x0f]
        self._name = str(self.data[0x10:0x1f], 'ascii').strip('\x00')

    
    # Groove length
    @property
    def length(self):
        return self._length
    
    @length.setter
    def length(self, val):
        self.data[0x22] = val
        self._length = self.data[0x22]


    # Edit parameter value at step
    # param is target parameter, one of 'trigger', 'velocity', 'gate'
    # delta is integer change to existing value
    def edit_step(self, step_idx, param, delta):
        
        if param not in ['trigger', 'velocity', 'gate']:
            return
        
        if param == 'trigger':
            self.step[step_idx].trigger = self.step[step_idx].trigger + delta
        
        elif param == 'velocity':
            self.step[step_idx].velocity = self.step[step_idx].velocity + delta
            
        elif param == 'gate':
            self.step[step_idx].gate = self.step[step_idx].gate + delta
        
        else:
            return


class E2GrooveStep:
    def __init__(self, data, idx):
        self.data = data
        
        base = 0x30
        leng = 4
        self.offset = base + idx * leng
        
        self._trigger = self.data[self.offset]
        self._velocity = self.data[self.offset+1]
        self._gate = self.data[self.offset+2]
        self._null = self.data[self.offset+3]
    
    
    # Trigger time
    @property
    def trigger(self):
        return self._trigger
    
    @trigger.setter
    def trigger(self, val):
        
        # Clamp to valid range
        if val > 0x30:
            val = 0x30
        elif val < -0x30:
            val = -0x30
        
        # Two's complement
        if val < 0:
            val = 0x100 + val
        
        self.data[self.offset] = val
        self._val = self.data[self.offset]


    # Velocity
    @property
    def velocity(self):
        return self._velocity
    
    @velocity.setter
    def velocity(self, val):
        
        # Clamp to valid range
        if val > 0x7f:
            val = 0x7f
        elif val < 0:
            val = 0

        self.data[self.offset+1] = val
        self._val = self.data[self.offset+1]


    # Gate time
    @property
    def gate(self):
        return self._gate
    
    @gate.setter
    def gate(self, val):
        
        # Clamp to valid range
        if val > 0x60:
            val = 0x60
        elif val < 0:
            val = 0

        self.data[self.offset+2] = val
        self._val = self.data[self.offset+2]


    # null
    @property
    def null(self):
        return self._null
    
    @null.setter
    def null(self, val):

        self.data[self.offset+3] = val
        self._val = self.data[self.offset+3]


if __name__ == '__main__':
    main() 

```

### scripts/e2_merge_patterns.py
<a name="scriptse2mergepatternspy"></a>

- **Name:** `e2_merge_patterns.py`
- **Pfad:** `scripts/e2_merge_patterns.py`
- **SHA256:** `416b40a4dd606a86de8efc23f04b14c7e72153ff6f2022841be0f5d0c540043a`

```
"""
Merges e2spat files in a directory into a single e2sallpat file.
I am very unpleased with another script that is named "e2pat2all.py" >:(
Usage: e2_merge_patterns.py <input directory> <output patterns file>

Expects filenames to be in format "XXX_NAME.e2pat" for example:
001_Something off.e2pat
051_W[`IRNMO.e2pat
250_ACIDSATAN.e2pat

March 20th 2025
@author: noVictim
"""

import re
import os
import sys

def eat_file(filepath) -> bytearray:
    with open(filepath, "rb") as f:
        return bytearray(f.read())
    return bytearray()

def find_pattern_files(directory):
    matched_files = {}
    pattern = re.compile(r"^(\d{3})_\s*[\w\[\]`!@#$%^&*()\-+=~'. ]*\.e2pat$", re.IGNORECASE)
    for filename in os.listdir(directory):
        match = pattern.match(filename)
        if match:
            num = int(match.group(1))
            if 1 <= num <= 250:
                matched_files[num] = filename
    return matched_files


if __name__ == '__main__':

    if sys.version_info <= (3,10):
        exit(f"Assumes Python version 3.10+, you have {sys.version_info.major}.{sys.version_info.minor}")
    if len(sys.argv) != 3:
        exit("Usage: e2_merge_patterns.py <input directory> <output patterns file>")
    if not os.path.exists(sys.argv[1]) or not os.path.isdir(sys.argv[1]):
        exit(f'Invalid input directory "{sys.argv[1]}"')
    
    # Grab reference init file and work from there
    allpat = eat_file(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'init/electribe_sampler_allpattern.e2sallpat'))

    for num, filename in find_pattern_files(sys.argv[1]).items():
        pattern = eat_file(os.path.join(sys.argv[1], filename))

        # Rename pattern to filename just in case
        pattern[0x110:0x110+16] = filename[4:-6].encode('ascii').ljust(16, b'\x00')

        offset = 0x10100 + (0x4000 * (num - 1))
        allpat[offset:offset+0x4000] = pattern[256:] # we mustn't copy the pattern's header

    with open(sys.argv[2], "wb") as f:
        f.write(allpat)

```

### scripts/e2_recode_sample_pat.py
<a name="scriptse2recodesamplepatpy"></a>

- **Name:** `e2_recode_sample_pat.py`
- **Pfad:** `scripts/e2_recode_sample_pat.py`
- **SHA256:** `8b9aa0433975deb96699f9031b9e7c23939cbe21e786bbe3cce0a01119618fc5`

```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Read sample library from e2sSample.all file, 
move sample references into slots 501+ as far as possible,
save altered library as e2sSample.shift.all,
and create a lookup table for the new osc locations. 

Sample file format: see https://github.com/untergeekDE/electribe2-docs/blob/main/e2sSample-all-file-format.md
Pattern file format: see e2pat_shift.py script

Read pattern file and recode patterns to use new osc locations.

2022-01-02
@author: untergeekDE
"""
import argparse
import os
import re # Regular Expressions

# Using bangcorrupt's e2all2pat.py script as a base.
# For testing in Spyder IDE: change working directory one level up
# os.chdir("..")

def get_category(c):
    # Convert integer to category string
    categories = ['Analog', # 0
                  'Audio In', 
                  'Kick', 
                  'Snare', 
                  'Clap',
                  'HiHat', #5
                  'Cymbal', 
                  'Hits', 
                  'Shots', 
                  'Voice', 
                  'SE', #10
                  'FX', 
                  'Tom', 
                  'Perc', 
                  'Phrase', 
                  'Loop', #15
                  'VPM', 
                  'Wave']
    if c > 17:
            return f"Error: {c}"
    return categories[c]

def get_pointers(buffer):
    # Return a list of pointers
    l = []
    for i in range(1000):
        ii = i * 4 +0x10
        p = int.from_bytes(buffer[ii:ii+4],'little')
        if (p > 0):
            l.append(p)
    return l

def get_used_osc_set(buffer):
    # Return a set with all the oscs used in the patterns. 
    # Structure of .e2allpat file: 
    # Extensive info can be found here: http://www.korgforums.com/forum/phpBB2/viewtopic.php?t=95368
    #    
    # 0x00000-0x00100: Korg Electribe file header
    # Next 0x10000 bytes (64k) are filler bytes containing 0xFF.
    # Length of one pattern is 0x4000 (16k) 
    # Data for the patterns 1-250 follows from 0x10100.
    # Part data starts 0x800 (2k) into the pattern data, i.e. first pattern is from 0x10900.
    # Length of one part is 0x330.
    # Osc data is 0x08 (lo) and 0x09 (hi) into this data. 
    osc_list = []
    pat_ofs = 0x10100
    pat_len = 0x4000
    part_ofs = 0x0800
    part_len = 0x0330
    # Repeat for all 250 patterns: 
    for i in range(250):
        # Repeat for all 16 parts:
        for k in range(16):
            part_ptr = pat_ofs + (i * pat_len) + part_ofs + (k * part_len)
            # Return oscillator for pattern 
            osc_list.append(buffer[part_ptr + 0x08] + 256 * buffer[part_ptr + 0x09])
    osc_set = set(osc_list)
    return osc_set

def get_used_pattern_set(buffer,osc):
    # Return a set with all the patterns making use of that osc. 
    # Structure of .e2allpat file: 
    # Extensive info can be found here: http://www.korgforums.com/forum/phpBB2/viewtopic.php?t=95368
    #    
    # 0x00000-0x00100: Korg Electribe file header
    # Next 0x10000 bytes (64k) are filler bytes containing 0xFF.
    # Length of one pattern is 0x4000 (16k) 
    # Data for the patterns 1-250 follows from 0x10100.
    # Part data starts 0x800 (2k) into the pattern data, i.e. first pattern is from 0x10900.
    # Length of one part is 0x330.
    # Osc data is 0x08 (lo) and 0x09 (hi) into this data. 
    pattern_set ={} 
    pat_ofs = 0x10100
    pat_len = 0x4000
    part_ofs = 0x0800
    part_len = 0x0330
    # Repeat for all 250 patterns: 
    for i in range(250):
        # Repeat for all 16 parts:
        for k in range(16):
            part_ptr = pat_ofs + (i * pat_len) + part_ofs + (k * part_len)
            # Return oscillator for pattern and add to list
            if osc == (buffer[part_ptr + 0x08] + 256 * buffer[part_ptr + 0x09]):
                pattern_set.append(i)
    return pattern_set


def get_sample_pointer(buf,i):
    # Read pointer from header block
    return(int.from_bytes(buf[i*4+16:i*4+20],'little'))

def get_sample_list(buf):
    # Check if sample is referenced, add to list if yes
    sample_list = []
    for i in range(1000):
        if get_sample_pointer(buf[0:0x1000],i) > 0:
            sample_list.append(i)
    return sample_list

def get_sample_name(buf,i):
    # Follow pointer and get category
    p = get_sample_pointer(buf,i)
    if p == 0: 
        return "?"
    RIFF_len = int.from_bytes(buf[p+4:p+8],'little') + 8
    # Calculate location of sample slot number: 0x494 bytes before the end
    sample_name_p = p + RIFF_len - 0x494 + 0x02
    # Assign the new sample number
    name = str(buf[sample_name_p:sample_name_p+16],encoding="utf-8")
    return re.sub(r'[^\w\s-]',' ',name)


def get_sample_category(buf,i):
    # Follow pointer and get category
    if i == 17: 
        # This is Audio In
        return 1 
    if i < 17: 
        # These are the Analog Synth models
        return 0
    p = get_sample_pointer(buf, i)
    if p == 0: 
        return 18 # "--"
    RIFF_len = int.from_bytes(buf[p+4:p+8],'little') + 8
    # Calculate location of sample slot number: 0x494 bytes before the end
    sample_cat_p = p + RIFF_len - 0x494 + 0x012
    # Assign the new sample number
    return int.from_bytes(buf[sample_cat_p:sample_cat_p+2],'little')

def main():        
    explanation = """This script reads an Electribe's sample library and pattern 
    dump files, and adapts them for the HackTribe: As you cannot use the 
    Factory sample slots (1-500).  
    in the HackTribe, the factory and user samples are moved to 501-999. The 
    code tries to fit as much as possible to the User slots; if there are 
    more samples than slots available,
    it starts overwriting loops and phrases not used in the patterns."""
    parser = argparse.ArgumentParser(epilog=explanation)    
    parser.add_argument("-s", "--sample", dest='sampleFile', help="path/to/input/file.e2sallpat")
    parser.add_argument("-p", "--pattern", dest='patternFile', help="path/to/input/e2sSample.all")
    parser.add_argument("-o", "--outdir", dest='outDir', help="path/to/output/")
    parser.add_argument("-f", "--ofs", dest='user_ofs', help="Offset in user memory (default: 18 to start factory samples at slot 519, makes it easier to find them)")
    parser.add_argument("-m", "--minimal", action="store_true", help="If this flag is set, all unused samples are discarded, and offset is set to 0")
    args = parser.parse_args()
    
    patternFile = './electribe_sampler_allpattern.e2sallpat'
    sampleFile = './e2sSample.all'
    outDir = "."
    minimalMode = args.minimal
    if minimalMode: 
        user_ofs = "0"
    else:
        user_ofs = "18"
    
    if args.sampleFile:
        sampleFile = args.sampleFile
    if args.patternFile:
        patternFile = args.patternFile
    if args.outDir:
        outDir = args.outDir
    
    if args.user_ofs:
        user_ofs = args.user_ofs

    # Check for valid range
    ofs_val = abs(int(user_ofs))
    if ofs_val > 500:
        ofs_val = ofs_val % 500
        

    # Conversion strategy: 
    #     - Start by moving factory samples 019-420 
    #     - Fill the empty slots at the end with user samples until full (999)
    #     - Fill any empty slots at the beginning (only if ofs is used)
    #     - Start overwriting sample slots not used in patterns, from the loop/phrase category dowmnwards 
    #     - When running out of slots, stop reassignment with a message listing unassigned samples. 
    #     Reorder:
    #     - Create a dictionary mapping old -> new osc slots
    #     - Create a text file containing the mappings
    #     - Remap osc numbers in patterns 
    #     - Write changed osc slots to sample blocks
    #     - Create the new pointer table
    #     - Save modified copies of .all and .e2sallpat files

    # Read sample file into memory
    try:
        with open(sampleFile, 'rb') as f:
            sample_buf =  bytearray(f.read())   
    except:
        print("Could not read ",sampleFile," into memory. Stopping.")
        return()
    else: 
        print(len(sample_buf)," bytes read from ",sampleFile)

    # Read pattern file into memory

            
    
    
    # Read pattern file into memory
    try:
        with open(patternFile, 'rb') as f:
            pattern_buf =  bytearray(f.read())    
    except:
        print("Could not read ",patternFile," into memory. Stopping.")
        return()
    else: 
        print(len(pattern_buf)," bytes read from ",patternFile)
        

    # Get a set of all oscs used in the patterns
    unfiltered_set = get_used_osc_set(pattern_buf)
    # ...and take out the synth oscs (0-17)
    osc_set = {x for x in unfiltered_set if x > 17}
    # Get a list of the existing samples from the sample bank
    old_header = sample_buf[0:0x1000]
    sample_list = get_sample_list(old_header)
    dropped_sample_list = []
    # Prepare Lookup dictionary; for first 18 slots: input = output. 
    old_to_new_dict = {}
    for i in range(18): 
        old_to_new_dict[i] = i
        
    # Test for number of sample slots needed. More samples used than slots
    # available? Will lose memory. 
    free_slots = 499
    if len(osc_set) > free_slots:
        print("WARNING: ",len(osc_set)," samples in use - only 499 will fit!!")
        print("Forcing Minimal Mode.")
        minimalMode = True
        # Cut off all samples beyond no. 499
        dropped_sample_list.append(sample_list[free_slots:])
        sample_list = sample_list[0:free_slots]
        print("See dropped_samples.txt for details.")
    #---- Remove unused samples in --minimal mode. ----
    if minimalMode: 
        for osc_no in sample_list:
            if not (osc_no in osc_set):
                # Erase entry in pre-move pointer table
                old_header[4*osc_no + 0x10] = 0
                old_header[4*osc_no + 0x11] = 0
                old_header[4*osc_no + 0x12] = 0
                old_header[4*osc_no + 0x13] = 0
                # Remove from sample list, add to removed samples list
                sample_list.remove(osc_no)
                dropped_sample_list.append(osc_no)
    
    #---- Remove unused samples if more space is needed. ----
    needed_slots = len(sample_list)
    # Do we need to lose some samples?
    # Calculate how many, and lose them.
    p = 0
    while needed_slots > free_slots:
        if sample_list[p] not in osc_set:
            needed_slots = needed_slots - 1
            dropped_sample_list.append(sample_list[p])
            del sample_list[p]
        else:
            p = p + 1

    #---- Generate all output files in output directory ---- 
    # Change to output directory
    if not os.path.isdir(outDir):
        os.mkdir(outDir)
    os.chdir(outDir)
    
    # Write samples marked for deletion to a file before deleting. 
    with open('dropped_samples.txt', 'w') as f:
        f.write("Dropped files listed by old number and name\n")
        f.write("-------------------------------------------\n")
    # Iterate over the dictionary and write each key-value pair to the file
        for osc in dropped_sample_list:
            osc_name = get_sample_name(sample_buf, osc)
            osc_cat = get_category(get_sample_category(sample_buf, osc))
            end_str = ""
            if osc in osc_set:
                # Very special case - samples dropped that are being used
                end_str = '!!!USED IN PATTERNS ' 
                for pat in get_used_pattern_set(pattern_buf, osc):
                    end_str = end_str + str(pat + 1) + " "
            f.write (f"{osc:03d} {osc_name} ({osc_cat}) {end_str}\n")
    
            
    #---- Moving samples ----
    # For the time being, don't move the samples, only change references. 
    
    # This loop steps through all existing samples.
    # First, it goes looking for the next free position.
    # If it doesn't find any, it gets more and more aggressive, 
    # overwriting unused sample slots in the process.)   
            
    # Assign first free position with offset. 
    # Why the offset? I found that I could keep track better if the
    # factory samples are still in their original position +500, so I
    # run this script with the --ofs 18 parameter, i.e. the factory samples
    # go from 19...421 to 519...921. 
    # Create a blank pointer table for moving
    for i in range(0x10,0x1000):
        sample_buf[i] = 0
    i = 500+ofs_val
    # Now: Move sample pointers and correct sample references.  
    for osc_no in sample_list:     
        # Start reading from slot 019 to 421
        # Humans count from 1, machines from 0.
        p = get_sample_pointer(old_header,osc_no)
        # Save sample pointer to new location in pointer table
        sample_buf[4*i + 0x10:4*i + 0x14] = p.to_bytes(4,'little')
        # Rewrite osc number in RIFF block
        # Get length of whole RIFF chunk
        RIFF_len = int.from_bytes(sample_buf[p+4:p+8],'little') + 8
        # Pointer to beginning of ESLI data data block
        esli_p = p + RIFF_len - 0x494
        # Write slot number: is stored 0x494 bytes before the end
        sample_buf[esli_p] = i % 256
        sample_buf[esli_p + 1] = i // 256
        # Write "Absolute Sample No" in esli_p + 0x14  
        abs_sample_no = i + 50
        sample_buf[esli_p + 0x14] = abs_sample_no % 256
        sample_buf[esli_p + 0x15] = abs_sample_no // 256
        # Rewrite categories 16 (PCM) and 17 (User) - 
        # ...the Hacktribe firmware re-brands them VPM and WAVE. 
        sample_cat = sample_buf[esli_p + 0x12] + 256 * sample_buf[esli_p + 0x13]
        if sample_cat == 16:
            sample_buf[esli_p + 0x12] = 17 # Make former PCM WAVE
        # Leave former USER category as WAVE
        # Add new location to dictionary
        old_to_new_dict[osc_no] = i
        # And don't forget to add 1 for the humans.
        print("Moved factory sample ",osc_no + 1," to slot ",i + 1)
        i = (i + 1) 
        if i > 500+free_slots:
            i = 500
    print("Changed categories: PCM -> WAVE, User -> WAVE")
    
    #---- Rewrite new osc numbers to patterns ----
    patOff = 0x10100
    patLen = 0x4000
    partOff = 0x0800
    partLen = 0x0330
    # Repeat for all 250 patterns: 
    for i in range(250):
        # When printing, add 1 for humans. 
        print("== Processing pattern ",i+1," ==")
        # Repeat for all 16 parts:
        for k in range(16):
            partPtr = patOff + (i*patLen) + partOff + (k * partLen)
            partOsc = pattern_buf[partPtr + 0x08] + 256 * pattern_buf[partPtr + 0x09]
            # New Oscillator
            try:
                shiftOsc = old_to_new_dict[partOsc]
                # Write shifted osc reference to data buffer
                pattern_buf[partPtr + 0x08] = shiftOsc % 256
                pattern_buf[partPtr + 0x09] = shiftOsc // 256
            except: 
                print("!!WARNING: Osc",partOsc+1,
                      "in Pattern ", i + 1,
                      ", Part ",k + 1,
                      "does not exist in sample set")
    
    #---- Write mappings
    with open('old_to_new_map.txt', 'w') as f:
        f.write("OLD --- NEW Osc Numbers ------\n")
    # Iterate over the dictionary and write each key-value pair to the file
        for key, value in old_to_new_dict.items():
            osc_name = get_sample_name(sample_buf, value)
            osc_cat = get_category(get_sample_category(sample_buf, value))
            osc_old = key + 1
            osc_new = value +1 
            map_text = (f'{osc_old:03d} --- {osc_new:03d} {osc_name} ({osc_cat})\n')
            f.write(map_text)
            print(map_text,end="")
    
    # Generate new pattern bank file hacktribe.e2sallpat
    # Copy to /KORG/hacktribe/
    with open("hacktribe.e2sallpat", 'wb') as f:
        f.write(pattern_buf)
    print("File hacktribe.e2sallpat generated - copy to SD card to load.")
    
    # Generate new sample bank file hacktribeSample.all
    with open("hacktribeSample.all", 'wb') as f:
        f.write(sample_buf)
    # Copy to /KORG/hacktribe/sample/e2sSample.all
    print("File hacktribeSample.all generated - copy to /KORG/hacktribe/Sample/e2sSample.all on SD CARD.")
    print("Done.")
    
if __name__ == '__main__':
    main()

```

### scripts/e2_sample_all_to_wav.py
<a name="scriptse2samplealltowavpy"></a>

- **Name:** `e2_sample_all_to_wav.py`
- **Pfad:** `scripts/e2_sample_all_to_wav.py`
- **SHA256:** `c4cb7a83f494d72ada92d917419d3f8b2ed23564b82956d806a198e76eaef34e`

```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Read e2sSample.all library and split it into single .WAV files with e2 metadata

For file format, see https://github.com/untergeekDE/electribe2-docs/blob/main/e2sSample-all-file-format.md
Created on Fri Dec 30 00:31:16 2022

@author: jan
"""

import argparse
import os
import re

# os.chdir("..")

# Using bangcorrupt's e2all2pat.py script as a base.

def get_category(c):
    # Convert integer to category string
    categories = ['Analog',
                  'Audio In', 
                  'Kick', 
                  'Snare', 
                  'Clap',
                  'HiHat', 
                  'Cymbal', 
                  'Hits', 
                  'Shots', 
                  'Voice', 
                  'SE', 
                  'FX', 
                  'Tom', 
                  'Perc', 
                  'Phrase', 
                  'Loop', 
                  'PCM', 
                  'User']
    return categories[c]

def get_pointers(buffer):
    # Return a list of pointers
    l = []
    for i in range(1000):
        ii = i * 4 +0x10
        p = int.from_bytes(buffer[ii:ii+4],'little')
        if (p > 0):
            l.append(p)
    return l

def main():        
    explanation = """This script reads a sample dump library and
        outputs each sample as a .WAV file followed by Korg's looping metadata.
        These files can be imported individually using the DATA UTILITY menu. """
    parser = argparse.ArgumentParser(epilog=explanation)    
    parser.add_argument("-s", "--sample", dest='sample_file', help="path/to/input/e2sSample.all")
    parser.add_argument("-o", "--outdir", dest='out_dir', help="path/to/output/")
    args = parser.parse_args()
    
    sample_file = './e2sSample.all'
    out_dir = "./output"

    if args.sample_file:
        sample_file = args.sample_file
    if args.out_dir:
        out_dir = args.out_dir
        
    # Start reading sample file into memory
    try:
        with open(sample_file, 'rb') as f:
            buffer =  bytearray(f.read())   
    except:
        print("Could not read ",sample_file," into memory. Stopping.")
        return()
    else: 
        print("Samples read from ",sample_file)
    
    if not os.path.isdir(out_dir):
        os.mkdir(out_dir)
    os.chdir(out_dir)
    # Copy pointers to all the samples 
    pointers = get_pointers(buffer)
    
    for p in pointers:
        # Get length of whole RIFF chunk
        # It's in the 4 bytes just after the "RIFF" marker. 
        RIFF_len = int.from_bytes(buffer[p+4:p+8],'little') + 8
        # Copy the whole thing to a new buffer
        wavebuf = buffer[p:p+RIFF_len]
        # Get the sample number
        sample_no = wavebuf[RIFF_len - 0x494] + wavebuf[RIFF_len - 0x493] * 256
        sample_name = str(wavebuf[RIFF_len - 0x492:RIFF_len - 0x482], encoding="utf-8")
        cat_no = wavebuf[RIFF_len - 0x482] + wavebuf[RIFF_len - 0x481] * 256
        print(sample_no+1,"  ",sample_name," (",get_category(cat_no),") len: ",len(wavebuf))
        # Create file name removing all non-alphanumeric chars via Regex
        # Add 1 to sample no for humans.
        wavefile = re.sub(r'[^\w\s-]','','{0:03d}-{1:s}'.format(sample_no+1,sample_name))
        with open(str(wavefile) + '.wav', 'wb') as f:
            f.write(wavebuf)
            
    print("Done - written ",len(pointers)," sample files")
                

if __name__ == '__main__':
    main()

```

### scripts/e2_syx_codec.py
<a name="scriptse2syxcodecpy"></a>

- **Name:** `e2_syx_codec.py`
- **Pfad:** `scripts/e2_syx_codec.py`
- **SHA256:** `91050de916650b18fdf0ef1389bcf375767162d22193bb77b6150b4d304c4130`

```
# Encode/decode bytes to/from SysEx for Electribe 2

"""
The dump data conversion

   DATA ( 1set = 8bit x 7Byte )
   b7     ~      b0   b7     ~      b0   b7   ~~    b0   b7     ~      b0
   +-+-+-+-+-+-+-+-+  +-+-+-+-+-+-+-+-+  +-+-+-~~-+-+-+  +-+-+-+-+-+-+-+-+
   | | | | | | | | |  | | | | | | | | |  | | |    | | |  | | | | | | | | |
   +-+-+-+-+-+-+-+-+  +-+-+-+-+-+-+-+-+  +-+-+-~~-+-+-+  +-+-+-+-+-+-+-+-+
         7n+0               7n+1          7n+2 ~~ 7n+5         7n+6

    MIDI DATA ( 1set = 7bit x 8Byte )
      b7b7b7b7b7b7b7     b6    ~     b0     b6 ~~    b0     b6    ~     b0
   +-+-+-+-+-+-+-+-+  +-+-+-+-+-+-+-+-+  +-+-+-~~-+-+-+  +-+-+-+-+-+-+-+-+
   |0| | | | | | | |  |0| | | | | | | |  |0| |    | | |  |0| | | | | | | |
   +-+-+-+-+-+-+-+-+  +-+-+-+-+-+-+-+-+  +-+-+-~~-+-+-+  +-+-+-+-+-+-+-+-+
   7n+6,5,4,3,2,1,0         7n+0          7n+1 ~~ 7n+5         7n+6
"""

def syx_enc(byt):
    
    lng = len(byt)
    lst = []
    tmp = []
    b = 0
    cnt = 7
    lim = 0
    for i,e in enumerate(byt):

        if lng < 7:
            lim = 7 - lng

        a = e & ~0b10000000
        b |= ((e & 0b10000000)>>cnt)
        
        tmp.append(a)
        
        cnt -= 1
        if cnt == lim:
            lst.append([b])
            lst.append(tmp)
            tmp = []
            b = 0
            cnt = 7

            if (lng - i) < 7:
                lim = 7 - (lng - i) + 1

    syx = [item for sublist in lst for item in sublist]

    return syx


def syx_dec(syx):

    chk = [syx[i:i + 8] for i in range(0, len(syx), 8)]

    lst = []
    tmp = []
    a = 0
    
    for l in chk:
        for i in range(len(l)-1):
            a = l[i+1]
            a |= ((l[0] & (1<<i))>>i)<<7
            
            tmp.append(a)

        lst.append(tmp)
        tmp = []
    
    byt = [item for sublist in lst for item in sublist]
    
    return byt

```

### scripts/e2_update_pat_samples.py
<a name="scriptse2updatepatsamplespy"></a>

- **Name:** `e2_update_pat_samples.py`
- **Pfad:** `scripts/e2_update_pat_samples.py`
- **SHA256:** `2ac6ef033243073705ff29ab4bc4cdda6924d421cf78d77a853b8c900f592bbc`

```
#!/usr/bin/env python3
"""
Updates e2sallpat after updating a sample library.
Useful for when the order of your samples changes frequently.
NOTE: This script does not understand renamed samples!

Sample file format: see https://github.com/untergeekDE/electribe2-docs/blob/main/e2sSample-all-file-format.md
Pattern file format: see http://www.korgforums.com/forum/phpBB3/viewtopic.php?t=95368

Usage: e2_update_pat_samples.py <patterns file> <old sample all> <new sample all>

March 19th 2025
@author: noVictim
"""

import sys

def eat_file(filepath) -> bytes:
    data = bytes()
    with open(filepath, "rb") as f:
        data += f.read()
    return data

def read_sample_addrs(data) -> list:
    addrs = []
    for i in range(1002):
        offset = 0x58 + (4 * i)
        address = int.from_bytes(data[offset : offset + 4], 'little')
        addrs.append(address)
    return addrs

def get_samples(data) -> dict:
    samples = {}
    for i, addr in enumerate(read_sample_addrs(data)):
        if addr == 0x00000000:
            continue
        esli_p = addr + int.from_bytes(data[addr+4:addr+8], 'little') - 0x494
        id_p = esli_p + 0x08
        name_p = esli_p + 0x0A
        sample_id = int.from_bytes(data[id_p:id_p+2], 'little')
        sample_name = data[name_p:name_p+16]
        samples[sample_id] = sample_name
    return samples

def find_changes(old_names, new_names) -> tuple[list,dict,list]:
    added_nums = []
    deleted_nums = []
    moved_nums = {}
    for num, name in old_names.items():

        # Deleted items
        if name not in new_names.values():
            print(f"Deleted {name.decode('ascii')}")
            deleted_nums.append(num)
            continue
        
        # Moved items
        if name != new_names[num]:
            for new_num, new_name in new_names.items():
                if name == new_name:
                    break
            print(f"Moved {name.decode('ascii')} {num} -> {new_num}")
            moved_nums[num] = new_num
    
    for num, name in new_names.items():
        if not name in old_names.values():
            print(f"Added {name.decode('ascii')} at {num}")
            added_nums.append(num)
    return (deleted_nums, moved_nums, added_nums)



if __name__ == '__main__':

    if sys.version_info <= (3,10):
        exit(f"Assumes Python version 3.10+, you have {sys.version_info.major}.{sys.version_info.minor}")
    if len(sys.argv) != 4:
        exit("Usage: e2_update_pat_samples.py <patterns file> <old sample all> <new sample all>")

    old_names = get_samples(eat_file(sys.argv[2]))
    new_names = get_samples(eat_file(sys.argv[3]))
    deleted, moved, added = find_changes(old_names, new_names)

    e2allpat_mode = True # TODO: implement the latter
    input_allpat = eat_file(sys.argv[1])
    output_allpat = bytearray(input_allpat)

    for pattern_index in range(250):
        for part_num in range(16):

            # Read oscillator ID
            pattern_offset = 0
            if e2allpat_mode:
                pattern_offset = 0x10100 + (0x4000 * pattern_index)
            offset = pattern_offset + 0x800 + (0x330 * part_num) + 0x08
            oscillator = int.from_bytes(input_allpat[offset : offset+2], 'little')

            # Update this part's oscillator to the newly corresponding ID if needed
            if oscillator in moved.keys():
                output_allpat[offset : offset+2] = moved[oscillator].to_bytes(2, 'little')

    with open(sys.argv[1], "wb") as f:
        f.write(bytes(output_allpat))

```

### scripts/e2all2pat.py
<a name="scriptse2all2patpy"></a>

- **Name:** `e2all2pat.py`
- **Pfad:** `scripts/e2all2pat.py`
- **SHA256:** `6d529cfd517cd64666762ec7c0d5998e39fa5f2e9783154387207bd0efc3e544`

```
import pathlib
import argparse

def main():		
	parser = argparse.ArgumentParser()	
	parser.add_argument("-i", "--input", dest='inFile', help="path/to/input/file.e2allpat")
	parser.add_argument("-o", "--output", dest='outDir', help="path/to/output/directory")
	args = parser.parse_args()
	
	inFile = 'electribe_allpattern.e2allpat'
	outDir = 'split_allpat'
	
	if args.inFile:
		inFile = args.inFile
	if args.outDir:
		outDir = args.outDir
		
	pathlib.Path(outDir).mkdir(parents=True, exist_ok=True)
	
	with open(inFile, 'rb') as f:
		apData =  bytearray(f.read())	
	
	patOff = 0x10100
	patLen = 0x4000
	for i in range(250):
		start = patOff+(i*patLen)
		end = start + patLen
		data = apData[start:end]
		outFile = outDir + '/' + str(i+1).zfill(3) + '_' + data[16:32].decode().rstrip('\0')	# get pattern name from data

		data = apData[:256] + data																# add korg file header
		with open(outFile + '.e2pat', 'wb') as f:
			f.write(data)

if __name__ == '__main__':
    main()

```

### scripts/e2ev.py
<a name="scriptse2evpy"></a>

- **Name:** `e2ev.py`
- **Pfad:** `scripts/e2ev.py`
- **SHA256:** `14890e4c1d653b0858f543fd01f2c7613f814c287635e295398f449661103952`

```
# INCOMPLETE

import ntpath
import math
import binascii
from bitstring import BitArray
import os
import argparse


def main():		
	parser = argparse.ArgumentParser()	
	parser.add_argument("inFile", metavar="INPUT_FILE", type=str, help="path/to/load/file.e2ev")
	parser.add_argument("-s", "--split", dest='split', help="Split event recording by pattern change", action='store_true')	
	parser.add_argument("-c", "--channels", dest='channels', nargs='+', help="Mute all channels except list of channel numbers to include in stem (0 - 15)")
	parser.add_argument("-n", "--name", dest='name', help="Name for stem.")
	parser.add_argument("-e", "--extract", dest='extract', help="Extract pattern files from event recording", action='store_true')
	parser.add_argument("-r", "--replace", dest='replace', help="Pattern number to replace.  Requires -p file.e2pat.  Overwrites original ev file.")
	parser.add_argument("-p", "--pattern", dest='pattern', help="path/to/pattern/file.e2pat")	
	parser.add_argument("-m", "--mute", dest='mute', help="Channel number to mute (0 - 15)")
	parser.add_argument("-i", "--info", dest='info', help="Print patterns found")
	args = parser.parse_args()

	ev = EventRec(args.inFile)
	
	if args.split:
		ev.split_by_pattern()
	
	if args.channels and args.name:
		ev.get_stem(args.channels, args.name)
		
	if args.extract:
		ev.extract_patterns()
	
	if args.replace and args.pattern:
		ev.replace_pattern(int(args.replace), args.pattern)
		ev.write_evData()
		
	if args.mute:
		ev.mute_channel(int(args.mute))
		ev.write_evData()

	if args.info:
		ev.get_info()

class EventRec:
	def __init__(self, path):
		print('This tool is unfinished.  Back up your files.')
		self.path = path
		self.name = self.get_filename(self.path)
		self.get_evData()

	
	def get_info(self):
		print(str(self.patCount) + ' patterns found.')
		for i in range(len(self.evPat)):		
			p = self.evPat[i].patData[0x10:0x1F]
			while p and p[-1] is 0:
				p.pop()	
			print(str(i) + ' ' + p.decode("utf-8") )


	def get_evData(self):	
		self.evData = []
		with open(self.path, 'rb') as f:
			self.evData =  bytearray(f.read())	
		ptCount = self.evData.count(bytearray('PTST', 'ascii'))
		self.patCount = ptCount
		ptPos = []
		x = 0
		for i in range(0, ptCount):
			x = self.evData.find(bytearray('PTST', 'ascii'), x+1)
			ptPos.append(x)
		self.evPat = []
		for i in range(0, ptCount):
			startByte = ptPos[i]
			try:
				endByte = ptPos[i+1]
			except:
				endByte = len(self.evData)-8
			self.evPat.append(EvPat(self, i, startByte, endByte))	# e2eventrec split by pattern change
			
		
	def write_evData(self, evPat=None, name=None):
		if not name:
			name = self.get_filename(self.path)[:-5]	
		if not evPat:
			evPat = self.evPat
		z = []
		evPatMod = []
		for i in range(len(evPat)):
			z.append(evPat[i].patData)
			for j in range(len(evPat[i].perfData)):
				z.append(evPat[i].perfData[j])
		for x in z:
			for y in x:
				evPatMod.append(y)	
		evPatMod = bytearray(evPatMod)	
		evDataMod = self.evData[:280] + evPatMod + self.evData[-8:]
		
		# insert file size
		leng = len(evDataMod)-288
		try:
			leng  = bytearray.fromhex('0' + hex(leng)[2:])[::-1]
		except:
			leng  = bytearray.fromhex(hex(leng)[2:])[::-1]
		pos = 260
		for byte in leng:			
			evDataMod[pos] = byte
			pos+=1
		evDataMod[pos] = 0x00

		with open(name + '.e2ev', 'wb') as f:
			f.write(bytearray(evDataMod))
			

	def mute_channel(self, channel):
		for j in range(0, len(self.evPat)):
			#	Add vol CC = 0 at start
			b  = b'\x00\x00\x00\x00\x01\x00' + bytes([channel]) + b'\x00\x26\x00\xFF\xFF\x00\x00\x00\x00'
			self.evPat[j].perfData.insert(self.evPat[j].goMsgPos+1,b)
			p = []	
			for msg in self.evPat[j].perfData:
				line = bytearray(msg)	# copy to mutable
				
				#	set volume changes to 0	
				if line[4] == 1 and line[6] == channel and line[8] == 38:
					line[12] = 0x00
					line[13] = 0x00 
				
				#	set all note velocities for channel to 0
				if len(line) == 16 and line[4] == 0 and line[11] == 1:		
					noteOn = int(str(hex(line[8])[2:3]), 16)
					chan = int(str(hex(line[8])[3:4]), 16)
					if noteOn == 9 and chan == channel:
						line[10] = 0x00
				p.append(line)			
			
			for i in range(0,len(p)):
				self.evPat[j].perfData[i] = p[i]	

	
	def extract_patterns(self):
		i = 0
		for pat in self.evPat:
			pattern = self.evData[:256] + pat.patData
			with open(self.name[:-5] + '_pat_' + str(i) + '.e2pat', 'wb') as f:
				f.write(pattern)
			i+=1


	def replace_pattern(self, position, pattern):
		with open(pattern, 'rb') as f:
			new_patData =  bytearray(f.read())		
		self.evPat[position].patData = new_patData[256:]
		
	
	def split_by_pattern(self):
		i = 0
		for evpat in self.evPat:
			ev = [evpat]
			self.write_evData(evPat=ev, name=self.name[:-5] + '_pat_' + str(i))
			i+=1
	
	
	def get_stem(self, channels, name):	# channels is list of channel numbers to include in stem
		mutes = [x for x in range(16) if x not in channels]
		for channel in mutes:
			self.mute_channel(channel)
		self.write_evData(name=self.name[:-5] + '_' + name + '_stem')
		self.get_evData()


	def get_filename(self, path):
		head, tail = ntpath.split(path)
		return tail or ntpath.basename(head)



class EvPat:
	def __init__(self, evRec, number, startByte, endByte):
		self.evRec = evRec
		self.evData = evRec.evData
		self.number = number
		self.patSt = startByte
		self.perfSt = startByte + 16384	
		self.endByte = endByte

		self.get_patData()
		self.get_perfData()


	def get_patData(self):
		self.patData = self.evData[self.patSt:self.patSt+16384]
		
			
	def get_perfData(self):	
		self.goMsgPos = 0
		j = 0	
		self.perfData = []
		for i in range(self.perfSt-8, self.endByte+8, 16):
			line = self.evData[i:i+16]
			self.perfData.append(line)
			if len(line) == 16:
				if line[8] != 0x00 and line[12] == 0x03 and line[11] == 0x00:
					self.goMsgPos = j
			j+=1
		self.perfData[0] = self.perfData[0][-8:]
		self.perfData[-1] = self.perfData[-1][:-8]


   
if __name__ == '__main__':
    main()


```

### scripts/e2pat2all.py
<a name="scriptse2pat2allpy"></a>

- **Name:** `e2pat2all.py`
- **Pfad:** `scripts/e2pat2all.py`
- **SHA256:** `c14595de2781c5336c24698e1b3249e5f800ab692f21ec42f832c2c679d4ff43`

```
import pathlib
import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", dest='inFile',
                        help="path/to/input/file.e2pat")
    parser.add_argument("-o", "--output", dest='outDir',
                        help="path/to/output/directory")
    args = parser.parse_args()

    inFile = 'init/init.e2pat'
    outDir = 'merged_allpat'
    outFile = 'electribe_sampler_allpattern.e2sallpat'
    initFile = 'init/electribe_sampler_allpattern.e2sallpat'

    if args.inFile:
        inFile = args.inFile
    if args.outDir:
        outDir = args.outDir

    pathlib.Path(outDir).mkdir(parents=True, exist_ok=True)
    outFile = outDir + '/' + outFile

    # Read reference allpatterns file to grab header
    # EOF is at 0x3F80D8 e.g. 4161752 (4.2 MB total size)
    # Korg header is up to 0x10100
    with open(initFile, 'rb') as f:
        allData = bytearray(f.read())

    # Read init pattern file to populate new allpatterns file
    with open(inFile, 'rb') as f:
        apData = bytearray(f.read())

    patOff = 0x10100  # where the pattern content starts in the allpatterns file
    patLen = 0x4000  # predefined size for each pattern (16384 bytes each)

    # Iterate 250 times and swap the patterns in our allData, starting from patOff
    data = allData[:0x10100]

    for i in range(250):
        start = patOff+(i*patLen)
        data[start:start+patLen] = apData[256:]

    with open(outFile, 'wb') as f:
        f.write(data)


if __name__ == '__main__':
    main()

```

### scripts/e2pat2syx.py
<a name="scriptse2pat2syxpy"></a>

- **Name:** `e2pat2syx.py`
- **Pfad:** `scripts/e2pat2syx.py`
- **SHA256:** `a10600dd3528ddd0940307235290cd48ef967a42a5ff79d4ef380ceecaacef59`

```
# Converts .e2pat to .syx
import argparse
from e2_syx_codec import syx_enc

def main():	
	
    parser = argparse.ArgumentParser()
    parser.add_argument("-p", "--pattern", dest='patNum', help="destination pattern number (1-250)")
    parser.add_argument("file", metavar="filepath", type=str, help="path/to/file.e2pat")

    args = parser.parse_args()

    with open(args.file, 'rb') as f:	
        data =  bytearray(f.read())	

    
    if args.patNum:
        syx_data = pat_to_syx(pat_data, pat_num=int(args.patNum))
    else:
        syx_data = pat_to_syx(pat_data)
    
    
    outfile = args.file[:-5] + 'syx'											# change filename extension
    with open(outfile, 'wb') as f:
        f.write(syx_data)

    if args.patNum:
        print(args.file + ' converted to ' + outfile + ', pattern number ' + args.patNum)
    else:
        print(args.file + ' converted to ' + outfile)




def pat_to_syx(pat_data, pat_num=False):
    
    data = pat_data[0x100:]

    bytearray(syx_head = [0xf0, 0x42, 0x30, 0x00, 0x01, 0x23, 0x40])                 # dump to current pattern

    if pat_num:
        pat_num = int(pat_num)-1
        msb = 0
        lsb = pat_num % 128
        if pat_num > 127:
            msb = 1
        syx_head = bytearray([0xf0, 0x42, 0x30, 0x00, 0x01, 0x23, 0x4c, lsb, msb])   # dump to patNum

    syx_data = syx_head + syx_enc(data) + b'\xf7'

    return syx_data


if __name__ == '__main__':
    main()

```

### scripts/e2pat_convert.py
<a name="scriptse2patconvertpy"></a>

- **Name:** `e2pat_convert.py`
- **Pfad:** `scripts/e2pat_convert.py`
- **SHA256:** `9b9b4415ca254b1f7028591f773bfce4b1a572c17faa594f79ea4c4b29f04c1f`

```
import sys
from pathlib import Path

if len(sys.argv) < 3:
    print("Usage:")
    print()
    print("e2pat_convert.py FILE_PATH [synth|sampler]")
    exit(0)

path = Path(sys.argv[1])
device = sys.argv[2]

if path.is_file():

    extension = path.suffix
    basename = path.stem
    output_dir = path.parent

    if extension == ".e2spat" or extension == ".e2pat":
        postfix = "pat"

    elif extension == ".e2sallpat" or extension == ".e2allpat":
        postfix = "allpat"

    else:
        print("File type not supported.")
        exit(0)

    with open(path, "rb") as f:
        hak = bytearray(f.read())

    if device == "sampler":
        # e2s
        hak[0x10:0x20] = "e2sampler".encode("ascii").ljust(16, b"\x00")
        prefix = ".e2s"

    elif device == "synth":
        # e2
        hak[0x10:0x20] = "electribe".encode("ascii").ljust(16, b"\x00")
        prefix = ".e2"

    else:
        print(
            "Incorrect argument:",
            device + ".",
            "Must be either 'synth' or 'sampler'.",
        )
        exit(0)

    print("Modified header of", path)

    output_filename = Path("converted-" + basename + prefix + postfix)

    output_path = output_dir / output_filename

    with open(output_path, "wb") as f:
        f.write(hak)

    print("Saved to", output_path)

else:
    print("File not found.")

```

### scripts/e2pat_shift.py
<a name="scriptse2patshiftpy"></a>

- **Name:** `e2pat_shift.py`
- **Pfad:** `scripts/e2pat_shift.py`
- **SHA256:** `9cfaabbab7f48d85f599b0f9461ccabf9452ca1ba05975192be1a5e335fa75bc`

```
# Simple program that reads an .e2allpat file and shifts all oscillator numbers 
# by the number given. This is to simplify using existing patterns with 
# bangcorrupt's wonderful HACKTRIBE ROM - https://github.com/bangcorrupt/hacktribe - 
# which brings a host of new possibilities, including new oscillators. (VPM!!!)
# This means, though, that all factory samples have to move to slots 501+.
#
# I wanted to keep my existing patterns, this kept me from installing HACKTRIBE - 
# but now that I've done it, I did not want to correct all existing patterns by hand

import argparse

# Using bangcorrupt's e2all2pat.py script as a base.
# (I'd normally use snake_case instead of camelCase for variables. Never mind!)

def main():        
    explanation = """This script adapts all the osc numbers in your existing patterns\n
            if you had to move the samples to make room for the new Hacktribe waveforms.\n 
            The factory waveforms 1..18 are left untouched."""
    parser = argparse.ArgumentParser(epilog=explanation)    
    parser.add_argument("-i", "--input", dest='inFile', help="path/to/input/file.e2sallpat")
    parser.add_argument("-o", "--output", dest='outFile', help="path/to/output/shiftedxxx.e2sallpat")
    parser.add_argument("-s", "--shift", dest='shiftBy', help="Shift osc by -999...999")
    args = parser.parse_args()
    
    inFile = 'electribe_allpattern.e2sallpat'
    shiftBy = "500"

    
    if args.inFile:
        inFile = args.inFile
    
    if args.shiftBy:
        shiftBy = args.shiftBy

    # Check for valid range
    shiftVal = int(shiftBy)
    if shiftVal > 999 or shiftVal < -999:
        shiftVal = shiftVal % 1000

    # Create output file name containing shift
    outFile = 'shifted' + str(shiftVal) + '.e2sallpat'
    if args.outFile:
        outFile = args.outFile
    

    with open(inFile, 'rb') as f:
        apData =  bytearray(f.read())    
    
    # Structure of .e2allpat file: 
    # Extensive info can be found here: http://www.korgforums.com/forum/phpBB2/viewtopic.php?t=95368
    #    
    # 0x00000-0x00100: Korg Electribe file header
    # Next 0x10000 bytes (64k) are filler bytes containing 0xFF.
    # Length of one pattern is 0x4000 (16k) 
    # Data for the patterns 1-250 follows from 0x10100.
    # Part data starts 0x800 (2k) into the pattern data, i.e. first pattern is from 0x10900.
     # Length of one part is 0x330.
    # Osc data is 0x08 (lo) and 0x09 (hi) into this data. 
    #
    # So
    patOff = 0x10100
    patLen = 0x4000
    partOff = 0x0800
    partLen = 0x0330
    # Repeat for all 250 patterns: 
    for i in range(250):
        # When printing, add 1 for humans. 
        print("== Processing pattern ",i+1," ==")
        # Repeat for all 16 parts:
        for k in range(16):
            partPtr = patOff + (i*patLen) + partOff + (k * partLen)
            partOsc = apData[partPtr + 0x08] + 256 * apData[partPtr + 0x09]
            # Shift and correct
            # (Leave the base waveforms 0-17 unchanged)
            if partOsc < 18:
                shiftOsc = partOsc
            else:
                shiftOsc = partOsc  + shiftVal
            if shiftOsc > 999 or shiftOsc < -999:
                shiftOsc = shiftOsc % 1000
            # Write shifted osc reference to data buffer
            apData[partPtr + 0x08] = shiftOsc % 256
            apData[partPtr + 0x09] = shiftOsc // 256
            # When printing, add 1 for humans. 
            print("Part ",k+1,": Shift osc ",partOsc + 1," ->  ",shiftOsc + 1)
    with open(outFile, 'wb') as f:
        f.write(apData)

if __name__ == '__main__':
    main()

```

### scripts/e2s_sample_lister.py
<a name="scriptse2ssamplelisterpy"></a>

- **Name:** `e2s_sample_lister.py`
- **Pfad:** `scripts/e2s_sample_lister.py`
- **SHA256:** `28b151adbee29ffc57d4921390032b89ec93050dd2bde0ca656189e4833b9284`

```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Read sample library from e2sSample.all file, 
list RIFF pointer and metadata for each sample 
and create a lookup table. 

Sample file format: see https://github.com/untergeekDE/electribe2-docs/blob/main/e2sSample-all-file-format.md

Read pattern file and recode patterns to use new osc locations.

2022-01-02
@author: untergeekDE
"""
import argparse
import os
import re # Regular Expressions

# Using bangcorrupt's e2all2pat.py script as a base.
# For testing in Spyder IDE: change working directory one level up
# os.chdir("..")

def get_category(c):
    # Convert integer to category string
    categories = ['Analog',
                  'Audio In', 
                  'Kick', 
                  'Snare', 
                  'Clap',
                  'HiHat', 
                  'Cymbal', 
                  'Hits', 
                  'Shots', 
                  'Voice', 
                  'SE', 
                  'FX', 
                  'Tom', 
                  'Perc', 
                  'Phrase', 
                  'Loop', 
                  'PCM', 
                  'User',
                  'Wave']
    if c > 17:
            return f"Error: {c}"
    return categories[c]

def get_pointers(buffer):
    # Return a list of pointers
    l = []
    for i in range(1000):
        ii = i * 4 +0x10
        p = int.from_bytes(buffer[ii:ii+4],'little')
        if (p > 0):
            l.append(p)
    return l



def get_sample_pointer(buf,i):
    # Read pointer from header block
    return(int.from_bytes(buf[i*4+16:i*4+20],'little'))

def get_sample_list(buf):
    # Check if sample is referenced, add to list if yes
    sample_list = []
    for i in range(1000):
        if get_sample_pointer(buf[0:0x1000],i) > 0:
            sample_list.append(i)
    return sample_list

def main():        
    explanation = """Reads an e2ssample.all file and gives back metadata
        for all the samples in the file."""
    parser = argparse.ArgumentParser(epilog=explanation)    
    parser.add_argument("-s", "--sample", dest='sampleFile', help="path/to/input/file.e2sallpat")
    parser.add_argument("-o", "--outdir", dest='outDir', help="path/to/output/")
    args = parser.parse_args()
    
    sampleFile = './e2sSample.all'
    outDir = "."
    
    if args.sampleFile:
        sampleFile = args.sampleFile
    if args.outDir:
        outDir = args.outDir    

    # Read sample file into memory
    try:
        with open(sampleFile, 'rb') as f:
            sample_buf =  bytearray(f.read())   
    except:
        print("Could not read ",sampleFile," into memory. Stopping.")
        return()
    else: 
        print(len(sample_buf)," bytes read from ",sampleFile)
        
    sample_list = get_sample_list(sample_buf)

    # Now: Move sample pointers and correct sample references.  
    os.chdir(outDir)
    with open('sample_list.txt', 'w') as f:
        for osc_no in sample_list:     
            # Start reading from slot 019 to 421
            # Humans count from 1, machines from 0.
            p = get_sample_pointer(sample_buf,osc_no)
            output_str = f"---- Osc No. {osc_no+1}, sample pointer {p:04x} ----\n"
            # Write sample slot number: is stored 0x494 bytes before the end
            p = get_sample_pointer(sample_buf,osc_no)
            if p == 0: 
                osc_name="?"
                osc_cat = "?"
            else:
                RIFF_len = int.from_bytes(sample_buf[p+4:p+8],'little') + 8
                esli_p = p + RIFF_len - 0x494
                # Calculate location of sample slot number: 0x494 bytes before the end
                sample_name_p = esli_p + 0x02
                # Assign the new sample number
                osc_name = re.sub(r'[^\w\s-]',' ',str(sample_buf[sample_name_p:sample_name_p+16],encoding="utf-8"))
                osc_cat = get_category(sample_buf[esli_p + 0x12]+ 256*sample_buf[esli_p+0x13])
                osc_snum = sample_buf[esli_p+0x14]+ 256* sample_buf[esli_p+0x15]
                playback_period= sample_buf[esli_p+0x22]+ 256* sample_buf[esli_p+0x23]
                playback_volume = sample_buf[esli_p+0x24]+ 256* sample_buf[esli_p+0x25]
                loop = sample_buf[esli_p+0x34] == 0
                
            output_str = output_str + (
                f'{osc_no+1:03d} {osc_name} ({osc_cat})\n'
                f'Sample Num: {osc_snum:04x}\n'
                f'Playback Period: {playback_period:04x}'
                f' Volume: {playback_volume:04x} Loop: {loop}\n'
                )
            f.write(output_str)
            print(output_str,end="")
    
    print("Done.")
    
if __name__ == '__main__':
    main()

```

### scripts/e2seqrot.py
<a name="scriptse2seqrotpy"></a>

- **Name:** `e2seqrot.py`
- **Pfad:** `scripts/e2seqrot.py`
- **SHA256:** `a41e304a212b5813c802418cecea011c7848aa6db2651b8ec8d0a9bff91254e3`

```

import argparse
parser = argparse.ArgumentParser()
parser.add_argument("-i", "--input", dest='path', help="path/to/pattern/file")	
parser.add_argument("-o", "--output", dest='outpath', help="path/to/save/file")	
parser.add_argument("-p", "--part", dest='part', help="part number")
parser.add_argument("-r", "--rot", dest='rot', help="rotation steps")	
args = parser.parse_args()
	
def rotate(l, n):
    return l[n:] + l[:n]
	
with open(args.path, 'rb') as f:
	pattern =  bytearray(f.read())	
partOff = 0x900
partLen = 0x330
seqOff = 0x30
seqLen = 0xC0
stepLen = 0x0C
part = int(args.part) - 1
rot = int(args.rot)

seqStart = partOff + (part * partLen) + seqOff
seqEnd = seqStart + seqLen
steps = pattern[seqStart:seqEnd]
output = rotate(steps, rot*stepLen)

for i in range(len(steps)):
	pattern[i+seqStart] = output[i]

with open(args.outpath, 'wb') as f:
	f.write(pattern)

```

### scripts/e2sysex.py
<a name="scriptse2sysexpy"></a>

- **Name:** `e2sysex.py`
- **Pfad:** `scripts/e2sysex.py`
- **SHA256:** `cefdd5eaaec8684326c39ebbf85f481ad0eed14698ea51bbd244a57926ca263a`

```
import mido
from mido import Message
import logging
from subprocess import run

from e2pat2syx import pat_to_syx
from e2syx2pat import syx_to_pat

from e2_syx_codec import syx_enc
from e2_syx_codec import syx_dec

from time import sleep


def main():
    logging.basicConfig(level=logging.DEBUG)

    e = E2Sysex()


def display_menu(menu):
    for k, v in menu.items():
        print(k, v)


class E2Sysex:
    def __init__(self, in_port=None, out_port=None):
        logging.debug("Initialise SysEx")

        if in_port is None:
            inputs = mido.get_input_names()
            menu_items = dict(enumerate(inputs, start=1))

            while in_port is None:
                display_menu(menu_items)
                selection = int(input("Please enter your selection number: "))
                in_port = menu_items[selection]
                logging.info("Input port selected: " + in_port)

        if out_port is None:
            outputs = mido.get_output_names()
            menu_items = dict(enumerate(outputs, start=1))

            while out_port is None:
                display_menu(menu_items)
                selection = int(input("Please enter your selection number: "))
                out_port = menu_items[selection]
                logging.info("Output port selected: " + out_port)

        self.inport = mido.open_input(in_port)
        self.outport = mido.open_output(out_port)

        self.global_channel, self.id, self.version = self.search_device()

        logging.info("Found device.")
        logging.info("Global channel: " + str(self.global_channel))
        # logging.info("Firmware version " + self.version)

        self.global_channel = 0
        self.id = 0x24

        self.sysex_head = [0x42, 0x30 + self.global_channel, 0x00, 0x01, self.id]

    def search_device(self):
        msg = Message("sysex", data=[0x42, 0x50, 0x00, 0x00])

        self.outport.send(msg)

        response = self.sysex_response()

        if response[:4] != [0xF0, 0x42, 0x50, 0x01]:
            logging.warning("Invalid response: Not search device reply message.")
            return -1

        global_channel = response[4]

        electribe_id = response[6]

        version = str(response[10]) + "." + str(response[11])

        return global_channel, electribe_id, version

    # get pattern from device
    # source is pattern number
    # returns pattern as sysex bytes
    def get_pattern(self, source):
        logging.debug("Called get_pattern")
        msg = Message("sysex", data=self.sysex_head + [0x1C] + self.int_to_midi(source))

        self.outport.send(msg)
        response = self.sysex_response()

        if response[6] == 0x24:
            logging.warning("DATA LOAD ERROR: Pattern dump request unsuccessful")
            return -1

        elif response[6] == 0x4C:
            logging.info("PATTERN DATA DUMP: Pattern dump request successful")

            data = response[9:-1]

            return data

    # send pattern to device
    # pattern is pattern file as list of sysex bytes
    # dest is pattern number (0-249)
    # returns SysEx response code
    def set_pattern(self, dest, pattern):
        logging.debug("Called set_pattern")

        msg = Message(
            "sysex", data=self.sysex_head + [0x4C] + self.int_to_midi(dest) + pattern
        )

        logging.debug("Sending pattern")
        self.outport.send(msg)

        response = self.sysex_response()
        logging.debug("Sysex response: " + str([hex(r) for r in response]))

        if response[6] == 0x24:
            logging.warning("DATA LOAD ERROR: Pattern dump unsuccessful")
            return 0x24

        elif response[6] == 0x23:
            logging.info("PATTERN DATA DUMP: Pattern dump successful")
            return 0x23

    # get current pattern edit buffer from device
    # returns current pattern as sysex bytes SysEx error code
    def get_current_pattern(self):
        msg = Message("sysex", data=self.sysex_head + [0x10])
        self.outport.send(msg)

        response = self.sysex_response()

        if response[6] == 0x24:
            logging.warning(
                "DATA LOAD ERROR: Current pattern dump request unsuccessful"
            )
            return 0x24

        elif response[6] == 0x40:
            logging.info(
                "CURRENT PATTERN DATA DUMP: Current pattern dump request successful"
            )

            data = response[7:-1]
            return bytes(data)

    # send pattern to device edit buffer
    # pattern is pattern file as sysex bytes
    # returns SysEx response code
    def set_current_pattern(self, pattern):
        msg = Message("sysex", data=self.sysex_head + [0x40] + pattern)

        self.outport.send(msg)
        response = self.sysex_response()

        if response[6] == 0x24:
            logging.warning("DATA LOAD ERROR: Current Pattern dump unsuccessful")
            return 0x24

        elif response[6] == 0x23:
            logging.info("PATTERN DATA DUMP: Current pattern dump successful")
            return 0x23

    # writes current edit buffer on device
    # returns SysEx Response code
    def write_pattern(self):
        logging.info("WRITE PATTERN: Not implemented yet")

    # helper function, uses get_pattern
    # get all patterns from device
    # returns list of pattern files as sysex bytes
    def get_all_patterns(self):
        return [self.get_pattern(i) for i in range(250)]

    # helper function, uses set_pattern
    # sends all patterns to device
    # patterns is list of patterns as sysex bytes
    def set_all_patterns(self, patterns):
        logging.info("SET ALL PATTERNS: Not implemented yet")

    # get global settings
    # returns settings as sysex bytes
    def get_global(self):
        msg = Message("sysex", data=self.sysex_head + [0x0E])
        self.outport.send(msg)

        response = self.sysex_response()

        if response[6] == 0x24:
            logging.warning("DATA LOAD ERROR: Global data dump request unsuccessful")
            return -1

        elif response[6] == 0x51:
            logging.info("GLOBAL DATA DUMP: Global data dump request successful")

            data = response[7:-1]
            return bytes(data)

    # sends global settings to device
    # settings is global settings as sysex bytes
    # checks response and returns 0 if successful
    def set_global(self, settings):
        logging.info("SET GLOBAL DATA")

        msg = Message("sysex", data=self.sysex_head + [0x51] + settings)

        self.outport.send(msg)
        response = self.sysex_response()

        if response[6] == 0x24:
            logging.warning("DATA LOAD ERROR: Global settings dump unsuccessful")
            return 0x24

        elif response[6] == 0x23:
            logging.info("GLOBAL DATA DUMP: Global settings dump successful")
            return 0x23

    def sysex_response(self):
        response = []
        for msg in self.inport:
            if msg.type == "sysex":
                response = msg.bytes()
                break

        return response

    # convert integer x <= 255 to midi bytes
    # returns little endian list of 7-bit bytes
    def int_to_midi(self, x):
        return [x % 128, x // 128]

    # val is list of sysex bytes
    def test_sysex_message(self, val):
        msg = Message("sysex", data=self.sysex_head + val)
        logging.debug("Sending message: " + msg.hex())
        self.outport.send(msg)
        response = self.sysex_response()

        return response

    # Read CPU RAM at address for length bytes
    # Returns data as bytearray
    def read_cpu_ram(self, address, length):
        logging.debug("Called read_cpu_ram")
        # Encode values as sysex
        addr = address.to_bytes(4, byteorder="little")
        leng = length.to_bytes(4, byteorder="little")
        syx_al = syx_enc(addr + leng)

        # Send message
        logging.debug("Sending message")
        msg = Message("sysex", data=self.sysex_head + [0x52] + syx_al)
        self.outport.send(msg)
        response = self.sysex_response()
        logging.debug("Received response")

        # Decode sysex response
        logging.debug("Decoding binary")
        byt_data = syx_dec(response[9:-1])

        return bytearray(byt_data)

    # Write data to CPU RAM at address
    # data is byte list
    def write_cpu_ram(self, address, data):
        logging.debug("Called write_cpu_ram")
        # First, set write address and length
        # Encode values as sysex
        addr = address.to_bytes(4, byteorder="little")
        leng = len(data).to_bytes(4, byteorder="little")
        syx_al = syx_enc(addr + leng)

        # Send first message
        msg = Message("sysex", data=self.sysex_head + [0x53] + syx_al)
        logging.debug("Send addres+length")
        self.outport.send(msg)
        response = self.sysex_response()
        logging.debug("Sysex response: " + str([hex(r) for r in response]))
        # Ignore response for now
        # UPDATE - test for success

        # Now send data to write
        # Encode data as sysex
        syx_dat = syx_enc(data)

        # Send final message
        msg = Message("sysex", data=self.sysex_head + [0x54] + syx_dat)

        logging.debug("Sending data")
        self.outport.send(msg)

        response = self.sysex_response()
        logging.debug("Sysex response: " + str([hex(r) for r in response]))

        return response

    def load_cpu_ram(self, data):
        logging.debug("Called load_cpu_ram")

        # Now send data to write
        # Encode data as sysex
        syx_dat = syx_enc(data)

        # Send final message
        msg = Message("sysex", data=self.sysex_head + [0x54] + syx_dat)

        logging.debug("Sending data")
        self.outport.send(msg)

        response = self.sysex_response()
        logging.debug("Sysex response: " + str([hex(r) for r in response]))

        return response

    # Execute CPU RAM at address
    def execute_cpu_ram(self, address):
        logging.debug("Called execute_cpu_ram")

        # Encode values as sysex
        addr = address.to_bytes(4, byteorder="little")
        reserved = bytes(4)
        syx_ar = syx_enc(addr + reserved)

        # Send message
        logging.debug("Sending message")
        msg = Message("sysex", data=self.sysex_head + [0x57] + syx_ar)
        self.outport.send(msg)

        response = self.sysex_response()
        logging.debug("Received response")

        logging.debug("Sysex response: " + str([hex(r) for r in response]))

        return response

    def read_flash(self, address, length):
        logging.debug("Called read_flash")
        # Encode values as sysex
        addr = address.to_bytes(4, byteorder="little")
        leng = length.to_bytes(4, byteorder="little")
        syx_al = syx_enc(addr + leng)

        # Send message
        logging.debug("Sending message")
        msg = Message("sysex", data=self.sysex_head + [0x55] + syx_al)
        self.outport.send(msg)
        response = self.sysex_response()
        logging.debug("Received response")

        # Decode sysex response
        logging.debug("Decoding binary")
        byt_data = syx_dec(response[9:-1])

        return bytearray(byt_data)

    # Get IFX preset from CPU RAM at index ifx_idx
    # Returns preset as bytearray
    # Uses get_cpu_ram for now
    # UPDATE - Add firmware hack for specific sysex function
    def get_ifx(self, ifx_idx):
        if ifx_idx > 99 or ifx_idx < 0:
            logging.warning("IFX index out of range - must be >= 0 & < 100.")
            return

        # Calculate IFX preset address
        ifx_base = 0xC00A80F0
        ifx_leng = 0x20C
        ifx_addr = ifx_base + ifx_leng * ifx_idx

        # Read IFX preset from CPU RAM
        ifx = self.read_cpu_ram(ifx_addr, ifx_leng)

        return ifx

    # Set IFX preset in CPU RAM at index ifx_idx
    # ifx is byte list
    # Uses write_cpu_ram for now
    # UPDATE - Add firmware hack for specific sysex function
    def set_ifx(self, ifx_idx, ifx):
        logging.debug("Called set_ifx")

        if ifx_idx > 99 or ifx_idx < 0:
            logging.warning("IFX index out of range - must be >= 0 & < 100.")
            return

        # Calculate IFX preset address
        ifx_base = 0xC00A80F0
        ifx_leng = 0x20C
        ifx_addr = ifx_base + ifx_leng * ifx_idx

        # Write IFX preset from CPU RAM
        # Writing in two halves fails less often
        ifx_a = ifx[:0x100]
        self.write_cpu_ram(ifx_addr, ifx_a)

        ifx_b = ifx[0x100:]
        self.write_cpu_ram(ifx_addr + 0x100, ifx_b)

        return

    # Add new IFX preset, increasing total count
    # ifx is byte list
    def add_ifx(self, ifx):
        # Get current max IFX index
        ifx_idx = self.read_cpu_ram(0xC003EFDC, 1)[0]

        if ifx_idx > 99 or ifx_idx < 0:
            logging.warning("IFX index out of range - must be >= 0 & < 100.")
            return

        # Set IFX preset data
        self.set_ifx(ifx_idx, ifx)

        # Increase limits for menu and saved parameters
        # UPDATE - Add firmware hack to set these values in one location
        self.write_cpu_ram(0xC003EFDC, [ifx_idx + 1])
        self.write_cpu_ram(0xC0048F80, [ifx_idx])
        self.write_cpu_ram(0xC0049EF0, [ifx_idx])
        self.write_cpu_ram(0xC004A1F8, [ifx_idx])
        self.write_cpu_ram(0xC009814C, [ifx_idx])
        self.write_cpu_ram(0xC0098150, [ifx_idx + 1])
        self.write_cpu_ram(0xC0098188, [ifx_idx])
        self.write_cpu_ram(0xC0098194, [ifx_idx + 1])
        self.write_cpu_ram(0xC00980E8, [ifx_idx])
        self.write_cpu_ram(0xC00980EC, [ifx_idx + 1])
        self.write_cpu_ram(0xC009809C, [ifx_idx + 1])
        self.write_cpu_ram(0xC009811C, [ifx_idx + 1])
        self.write_cpu_ram(0xC0098138, [ifx_idx + 1])

        return

    # Get groove template from CPU RAM at index gv_idx
    # Returns preset as list of bytearray
    # Uses get_cpu_ram for now
    # UPDATE - Add firmware hack for specific sysex function
    def get_groove(self, gv_idx):
        if gv_idx > 127 or gv_idx < 0:
            logging.warning("Groove index out of range - must be >= 0 & < 128.")
            return

        # Calculate groove template address
        gv_base = 0xC0143B00
        gv_leng = 0x140
        gv_addr = gv_base + gv_leng * gv_idx

        # Read groove template from CPU RAM
        gv = self.read_cpu_ram(gv_addr, gv_leng)

        return gv

    # Set Groove template in CPU RAM at index gv_idx
    # gv is byte list
    # Uses write_cpu_ram for now
    # UPDATE - Add firmware hack for specific sysex function
    def set_groove(self, gv_idx, gv):
        if gv_idx > 127 or gv_idx < 0:
            logging.warning("Groove index out of range - must be >= 0 & < 128.")
            return

        # Calculate groove template address
        gv_base = 0xC0143B00
        gv_leng = 0x140
        gv_addr = gv_base + gv_leng * gv_idx

        # Write Groove template from CPU RAM
        self.write_cpu_ram(gv_addr, gv)

        return

    # Add new groove template, increasing total count
    # gv is byte list
    def add_groove(self, gv):
        # Get current max groove index
        gv_idx = self.read_cpu_ram(0xC007BB88, 1)[0]

        if gv_idx > 127 or gv_idx < 0:
            logging.warning("Groove index out of range - must be >= 0 & < 128.")
            return

        # Set groove template data
        self.set_groove(gv_idx, gv)

        # Increase limits for menu and saved parameters
        # UPDATE - Add firmware hack to set these values in one location
        self.write_cpu_ram(0xC0049DA4, [gv_idx])
        self.write_cpu_ram(0xC007BB90, [gv_idx])
        self.write_cpu_ram(0xC007BB88, [gv_idx + 1])
        self.write_cpu_ram(0xC007BB94, [gv_idx + 1])

        return


if __name__ == "__main__":
    main()

```

### scripts/e2syx2pat.py
<a name="scriptse2syx2patpy"></a>

- **Name:** `e2syx2pat.py`
- **Pfad:** `scripts/e2syx2pat.py`
- **SHA256:** `3a649840bea00729e4eb045afd9254548793af3b756f3e7a1de79355417f722c`

```
# Converts .syx to .e2pat
import argparse
from e2_syx_codec import syx_dec


def main():	

    parser = argparse.ArgumentParser()
    parser.add_argument("file", metavar="filepath", type=str, help="path/to/file.syx")

    args = parser.parse_args()

    with open(args.file, 'rb') as f:	
        data =  bytearray(f.read())

    if data[6] == 0x40:						# remove syx header from 'current pattern dump'
        data = data[7:-1]		
    elif data[6] == 0x4c:					# remove syx header from 'pattern dump'
        data = data[9:-1]


    pat_data = syx_to_pat(data)

    outfile = args.file[:-3] + 'e2pat'			# change filename extension
    with open(outfile, 'wb') as f:
        f.write(pat_data)

    print(args.file + ' converted to ' + outfile)



def syx_to_pat(syx_data):
    
    pat_head = (b'KORG'.ljust(16, b'\x00') + 
               b'electribe'.ljust(16, b'\x00') +
               b'\x01\x00\x00\x00'.ljust(224, b'\xff'))
                    
    pat_data = pat_head + syx_dec(syx_data)
    
    return pat_data

if __name__ == '__main__':
    main()

```

### scripts/execute_freetribe.py
<a name="scriptsexecutefreetribepy"></a>

- **Name:** `execute_freetribe.py`
- **Pfad:** `scripts/execute_freetribe.py`
- **SHA256:** `337a55689880141a19d1d935b4d75457d8bce7b72062b13c5518a9f050685647`

```
import sys
import mido
import logging

from pathlib import Path
from time import sleep

from e2sysex import *


def chunks(lst, n):
    """Yield successive n-sized chunks from lst."""
    for i in range(0, len(lst), n):
        yield lst[i : i + n]


def display_menu(menu):
    for k, v in menu.items():
        print(k, v)


def bytes_to_string(byt):
    return " ".join([hex(b)[2:].upper().rjust(2, "0") for b in byt])


logging.basicConfig(level=logging.DEBUG)

if len(sys.argv) < 2:
    print("Usage:\n")
    print("python execute_freetribe.py FILE_PATH [PORT_NAME]\n")
    exit(0)

bin_path = Path(sys.argv[1])

in_port = None
out_port = None

if len(sys.argv) > 2:
    in_port = sys.argv[2]

if len(sys.argv) > 3:
    out_port = sys.argv[3]


if not bin_path.is_file():
    logging.error("File not found: " + str(bin_path))
    exit(0)


logging.info("Load and execute Freetribe.")

logging.info("Initialising MIDI connection.")

e = E2Sysex(in_port, out_port)

logging.info("Pivoting to Freetribe loader.")

msg = mido.Message("sysex", data=e.sysex_head + [0x58] + syx_enc(bytes(8)))
e.outport.send(msg)

sleep(1)

logging.info("Sending magic word.")

r = e.test_sysex_message(list(b"\x64\x01\x23\x45\x67"))

logging.debug("Received message: " + bytes_to_string(r))

response_word = r[5:9]
if response_word != [0x76, 0x54, 0x32, 0x10]:
    logging.error("Incorrect response: " + bytes_to_string(response_word))
    exit(0)

logging.info("Loading binary...")

with open(bin_path, "rb") as f:
    code = f.read()

code_chunks = list(chunks(code, 0x100))
num_chunks = len(code_chunks)

for i, chunk in enumerate(code_chunks):
    logging.info("Loading chunk: " + str(i) + " of " + str(num_chunks))

    chunk = chunk.ljust(256, b"\x00")[:256]

    r = e.load_cpu_ram(chunk)

    logging.debug("Received message: " + bytes_to_string(r))

    if r[5] != 0x21:
        logging.error("Load chunk failed.")
        exit(0)
    else:
        logging.info("Load chunk success.")


execute_address = 0x80000000
r = e.execute_cpu_ram(execute_address)

print()
print(bytes(r[1:-1]).decode("ascii"))

for msg in e.inport:
    if msg.type == "sysex":
        print("".join(chr(i) for i in msg.data))

```

### scripts/hacktribe-tutorial.sh
<a name="scriptshacktribe-tutorialsh"></a>

- **Name:** `hacktribe-tutorial.sh`
- **Pfad:** `scripts/hacktribe-tutorial.sh`
- **SHA256:** `8475b43d7a302caf146891e287922b2595988062c9784a42dc80ed6ab743d54b`

```
#!/bin/bash

# Hacktribe firmware patch tutorial
#
# See https://github.com/bangcorrupt/hacktribe for details.

# This tutorial will help you learn how to run a few bash commands and a python script.
# For best results, read everything, 
# run each command separately and pay attention to the output.
#
# Anything starting with a '#' character is a comment and ignored by the shell 
# (you don't need to type these).  
# We can use comments to disable a command (see line 66 below).
#
# You will need to install git, python and pip.
#
# Happy hacking!


# First we need to download some files.  Clone the repo, including all submodules:
git clone --recursive https://github.com/bangcorrupt/hacktribe.git

# Then change directory to the 'hacktribe' directory we just downloaded:
cd hacktribe

# Next we need to download the factory firmware.  
# This is proprietary and copyrighted.  
# Please only download it for yourself and do not distribute it.  
# 
# 'wget' command can be used to download files if we know the URL:
wget https://cdn.korg.com/us/support/download/files/0b87bcd3112fbb8c0ad7b0f55e618837.zip

# Unzip the zip archive we just downloaded to access the files inside:
unzip 0b87bcd3112fbb8c0ad7b0f55e618837.zip

# Move the firmware update file 'SYSTEM.VSB' to our current directory '.' :
mv electribe_sampler_system_v202/SYSTEM.VSB .

# Now we have all the files in the right places.

# Next, make sure the required python packages are installed:
pip install argparse bsdiff4

# Now we are ready to run the firmware patching script.
# This will apply the hacktribe patch to the factory firmware,
# then check the sha256 hash of the patched file.
# If the hashes match, you have the same file I tested.
# If not, you will get a scary error message saying 'patch failed' or something.
#
# If you're installing hacktribe to a factory synth (grey or blue) 
# for the first time, we need to modify the update file header as well.
# (If you already have a previous version of hacktribe installed, this is not necessary).
#
# EITHER: Run the firmware patching script for synth, using '-e' flag to modify header:
python scripts/e2-firmware-patch.py -e

# OR: Run the firmware patching script for sampler/hacktribe, no flags necessary:
# python scripts/e2-firmware-patch.py

# If the patching was successful, 
# you should see 'Firmware patched successfully' in the output from the script.  

# Copy 'hacked-SYSTEM.VSB' to the 'System' directory on the SD card, 
# rename it to 'SYSTEM.VSB' and run the firmware update function on the device.

# Everything is done nowm the rest is just tidying up.

# Move hacked-SYSTEM.VSB to parent directory:

# mv hacked-SYSTEM.VSB ..

# Change directory to parent directory:

# cd ..

# Delete all the files we downloaded:

# rm -rf hacktribe

# See https://github.com/bangcorrupt/hacktribe/discussions/41 if you are having difficulties

```

### scripts/ht_splash_screen.py
<a name="scriptshtsplashscreenpy"></a>

- **Name:** `ht_splash_screen.py`
- **Pfad:** `scripts/ht_splash_screen.py`
- **SHA256:** `dbfc639b94ca1e409cf965339590792cbd3f60254e239102fbfb6fd0c921a3b3`

```
# Replace boot splash screen image.

import os
import argparse
import hashlib

from PIL import Image
from PIL import ImageOps


# Return 1bpp image from bytes.
def get_image(data, width, height):
    image = Image.new("1", (width, height))

    for i in range(len(data) // width):
        # get 8 pixel high row of image
        row = data[i * width : i * width + width]

        img = Image.frombytes("1", (8, width), bytes(row), decoder_name="raw").rotate(
            270, expand=True
        )

        # build image from rows
        image.paste(img, (0, img.height * i))

    image = ImageOps.mirror(image)

    return image


# Path to 1bpp image file, length of buffer in firmware.
def set_image(path, length):
    image = Image.open(path)

    image = ImageOps.mirror(image)

    width, height = image.size
    pixel_data = []

    # Transform image.
    for i in range(length // height):
        upper = i * 8
        lower = upper + 8
        row = (
            image.crop((0, upper, width, lower))
            .rotate(90, expand=True)
            .tobytes(encoder_name="raw")
        )
        pixel_data.extend(row)

    pixel_data = bytes(pixel_data)

    # truncate / extend data
    pixel_data = pixel_data[:length].ljust(length)

    return pixel_data


def get_digest(path):
    h = hashlib.sha256()

    with open(path, "rb") as file:
        while True:
            chunk = file.read(h.block_size)
            if not chunk:
                break
            h.update(chunk)

    return h.hexdigest()


def main():
    usage = """ Replace boot splash screen in Hacktribe firmware.
                """
    parser = argparse.ArgumentParser(epilog=usage)
    parser.add_argument("input_path", help="/path/to/hacked-SYSTEM.VSB")
    parser.add_argument("image_path", help="/path/to/image.bmp")
    parser.add_argument(
        "-b", "--backup", dest="backup_path", help="/path/to/backup.bmp"
    )
    args = parser.parse_args()

    input_path = args.input_path
    image_path = args.image_path
    backup_path = args.backup_path

    hash_path = "./hash/hacked-SYSTEM.VSB.sha"
    hash_path_mod = "./hash/modified-hacked-SYSTEM.VSB.sha"
    hash_path_og = "./hash/SYSTEM.VSB.sha"

    with open(hash_path, "r") as f:
        hash = f.readlines()[0].split()[0]

    with open(hash_path_mod, "r") as f:
        hash_mod = f.readlines()[0].split()[0]

    with open(hash_path_og, "r") as f:
        hash_og = f.readlines()[0].split()[0]

    if os.path.exists(input_path):
        print("Found firmware file:", os.path.basename(input_path))
    else:
        print("Firmware file not found:", os.path.basename(input_path))
        exit()

    if os.path.exists(image_path):
        print("Found firmware file:", os.path.basename(image_path))
    else:
        print("Image file not found:", os.path.basename(image_path))
        exit()

    if get_digest(input_path) == hash:
        print("Input hash matches Hacktribe firmware.")

    elif get_digest(input_path) == hash_mod:
        print("Input hash matches Hacktribe firmware with modified header.")

    elif get_digest(input_path) == hash_og:
        print("Input hash matches Electribe 2 Sampler firmware.")

    else:
        print("Input hash does not match any supported firmware.")
        exit()

    with open(input_path, "rb") as f:
        vsb = bytearray(f.read())

    head = vsb[:0x100]
    body = vsb[0x100:]

    base = 0xF9854
    length = 128 * 8

    start = base
    end = base + length

    pre_hash_head = hashlib.sha256(head).hexdigest()
    pre_hash_before = hashlib.sha256(body[:start]).hexdigest()
    pre_hash_after = hashlib.sha256(body[end:]).hexdigest()

    if backup_path:
        print("Backing up existing splash image.")
        old_bmp = body[start:end]
        old_bmp = get_image(old_bmp, 128, 64)
        old_bmp.save(backup_path, mode="1")

    body[start:end] = set_image(image_path, length)

    post_hash_head = hashlib.sha256(head).hexdigest()
    post_hash_before = hashlib.sha256(body[:start]).hexdigest()
    post_hash_after = hashlib.sha256(body[end:]).hexdigest()

    if (
        (pre_hash_before != post_hash_before)
        or (pre_hash_after != post_hash_after)
        or (pre_hash_head != post_hash_head)
    ):
        print("Output hash error, firmware corrupt!")
        exit()
    else:
        print("Output hash matches, only splash image bytes may have changed.")

    vsb = head + body

    assert len(vsb) == 0x200100

    print("Everything appears to be OK, writing firmware.")

    output_path = input_path
    with open(output_path, "wb") as f:
        f.write(vsb)


if __name__ == "__main__":
    main()

```

## DOCS

### apps/autorecorder/composer_policy.md
<a name="appsautorecordercomposerpolicymd"></a>

- **Name:** `composer_policy.md`
- **Pfad:** `apps/autorecorder/composer_policy.md`
- **SHA256:** `534dab0e222bcd52e32bef287ac81f01fc35577041084cf80e0b4c1e92b27d7e`

```
# composer_policy.md — WHY / Musical Rationale

## Ziel
`composer_policy.c` definiert **musikalische Makro-Entscheidungen** pro Genre / Section / Segment:
- Section: INTRO / MAIN / BREAK / PEAK / OUTRO
- Segment: A/B/C/D (0..3), bei BREAK/PEAK meist nur A/B
- Outputs sind **nicht-destruktiv**:
  - Randomizer-Parameter (Density / Variation)
  - Fill-State (für Live-FX / SongMode)
  - Decision-Flags (Bias, “musikalische Intention”)

Das Composer-Modul schreibt **keine Notes direkt** (außer wenn bewusst Generation gerufen wird).
Die Policy ist das “Regelwerk”, das später stabil bleibt.

---

## Begriffe

### Density (0–100)
Wie “voll” das Pattern ist (Wahrscheinlichkeit, dass Steps belegt werden).
- INTRO: eher niedrig (Platz schaffen)
- MAIN: mittel bis hoch (Groove)
- PEAK: hoch (Energie)
- OUTRO: zurückfahren

### Variation (0–127)
Wie stark Variation/Randomness wirkt (Pitch/Vel/Pattern-Varianz).
- Intro: gering bis moderat
- Main: moderat
- Peak: höher (Aggressivität/Bewegung)
- Outro: sinkend

### Fill-State (FILL_*)
Wird als “Performance-Layer”-Signal genutzt (Live-FX, Boosts, Fill-Triggers).
- FILL_GROOVE: subtiler Lift
- FILL_BUILD: Energie steigt (Riser/Fill erlaubt)
- FILL_PUNCTUATION: kurze Akzent-Fills
- FILL_NONE: neutral

### Decision-Flags (CP_FLAG_*)
Die Flags codieren **Intention** (nicht “Noten”):
- SPARSE / DENSE: Struktur-Dichte
- LOW_REGISTER / HIGH_REGISTER: Register-Tendenz
- STRAIGHT / SYNCOPATED: Groove-Fokus
- SUSTAINED / PERCUSSIVE: Artikulation
- BUILDING / RELEASE: Verlauf innerhalb des Segments

Composer setzt Flags → Randomizer interpretiert Flags als Bias.

---

## Designprinzipien

### 1) Intro ≠ Peak (Section-Spezifisch)
Die Sections sind bewusst verschieden:
- INTRO: Setup / “Teasing”, weniger Notes, eher low register, Aufbau möglich
- MAIN: stabiler Groove, “Tanzen”
- BREAK: Spannung lösen, Raum, Release/Sparse
- PEAK: Max Energy, DENSE + HIGH_REGISTER + BUILDING
- OUTRO: Abbau, Release, Sparse

### 2) Segment-Logik (A/B/C/D)
Segments stehen für Mikro-Entwicklung innerhalb einer Section:
- A: Einstieg (stabil/etwas leer)
- B: Aufbau (mehr Bewegung)
- C: Richtung Peak (wenn genutzt)
- D: Punch / Transition (wenn genutzt)

BREAK/PEAK sind kurz → oft nur A/B.

### 3) Flags sind “Meta”, nicht “Note-Commands”
Flags dürfen keine harten Regeln sein.
Sie sind Bias:
- beeinflussen Wahrscheinlichkeit (Density +-)
- beeinflussen Register (Pitch-Bereich)
- beeinflussen Groove-Verteilung (Downbeats vs Offbeats)
- beeinflussen Artikulation (Gate/Vel)

---

## Part-spezifische Bias-Matrix (aktuell)

### Rollenmodell (empfohlen)
Wir behandeln Parts grob als Rollen:
- Part 0: BASS (low register, eher stabil, etwas höhere Hit-Rate)
- Part 1: LEAD (höheres Register, etwas weniger Hits als Bass)
- Parts 2–7: MID/PAD/FX (kontextabhängig, meist sparsamer)
- Parts 8–15: DRUMS (feel stärker, kurze Gates, punchier vel)

### Einfluss der Flags pro Rolle (Beispiel)
| Flag | Bass | Lead | Mid/Pad | Drums |
|---|---:|---:|---:|---:|
| SPARSE | - | - | -- | - |
| DENSE | + | + | + | + |
| LOW_REGISTER | ++ | - | + | 0 |
| HIGH_REGISTER | - | ++ | + | 0 |
| STRAIGHT | + (Downbeat) | + | + | ++ |
| SYNCOPATED | + | ++ | ++ | ++ |
| SUSTAINED | + (länger) | + | ++ | 0/leicht |
| PERCUSSIVE | - | + | + | ++ |
| BUILDING | + | + | + | + (fill feel) |
| RELEASE | + | + | ++ | + |

*Hinweis:* Das ist eine Doku der Intention – die genaue Implementierung lebt in `randomizer.c`.

---

## Genre Review (musikalisch, Leitplanken)

### Acid Techno
- Charakter: hypnotisch, rolling, low register, klare Transitions.
- Intro: sparse/low, langsam building
- Main: dichter, syncopation optional
- Break: release, punctuations
- Peak: dense/high + building
- Outro: release, sparse

### Rave / Gabber / Frenchcore / HHC / Tech Trance / Tekkno
Hier definieren wir pro Genre:
- typische Dichte
- typische Register-Tendenz
- Groove-Charakter (straight vs syncopated)
- Peak-Overdrive

*(Wenn du willst, schreibe ich diese Genre-Blöcke als nächsten Step mit konkreten Empfehlungen pro Section.)*

---

## Pflege-Regeln (“Gold wert später”)
1) Werteänderung immer mit WHY-Kommentar (1 Satz).
2) Keine harten Sprünge ohne Übergang (A→B→C→D).
3) BREAK ist nicht “leise MAIN” – es ist **Raum**.
4) PEAK ist “max energy”, aber nicht “random chaos”: Variation kontrolliert.

```

### apps/autorecorder/Menu/Speichern/NRPN_SAVE_MAPPING.md
<a name="appsautorecordermenuspeichernnrpnsavemappingmd"></a>

- **Name:** `NRPN_SAVE_MAPPING.md`
- **Pfad:** `apps/autorecorder/Menu/Speichern/NRPN_SAVE_MAPPING.md`
- **SHA256:** `975d7b2f6b7d7a5c78e66f102138f11370c68a4b32b8b49a7abe197de3fd0d86`

```
# NRPN Mapping — Save / Speichern (AutoRecorder)

> Konvention: MSB = 0 für Menü-Panels (wie gewünscht). LSB codiert die Funktion innerhalb des Panels.
> NRPN uses: NRPN MSB = 0, NRPN LSB = [LSB value] — DataEntry(MSB) carries payload/value.

## Übersicht / Kurzfassung
- **Panel**: MSB = `0` (Menü / UI)
- **Sub-IDs (LSB)**: 0x40..0x4F reserved for "Speichern" menu
- **Werte**: Data Entry MSB (CC 6) überträgt 0..127 (oder längere Streams in mehrere NRPN-Frames).

## LSB Codes (empfohlen)
| LSB (dec/hex) | Name | Beschreibung | Werte / Payload |
|---:|---|---|---|
| 64 / 0x40 | SAVE_REQUEST | Startet Save-Request. DataEntry: Modus (1=Sysex+e2Pat, 2=e2Pat, 3=Sysex) | 1..3 |
| 65 / 0x41 | SAVE_CONFIRM | Bestätigung. DataEntry: 1 = accept, 0 = cancel | 0/1 |
| 66 / 0x42 | SAVE_STATUS | Outgoing — Status reporting (Log) | 0=Idle,1=Saving,2=Saved,3=Error |
| 67 / 0x43 | SAVE_NAME_STREAM | Streaming eines ASCII-Namens (8-bit per NRPN value = ASCII) — Use sequence numbers or termination char (0x00). | mehrere NRPNs: each DataEntry=ASCII byte |
| 68 / 0x44 | SAVE_MODE_SET | Setzt Default Save Mode persistent (same encoding as SAVE_REQUEST) | 1..3 |
| 69 / 0x45 | SAVE_ICON_REQ | Request to show a save icon on Display (DataEntry: icon id) | 0..127 |

## Status Meldungen (Log, an DAW / Host gesendet)
Beim Start eines Requests (aus Gerät oder DAW) sendet das Gerät per NRPN oder SysEx folgende Log-Strings (gerendert lokal; NRPN-Ausgabe optional):
- `NRPN: SAVE_REQUEST geladen`  — wenn ein SAVE_REQUEST empfangen wurde
- `NRPN: SAVE_CONFIRM gespeichert` — nach erfolgreichem Speichern

## Name-Streaming (praktische Regeln)
- Beginne mit NRPN (MSB=0, LSB=67) für ersten Byte.
- Verwende DataEntry MSB (CC6) zum Übertragen eines Bytes.
- Terminiere mit ASCII `0x00` oder mit `SAVE_CONFIRM` (LSB=65, value=1).

## Beispiele
**Host → Gerät:** Save request for Sysex+e2Pat:
- NRPN MSB=0 (CC99 = 0)
- NRPN LSB=64 (CC98 = 64)
- DATA ENTRY (CC6) = 1

**Host → Gerät:** Name "beat01" streamen:
- MSB=0 LSB=67 DataEntry= 'b' (0x62)
- MSB=0 LSB=67 DataEntry= 'e' (0x65)
- ...
- MSB=0 LSB=67 DataEntry= 0x00 (terminator)
- MSB=0 LSB=65 DataEntry=1 (SAVE_CONFIRM)

## Hinweise zur Implementation
- Implementiere eine Timeout (z. B. 5s) beim Name-Streaming, falls Terminator fehlt.
- Sicherstellen: NRPN-IDs nicht mit anderen Panels kollidieren.
- Lokal UI-Texte in Deutsch / Anzeige-Strings wie oben definieren.


```

### LICENSE.txt
<a name="licensetxt"></a>

- **Name:** `LICENSE.txt`
- **Pfad:** `LICENSE.txt`
- **SHA256:** `8486a10c4393cee1c25392769ddd3b2d6c242d6ec7928e1414efff7dfb2f07ef`

```
                    GNU AFFERO GENERAL PUBLIC LICENSE
                       Version 3, 19 November 2007

 Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.

                            Preamble

  The GNU Affero General Public License is a free, copyleft license for
software and other kinds of works, specifically designed to ensure
cooperation with the community in the case of network server software.

  The licenses for most software and other practical works are designed
to take away your freedom to share and change the works.  By contrast,
our General Public Licenses are intended to guarantee your freedom to
share and change all versions of a program--to make sure it remains free
software for all its users.

  When we speak of free software, we are referring to freedom, not
price.  Our General Public Licenses are designed to make sure that you
have the freedom to distribute copies of free software (and charge for
them if you wish), that you receive source code or can get it if you
want it, that you can change the software or use pieces of it in new
free programs, and that you know you can do these things.

  Developers that use our General Public Licenses protect your rights
with two steps: (1) assert copyright on the software, and (2) offer
you this License which gives you legal permission to copy, distribute
and/or modify the software.

  A secondary benefit of defending all users' freedom is that
improvements made in alternate versions of the program, if they
receive widespread use, become available for other developers to
incorporate.  Many developers of free software are heartened and
encouraged by the resulting cooperation.  However, in the case of
software used on network servers, this result may fail to come about.
The GNU General Public License permits making a modified version and
letting the public access it on a server without ever releasing its
source code to the public.

  The GNU Affero General Public License is designed specifically to
ensure that, in such cases, the modified source code becomes available
to the community.  It requires the operator of a network server to
provide the source code of the modified version running there to the
users of that server.  Therefore, public use of a modified version, on
a publicly accessible server, gives the public access to the source
code of the modified version.

  An older license, called the Affero General Public License and
published by Affero, was designed to accomplish similar goals.  This is
a different license, not a version of the Affero GPL, but Affero has
released a new version of the Affero GPL which permits relicensing under
this license.

  The precise terms and conditions for copying, distribution and
modification follow.

                       TERMS AND CONDITIONS

  0. Definitions.

  "This License" refers to version 3 of the GNU Affero General Public License.

  "Copyright" also means copyright-like laws that apply to other kinds of
works, such as semiconductor masks.

  "The Program" refers to any copyrightable work licensed under this
License.  Each licensee is addressed as "you".  "Licensees" and
"recipients" may be individuals or organizations.

  To "modify" a work means to copy from or adapt all or part of the work
in a fashion requiring copyright permission, other than the making of an
exact copy.  The resulting work is called a "modified version" of the
earlier work or a work "based on" the earlier work.

  A "covered work" means either the unmodified Program or a work based
on the Program.

  To "propagate" a work means to do anything with it that, without
permission, would make you directly or secondarily liable for
infringement under applicable copyright law, except executing it on a
computer or modifying a private copy.  Propagation includes copying,
distribution (with or without modification), making available to the
public, and in some countries other activities as well.

  To "convey" a work means any kind of propagation that enables other
parties to make or receive copies.  Mere interaction with a user through
a computer network, with no transfer of a copy, is not conveying.

  An interactive user interface displays "Appropriate Legal Notices"
to the extent that it includes a convenient and prominently visible
feature that (1) displays an appropriate copyright notice, and (2)
tells the user that there is no warranty for the work (except to the
extent that warranties are provided), that licensees may convey the
work under this License, and how to view a copy of this License.  If
the interface presents a list of user commands or options, such as a
menu, a prominent item in the list meets this criterion.

  1. Source Code.

  The "source code" for a work means the preferred form of the work
for making modifications to it.  "Object code" means any non-source
form of a work.

  A "Standard Interface" means an interface that either is an official
standard defined by a recognized standards body, or, in the case of
interfaces specified for a particular programming language, one that
is widely used among developers working in that language.

  The "System Libraries" of an executable work include anything, other
than the work as a whole, that (a) is included in the normal form of
packaging a Major Component, but which is not part of that Major
Component, and (b) serves only to enable use of the work with that
Major Component, or to implement a Standard Interface for which an
implementation is available to the public in source code form.  A
"Major Component", in this context, means a major essential component
(kernel, window system, and so on) of the specific operating system
(if any) on which the executable work runs, or a compiler used to
produce the work, or an object code interpreter used to run it.

  The "Corresponding Source" for a work in object code form means all
the source code needed to generate, install, and (for an executable
work) run the object code and to modify the work, including scripts to
control those activities.  However, it does not include the work's
System Libraries, or general-purpose tools or generally available free
programs which are used unmodified in performing those activities but
which are not part of the work.  For example, Corresponding Source
includes interface definition files associated with source files for
the work, and the source code for shared libraries and dynamically
linked subprograms that the work is specifically designed to require,
such as by intimate data communication or control flow between those
subprograms and other parts of the work.

  The Corresponding Source need not include anything that users
can regenerate automatically from other parts of the Corresponding
Source.

  The Corresponding Source for a work in source code form is that
same work.

  2. Basic Permissions.

  All rights granted under this License are granted for the term of
copyright on the Program, and are irrevocable provided the stated
conditions are met.  This License explicitly affirms your unlimited
permission to run the unmodified Program.  The output from running a
covered work is covered by this License only if the output, given its
content, constitutes a covered work.  This License acknowledges your
rights of fair use or other equivalent, as provided by copyright law.

  You may make, run and propagate covered works that you do not
convey, without conditions so long as your license otherwise remains
in force.  You may convey covered works to others for the sole purpose
of having them make modifications exclusively for you, or provide you
with facilities for running those works, provided that you comply with
the terms of this License in conveying all material for which you do
not control copyright.  Those thus making or running the covered works
for you must do so exclusively on your behalf, under your direction
and control, on terms that prohibit them from making any copies of
your copyrighted material outside their relationship with you.

  Conveying under any other circumstances is permitted solely under
the conditions stated below.  Sublicensing is not allowed; section 10
makes it unnecessary.

  3. Protecting Users' Legal Rights From Anti-Circumvention Law.

  No covered work shall be deemed part of an effective technological
measure under any applicable law fulfilling obligations under article
11 of the WIPO copyright treaty adopted on 20 December 1996, or
similar laws prohibiting or restricting circumvention of such
measures.

  When you convey a covered work, you waive any legal power to forbid
circumvention of technological measures to the extent such circumvention
is effected by exercising rights under this License with respect to
the covered work, and you disclaim any intention to limit operation or
modification of the work as a means of enforcing, against the work's
users, your or third parties' legal rights to forbid circumvention of
technological measures.

  4. Conveying Verbatim Copies.

  You may convey verbatim copies of the Program's source code as you
receive it, in any medium, provided that you conspicuously and
appropriately publish on each copy an appropriate copyright notice;
keep intact all notices stating that this License and any
non-permissive terms added in accord with section 7 apply to the code;
keep intact all notices of the absence of any warranty; and give all
recipients a copy of this License along with the Program.

  You may charge any price or no price for each copy that you convey,
and you may offer support or warranty protection for a fee.

  5. Conveying Modified Source Versions.

  You may convey a work based on the Program, or the modifications to
produce it from the Program, in the form of source code under the
terms of section 4, provided that you also meet all of these conditions:

    a) The work must carry prominent notices stating that you modified
    it, and giving a relevant date.

    b) The work must carry prominent notices stating that it is
    released under this License and any conditions added under section
    7.  This requirement modifies the requirement in section 4 to
    "keep intact all notices".

    c) You must license the entire work, as a whole, under this
    License to anyone who comes into possession of a copy.  This
    License will therefore apply, along with any applicable section 7
    additional terms, to the whole of the work, and all its parts,
    regardless of how they are packaged.  This License gives no
    permission to license the work in any other way, but it does not
    invalidate such permission if you have separately received it.

    d) If the work has interactive user interfaces, each must display
    Appropriate Legal Notices; however, if the Program has interactive
    interfaces that do not display Appropriate Legal Notices, your
    work need not make them do so.

  A compilation of a covered work with other separate and independent
works, which are not by their nature extensions of the covered work,
and which are not combined with it such as to form a larger program,
in or on a volume of a storage or distribution medium, is called an
"aggregate" if the compilation and its resulting copyright are not
used to limit the access or legal rights of the compilation's users
beyond what the individual works permit.  Inclusion of a covered work
in an aggregate does not cause this License to apply to the other
parts of the aggregate.

  6. Conveying Non-Source Forms.

  You may convey a covered work in object code form under the terms
of sections 4 and 5, provided that you also convey the
machine-readable Corresponding Source under the terms of this License,
in one of these ways:

    a) Convey the object code in, or embodied in, a physical product
    (including a physical distribution medium), accompanied by the
    Corresponding Source fixed on a durable physical medium
    customarily used for software interchange.

    b) Convey the object code in, or embodied in, a physical product
    (including a physical distribution medium), accompanied by a
    written offer, valid for at least three years and valid for as
    long as you offer spare parts or customer support for that product
    model, to give anyone who possesses the object code either (1) a
    copy of the Corresponding Source for all the software in the
    product that is covered by this License, on a durable physical
    medium customarily used for software interchange, for a price no
    more than your reasonable cost of physically performing this
    conveying of source, or (2) access to copy the
    Corresponding Source from a network server at no charge.

    c) Convey individual copies of the object code with a copy of the
    written offer to provide the Corresponding Source.  This
    alternative is allowed only occasionally and noncommercially, and
    only if you received the object code with such an offer, in accord
    with subsection 6b.

    d) Convey the object code by offering access from a designated
    place (gratis or for a charge), and offer equivalent access to the
    Corresponding Source in the same way through the same place at no
    further charge.  You need not require recipients to copy the
    Corresponding Source along with the object code.  If the place to
    copy the object code is a network server, the Corresponding Source
    may be on a different server (operated by you or a third party)
    that supports equivalent copying facilities, provided you maintain
    clear directions next to the object code saying where to find the
    Corresponding Source.  Regardless of what server hosts the
    Corresponding Source, you remain obligated to ensure that it is
    available for as long as needed to satisfy these requirements.

    e) Convey the object code using peer-to-peer transmission, provided
    you inform other peers where the object code and Corresponding
    Source of the work are being offered to the general public at no
    charge under subsection 6d.

  A separable portion of the object code, whose source code is excluded
from the Corresponding Source as a System Library, need not be
included in conveying the object code work.

  A "User Product" is either (1) a "consumer product", which means any
tangible personal property which is normally used for personal, family,
or household purposes, or (2) anything designed or sold for incorporation
into a dwelling.  In determining whether a product is a consumer product,
doubtful cases shall be resolved in favor of coverage.  For a particular
product received by a particular user, "normally used" refers to a
typical or common use of that class of product, regardless of the status
of the particular user or of the way in which the particular user
actually uses, or expects or is expected to use, the product.  A product
is a consumer product regardless of whether the product has substantial
commercial, industrial or non-consumer uses, unless such uses represent
the only significant mode of use of the product.

  "Installation Information" for a User Product means any methods,
procedures, authorization keys, or other information required to install
and execute modified versions of a covered work in that User Product from
a modified version of its Corresponding Source.  The information must
suffice to ensure that the continued functioning of the modified object
code is in no case prevented or interfered with solely because
modification has been made.

  If you convey an object code work under this section in, or with, or
specifically for use in, a User Product, and the conveying occurs as
part of a transaction in which the right of possession and use of the
User Product is transferred to the recipient in perpetuity or for a
fixed term (regardless of how the transaction is characterized), the
Corresponding Source conveyed under this section must be accompanied
by the Installation Information.  But this requirement does not apply
if neither you nor any third party retains the ability to install
modified object code on the User Product (for example, the work has
been installed in ROM).

  The requirement to provide Installation Information does not include a
requirement to continue to provide support service, warranty, or updates
for a work that has been modified or installed by the recipient, or for
the User Product in which it has been modified or installed.  Access to a
network may be denied when the modification itself materially and
adversely affects the operation of the network or violates the rules and
protocols for communication across the network.

  Corresponding Source conveyed, and Installation Information provided,
in accord with this section must be in a format that is publicly
documented (and with an implementation available to the public in
source code form), and must require no special password or key for
unpacking, reading or copying.

  7. Additional Terms.

  "Additional permissions" are terms that supplement the terms of this
License by making exceptions from one or more of its conditions.
Additional permissions that are applicable to the entire Program shall
be treated as though they were included in this License, to the extent
that they are valid under applicable law.  If additional permissions
apply only to part of the Program, that part may be used separately
under those permissions, but the entire Program remains governed by
this License without regard to the additional permissions.

  When you convey a copy of a covered work, you may at your option
remove any additional permissions from that copy, or from any part of
it.  (Additional permissions may be written to require their own
removal in certain cases when you modify the work.)  You may place
additional permissions on material, added by you to a covered work,
for which you have or can give appropriate copyright permission.

  Notwithstanding any other provision of this License, for material you
add to a covered work, you may (if authorized by the copyright holders of
that material) supplement the terms of this License with terms:

    a) Disclaiming warranty or limiting liability differently from the
    terms of sections 15 and 16 of this License; or

    b) Requiring preservation of specified reasonable legal notices or
    author attributions in that material or in the Appropriate Legal
    Notices displayed by works containing it; or

    c) Prohibiting misrepresentation of the origin of that material, or
    requiring that modified versions of such material be marked in
    reasonable ways as different from the original version; or

    d) Limiting the use for publicity purposes of names of licensors or
    authors of the material; or

    e) Declining to grant rights under trademark law for use of some
    trade names, trademarks, or service marks; or

    f) Requiring indemnification of licensors and authors of that
    material by anyone who conveys the material (or modified versions of
    it) with contractual assumptions of liability to the recipient, for
    any liability that these contractual assumptions directly impose on
    those licensors and authors.

  All other non-permissive additional terms are considered "further
restrictions" within the meaning of section 10.  If the Program as you
received it, or any part of it, contains a notice stating that it is
governed by this License along with a term that is a further
restriction, you may remove that term.  If a license document contains
a further restriction but permits relicensing or conveying under this
License, you may add to a covered work material governed by the terms
of that license document, provided that the further restriction does
not survive such relicensing or conveying.

  If you add terms to a covered work in accord with this section, you
must place, in the relevant source files, a statement of the
additional terms that apply to those files, or a notice indicating
where to find the applicable terms.

  Additional terms, permissive or non-permissive, may be stated in the
form of a separately written license, or stated as exceptions;
the above requirements apply either way.

  8. Termination.

  You may not propagate or modify a covered work except as expressly
provided under this License.  Any attempt otherwise to propagate or
modify it is void, and will automatically terminate your rights under
this License (including any patent licenses granted under the third
paragraph of section 11).

  However, if you cease all violation of this License, then your
license from a particular copyright holder is reinstated (a)
provisionally, unless and until the copyright holder explicitly and
finally terminates your license, and (b) permanently, if the copyright
holder fails to notify you of the violation by some reasonable means
prior to 60 days after the cessation.

  Moreover, your license from a particular copyright holder is
reinstated permanently if the copyright holder notifies you of the
violation by some reasonable means, this is the first time you have
received notice of violation of this License (for any work) from that
copyright holder, and you cure the violation prior to 30 days after
your receipt of the notice.

  Termination of your rights under this section does not terminate the
licenses of parties who have received copies or rights from you under
this License.  If your rights have been terminated and not permanently
reinstated, you do not qualify to receive new licenses for the same
material under section 10.

  9. Acceptance Not Required for Having Copies.

  You are not required to accept this License in order to receive or
run a copy of the Program.  Ancillary propagation of a covered work
occurring solely as a consequence of using peer-to-peer transmission
to receive a copy likewise does not require acceptance.  However,
nothing other than this License grants you permission to propagate or
modify any covered work.  These actions infringe copyright if you do
not accept this License.  Therefore, by modifying or propagating a
covered work, you indicate your acceptance of this License to do so.

  10. Automatic Licensing of Downstream Recipients.

  Each time you convey a covered work, the recipient automatically
receives a license from the original licensors, to run, modify and
propagate that work, subject to this License.  You are not responsible
for enforcing compliance by third parties with this License.

  An "entity transaction" is a transaction transferring control of an
organization, or substantially all assets of one, or subdividing an
organization, or merging organizations.  If propagation of a covered
work results from an entity transaction, each party to that
transaction who receives a copy of the work also receives whatever
licenses to the work the party's predecessor in interest had or could
give under the previous paragraph, plus a right to possession of the
Corresponding Source of the work from the predecessor in interest, if
the predecessor has it or can get it with reasonable efforts.

  You may not impose any further restrictions on the exercise of the
rights granted or affirmed under this License.  For example, you may
not impose a license fee, royalty, or other charge for exercise of
rights granted under this License, and you may not initiate litigation
(including a cross-claim or counterclaim in a lawsuit) alleging that
any patent claim is infringed by making, using, selling, offering for
sale, or importing the Program or any portion of it.

  11. Patents.

  A "contributor" is a copyright holder who authorizes use under this
License of the Program or a work on which the Program is based.  The
work thus licensed is called the contributor's "contributor version".

  A contributor's "essential patent claims" are all patent claims
owned or controlled by the contributor, whether already acquired or
hereafter acquired, that would be infringed by some manner, permitted
by this License, of making, using, or selling its contributor version,
but do not include claims that would be infringed only as a
consequence of further modification of the contributor version.  For
purposes of this definition, "control" includes the right to grant
patent sublicenses in a manner consistent with the requirements of
this License.

  Each contributor grants you a non-exclusive, worldwide, royalty-free
patent license under the contributor's essential patent claims, to
make, use, sell, offer for sale, import and otherwise run, modify and
propagate the contents of its contributor version.

  In the following three paragraphs, a "patent license" is any express
agreement or commitment, however denominated, not to enforce a patent
(such as an express permission to practice a patent or covenant not to
sue for patent infringement).  To "grant" such a patent license to a
party means to make such an agreement or commitment not to enforce a
patent against the party.

  If you convey a covered work, knowingly relying on a patent license,
and the Corresponding Source of the work is not available for anyone
to copy, free of charge and under the terms of this License, through a
publicly available network server or other readily accessible means,
then you must either (1) cause the Corresponding Source to be so
available, or (2) arrange to deprive yourself of the benefit of the
patent license for this particular work, or (3) arrange, in a manner
consistent with the requirements of this License, to extend the patent
license to downstream recipients.  "Knowingly relying" means you have
actual knowledge that, but for the patent license, your conveying the
covered work in a country, or your recipient's use of the covered work
in a country, would infringe one or more identifiable patents in that
country that you have reason to believe are valid.

  If, pursuant to or in connection with a single transaction or
arrangement, you convey, or propagate by procuring conveyance of, a
covered work, and grant a patent license to some of the parties
receiving the covered work authorizing them to use, propagate, modify
or convey a specific copy of the covered work, then the patent license
you grant is automatically extended to all recipients of the covered
work and works based on it.

  A patent license is "discriminatory" if it does not include within
the scope of its coverage, prohibits the exercise of, or is
conditioned on the non-exercise of one or more of the rights that are
specifically granted under this License.  You may not convey a covered
work if you are a party to an arrangement with a third party that is
in the business of distributing software, under which you make payment
to the third party based on the extent of your activity of conveying
the work, and under which the third party grants, to any of the
parties who would receive the covered work from you, a discriminatory
patent license (a) in connection with copies of the covered work
conveyed by you (or copies made from those copies), or (b) primarily
for and in connection with specific products or compilations that
contain the covered work, unless you entered into that arrangement,
or that patent license was granted, prior to 28 March 2007.

  Nothing in this License shall be construed as excluding or limiting
any implied license or other defenses to infringement that may
otherwise be available to you under applicable patent law.

  12. No Surrender of Others' Freedom.

  If conditions are imposed on you (whether by court order, agreement or
otherwise) that contradict the conditions of this License, they do not
excuse you from the conditions of this License.  If you cannot convey a
covered work so as to satisfy simultaneously your obligations under this
License and any other pertinent obligations, then as a consequence you may
not convey it at all.  For example, if you agree to terms that obligate you
to collect a royalty for further conveying from those to whom you convey
the Program, the only way you could satisfy both those terms and this
License would be to refrain entirely from conveying the Program.

  13. Remote Network Interaction; Use with the GNU General Public License.

  Notwithstanding any other provision of this License, if you modify the
Program, your modified version must prominently offer all users
interacting with it remotely through a computer network (if your version
supports such interaction) an opportunity to receive the Corresponding
Source of your version by providing access to the Corresponding Source
from a network server at no charge, through some standard or customary
means of facilitating copying of software.  This Corresponding Source
shall include the Corresponding Source for any work covered by version 3
of the GNU General Public License that is incorporated pursuant to the
following paragraph.

  Notwithstanding any other provision of this License, you have
permission to link or combine any covered work with a work licensed
under version 3 of the GNU General Public License into a single
combined work, and to convey the resulting work.  The terms of this
License will continue to apply to the part which is the covered work,
but the work with which it is combined will remain governed by version
3 of the GNU General Public License.

  14. Revised Versions of this License.

  The Free Software Foundation may publish revised and/or new versions of
the GNU Affero General Public License from time to time.  Such new versions
will be similar in spirit to the present version, but may differ in detail to
address new problems or concerns.

  Each version is given a distinguishing version number.  If the
Program specifies that a certain numbered version of the GNU Affero General
Public License "or any later version" applies to it, you have the
option of following the terms and conditions either of that numbered
version or of any later version published by the Free Software
Foundation.  If the Program does not specify a version number of the
GNU Affero General Public License, you may choose any version ever published
by the Free Software Foundation.

  If the Program specifies that a proxy can decide which future
versions of the GNU Affero General Public License can be used, that proxy's
public statement of acceptance of a version permanently authorizes you
to choose that version for the Program.

  Later license versions may give you additional or different
permissions.  However, no additional obligations are imposed on any
author or copyright holder as a result of your choosing to follow a
later version.

  15. Disclaimer of Warranty.

  THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY
OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM
IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF
ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

  16. Limitation of Liability.

  IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS
THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY
GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE
USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF
DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD
PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS),
EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF
SUCH DAMAGES.

  17. Interpretation of Sections 15 and 16.

  If the disclaimer of warranty and limitation of liability provided
above cannot be given local legal effect according to their terms,
reviewing courts shall apply local law that most closely approximates
an absolute waiver of all civil liability in connection with the
Program, unless a warranty or assumption of liability accompanies a
copy of the Program in return for a fee.

                     END OF TERMS AND CONDITIONS

            How to Apply These Terms to Your New Programs

  If you develop a new program, and you want it to be of the greatest
possible use to the public, the best way to achieve this is to make it
free software which everyone can redistribute and change under these terms.

  To do so, attach the following notices to the program.  It is safest
to attach them to the start of each source file to most effectively
state the exclusion of warranty; and each file should have at least
the "copyright" line and a pointer to where the full notice is found.

    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

Also add information on how to contact you by electronic and paper mail.

  If your software can interact with users remotely through a computer
network, you should also make sure that it provides a way for users to
get its source.  For example, if your program is a web application, its
interface could display a "Source" link that leads users to an archive
of the code.  There are many ways you could offer source, and different
solutions will be better for different programs; see section 13 for the
specific requirements.

  You should also get your employer (if you work as a programmer) or school,
if any, to sign a "copyright disclaimer" for the program, if necessary.
For more information on this, and how to apply and follow the GNU AGPL, see
<https://www.gnu.org/licenses/>.

```

### README.md
<a name="readmemd"></a>

- **Name:** `README.md`
- **Pfad:** `README.md`
- **SHA256:** `21f92f0fe2307e86a373d13666431a88b10b6ae99b7edcd04017e3a6b758cb8d`

```
# Freetribe

Freetribe is a free, open-source firmware for Electribe 2, built from the ground
up using original code and open-source projects. Freetribe aims to provide a
user-friendly API for connecting control input to audio processing.

See
[Getting Started](https://bangcorrupt.github.io/freetribe-docs/getting-started/)
to jump right into the Freetribe API, or
[Architecture](https://bangcorrupt.github.io/freetribe-docs/architecture/) for a
deeper look at the system.

## Features

From a user application perspective, Freetribe is currently light on features.
Most of the hardware initialisation is complete, with driver stacks for much of
the system. Built on this is a set of services providing a high-level interface
to the device. Some basic examples are provided, showing how to integrate user
application code with the Freetribe kernel.

### Existing Features

- Serial MIDI input and output via TRS port.
- Set or clear a pixel anywhere in the vast 128x64 dot-matrix.
- Control backlight RGB (binary).
- Register callbacks for all of the panel controls.
- Set and toggle LEDs, with brightness control for those with support.
- Send commands to the Blackfin DSP and receive feedback.
- Process audio based on control input.
- Audio module API similar to many plugin formats.

### Planned Features

Some of these are in progress, most should be possible.

- High speed DSP control via EMIFA/HostDMA.
- DMA support for peripheral drivers.
- USB driver.
- SD card driver.
- DSP block processing.
- Memory protection.
- Dynamic loading of apps and modules.
- Preemptive scheduling using FreeRTOS.
- Embedded Lua and MicroPython.
- Support for sync ports.

## Support for You

If you need help with this project, please visit the
[Freetribe discussion forum](https://github.com/bangcorrupt/freetribe/discussions).

## Support for Me

Freetribe is free (as in GPL) and always will be. If you would like to support
my work you are most welcome to
[become a sponsor](https://github.com/sponsors/bangcorrupt). Freetribe exists
because people sponsored Hacktribe. Your support helps keep me motivated,
fuelled and focussed.

## Acknowledgements

Freetribe would be almost impossible without other open-source projects. The CPU
drivers are based on [StarterWare](https://www.ti.com/tool/STARTERWARE-SITARA)
by Texas Instruments. The hardware abstraction, build environment and code
examples provided the stepping-stone needed to get started.

In much the same way, the DSP drivers are based on
[monome/aleph](https://github.com/monome/aleph). This showed how to initialise
the Blackfin processor and configure peripherals. They also provide a public
domain DSP library, with many of the difficult maths problems packaged into
convenient unit generators.

MIDI input parsing is based on
[mikromodular/libmidi](https://github.com/mikromodular/libmidi), with
sysex/binary conversion borrowed from the
[Arduino MIDI library](https://github.com/FortySevenEffects/arduino_midi_library/blob/master/src/MIDI.cpp)
by Francois Best.

[UGUI](https://github.com/deividAlfa/UGUI) and
[micromenu](https://github.com/abcminiuser/micromenu-v2) provide a graphical
interface for user applications.

Special thanks to countless stackoverflow users.

## License

AGPL-3.0.

```

### scripts/README.md
<a name="scriptsreadmemd"></a>

- **Name:** `README.md`
- **Pfad:** `scripts/README.md`
- **SHA256:** `ab85f1619624c20321ff850fc14eac810203b47bfb0b2d33666817dea92e3ecc`

```
# e2-scripts

Scripts for dealing with electribe2 files.

e2all2pat.py  - Converts allpat file to a directory of e2pat files.  

e2pat2syx.py - Converts a pattern file in e2pat format to a pattern file in sysex format.

e2syx2pat.py - Converts a pattern file in sysex format to pattern file in e2pat format.

e2seqrot.py - Rotates sequence of specified part by specified number of steps.  Takes e2pat as input.

e2pat2all.py - Create allpatterns from a single pattern.

e2ev.py - Split event recording by pattern, create stems, mute parts, extract and replace patterns.

e2sysex.py - <-- Moved to [hacktribe-editor](https://github.com/bangcorrupt/hacktribe-editor)

e2-header.py - Edit file header to load sampler firmware on synth hardware

e2-init-pat.py - Insert custom init pattern in electribe 2 sampler firmware version 2.02

e2_syx_codec.py - <-- Moved to [hacktribe-editor](https://github.com/bangcorrupt/hacktribe-editor)

```

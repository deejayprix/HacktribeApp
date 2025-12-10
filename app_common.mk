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

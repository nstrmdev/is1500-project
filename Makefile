.DEFAULT_GOAL := build

TOOLCHAIN ?= riscv32-unknown-elf-
CC := $(TOOLCHAIN)gcc
LD := $(TOOLCHAIN)ld

SRC_DIR := src
PLATFORM_DIR := platform
BUILD_DIR := build

# Include platform headers + normal headers
CPPFLAGS := -Iinclude -I$(PLATFORM_DIR)
CFLAGS := -Wall -nostdlib -O3 -mabi=ilp32 \
          -march=rv32imzicsr -fno-builtin

# Find all source files
SOURCES := $(shell find $(SRC_DIR) $(PLATFORM_DIR) \
           -type f \( -name '*.c' -o -name '*.S' \))

# Derive object file names from source paths
OBJECTS := $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(basename $(SOURCES))))

# Track header dependencies so changes to .h files will rebuild
# the affected objects.
DEPS := $(OBJECTS:.o=.d)

LINKER := $(PLATFORM_DIR)/dtekv-script.lds
SOFTFLOAT := $(PLATFORM_DIR)/softfloat.a
BOOT_OBJ := $(BUILD_DIR)/$(PLATFORM_DIR)/boot.o
LINK_OBJECTS := $(filter-out $(BOOT_OBJ),$(OBJECTS))

ELF := $(BUILD_DIR)/main.elf
BIN := $(BUILD_DIR)/main.bin
DISASM := $(BUILD_DIR)/main.elf.txt

.PHONY: build clean

build: $(BIN) $(DISASM)

# Compile C source files
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

# Compile assembly source files
$(BUILD_DIR)/%.o: %.S
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

# Link the ELF file
$(ELF): $(OBJECTS) $(LINKER) $(SOFTFLOAT) Makefile
	cd $(BUILD_DIR) && $(LD) -m elf32lriscv \
		-L$(PLATFORM_DIR) \
		-T $(abspath $(LINKER)) \
		-o main.elf \
		$(patsubst $(BUILD_DIR)/%,%,$(LINK_OBJECTS)) \
		$(abspath $(SOFTFLOAT))

# Generate binary
$(BIN): $(ELF)
	$(TOOLCHAIN)objcopy --output-target binary $< $@

# Generate disassembly
$(DISASM): $(ELF)
	$(TOOLCHAIN)objdump -D $< > $@

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

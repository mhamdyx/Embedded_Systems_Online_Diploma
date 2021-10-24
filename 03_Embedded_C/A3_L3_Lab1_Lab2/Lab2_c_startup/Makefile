# Simple Makefile by Mahmoud Hamdy
######################################

# File names
# C Source Files
SRC = $(wildcard *.c)
# Include directories
INC_DIR = .
# Assembly source files
ASM = $(wildcard *.s)
# Object files from C files
OBJ = $(SRC:.c=.o)
# Object files from assembly files
ASM_OBJ = $(ASM:.s=.o)
# Dependcies for each source (prerequisites)
DEP = $(SRC:.c=.d)
# Target
TARGET = learn-in-depth-cortex-m3-v2
######################################

# Architecture-specific
# Linker script
LINKER_FILE = linker_script.ld
# Map file
MAP_FILE = map_file.map
# Processor name
CPU = cortex-m3
# ARM-specific flags
ARM_CFLAGS = -mcpu=$(CPU)
######################################

# Compiler tools
# Compiler
CC = arm-none-eabi-gcc
# Assembler
AS = arm-none-eabi-as
# Linker
LD = arm-none-eabi-ld
# Object copy utility
OBJCOPY = arm-none-eabi-objcopy
######################################

# Compiler flags
CFLAGS = $(ARM_CFLAGS) -c $(DEBUG_OPTIONS)
# Preprocessor flags
CPPFLAGS = -I$(INC_DIR) $(DEPFLAGS)
# Assembler flags
ASFLAGS = $(ARM_CFLAGS) $(DEBUG_OPTIONS)
# Linker flags
LDFLAGS = -T $(LINKER_FILE) -Map=$(MAP_FILE)
# Dependency flags (belongs to CPPFLAGS)
DEPFLAGS = -MMD -MP
# Debug flags
DEBUG_OPTIONS = -gdwarf-2
######################################

# Make rules (targets)
.PHONY: all
all: $(TARGET).bin
	@echo "=======Build is Successful======="
######################################

# Generate binary image from elf image
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@
######################################

# Generate output executable from object files
$(TARGET).elf: $(OBJ) $(ASM_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^
######################################

# Generate object file from assembly file
%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<
######################################

# Generate object file from c file
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $<
######################################

# Clean target files
.PHONY: clean
clean:
	rm -rf $(TARGET).*
######################################

# Clean project from generated files
.PHONY: clean_all
clean_all:
	rm -rf $(TARGET).* *.o *.d
######################################

# Include dependencies to source files
# - means to suppress the error at first
-include $(DEP)
######################################

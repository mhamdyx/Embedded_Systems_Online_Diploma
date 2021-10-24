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
TARGET = collision_avoidance
######################################

# Compiler tools
# Compiler
CC = gcc
# Assembler
AS = as
# Linker
LD = gcc
######################################

# Compiler flags
CFLAGS = -c $(DEBUG_OPTIONS)
# Preprocessor flags
CPPFLAGS = -I$(INC_DIR) $(DEPFLAGS)
# Assembler flags
ASFLAGS = $(DEBUG_OPTIONS)
# Linker flags
LDFLAGS = 
# Dependency flags (belongs to CPPFLAGS)
DEPFLAGS = -MMD -MP
# Debug flags
DEBUG_OPTIONS = -gdwarf-2 -g
######################################

# Make rules (targets)
.PHONY: all
all: $(TARGET)
	@echo "=======Build is Successful======="
######################################

# Generate output executable from object files
$(TARGET): $(OBJ) $(ASM_OBJ)
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
	rm -rf $(TARGET)
	@echo "=======Target is clean======="
######################################

# Clean project from generated files
.PHONY: clean_all
clean_all:
	rm -rf $(TARGET) *.o *.d
	@echo "=======Build is clean======="
######################################

# Include dependencies to source files
# - means to suppress the error at first
-include $(DEP)
######################################

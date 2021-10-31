# Source Files
SRCS = $(wildcard *.c)

# Header Files
INCLUDES = -I.

# Compiler Flags and Defines
CC = gcc

# Compiler Flags
CFLAGS = -O0 -g -Wall

# Object File
OBJS = $(SRCS:.c=.o)

# Program File (./PROG argvs)
PROG = students_msys

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -rf $(OBJS) $(PROG)


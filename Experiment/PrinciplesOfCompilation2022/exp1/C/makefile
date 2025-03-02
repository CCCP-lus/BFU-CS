# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99 -O3
LDFLAGS =

# Targets
TARGET = scanner
OBJS = scanner.o common.o

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependencies
scanner.o: scanner.h common.h scanner.c
common.o: common.h common.c

# Clean up build artifacts
clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: all clean
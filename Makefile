CC = gcc
CFLAGS = -Wall -Wextra
SRC = epochalypse.c

# Output binary names
BIN64 = epochalypse-64
BIN32 = epochalypse-32

.PHONY: all clean run

# Default target: builds both 64-bit and 32-bit versions
all: $(BIN64) $(BIN32)

# Build 64-bit executable
$(BIN64): $(SRC)
	$(CC) $(CFLAGS) -m64 $(SRC) -o $(BIN64)
	strip $(BIN64)

# Build 32-bit executable
$(BIN32): $(SRC)
	$(CC) $(CFLAGS) -m32 $(SRC) -o $(BIN32)
	strip $(BIN32)

# Run both side-by-side to compare output
run: all
	@echo "=== Running 64-bit version ==="
	./$(BIN64)
	@echo ""
	@echo "=== Running 32-bit version ==="
	./$(BIN32)

# Remove compiled binaries
clean:
	rm -f $(BIN64) $(BIN32)

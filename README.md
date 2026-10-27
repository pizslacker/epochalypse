# 2038-linux-bug

This C program demonstrates the Year 2038 problem (also known as the Y2K38 or Epochalypse bug), showing what happens when a 32-bit signed integer tracking Unix time overflows.

## How the Program Works

In traditional 32-bit Unix and Linux systems, `time_t` is a signed 32-bit integer that counts the number of seconds elapsed since the Unix Epoch (00:00:00 UTC on January 1, 1970).
1. **Historical Milestones** (`0, 100000000, 900000000`): The program sets `t` to specific second counts, converts them to UTC via `gmtime(&t)`, and formats them into human-readable strings using `asctime()` (which automatically appends a newline `\n`).
2. **Current Time** (`time(NULL)`): Reads your system's live clock and prints the current Unix timestamp and UTC date.
3. **The 32-bit Limit** (`2147483647`): Sets `t` to $2^{31} - 1$, the maximum positive value a signed 32-bit integer can hold (`0x7FFFFFFF` in hexadecimal), which corresponds to January 19, 2038, at 03:14:07 UTC.
4. **The Rollover** (`t++`): Adds 1 second. On a 32-bit system, the binary value flips from `01111111...` to `10000000...` (`-2147483648`), wrapping the clock backward to December 13, 1901, at 20:45:52 UTC.

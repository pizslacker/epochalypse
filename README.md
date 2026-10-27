# Epochalypse

This C program demonstrates the Year 2038 problem (also known as the Y2K38 or Epochalypse bug), showing what happens when a 32-bit signed integer tracking Unix time overflows.

Example output:
```bash
=== Running 64-bit version ===
./2038-linux-bug-64
2038-linux-bug (S2C) v1.0
======================================
          0, Thu Jan  1 00:00:00 1970
  100000000, Sat Mar  3 09:46:40 1973
  900000000, Thu Jul  9 16:00:00 1998
 1793137056, Tue Oct 27 21:37:36 2026
 2147483647, Tue Jan 19 03:14:07 2038
-2147483648, Tue Jan 19 03:14:08 2038

=== Running 32-bit version ===
./2038-linux-bug-32
2038-linux-bug (S2C) v1.0
======================================
          0, Thu Jan  1 00:00:00 1970
  100000000, Sat Mar  3 09:46:40 1973
  900000000, Thu Jul  9 16:00:00 1998
 1793137056, Tue Oct 27 21:37:36 2026
 2147483647, Tue Jan 19 03:14:07 2038
-2147483648, Fri Dec 13 20:45:52 1901
```

## How the Program Works

In traditional 32-bit Unix and Linux systems, `time_t` is a signed 32-bit integer that counts the number of seconds elapsed since the Unix Epoch (00:00:00 UTC on January 1, 1970).
1. **Historical Milestones** (`0, 100000000, 900000000`): The program sets `t` to specific second counts, converts them to UTC via `gmtime(&t)`, and formats them into human-readable strings using `asctime()` (which automatically appends a newline `\n`).
2. **Current Time** (`time(NULL)`): Reads your system's live clock and prints the current Unix timestamp and UTC date.
3. **The 32-bit Limit** (`2147483647`): Sets `t` to $2^{31} - 1$, the maximum positive value a signed 32-bit integer can hold (`0x7FFFFFFF` in hexadecimal), which corresponds to January 19, 2038, at 03:14:07 UTC.
4. **The Rollover** (`t++`): Adds 1 second. On a 32-bit system, the binary value flips from `01111111...` to `10000000...` (`-2147483648`), wrapping the clock backward to December 13, 1901, at 20:45:52 UTC.

### How to Force the Bug on a 64-bit Machine

If you want to see the genuine 1901 date rollover on a modern 64-bit Linux system, this project compiles to both `32-bit` and `64-bit` binaries. Just run the following:
```bash
make run
```

### License

This project is open-source software licensed under the GNU General Public License v3.0 (GPLv3). See the [LICENSE](LICENSE) file for terms and conditions.

Copyright (C) k!M/pizslacker 2014-2026

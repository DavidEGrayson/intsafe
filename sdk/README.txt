This directory contains patches for getting intsafe.h from different versions
of the SDK to work with GCC/Clang so we can test it.

In addition to the patch, you also have to modify test.sh:
change the C language standard to -std=gnu11 (for the asserts).

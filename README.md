# intsafe.h implementation collection

These files are implementations of Microsoft's [intsafe.h header](https://msdn.microsoft.com/en-us/library/windows/desktop/ff521693), which defines 253 inline functions for safe conversions, additions, multiplications, and subtractions of integers.
I made this collection so that we can easily compare the choices available to us and make a good implementation for [mingw-w64](http://mingw-w64.org/).

## coreclr

This is [Microsoft's implementation from coreclr](https://github.com/dotnet/coreclr/blob/master/src/pal/inc/rt/intsafe.h).

* License: MIT
* Lines: 1621
* Functions missing: 108

## tta

This implementation was originally [posted](https://sourceforge.net/p/mingw-w64/feature-requests/33/) on SourceForge by tta in 2010.

* License: Public domain
* Lines: 5587
* Functions missing: 30

## tta_fixed

This is based on tta's work, but with some small patches to get most of my tests to pass.

## reactos

This version is [ReactOS's version of intsafe.h](https://code.google.com/p/reactos-mirror/source/browse/trunk/reactos/include/psdk/intsafe.h?r=56995).

* License: Public domain
* Lines: 770
* Functions missing: 154

## sdk10

This version is from Microsoft's [Standalone Windows SDK for Windows 10](https://msdn.microsoft.com/en-us/windows/hardware/dn913721.aspx) and I don't think I can actually commit it to this repo without violating their license, so I didn't.

The versions found in the Windows 8 and Windows 8.1 SDKs were very similar.

* License: <font color='red'>All rights reserved AFAIK</font>
* Lines: 8570

## test

The "test" folder contains scripts for testing an implementation of intsafe.h.

The `grepcheck.sh` script uses grep to see which functions are implemented and reports the missing ones.

The `build.sh` script calls grepcheck.sh, and it also calls a Ruby script to generate a C/C++ test file (`generated_tests.cpp`).  It then compiles and runs the generated tests for several different environments.

# intsafe.h testing and generation for mingw-w64

These files help the [mingw-w64] project matain its implementation of
[Microsoft's intsafe.h header], which defines hundreds of inline functions for safe
conversions, additions, multiplications, and subtractions of integers.

I originally auto-generated mignw-w64's intsafe.h back in 2015, but a few other
contributors have added things since then.

## How to run tests

To run an auto-generated testsuite for intsafe.h, run `./test/test.sh INTSAFE`, where `INTSAFE`
is the path to the implementation you want to test.  Some examples:

    ./test/test.sh ./intsafe.h
    ./test/test.sh ../mingw-w64/mingw-w64-headers/include/intsafe.h

[mingw-w64]: https://www.mingw-w64.org/
[Microsoft's intsafe.h header]: https://msdn.microsoft.com/en-us/library/windows/desktop/ff521693

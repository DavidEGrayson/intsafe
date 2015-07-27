cd `dirname $0`

if [ -z "$VER" ]
then
    VER=proposed
fi
echo "intsafe version: $VER"

set -ue

echo "compiling C tests"
gcc -I../$VER test.c -o run_test_c

echo "generating tests"
ruby generate.rb

# TODO: add -Wall and fix all warnings
CXXARGS="--std=gnu++11 -I../$VER generated_tests.cpp"

#echo "compiling for C++, win32, signed char"
#PATH=/mingw32/bin:$PATH g++ $CXXARGS -fno-unsigned-char -o run_test_32s
#./run_test_32s

#echo "compiling for C++, win32, unsigned char"
#PATH=/mingw32/bin:$PATH g++ $CXXARGS -funsigned-char -o run_test_32u
#./run_test_32u

echo "compiling for C++, win64, signed char"
PATH=/mingw64/bin:$PATH g++ $CXXARGS -fno-unsigned-char -o run_test_64s
./run_test_64s

echo "compiling for C++, win64, unsigned char"
PATH=/mingw64/bin:$PATH g++ $CXXARGS -funsigned-char -o run_test_64u
./run_test_64u


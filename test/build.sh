cd `dirname $0`

if [ -z "$VER" ]
then
    VER=proposed
fi
echo "intsafe version: $VER"

echo compiling C tests
gcc -I../$VER test.c -o run_test_c

echo compiling C++ tests
g++ --std=gnu++11 -I../$VER test.cpp -o run_test

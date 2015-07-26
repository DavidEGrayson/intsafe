cd `dirname $0`

if [ -z "$VER" ]
then
    VER=proposed
fi
echo "intsafe version: $VER"

set -ue

echo compiling C tests
gcc -I../$VER test.c -o run_test_c

echo generating C++ tests
ruby generate.rb

echo compiling C++ tests
g++ --std=gnu++11 -I../$VER test.cpp generated_tests.cpp -o run_test

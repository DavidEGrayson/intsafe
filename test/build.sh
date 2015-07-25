cd `dirname $0`

if [ -z "$VER" ]
then
    VER=proposed
fi
echo "intsafe version: $VER"

g++ --std=gnu++11 -I../$VER test.cpp -o run_test


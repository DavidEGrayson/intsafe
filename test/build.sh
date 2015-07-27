cd `dirname $0`

if [ -z "$VER" ]
then
    VER=proposed
fi
echo "intsafe version: $VER"

set -ue

echo "Compiling C tests"
gcc -I../$VER test.c -o run_test_c

echo "Generating tests"
ruby generate.rb

# TODO: add -Wall and fix all warnings
CXXARGS="--std=gnu++11 -I../$VER generated_tests.cpp"

test_machine () {
  local machine=`g++ -dumpmachine`

  echo "Testing ${machine}, signed char, C++"
  g++ $CXXARGS -fno-unsigned-char -o run_test
  ./run_test

  echo "Testing ${machine}, unsigned char, C++"
  g++ $CXXARGS -funsigned-char -o run_test
  ./run_test
}

PATH=/mingw32/bin:$PATH test_machine
PATH=/mingw64/bin:$PATH test_machine

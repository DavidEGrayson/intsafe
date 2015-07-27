cd $(dirname $0)

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

test_config () {
  echo "Testing $(gcc -dumpmachine), ${extra_args}, C++"
  g++ $CXXARGS ${extra_args} -o run_test
  ./run_test
}

test_machine () {
  extra_args="-fno-unsigned-char" test_config
  extra_args="-funsigned-char" test_config
}

# Uncomment this to just test your default environment, which allows
# for a faster development cycle.
# extra_args= test_config && exit

PATH=/mingw32/bin:$PATH test_machine
PATH=/mingw64/bin:$PATH test_machine

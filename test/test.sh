#!/usr/bin/bash
set -ue

if [ $# -eq 0 ]; then
  echo "Usage: ./test/test.sh path/to/intsafe.h"
  exit 1
fi

if [ '!' -f "$1" ]; then
  echo "error: file not found, or it is not a file: $1"
fi

cp "$1" $(dirname $0)/intsafe.h

cd $(dirname $0)

echo "Generating tests"
ruby gen_tests.rb

# To test using clang, edit the script below:
# - change -O1 to -O3
# - add -fsanitized=undefined
# - change "g++" and "gcc" to "clang"
# - comment out things that don't work (c++ didn't work for me)

# We add -O1 to avoid getting undefined reference errors for the
# inline functions without optimizations.  This should probably be fixed.
# Some day, we should add -fsanitize=undefined here.
CARGS="-Wall -Werror -pedantic -O1 generated_tests.cpp"

test_config () {
  echo "Testing $machine, $language, $extra_args"
  if [ "$language" = "c++" ]; then
    compiler="g++ -x c++ --std=gnu++11"
  else
    compiler="gcc -x c --std=gnu99"
  fi
  $compiler $CARGS ${extra_args} -o run_test.exe
  ./run_test
}

test_machine () {
  language=c extra_args="-fno-unsigned-char" test_config
  language=c extra_args="-funsigned-char" test_config
  language=c++ extra_args="-fno-unsigned-char" test_config
  language=c++ extra_args="-funsigned-char" test_config
}

machine=mingw32 PATH=/mingw32/bin:$PATH test_machine
machine=mingw64 PATH=/mingw64/bin:$PATH test_machine

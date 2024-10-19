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
CFLAGS="-Wall -Werror -pedantic -O1"

test_config() {
  if [ "$machine" == "clangarm64" ]; then
    compiler="/opt/bin/aarch64-w64-mingw32-"
    runtime_path=
  else
    compiler="/$machine/bin/"
    runtime_path="/$machine/bin/"
  fi

  echo "Compiling${runtime_path:+ and running} tests for $machine, $language, $extra_args"

  if [ "$language" = "c++" ]; then
    compiler+="g++ -x c++ --std=gnu++11"
  else
    compiler+="gcc -x c --std=gnu99"
  fi
  PATH=$runtime_path:$PATH $compiler $CFLAGS $extra_args run_tests.cpp -o run_tests.exe

  if [ -n "$runtime_path" ]; then
    PATH=$runtime_path:$PATH ./run_tests
  fi
}

test_machine() {
  language=c extra_args="-fno-unsigned-char" test_config
  language=c extra_args="-funsigned-char" test_config
  language=c++ extra_args="-fno-unsigned-char" test_config
  language=c++ extra_args="-funsigned-char" test_config
}

machine=mingw32 test_machine
machine=mingw64 test_machine
machine=clangarm64 test_machine

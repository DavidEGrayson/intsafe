cd $(dirname $0)

if [ -z "$VER" ]
then
    VER=generated
fi
echo "intsafe version: $VER"

set -ue

echo "Generating tests"
ruby generate.rb

# To test using clang, edit the script below:
# - change -O1 to -O3
# - add -fsanitized=undefined
# - change "g++" and "gcc" to "clang"
# - comment out things that don't work (c++ didn't work for me)

# We add -O1 to avoid getting undefined reference errors for the
# inline functions without optimizations.  This should probably be fixed.
# Some day, we should add -fsanitize=undefined here.
CARGS="-Wall -Werror -pedantic -O1 -I../$VER generated_tests.cpp"

test_config () {
  echo "Testing $language, $(gcc -dumpmachine), ${extra_args}"
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

PATH=/mingw32/bin:$PATH test_machine
PATH=/mingw64/bin:$PATH test_machine

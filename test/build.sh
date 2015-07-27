cd $(dirname $0)

if [ -z "$VER" ]
then
    VER=proposed
fi
echo "intsafe version: $VER"

set -ue

echo "Checking for missing functions"
sh grepcheck.sh

echo "Generating tests"
ruby generate.rb

# We add -O1 to avoid getting undefined reference errors for the
# inline functions without optimizations.  This should probably be fixed.
CARGS="-Wall -Werror -O1 -I../$VER generated_tests.cpp"

test_config () {
  echo "Testing $language, $(gcc -dumpmachine), ${extra_args}"
  if [ "$language" = "c++" ]; then
    compiler="g++ -x c++ --std=gnu++11"
  else
    compiler="gcc -x c --std=gnu99"
  fi
  $compiler $CARGS ${extra_args} -o run_test
  ./run_test
}

test_machine () {
  language=c extra_args="-fno-unsigned-char" test_config
  language=c extra_args="-funsigned-char" test_config
  language=c++ extra_args="-fno-unsigned-char" test_config
  language=c++ extra_args="-funsigned-char" test_config
}

# Uncomment to just test your default C++ environment and skip others:
# compiler=g++ extra_args= test_config; exit

PATH=/mingw32/bin:$PATH test_machine
PATH=/mingw64/bin:$PATH test_machine

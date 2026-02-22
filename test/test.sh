#!/usr/bin/bash
set -ue

if [ $# -eq 0 ]; then
  echo "Usage: ./test/test.sh path/to/intsafe.h"
  exit 1
fi

if [ '!' -f "$1" ]; then
  echo "error: file not found, or it is not a file: $1"
  exit 1
fi

cp "$1" $(dirname $0)/intsafe_under_test.h
cd $(dirname $0)

echo "Generating tests"
./gen_tests.rb

echo "Cleaning up"
outdir="ninja-out"
rm -rf "$outdir"
mkdir -p "$outdir"

echo "Generating ninja build file"

stamps=()

ninja_escape() {
  local s="$1"
  s=${s//$'\n'/ }
  s=${s//\$/\$\$}
  printf '%s' "$s"
}

cat > build.ninja <<'EOF'
ninja_required_version = 1.3

rule test
  command = bash -lc "$cmd"
  description = $desc
EOF

add_test() {
  local id="$1"
  local machine="$2"
  local language="$3"
  local extra_args="$4"

  local compiler runtime_path
  if [ "$machine" = "clangarm64" ]; then
    compiler="/opt/bin/aarch64-w64-mingw32-"
    runtime_path=""
  elif [ "$machine" = "msys" ]; then
    compiler="/usr/bin/"
    runtime_path="/usr/bin/"
  else
    compiler="/$machine/bin/"
    runtime_path="/$machine/bin/"
  fi

  local cc
  if [ "$language" = "c++" ]; then
    cc="${compiler}g++ -x c++ --std=gnu++11"
  else
    cc="${compiler}gcc -x c --std=gnu23"
  fi

  local cflags="-Wall -Werror -pedantic -O1 -isystem ."
  if [[ "$machine" == clang32 || "$machine" == clang64 ]]; then
    cflags+=" -fsanitize=undefined"
  fi

  local exe="$outdir/run_tests_${id}.exe"
  local stamp="$outdir/${id}.stamp"
  stamps+=("$stamp")

  local path_prefix=""
  if [ -n "$runtime_path" ]; then
    path_prefix="PATH=\"$runtime_path:\$PATH\" "
  fi

  local run_part=":"
  if [ -n "$runtime_path" ]; then
    run_part="$path_prefix \"$exe\""
  fi

  local cmd_str="${path_prefix}$cc $cflags $extra_args run_tests.cpp -o \"$exe\" && $run_part && touch \"$stamp\""

  local desc="Compiling${runtime_path:+ and running} tests for $machine $language${extra_args:+ $extra_args}"

  cmd_str="$(ninja_escape "$cmd_str")"
  desc="$(ninja_escape "$desc")"

  {
    echo
    echo "build $stamp: test run_tests.cpp generated.cpp intsafe_under_test.h"
    echo "  cmd = $cmd_str"
    echo "  desc = $desc"
  } >> build.ninja
}

add_machine() {
  local machine="$1"
  add_test "$machine-c0" "$machine" "c"   ""
  add_test "$machine-c1" "$machine" "c"   "-DINCLUDE_STYLE=1"
  add_test "$machine-c2" "$machine" "c"   "-funsigned-char"
  add_test "$machine-c3" "$machine" "c++" ""
}

add_machine msys
add_machine ucrt64
add_machine mingw32
add_machine mingw64
add_machine clang64
add_machine clangarm64

# Phony default target
{
  echo
  printf 'build all: phony'
  for s in "${stamps[@]}"; do
    printf ' %s' "$s"
  done
  printf '\n\ndefault all\n'
} >> build.ninja

echo "Running ninja"
ninja

echo Success.

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

cp "$1" $(dirname $0)/intsafe.h
cd $(dirname $0)

echo "Generating tests"
ruby gen_tests.rb

echo "Cleaning up"
outdir="ninja-out"
rm -rf "$outdir"
mkdir -p "$outdir"

echo "Generating ninja build file"

stamps=()

# Replace literal $ with $$ for Ninja.
ninja_escape_dollars() {
  local s="$1"
  s=${s//\$/\$\$}
  printf '%s' "$s"
}

# For cmd: also collapse newlines to spaces.
ninja_escape_cmd() {
  local s="$1"
  s=${s//$'\n'/ }
  s=${s//\$/\$\$}
  printf '%s' "$s"
}

# Sanitize extra_args into a filename-ish chunk, without spawning tr/sed.
sanitize_id() {
  # Keep only [A-Za-z0-9_=-], turn space and / into _
  local s="$1"
  s=${s//[\/ ]/_}
  local out="" c
  local i
  for ((i=0; i<${#s}; i++)); do
    c=${s:i:1}
    case "$c" in
      [A-Za-z0-9_=\-]) out+="$c" ;;
    esac
  done
  printf '%s' "$out"
}

cat > build.ninja <<'EOF'
ninja_required_version = 1.3

rule test
  command = bash -lc "$cmd"
  description = $desc
EOF

add_test() {
  local machine="$1"
  local language="$2"
  local extra_args="$3"

  local compiler runtime_path
  if [ "$machine" = "clangarm64" ]; then
    compiler="/opt/bin/aarch64-w64-mingw32-"
    runtime_path=""
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

  local cflags="-Wall -Werror -pedantic -O1"
  if [[ "$machine" == clang32 || "$machine" == clang64 ]]; then
    cflags+=" -fsanitize=undefined"
  fi

  local id="${machine}_${language}"
  if [ -n "$extra_args" ]; then
    id+="_$(sanitize_id "$extra_args")"
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

  cmd_str="$(ninja_escape_cmd "$cmd_str")"
  desc="$(ninja_escape_dollars "$desc")"

  {
    echo
    echo "build $stamp: test run_tests.cpp intsafe.h"
    echo "  cmd = $cmd_str"
    echo "  desc = $desc"
  } >> build.ninja
}

add_machine() {
  local machine="$1"
  add_test "$machine" "c"   ""
  add_test "$machine" "c"   "-DINCLUDE_STYLE=1"
  add_test "$machine" "c"   "-funsigned-char"
  add_test "$machine" "c++" ""
}

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

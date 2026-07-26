#!/usr/bin/env bash
# clean old artifacts
# compile each .c file to its own .o
# inspect symbols and relocations
# link the object files
# inspect the final ELF
# run the program

set -euo pipefail

main () {
   cc -E "$1" > build/main.i
   cc -S "$1" -o build/main.s
   cc -c "$1" -o build/main.o
   nm build/main.o > build/main.symbols
   readelf -S build/main.o > build/main.sections
   readelf -r build/main.o > build/main.relocations
   objdump -dr build/main.o > build/main.disassembly

    nvim \
      build/main.i \
      build/main.s \
      build/main.symbols \
      build/main.sections \
      build/main.relocations \
      build/main.disassembly
}

main "$@"

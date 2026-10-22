#!/usr/bin/env bash
set -Eeuo pipefail
IFS=$'\n\t'

main() {
  ./build-copy.sh cp.c hello.txt > outfile.txt
}

main "$@"

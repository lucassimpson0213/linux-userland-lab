#!/usr/bin/env bash
set -Eeuo pipefail
IFS=$'\n\t'

main() {
    gcc -o copy cp.c  
    ./copy
}

main "$@"

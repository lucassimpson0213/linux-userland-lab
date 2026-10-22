#!/usr/bin/env bash
set -Eeuo pipefail
IFS=$'\n\t'

main() {
    gcc -o copy cp.c buffer.c
    if [[ $# -gt 1 ]]; then 
       ./copy "$1" "$2"
    else 
        ./copy "$1"
    fi

}

main "$@"

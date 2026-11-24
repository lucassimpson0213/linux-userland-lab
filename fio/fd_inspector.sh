#!/usr/bin/env bash
set -Eeuo pipefail
IFS=$'\n\t'

main() {
    cat /dev/fd/2
}

main "$@"

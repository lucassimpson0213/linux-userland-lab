#!/usr/bin/env bash
set -Eeuo pipefail
IFS=$'\n\t'
FILE_ARR=()
inputs=(
  ""
  "a"
  "hello"
  "Hello, World!"
  "The quick brown fox jumps over the lazy dog."
  "1234567890"
  "special !@#$%^&*()_+-=[]{}|;:',.<>/?"
  "multiple     spaces"
  $'line1\nline2'
  $'line1\nline2\nline3'
  $'trailing newline\n'
  $'\ttabs\tbetween\twords'
  $'mixed\tspaces and\ttabs'
  $'carriage\rreturn'
  $'null?\0'   # Bash strings cannot actually contain embedded NULs
)
test_case() {
    input=$1
    test_number=$2
    echo "$input" | ./mytee "myhello${test_number}.txt"
    echo "$input"  | tee "hello${test_number}.txt"

    
    if diff "hello${test_number}.txt" "myhello${test_number}.txt" > "generated_diff${test_number}.txt" ; then
        echo "Test number ${test_number} PASS there are no diffs for this file: $input"
    else
        echo "Test number ${test_number} FAIL there is a diff for this input"
        cat "generated_diff${test_number}.txt"
        FILE_ARR+=("generated_diff${test_number}.txt") 
    fi

    printf "\n"
    printf "\n"
    printf "\n"



}
main() {
    
#-g adds debugging symbols  
 gcc -g -Wall -Wextra -Wpedantic -fsanitize=undefined,address,leak tee.c -fno-omit-frame-pointer -o mytee
 which tee 

 touch myhello.txt 
 touch hello.txt

 i=1

 
 for input in "${inputs[@]}"; do 

     ((i++))
     #bash gotcha: if i is 0 it will evaluate to false in the shell this will exit the program

     test_case "$input" "$i"
     
done 



 rm myhello.txt 
 rm hello.txt

 nvim "${FILE_ARR[@]}"
}

main "$@"

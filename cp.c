#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]) {

  if (argc != 3 || strcmp(argv[0], "--help") == 0) {
     printf("not enough arguments, expected 3 or more and got %i...\n", argc);
     printf("usage: cp <file> <file> \n");
  }

  int fd = open(argv[1]) 
}

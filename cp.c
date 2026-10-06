#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

  if (argc != 3 || strcmp(argv[0], "--help") == 0) {
    printf("not enough arguments, expected 3 or more and got %i...\n", argc);
    printf("usage: cp <file> <file> \n");
  }

  int flags = O_RDONLY;

  // owner is the user 
  int fd = open(argv[1], flags, S_IRUSR);

  if (fd == -1) {
    // do something... 
    return 1;
  }
}


void errExit() {
    // this is a placeholder for the function 
    // to examine error info from errno after an error has occurred
}

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

  if (argc != 3 || strcmp(argv[0], "--help") == 0) {
    printf("not enough arguments, expected 3 or more and got %i...\n", argc);
    printf("usage: cp <file> <file> \n");
  }

  int flags = O_RDONLY | O_DIRECTORY | O_APPEND;
  int fd = open(argv[1], flags, S_IRUSR);

  if (fd == 0) {
    // do something... 
  }
}

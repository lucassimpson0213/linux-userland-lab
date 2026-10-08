#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define READBUFSIZE 1024

int errExit(int errnumber, char *formatstring) {
  char *error = strerror(errnumber);

  printf(formatstring, error);
  return 1;
  // this is a placeholder for the function
  // to examine error info from errno after an error has occurred
}

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
    errExit(errno, "There has been an error opening the file: \n %s");
  }

  uint8_t buffer[1024] = {0};
  int read_bytes = read(fd, buffer, 1024);

  for (int i = 0; i < 1024; i++) {
  }
}

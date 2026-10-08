#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define READBUFSIZE 1024

int err_exit(int errnumber, char *formatstring) {
  char *error = strerror(errnumber);

  printf(formatstring, error);
  return 1;
  // this is a placeholder for the function
  // to examine error info from errno after an error has occurred
}

void print_buffer(const char *buffer) {
    printf("%s", buffer);
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
    err_exit(errno, "There has been an error opening the file: \n %s");
  }

  char buffer[1024] = {0};
  int read_bytes = read(fd, buffer, 1024);

  print_buffer(buffer);
}

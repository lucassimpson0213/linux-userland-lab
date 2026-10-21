#include "buffer.h"
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define READBUFSIZE 1024

void err_exit(int errnumber, const char func[], char *formatstring) {
  char *error = strerror(errnumber);

  printf(formatstring, func, error);
  printf("\n");
  exit(EXIT_FAILURE);
  // this is a placeholder for the function
  // to examine error info from errno after an error has occurred
}

void print_buffer(const char *buffer, int line) {
  printf("current state of buffer on line %d of file %s: \n %s \n ", line,
         __FILE__, buffer);
}
void write_to_file(const char *file_name, char *const buffer,
                   int number_of_bytes) {
  int fd = open(file_name, O_WRONLY | O_CREAT, 0644);
  print_buffer(buffer, __LINE__);

  if (fd == -1) {
    err_exit(errno, __func__,
             "There was an error opening the file in %s: \n %s \n");
  }

  int bytes_written = write(fd, buffer, number_of_bytes);

  if (bytes_written == -1) {
    err_exit(errno, __func__,
             "There was an error writing to the buffer in %s: \n %s \n");
  }

  // ensure that you don't overwrite outside the buffer so ensure that the
  // buffer is a certain lenght
  //  also ensure that you only write the amount of bytes that you read from the
  //  other file
}

int main(int argc, char *argv[]) {

  if (argc < 2 || strcmp(argv[0], "--help") == 0) {
    printf("not enough arguments, expected 3 or more and got %i...\n", argc);
    printf("usage: cp <file> <file> \n");
  }

  int flags = O_RDONLY;

  // owner is the user
  int fd = open(argv[1], flags, S_IRUSR);

  if (fd == -1) {
    // do something...
    err_exit(errno, __func__,
             "There has been an error opening the file in %s: \n %s");
  }

  char buffer[1024] = {0};
  Buffer *buf = new_buf(BUFSIZE);
  char *const buf_ref = get_raw_bytes_mut(buf);
  int read_bytes = read(fd, buf_ref, 1024);

  print_buffer(buf_ref, __LINE__);

  if (read_bytes == -1) {
    err_exit(errno, __func__,
             "There was an error reading the file in %s: \n %s \n");
  } else if (read_bytes == 0) {
    printf("reached end of file while reading %s", argv[1]);
  } else {
    update_size(buf, read_bytes);
  }

  print_buffer(buf_ref, __LINE__);

  size_t current_size = get_size(buf);
  const char *const buffer_ref = get_raw_bytes(buf);

  // need to add size and buffer methods
  write_to_file(argv[2], get_raw_bytes_mut(buf), current_size);
}

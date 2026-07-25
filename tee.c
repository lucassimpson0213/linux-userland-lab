#include <asm-generic/errno.h>
#include <assert.h>
#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFSIZE 1024
#define ACCUMSIZE 8192

int write_to_accum(char *src[], char *dest[], ssize_t current_idx) {
  const uint64_t SPACE_TIL_END = ACCUMSIZE - (current_idx + 1);

  if (!(SPACE_TIL_END < 1025)) {
    for (int i = 0; i < sizeof(*src); i++) {
      dest[i + current_idx] = src[i];
    }
  } else {
    *dest[ACCUMSIZE] = '\0';
    return false;
  }
  return true;
}

bool file_exists(const char *filename) {
  struct stat *buffer;
  int error = stat(filename, buffer);
  if (error == -1) {
    // now inspect errno
    //  errno is only set after the system call fails with -1
    int error = errno;

    if (error == ENONET) {
      printf("%s", "file not found, or does not exist");
      return false;
    }
  }
  return true;
}
int main(int argc, char *argv[]) {
  // read from stdin until end of file

  // file to write to
  char *file_arg = argv[1];

  char buf[BUFSIZE];
  char accum[ACCUMSIZE];
  ssize_t sizeOrStatus;
  ssize_t index = 0;

  while ((sizeOrStatus = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
    index += sizeOrStatus;
    printf("%s", buf);
    fflush(stdout);
    if (sizeOrStatus == -1) {
      // exit code 1
      printf("%s", "returning error code 1");
      fflush(stdout);
      return 1;
    } else if (sizeOrStatus == 0) {
      printf("%s", "printing at end of file");
      printf("%s", buf);
      fflush(stdout);
      break;
    }
  }

  // we are under the assumption that the characters are now accumulated in the
  // buffer we are going to write to the file assuming it exists) {
  if (!file_exists(file_arg)) {
    return 1;
  }
  int fd = open(file_arg, O_FSYNC); 
  ssize_t ret = write(fd, accum, index);
   
}

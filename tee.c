#include <error.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFSIZE 1024
#define ACCUMSIZE 8192

void write_to_accum(char *src[], char *dest[], ssize_t current_idx) {
  const uint64_t SPACE_TIL_END = ACCUMSIZE - (current_idx + 1);

  if (!(SPACE_TIL_END < 1024)) {
    for (int i = 0; i < sizeof(*src); i++) {
      dest[i + current_idx] = src[i];
    }
  }
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
}

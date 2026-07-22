#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFSIZE 1024
#define ACCUMSIZE 8192

void write_to_accum(char *src[], char *dest[]) {}
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

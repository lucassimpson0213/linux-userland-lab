#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFSIZE 2000
int main() {
  // read from stdin until end of file

  int fd;
  ssize_t index = 0;
  char buf[BUFSIZE];
  ssize_t sizeOrStatus;
  while ((sizeOrStatus = read(STDIN_FILENO, buf, BUFSIZE))) {

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

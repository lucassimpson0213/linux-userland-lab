#include <error.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFSIZE 100
int main() {
  // read from stdin until end of file

  int fd;

  char buf[BUFSIZE];

  ssize_t status = read(STDIN_FILENO, buf, BUFSIZE);

  if (status == -1) {
    // exit code 1
    return 1;
  }
}

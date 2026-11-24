#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>  // Required for close()

int main() {
    printf("hello");
    const char * file_name = "filename";
    int fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND);
    lseek(fd, 0, SEEK_SET);

}

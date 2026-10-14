#include "buffer.h"
#include <stdlib.h>


struct Buffer {
    char buffer [BUFSIZE];
    int capacity; 
    size_t size; 
};

void new_buf(size_t capacity) {
  Buffer *buf = malloc(sizeof(Buffer));

  for (int i = 0; i < BUFSIZE; i++) {

  }
}

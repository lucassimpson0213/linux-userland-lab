#include "buffer.h"
#include <stdlib.h>

struct Buffer {
  char *buffer;
  int capacity;
  size_t size;
};

Buffer *new_buf(size_t capacity) {
  // if you extend the buffer any previous pointers will be invalidated
  Buffer *buf = malloc(sizeof(Buffer));
  buf->buffer = malloc(BUFSIZE);


  for (int i = 0; i < BUFSIZE; i++) {
    // every buffer that holds characters must have a null termination byte at
    // the end
    if (i == BUFSIZE - 1) {
      buf->buffer[i] = '\n';
    } else {
      buf->buffer[i] = 0;
    }
  }

  return buf;
}

void update_size(Buffer* buffer, size_t size) {
    // bookkeeping for size making sure no operations go outside of buffer length;
    buffer->size = size; 
}

void destroy_buf(Buffer* buf) {
    free(buf->buffer);
    buf->buffer = NULL;
    free(buf);
    buf = NULL;

}




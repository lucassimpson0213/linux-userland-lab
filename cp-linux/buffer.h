#ifndef BUFFER_H
#define BUFFER_H
#define BUFSIZE 1024
#include <stddef.h>


// typedef struct  {
//     char buffer [BUFSIZE];
//     int capacity; 
//     size_t size; 
// } Buffer;
//
typedef struct Buffer Buffer;


Buffer*  new_buf(size_t capacity);

// track new size 
void insert(int num);

void update_size(Buffer* buffer, size_t size);


size_t get_size(Buffer* buffer);











#endif 

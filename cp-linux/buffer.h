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


void newbuf(size_t capacity);

// track new size 
void insert(int num);












#endif 

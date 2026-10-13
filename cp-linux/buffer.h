#ifndef BUFFER_H
#define BUFFER_H
#define BUFSIZE 1024
#include <stddef.h>


struct Buffer {
    char buffer [BUFSIZE];
    int capacity; 
    size_t size; 
};


void newbuf(size_t capacity);


void insert(int num);












#endif 

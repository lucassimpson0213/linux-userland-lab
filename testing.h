#include <stdio.h>
#define ASSERT(EXP)                                                            \
  do {                                                                         \
    if (EXP) {                                                                 \
      printf("%s", #EXP);                                                      \
    } else {                                                                   \
      printf("%s", #EXP);                                                      \
    }                                                                          \
  } while (0)
// if this gets confusing use cc to compile: cc -E -P source.c

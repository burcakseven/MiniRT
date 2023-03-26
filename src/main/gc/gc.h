#ifndef GC_H
#define GC_H
#include <stdlib.h>

void *new(size_t size);

void del(void *ptr);

void garbage_collect();

#endif
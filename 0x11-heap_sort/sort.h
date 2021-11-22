#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void true_heap_sort(int *a, size_t size, size_t full);

#endif /* _SORT_H_ */

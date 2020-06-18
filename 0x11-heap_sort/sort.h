#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);
void siftDown(int *array, int start, int end, int size);

#endif /* SORT_H */

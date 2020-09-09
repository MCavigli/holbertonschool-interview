#ifndef SORT_H
#define SORT_H
#include <stdio.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void countSort(int *array, int size, int exp);

#endif /* SORT_H */

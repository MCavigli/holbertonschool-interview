#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void printTime(int LA[], int n1, int RA[], int n2);
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int middle, int right);

#endif /* SORT_H */

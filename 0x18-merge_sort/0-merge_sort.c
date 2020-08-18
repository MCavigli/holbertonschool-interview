#include "sort.h"

/**
 * printTime - prints a collection of statements
 * @LA: the left subarray
 * @n1: the position of the left subarray
 * @RA: the right subarray
 * @n2: the position of the right subarray
 */
void printTime(int LA[], int n1, int RA[], int n2)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(LA, n1);
	printf("[right]: ");
	print_array(RA, n2);
}

/**
 * merge - merges to subarrays of @array
 * @array: the pointer to the array
 * @left: the leftmost point of the array
 * @middle: the middle of the array
 * @right: the rightmost point of the array
 */
void merge(int *array, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	#pragma GCC diagnostic ignored "-Wvla"
	int LeftArray[n1], RightArray[n2];

	for (i = 0; i < n1; i++)
		LeftArray[i] = array[i + left];
	for (j = 0; j < n2; j++)
		RightArray[j] = array[j + middle + 1];
	printTime(LeftArray, n1, RightArray, n2);
	i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (LeftArray[i] <= RightArray[j])
		{
			array[k] = LeftArray[i];
			i++;
		}
		else
		{
			array[k] = RightArray[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = LeftArray[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = RightArray[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(&array[left], n1 + n2);
}

/**
 * mergeSort - Recursively divys up the arrays, left side first
 * @array: a pointer to where we want the beginning of the array to be
 * @left: the leftmost point of the array
 * @right: the rightmost point of the array
 */
void mergeSort(int *array, int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = (left + right - 1) / 2;
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);
		merge(array, left, middle, right);
	}
}

/**
 * merge_sort - merge sorts and array, top-down
 * @array: a pointer to an array
 * @size: size of the array
 * size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int left = 0;
	int right = size - 1;

	if (array && size > 1)
		mergeSort(array, left, right);
}

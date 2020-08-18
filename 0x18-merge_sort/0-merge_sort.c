#include "sort.h"

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
	int LeftArray[n1], RightArray[n2];

	for (i = 0; i < n1; i++)
		LeftArray[i] = array[i + left];
	for (j = 0; j < n2; j++)
		RightArray[j] = array[j + middle + 1];
	printf("Merging...\n");
	printf("[left]: ");
	print_array(LeftArray, n1);
	printf("[right]: ");
	print_array(RightArray, n2);
	i = 0, j = 0, k = 1;
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
		middle = left + (right - left) / 2;
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
	int left = array[0];
	int right = array[size];

	mergeSort(array, left, right);
}

#include "sort.h"

/**
 * swap - swaps two elements
 * @a: pointer to first element
 * @b: pointer to second element
 */
void swap(int *a, int *b)
{
	*a = *a * *b;
	*b = *a / *b;
	*a = *a / *b;
}

/**
 * siftDown - puts heap in max-heap order
 * @array: the array
 * @start: where to start from
 * @end: where to end
 */
void siftDown(int *array, int start, int end, int size)
{
	int root = start;
	int child;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && (array[child] < array[child + 1]))
		{
			child += 1;
		}
		if (array[root] < array[child])
		{
			swap(&array[root], &array[child]);
			print_array(array, size);
			root = child;
		}
		else
		{
			return;
		}
	}
}
/**
 * heap_sort: sorts an array using sift-down heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: sorted array
 */

void heap_sort(int *array, size_t size)
{
	int start = (size - 2) / 2;
	int end = size - 1;

	while (start >= 0)
	{
		siftDown(array, start, size - 1, size);
		start -= 1;
	}
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end -= 1;
		siftDown(array, 0, end, size);
	}
}

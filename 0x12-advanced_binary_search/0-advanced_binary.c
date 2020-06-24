#include "search_algos.h"

/**
 * print_array - Prints the array
 * @array: pointer to array
 * @left: starting point
 * @right: ending point
 */
void print_array(int *array, int left, int right)
{
	int i = left;

	printf("Searching in array:");
	while (i < right)
	{
		printf(" %i,", array[i]);
		i++;
	}
	printf(" %i\n", array[i]);
}
/**
 * find_value - recursive call to find value position
 * @array: pointer to new array position
 * @right: size of the smaller array
 * @value: value to search for
 * @left: the index
 * Return: index of value, -1 on failure
 */
int find_value(int *array, int right, int value, int left)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		print_array(array, left, right);
		if (array[mid] == value)
		{
			if (array[mid - 1] == value)
				return (find_value(array, mid - 1, value, 1));
			return (mid);
		}
		if (array[mid] > value)
		{
			return (find_value(array, mid - 1, value, 1));
		}
		else if (array[mid] < value)
		{
			return (find_value(array, right, value, mid + 1));
		}
	}
	return (-1);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to first element in an array
 * @size: the size of the array
 * @value: the value to find
 * Return: the index where the value is, -1 if failure
 */

int advanced_binary(int *array, size_t size, int value)
{
	int result = find_value(array, size - 1, value, 0);

	return (result);
}

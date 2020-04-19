#include "slide_line.h"

/**
 * slide_left - called when the array needs to be slid left
 * @line: the line to slide left
 * @size: size of line
 * Return: nothing
 */

void slide_left(int *line, size_t size)
{
	size_t i = 1;
	size_t j = 0;

	for (; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		if (line[j] == 0)
		{
			line[j] = line[i];
			line[i] = 0;
		}
		else if (line[j] == line[i])
		{
			line[j] += line[j];
			line[i] = 0;
		}
		else
		{
			line[j + 1] = line[i];
		}
		j++;
	}
}

/**
 * slide_right - slides numbers to the right
 * @line: the line to check
 * @size: size of the line
 * Return: nothing
 */

void slide_right(int *line, size_t size)
{
	size_t i = size - 2;
	size_t j = size - 1;

	for (; (int)i >= 0; i--)
	{
		if (line[i] == 0)
			continue;

		if (line[j] == 0)
		{
			line[j] = line[i];
			line[i] = 0;
		}
		else if (line[j] == line[i])
		{
			line[j] += line[j];
			line[i] = 0;
		}
		else
		{
			line[j - 1] = line[i];
		}
		j--;
	}
}

/**
 * slide_line - slides and merges an array of integers
 * @line: pointer to an array of integers
 * @size: size of array
 * @direction: slide direction of either left or right
 * Return: 1 upon success, 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		slide_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		slide_right(line, size);
		return (1);
	}
	else
		return (0);
}

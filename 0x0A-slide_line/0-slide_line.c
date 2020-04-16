#include "slide_line.h"
#include <stdlib.h>

/**
 * slide_line - slides and merges an array of integers
 * @line: pointer to an array of integers
 * @size: size of array
 * @direction: slide direction of either left or right
 * Return: 1 upon success, 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i = 1;
	size_t j = 0;
	if (direction == SLIDE_LEFT)
	{
		while (i < size)
		{
			if (line[i] == 0)
			{
				i++;
				continue;
			}
			else
			{
				// if (line[j - 1] && line[i] == line[j - 1])
				if (line[i] == line[j])
				{
					// line[j - 1] += line[j - 1];
					line[j] += line[j];
					line[i] = 0;
					j++;
					i++;
					continue;
				}
				else if (i == j)
				{
					i++;
					continue;
				}
				else
				{
					line[j] = line[i];
					line[i] = 0;
					i++;
					j++;
					continue;
				}
			}
		}
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		return (2);
	}
	return (10);
}

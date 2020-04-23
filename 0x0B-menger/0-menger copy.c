#include "menger.h"

/**
 * hashOrSpace - draws a hash or space
 * @row: the row of the shape
 * @col: the column of the shape
 */
/*
void hashOrSpace(int row, int col)
{
	if (row && col)
	{
		if (row % 2 == 1 && col % 3 == 1)
		{
			putchar(' ');
		}
		else
		{
			putchar(35);
		}
	}
}
*/
/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of sponge to draw
 */

void menger(int level)
{
	if (level < 0)
		return;
	int r = 0;

	r = pow(3, level);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
		{
			putchar(35);
			/* hashOrSpace(i, j); */
		}
		putchar('\n');
	}
}

#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of sponge to draw
 */

void menger(int level)
{
	int r, i, j = 0;
	r = pow(3, level);

	if (level < 0)
		return;

	for (; i < r; i++)
	{
		for (; j < r; j++)
		{
			putchar(35);
		}
		putchar('\n');
	}
}

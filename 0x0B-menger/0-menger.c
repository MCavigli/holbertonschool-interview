#include "menger.h"

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
		}
		putchar('\n');
	}
}

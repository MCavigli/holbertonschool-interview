#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: the first grid
 * @grid2: the second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_piles_together(grid1, grid2);
	while (grid_unstable(grid1))
	{
		printf("=\n");
		p_grid(grid1);
		grid_dispersal(grid1, grid2);
	}
}

/**
 * add_piles_together - adds two sandpiles together
 * @grid1: first grid
 * @grid2: second grid
 */
void add_piles_together(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
	}
}

/**
 * grid_unstable - checks if grid has unstable sandpiles
 * @grid: grid to check
 * Return: True if grid is unstable, false if fine
 */
bool grid_unstable(int grid[3][3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (grid[i][j] > 3)
				return (true);
		}
	}
	return (false);
}

/**
 * grid_dispersal - disperses sand in grid
 * @grid1: grid to disperse
 * @grid2: empty grid
 */
void grid_dispersal(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (i > 0)
					grid2[i - 1][j] += 1;
				if (j > 0)
					grid2[i][j - 1] += 1;
				if (i < 2)
					grid2[i + 1][j] += 1;
				if (j < 2)
					grid2[i][j + 1] += 1;
				grid1[i][j] -= 4;
			}
		}
	}
	add_piles_together(grid1, grid2);
}

/**
 * p_grid - prints a grid
 * @grid: the grid to print
 */
void p_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

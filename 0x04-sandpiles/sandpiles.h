#ifndef _SANDPILES_H_
#define _SANDPILES_H_
#include <stdbool.h>
void print_grid_sum(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void add_piles_together(int grid1[3][3], int grid2[3][3]);
bool grid_unstable(int grid[3][3]);
void grid_dispersal(int grid1[3][3], int grid2[3][3]);
#endif

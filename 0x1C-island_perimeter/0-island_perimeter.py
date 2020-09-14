#!/usr/bin/python3
"""
Finds the perimiter of an island.
"""


def island_perimeter(grid):
    """ Returns the perimiter of @grid"""
    pm = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                if x > 0 and grid[x - 1][y] == 0:
                    pm += 1
                if x < len(grid) and grid[x + 1][y] == 0:
                    pm += 1
                if y > 0 and grid[x][y - 1] == 0:
                    pm += 1
                if y < len(grid[x]) and grid[x][y + 1] == 0:
                    pm += 1
    return (pm)

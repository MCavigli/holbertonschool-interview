#!/usr/bin/python3
"""
Finds the perimiter of an island.
"""


def island_perimeter(grid):
    """ Returns the perimiter of @grid"""
    pm = 0
    for x in range(len(grid)):
        for y in range(len(grid[0])):
            if grid[x][y]:
                pm += 4
                if x and grid[x - 1][y]:
                    pm -= 2
                if y and grid[x][y - 1]:
                    pm -= 2
    return (pm)

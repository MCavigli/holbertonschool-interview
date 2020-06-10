#!/usr/bin/python3
"""
Calculates how much rainfall
"""


def rain(walls):
    """
    Moves through @walls to calculate rainfall
    @walls: a list of non-negative integers
    """

    if not walls or len(walls) < 3 or type(walls) != list:
        return 0
    i = 1
    rainAmount = 0
    while (i + 1 < len(walls)):
        if walls[i - 1] > walls[i] and walls[i + 1] > walls[i]:
            rainAmount += WallCompare(walls[i - 1], walls[i + 1], walls[i])
        i += 1
    return rainAmount


def WallCompare(left, right, mid):
    """
    Finds the shortest wall
    """

    if left < right:
        return left - mid
    else:
        return right - mid

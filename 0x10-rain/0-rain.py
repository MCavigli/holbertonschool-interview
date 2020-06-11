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
    rainAmount = 0

    for i in range(1, len(walls) - 1):
        highL = walls[i]
        for j in range(i):
            highL = max(highL, walls[j])
        highR = walls[i]
        for j in range(i + 1, len(walls)):
            highR = max(highR, walls[j])
        rainAmount += (min(highL, highR) - walls[i])
    return rainAmount

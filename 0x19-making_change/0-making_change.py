#!/usr/bin/python3
"""
Method that finds the fewest number of coins to use for
a given value
"""


def makeChange(coins, total):
    if total <= 0:
        return (0)
    newTotal = total
    count = 0
    coins.sort(reverse=True)
    for num in coins:
        currentNum = num
        while (currentNum <= newTotal):
            newTotal = newTotal - num
            count += 1
    if newTotal is 0:
        return (count)
    else:
        return (-1)

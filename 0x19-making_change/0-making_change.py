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
        print("*")
        print("CurrentNum: ", currentNum)
        print("newTotal: ", newTotal)
        while (currentNum <= newTotal):
            print("newTotal at beginning of while: ", newTotal)
            print("count at beginning of while: ", count)
            newTotal = newTotal - num
            count += 1
            print("newTotal at end of while: ", newTotal)
            print("count at end of while: ", count)
        print("***Exited while loop***")
    print("RETURNING")
    print("**************")
    print()
    if newTotal is 0:
        return (count)
    else:
        return (-1)

#!/usr/bin/python3
'''
Module that holds isWinner method
'''


def getPrime(start, end):
    '''
    Gets prime numbers
    '''

    count = [0] * end
    counter = 0
    for i in range(start, end):
        if i > 1:
            for j in range(2, i):
                if(i % j == 0):
                    break
            else:
                count[counter] = i
    return count


def isWinner(x, nums):
    '''
    Determines the winner
    '''
    
    if x < 1 or nums is None:
        return None
    if min(nums) < 0:
        return None
    lastnum = len(nums)
    firstnum = nums[0]
    primes = getPrime(firstnum, lastnum)
    if primes is None:
        return None
    wins = 0
    for i in primes:
        if i % 2 == 0:
            wins += 1
    if x < 2 * wins:
        return "Ben"
    if x == 2 * wins:
        return None
    return "Maria"

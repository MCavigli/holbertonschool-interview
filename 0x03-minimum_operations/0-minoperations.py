#!/usr/bin/python3
import math


def minOperations(n):

    nCopy = n
    prime_factors = []
    final_sum = 0

    while nCopy % 2 == 0:
        prime_factors.append(2)
        nCopy = nCopy / 2

    for i in range(3, int(math.sqrt(nCopy)) + 1, 2):
        while nCopy % i == 0:
            prime_factors.append(i)
            nCopy = nCopy / i

    if nCopy > 2:
        prime_factors.append(nCopy)

    for i in prime_factors:
        final_sum += i

    return int(final_sum)

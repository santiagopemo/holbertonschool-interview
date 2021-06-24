#!/usr/bin/python3
"""
Make Change Module
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total
    """
    if total == 0:
        return 0
    coins.sort(reverse=True)
    remainig = total
    coins_count = 0
    i = 0
    while (i < len(coins)):
        if coins[i] <= remainig:
            remainig -= coins[i]
            coins_count += 1
        else:
            i += 1
        if remainig == 0:
            return coins_count
    return -1

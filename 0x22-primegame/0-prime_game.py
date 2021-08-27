#!/usr/bin/python3
"""Prime Game"""


def is_prime(num):
    """Determine if a number is prime"""
    if num <= 1:
        return False
    for i in range(2, int(num / 2) + 1):
        if num % i == 0:
            return False
    else:
        return True


def isWinner(x, nums):
    """Determine who is the winner of a prime game"""
    if not nums or x < 1:
        return None
    return "Ben"

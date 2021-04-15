#!/usr/bin/python3
"""
0-rain.py
"""


def rain(walls):
    """
    Funciton that calculate how much water will be retained after it rains
    """
    water = 0
    i = 0
    while i < len(walls):
        if walls[i] > 0:
            j = i + 1
            while j < len(walls):
                if walls[j] > 0:
                    water += ((j - i - 1) * min(walls[i], walls[j]))
                    i = j - 1
                    break
                j += 1
        i += 1
    return water

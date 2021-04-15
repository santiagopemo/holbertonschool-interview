#!/usr/bin/python3
"""
0-rain.py
"""


def rain(walls):
    """
    Funciton that calculate how much water will be retained after it rains
    """
    water = 0
    higher_idx = 0
    while higher_idx < len(walls) - 1:
        i = higher_idx
        while i < len(walls):
            if walls[i] >= walls[higher_idx]:
                j = higher_idx
                while j < i:
                    water += walls[higher_idx] - walls[j]
                    j += 1
                higher_idx = i
            i += 1
        walls[higher_idx] -= 1
    return water

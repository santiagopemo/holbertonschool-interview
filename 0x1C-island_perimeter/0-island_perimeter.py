#!/usr/bin/python3
"""
0-island_perimeter.py
"""


def island_perimeter(grid):
    """
    Function that returns the perimeter of the island described in grid
    """
    i = 0
    perimeter = 0
    while i < len(grid):
        j = 0
        while j < len(grid[0]):
            if grid[i][j] == 1:
                perimeter += 4
                if i - 1 > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                if i + 1 < len(grid) and grid[i + 1][j] == 1:
                    perimeter -= 1
                if j - 1 > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                if j + 1 < len(grid[j]) and grid[i][j + 1] == 1:
                    perimeter -= 1
            j += 1
        i += 1
    return perimeter

#!/usr/bin/python3
"""
0-pascal_triangle.py
"""


def pascal_triangle(n):
    """
    Function def pascal_triangle(n): that returns a list of lists
    of integers representing the Pascal’s triangle of n
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        row = []
        for j in range(0, i + 1):
            row.append((triangle[i - 1][j - 1] if j > 0 else 0) +
                       (triangle[i - 1][j] if j < len(triangle[i - 1]) else 0))
        triangle.append(row)

    return triangle

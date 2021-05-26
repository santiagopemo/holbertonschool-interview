#!/usr/bin/python3
""" 0-rotate_2d_matrix.py"""


def rotate_2d_matrix(matrix):
    """Rotate a matrix 90 degrees clockwise"""
    tmp_matrix = matrix.copy()
    matrix.clear()
    rows_n = len(tmp_matrix)
    i = 0
    while (i < rows_n):
        new_row = []
        j = rows_n - 1
        while (j >= 0):
            new_row.append(tmp_matrix[j][i])
            j -= 1
        matrix.append(new_row)
        i += 1

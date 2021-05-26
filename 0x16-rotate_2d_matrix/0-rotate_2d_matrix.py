#!/usr/bin/python3
""" 0-rotate_2d_matrix.py"""


def rotate_2d_matrix(matrix):
    """Rotate a matrix 90 degrees clockwise"""
    new_matrix = matrix.copy()
    rows_n = len(new_matrix)
    i = 0    
    matrix.clear()
    while (i < rows_n):
        new_row = []
        j = rows_n - 1
        while (j >= 0):
            new_row.append(new_matrix[j][i])
            # print(matrix[i][rows_n - j - 1], end='-')
            # print(new_matrix[j][i])
            # matrix[i][rows_n - j - 1] = new_matrix[j][i]
            j -= 1        
        matrix.append(new_row)
        i += 1

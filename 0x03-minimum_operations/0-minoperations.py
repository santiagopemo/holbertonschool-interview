#!/usr/bin/python3
"""minoperations module"""


def minOperations(n):
    """
    Method that calculates the fewest number of operations needed to
    result in exactly n number of characters H characters in a file
    """
    if n <= 1:
        return 0
    operations = 0
    current_length = 1
    copy_lenght = 0
    while current_length < n:
        if n % current_length == 0:
            # copy all
            operations += 1
            copy_lenght = current_length
        # paste
        operations += 1
        current_length += copy_lenght
    return operations

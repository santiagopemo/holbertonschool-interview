#!/usr/bin/python3
"""Validate UTF-8 module"""


def validUTF8(data):
    """
    Method that determines if a given data
    set represents a valid UTF-8 encoding
    """
    for number in data:
        b_index = bin(number).find("b")
        data_byte = bin(number)[b_index + 1:]
        if (len(data_byte) > 8):
            data_byte = data_byte[-8:]
        length = data_byte.find("0")
        if (length > 4 or length <= 0):
            return False
    return True

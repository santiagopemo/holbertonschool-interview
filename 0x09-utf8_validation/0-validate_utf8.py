#!/usr/bin/python3
"""Validate UTF-8 module"""


def validUTF8(data):
    """
    Method that determines if a given data
    set represents a valid UTF-8 encoding
    """
    continuation = False
    for number in data:
        data_byte = bin(number).replace("0b", "").rjust(8, "0")
        if continuation is False:
            char_length = data_byte.find("0")
            if char_length > 4 or char_length == -1:
                return False
            if char_length > 1:
                continuation = True
        else:
            char_length -= 1
            if char_length == 0:
                continuation = False
            elif data_byte[0: 2] != "10":
                return False            
    return True

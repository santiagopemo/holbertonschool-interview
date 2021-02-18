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
        if data_byte == "00000000":
            return False
        if continuation is False:
            if data_byte[0] == "0":
                continue
            char_length = data_byte.find("0")
            if char_length > 4 or char_length == -1:
                return False
            if char_length > 1:
                continuation = True
        else:
            if data_byte[0: 2] != "10":
                return False
            char_length -= 1
            if char_length == 0:
                continuation = False
    return True

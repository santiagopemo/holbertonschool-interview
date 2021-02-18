#!/usr/bin/python3
"""Validate UTF-8 module"""


def validUTF8(data):
    """
    Method that determines if a given data
    set represents a valid UTF-8 encoding
    """
    continuation = False
    for number in data:
        data_byte = bin(number).replace("0b", "").rjust(8, "0")[-8:]
        if continuation is False:
            if data_byte[0] == "0":
                continue
            char_length = data_byte.find("0")
            if char_length > 4 or char_length < 2:
                return False
            continuation = True
        else:
            char_length -= 1
            if data_byte[0: 2] != "10":
                return False
            if char_length == 1:
                continuation = False
    if continuation:
        return False
    return True

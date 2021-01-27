#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""
import sys


def print_metrics(status_codes, file_size):
    """function to print status codes and total file size"""
    for k, v in status_codes.items():
        if v > 0:
            print("{}: {}".format(k, v))
    print("File size: {}".format(file_size))


status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0,
}
counter = 1
file_size = 0
try:
    for line in sys.stdin:
        splited_line = line.strip().split(" ")
        file_size += int(splited_line[-1])
        status_code = splited_line[-2]
        if status_code in status_codes:
            status_codes[status_code] += 1
        if counter == 10:
            print_metrics(status_codes, file_size)
            counter = 0
        counter += 1
except KeyboardInterrupt:
    print_metrics(status_codes, file_size)
    raise

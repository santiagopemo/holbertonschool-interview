#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4] # 6
    print(rain(walls))
    walls = [0, 3, 0, 2, 0, 3, 0, 0] # 7
    print(rain(walls))
    walls = [0, 1, 0, 2, 0, 3, 0, 0] # 3
    print(rain(walls))
    walls = [0, 3, 0, 2, 0, 1, 0, 0] # 3
    print(rain(walls))
    walls = [0, 3, 0, 1, 0, 2, 0, 3] # 12
    print(rain(walls))


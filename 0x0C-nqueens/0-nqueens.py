#!/usr/bin/python3
"""N queens program"""
import sys


def is_valid(placed_queens):
    row = len(placed_queens) - 1
    for i in range(0, row):
        diff = abs(placed_queens[i][1] - placed_queens[row][1])
        if diff == 0 or diff == row - i:
            return False
    return True


def n_queens(n, row, results, placed_queens=[]):
    if (row == n):
        results.append(placed_queens[:])
    else:
        for col in range(0, n):
            placed_queens.append([row, col])
            if (is_valid(placed_queens)):
                n_queens(n, row + 1, results)
            placed_queens.pop()


def main():
    if (len(sys.argv) < 2):
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        sys.exit(1)
    if (n < 4):
        print("N must be at least 4")
        sys.exit(1)
    results = []
    n_queens(n, 0, results)
    for result in results:
        print(result)


if __name__ == "__main__":
    main()

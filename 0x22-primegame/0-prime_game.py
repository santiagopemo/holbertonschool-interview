#!/usr/bin/python3
"""Prime Game"""


def is_prime(num):
    """Determine if a number is prime"""
    if num <= 1:
        return False
    for i in range(2, int(num / 2) + 1):
        if num % i == 0:
            return False
    else:
        return True


def play_a_round(arr):
    """Plays a round of prime game"""
    j = 0
    has_pick = False
    addition = 1
    while j < len(arr):
        if is_prime(arr[j]) and not has_pick:
            has_pick = True
            addition = arr[j] - 1
        if has_pick:
            arr.pop(j)
        j += addition
    return has_pick


def isWinner(x, nums):
    """Determine who is the winner of a prime game"""
    if not nums or x < 1:
        return None
    ben_wins = 0
    maria_wins = 0
    for i in range(x):
        arr = [*range(2, nums[i] + 1)]
        current = "Maria"
        while True:
            if len(arr) == 0 and current == "Maria":
                ben_wins += 1
                break
            if len(arr) == 0 and current == "Ben":
                maria_wins += 1
                break
            has_pick = play_a_round(arr)
            if has_pick:
                current = "Ben" if current == "Maria" else "Maria"
                continue
            if not has_pick and current == "Maria":
                ben_wins += 1
                break
            elif not has_pick and current == "Ben":
                maria_wins += 1
                break
    print(maria_wins)
    print(ben_wins)
    if ben_wins > maria_wins:
        return "Ben"
    if ben_wins < maria_wins:
        return "Maria"
    return None

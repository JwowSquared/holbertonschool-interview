#!/usr/bin/python3
"""this module holds the rain function"""


def rain(walls):
    """calculates the amount of rainwater left in walls"""
    if not walls:
        return 0

    i = 0
    out = 0
    pool = 0
    height = -1
    left_wall = -1
    left_idx = -1
    while i < len(walls):
        if left_wall <= walls[i]:
            out += pool
            pool = 0
            left_wall = walls[i]
            left_idx = i
        else:
            pool += left_wall - walls[i]
        i += 1
        if i >= len(walls) and pool > 0:
            i = left_idx + 1
            left_wall -= 1
            if left_wall <= 0:
                break
            pool = 0
    return out

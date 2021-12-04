#!/usr/bin/python3
"""this module holds the rain function"""


def rain(walls):
    """calculates the amount of rainwater left in walls"""
    if not walls:
        return 0

    i = 0
    out = 0
    height = -1
    left_wall = -1
    right_wall = -1
    while i < len(walls):
        if walls[i] == 0:
            i += 1
            continue
        if left_wall == -1:
            left_wall = i
            i += 1
            continue
        if right_wall == -1:
            right_wall = i
            if walls[left_wall] < walls[right_wall]:
                height = walls[left_wall]
            else:
                height = walls[right_wall]
            out += (height * (right_wall - left_wall - 1))
            left_wall = right_wall
            right_wall = -1
            i += 1
            continue
    return out

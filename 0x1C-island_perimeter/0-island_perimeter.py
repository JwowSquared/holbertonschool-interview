#!/usr/bin/python3
"""This module contains a function answer for the island perimeter interview"""


def island_perimeter(grid):
    """determines the perimeter of an island"""
    # type checking?
    total = 0
    height = len(grid)
    width = len(grid[0])
    for i in range(height):
        for j in range(width):
            if grid[i][j] is 0:
                continue
            # if island is on edge, should the out of bounds perimeter count?
            if i > 0 and grid[i - 1][j] is 0:
                total += 1
            if i < height - 1 and grid[i + 1][j] is 0:
                total += 1
            if j > 0 and grid[i][j - 1] is 0:
                total += 1
            if j < width - 1 and grid[i][j + 1] is 0:
                total += 1
    return total

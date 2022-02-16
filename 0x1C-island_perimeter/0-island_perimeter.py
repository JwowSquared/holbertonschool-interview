#!/usr/bin/python3
"""This module contains a function answer for the island perimeter interview"""


def island_perimeter(grid):
    """determines the perimeter of an island"""
    # grid assumed populated and in proper format
    total = 0
    height = len(grid)
    width = len(grid[0])
    for i in range(height):
        for j in range(width):
            if grid[i][j] is 0:
                continue
            if i is 0 or grid[i - 1][j] is 0:
                total += 1
            if i is height - 1 or grid[i + 1][j] is 0:
                total += 1
            if j is 0 or grid[i][j - 1] is 0:
                total += 1
            if j is width - 1 or grid[i][j + 1] is 0:
                total += 1
    return total

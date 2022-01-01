#!/usr/bin/python3
"""this module holds rotate_2d_matrix for 0x16 task 0"""


def rotate_2d_matrix(matrix):
    """rotates an n by n 2D matrix 90 degrees clockwise"""
    low_bound = 0
    high_bound = len(matrix) - 1
    temp = 0
    x = 0
    y = 0
    while (high_bound - low_bound > 0):
        x = low_bound
        y = high_bound
        while (x < high_bound):
            temp = matrix[y][low_bound]
            matrix[y][low_bound] = matrix[high_bound][y]
            matrix[high_bound][y] = matrix[x][high_bound]
            matrix[x][high_bound] = matrix[low_bound][x]
            matrix[low_bound][x] = temp
            x += 1
            y -= 1
        low_bound += 1
        high_bound -= 1

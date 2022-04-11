#!/usr/bin/python3
"""This module contains a function to display Pascal's Triangle"""


def pascal_triangle(n):
    """returns list of lists representing n depth of Pascal's Triangle"""
    out = []
    for y in range(n):
        row = [1]
        for x in range(y):
            if x + 1 == y:
                res = 1
            else:
                res = out[y - 1][x] + out[y - 1][x + 1]
            row.append(res)
        out.append(row)
    return out

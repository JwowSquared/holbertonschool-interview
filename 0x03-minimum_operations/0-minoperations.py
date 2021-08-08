#!/usr/bin/python3
""" this module contains the minOperations function """


def minOperations(n):
    out = 0
    factor = 2
    while n > 1:
        if n % factor == 0:
            out = out + factor
            n = n / factor
        else:
            factor = factor + 1
    return out

#!/usr/bin/python3
"""this module contains the driver for nqueens"""
import sys


def gen_queens(solutions, n, current, depth):
    """x"""
    if depth >= n:
        solutions.append(current.copy())
        return
    for i in range(n):
        if i in current:
            continue
        current[depth] = i
        if depth > 0:
            d_pos = [x + current[x] for x in range(depth + 1)]
            d_neg = [x - current[x] for x in range(depth + 1)]
            if len(set(d_pos)) != depth + 1:
                continue
            if len(set(d_neg)) != depth + 1:
                continue
        gen_queens(solutions, n, current, depth + 1)
    current[depth] = -1


def n_queens(n):
    """calls gen_solutions with n and formats result"""
    solutions = []
    current = [-1 for x in range(n)]
    gen_queens(solutions, n, current, 0)
    for s in solutions:
        print([[x, s[x]] for x in range(n)])


def main():
    """prints nqueens where n is the first argv"""
    if len(sys.argv) is not 2:
        print("Usage: nqueens N")
        return 1
    if not sys.argv[1].isnumeric():
        print("N must be a number")
        return 1
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        return 1
    n_queens(int(sys.argv[1]))

if __name__ == "__main__":
    main()

#!/usr/bin/python3
"""this module contains the driver for nqueens"""
import sys


def main():
    """prints nqueens where n is the first argv"""
    if len(sys.argv) is not 2:
        print("Usage: nqueens N")
        return 1
    if not sys.argv[1].isnumeric():
        print("N must be a number")
        return 1
    if sys.argv[1] < 4:
        print("N must be at least 4")
        return 1
    print("poggers")

if __name__ == "__main__":
    main()

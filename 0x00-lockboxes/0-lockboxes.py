#!/usr/bin/python3
"""This module contains a function answer for the lockboxes interview"""


def canUnlockAll(boxes):
    unlocked = {0}
    prevLen = 0
    allowed = set(range(len(boxes)))
    while prevLen < len(unlocked):
        prevLen = len(unlocked)
        acquired = []
        for key in unlocked:
            if boxes[key]:
                acquired = acquired + boxes[key]
                boxes[key] = []
        unlocked = unlocked | set(acquired)
        unlocked = unlocked & allowed
        if len(unlocked) == len(boxes):
            return True
    return False

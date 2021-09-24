#!/usr/bin/python3
""" this module contains the validUTF8 function """


def validUTF8(data):
    """ determines if list of integers is UTF8 compliant """
    for i in data:
        i = i & 255
        if i == 0:
            return False
    return True

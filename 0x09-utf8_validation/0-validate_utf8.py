#!/usr/bin/python3
""" this module contains the validUTF8 function """


def validUTF8(data):
    """ determines if list of integers is UTF8 compliant """
    cont = 0
    for i in data:
        i = i & 255
        if cont > 0:
            if i & 128 == 0 or i & 64 == 64:
                return False
            cont = cont - 1
            continue
        if i < 128:
            continue
        temp = i << 1
        while temp & 128:
            cont = cont + 1
            temp = temp << 1
        if cont == 0 or cont > 3:
            return False
    if cont > 0:
        return False
    return True

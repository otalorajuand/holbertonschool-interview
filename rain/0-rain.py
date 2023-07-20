#!/usr/bin/python3
"""This module contains the function rain"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.

    Params:
        walls is a list of non-negative integers.

    Return: Integer indicating total amount of rainwater retained.
    """

    flag1, flag2, rain = 0, 0, 0

    for elem in walls:

        if flag1 != 0 and elem != 0:
            flag2 = elem

        if elem != 0 and flag2 == 0:
            flag1 = elem

        if flag2 != 0:
            rain += flag1
            flag1, flag2 = elem, 0

    return rain

#!/usr/bin/python3
"""This module contains the function rain"""


def rain(walls):
    """
    Calculate the total amount of rainwater retained after it rains.
    Args:
        walls: List of non-negative integers representing the heights of walls.
    Returns:
        Integer indicating the total amount of rainwater retained.
    """
    n = len(walls)
    if n < 3:
        return 0

    total_water = 0
    left_max = [0] * n
    right_max = [0] * n

    # Calculate the left maximum heights
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Calculate the right maximum heights
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate the retained water at each position
    for i in range(n):
        effective_height = min(left_max[i], right_max[i])
        total_water += effective_height - walls[i]

    return total_water

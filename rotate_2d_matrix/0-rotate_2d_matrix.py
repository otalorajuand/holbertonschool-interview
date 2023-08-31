#!/usr/bin/python3
"""This module contains the function rotate_2d_matrix"""


def rotate_2d_matrix(matrix):
    """Rotates a matrix in-place"""

    l, r = 0, len(matrix) - 1

    while l < r:
        for i in range(r - l):
            top, bottom = l, r

            # save the top left
            top_left = matrix[top][l + i]

            # move the bottom left to top left
            matrix[top][l + i] = matrix[bottom - i][l]

            # move the bottom right into bottom left
            matrix[bottom - i][l] = matrix[bottom][r - i]

            # move the top right into bottom right
            matrix[bottom][r - i] = matrix[top + i][r]

            # move the top left into top right
            matrix[top + i][r] = top_left

        r -= 1
        l += 1

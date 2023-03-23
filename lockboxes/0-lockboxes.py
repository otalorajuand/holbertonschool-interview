#!/usr/bin/python3
"""This module contains the function canUnlockAll"""


def canUnlockAll(boxes):
    """This function checks whether all the boxes can be unlocked"""
    keys = boxes[0]
    boxes_visited = set([0])

    while keys:
        to_visit = keys[-1]
        keys.pop()

        if to_visit < len(boxes) and to_visit not in boxes_visited:
            boxes_visited.add(to_visit)
            keys.extend(boxes[to_visit])

    if len(boxes_visited) == len(boxes):
        return True
    return False

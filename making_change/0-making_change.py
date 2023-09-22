#!/usr/bin/python3
"""This module contains the function makeChange"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine the fewest number
       of coins needed to meet a given amount total

    Args:
    - coins: a list containing the coins to use
    - total: the total number to be obtained

    Return: fewest number of coins needed to meet total
    """

    if total <= 0 :
        return 0

    if len(coins) == 0:
        return -1

    coins.sort(reverse=True)

    number_coins, i = 0, 0

    while i < len(coins):
        coin = coins[i]

        total -= coin
        number_coins += 1

        if total == 0:
            return number_coins

        if total < 0:
            number_coins -= 1
            i += 1

            if i == len(coins) and total < 0:
                return -1

            total += coin

    return number_coins

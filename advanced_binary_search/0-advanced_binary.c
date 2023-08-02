#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

int recursive_advanced_binary(int *array, int low, int high, int value);

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: The value to search for.
 *
 * Return: The index where value is located (leftmost occurrence),
 *         or -1 if value is not present in array or if array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    return recursive_advanced_binary(array, 0, size - 1, value);
}

int recursive_advanced_binary(int *array, int low, int high, int value)
{
    int mid, result;

    if (low <= high)
    {
        mid = (low + high) / 2;
        result = array[mid];

        if (result == value)
        {
            if (mid == low || array[mid - 1] != value)
                return mid;
            else
                return recursive_advanced_binary(array, low, mid, value);
        }
        else if (result > value)
        {
            return recursive_advanced_binary(array, low, mid, value);
        }
        else
        {
            return recursive_advanced_binary(array, mid + 1, high, value);
        }
    }

    return -1;
}

#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge(int *array, int *left, int left_size, int *right, int right_size);
void merge_sort_recursive(int *array, size_t size);
void merge_sort(int *array, size_t size);

/**
 * merge - Merge two subarrays into one sorted array
 * @array: The original array
 * @left: The left subarray
 * @left_size: The size of the left subarray
 * @right: The right subarray
 * @right_size: The size of the right subarray
 */
void merge(int *array, int *left, int left_size, int *right, int right_size)
{
    int i = 0, j = 0, k = 0;
    int *temp = malloc((left_size + right_size) * sizeof(int));

    if (temp == NULL)
    {
        free(temp);
        return;
    }

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            temp[k] = left[i];
            i++;
        }
        else
        {
            temp[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        temp[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        temp[k] = right[j];
        j++;
        k++;
    }

    for (i = 0; i < left_size + right_size; i++)
    {
        array[i] = temp[i];
    }

    free(temp);
}

/**
 * merge_sort_recursive - Recursively divides and sorts the array
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort_recursive(int *array, size_t size)
{

    int mid;
    int *left;
    int *right;
    int left_size;
    int right_size;

    if (size <= 1)
        return;

    mid = size / 2;
    left = array;
    right = array + mid;
    left_size = mid;
    right_size = size - mid;

    merge_sort_recursive(left, left_size);
    merge_sort_recursive(right, right_size);

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    merge(array, left, left_size, right, right_size);

    printf("[Done]: ");
    print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, size);
}


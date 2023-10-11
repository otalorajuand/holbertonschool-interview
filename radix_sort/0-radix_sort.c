#include "sort.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * getMax - Find the maximum element in an array
 *
 * @array: The input array
 * @size: Size of the array
 *
 * Return: The maximum element in the array
 */
int getMax(int *array, size_t size) {
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


/**
 * countSort - Perform counting sort on an array based on a significant digit
 *
 * @array: The input array
 * @size: Size of the array
 * @exp: The current significant digit (e.g., 1, 10, 100, ...)
 */
void countSort(int *array, size_t size, int exp) {
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (output == NULL) {
        return;
    }

    for (i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i < size; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
} 


/**
 * radix_sort - Sort an array of integers in ascending order using Radix sort
 *
 * @array: The input array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size) {

    int max;
    int exp;

    if (array == NULL || size < 2) {
    return;
    }

    max = getMax(array, size);

    for (exp = 1; max / exp > 0; exp *= 10) {
        countSort(array, size, exp);
        print_array(array, size);
    }
}

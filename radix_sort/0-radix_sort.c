#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/* Function to get the maximum value in the array */
int getMax(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/* Counting sort for a specific digit (exp) */
void countSort(int *array, size_t size, int exp) {
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    if (output == NULL) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
}

/* Radix sort */
void radix_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    int max = getMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(array, size, exp);
        print_array(array, size);
    }
}

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

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

void radix_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    int max = getMax(array, size);
    int exp;
    size_t i;

    for (exp = 1; max / exp > 0; exp *= 10) {
        for (i = 0; i < size; i++) { // Move the loop variable declaration here
            print_array(array, size);
        }
        countSort(array, size, exp);
    }
}

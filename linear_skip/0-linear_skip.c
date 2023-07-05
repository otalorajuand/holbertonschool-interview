#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present or head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express = list, *prev;

    if (list == NULL)
        return (NULL);

    while (express && express->n < value)
    {
        prev = express;
        if (express->express == NULL)
        {
            while (express->next)
                express = express->next;
            break;
        }
        express = express->express;
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, express->index);

    while (prev && prev->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    return (NULL);
}

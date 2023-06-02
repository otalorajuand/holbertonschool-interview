#include "slide_line.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * slide_line - Slides and merges an array of integers in the specified direction.
 *
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    int *current, *end, *stop;
    int merged = 0;

    if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (direction == SLIDE_LEFT)
    {
        current = line;
        stop = line + size;
        end = current + 1;

        while (current < stop)
        {
            if (*current == 0)
            {
                current++;
                continue;
            }

            if (*end == *current)
            {
                *current *= 2;
                *end = 0;
                merged = 1;
            }

            current++;
            end++;
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        current = line + size - 1;
        stop = line - 1;
        end = current - 1;

        while (current > stop)
        {
            if (*current == 0)
            {
                current--;
                continue;
            }

            if (*end == *current)
            {
                *current *= 2;
                *end = 0;
                merged = 1;
            }

            current--;
            end--;
        }
    }

    if (merged)
    {
        if (direction == SLIDE_LEFT)
        {
            current = line;
            end = current + 1;

            while (current < stop)
            {
                if (*current == 0)
                {
                    while (end < stop && *end == 0)
                        end++;

                    if (end < stop)
                    {
                        *current = *end;
                        *end = 0;
                        merged = 1;
                    }
                }

                current++;
                end++;
            }
        }
        else if (direction == SLIDE_RIGHT)
        {
            current = line + size - 1;
            stop = line - 1;
            end = current - 1;

            while (current > stop)
            {
                if (*current == 0)
                {
                    while (end > stop && *end == 0)
                        end--;

                    if (end > stop)
                    {
                        *current = *end;
                        *end = 0;
                        merged = 1;
                    }
                }

                current--;
                end--;
            }
        }
    }

    return 1;
}

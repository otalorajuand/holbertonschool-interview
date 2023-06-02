#include "slide_line.h"

/**
 * merge_left - Merges the elements of an array towards the left
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */
static void merge_left(int *line, size_t size)
{
    int merged[LINE_SIZE] = {0};
    size_t i, j = 0;

    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (j > 0 && line[i] == merged[j - 1])
            {
                merged[j - 1] *= 2;
            }
            else
            {
                merged[j] = line[i];
                j++;
            }
        }
    }

    for (i = 0; i < size; i++)
        line[i] = merged[i];
}

/**
 * merge_right - Merges the elements of an array towards the right
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */
static void merge_right(int *line, size_t size)
{
    int merged[LINE_SIZE] = {0};
    size_t i, j = size - 1;

    for (i = size - 1; i < size; i--)
    {
        if (line[i] != 0)
        {
            if (j < size - 1 && line[i] == merged[j + 1])
            {
                merged[j + 1] *= 2;
            }
            else
            {
                merged[j] = line[i];
                j--;
            }
        }
    }

    for (i = 0; i < size; i++)
        line[i] = merged[i];
}

/**
 * slide_line - Slides and merges an array of integers
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 * @direction: Direction of the slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (direction == SLIDE_LEFT)
        merge_left(line, size);
    else if (direction == SLIDE_RIGHT)
        merge_right(line, size);

    return 1;
}

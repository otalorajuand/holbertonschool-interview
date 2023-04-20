#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print a 3x3 grid
 * @grid: Grid to be printed
 *
 * Return: void
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sanpiles_sum - Add two sandpiles
 * @grid1: First sandpile
 * @grid2: Second sandpile
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, unstable;
    int tmp[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
	print_grid(grid1);
    do {
        unstable = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                tmp[i][j] = grid1[i][j];
            }
        }

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (tmp[i][j] > 3)
                {
                    unstable = 1;
                }
            }
        }
	
	if (unstable)
		print_grid(grid1);

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (tmp[i][j] > 3)
                {
                    grid1[i][j] -= 4;
                    if (i > 0)
                        grid1[i - 1][j] += 1;
                    if (i < 2)
                        grid1[i + 1][j] += 1;
                    if (j > 0)
                        grid1[i][j - 1] += 1;
                    if (j < 2)
                        grid1[i][j + 1] += 1;
                }
            }
        }
    } while (unstable);
}

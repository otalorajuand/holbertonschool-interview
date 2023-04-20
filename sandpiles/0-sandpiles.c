#include "sandpiles.h"
#include <stdbool.h>
#include <stdio.h>


/**
 * topple - Topple a cell in the grid if it has more than 3 grains
 * @grid: Grid to topple in
 * @i: Row index of the cell to topple
 * @j: Column index of the cell to topple
 */
static void topple(int grid[3][3], int i, int j)
{
    grid[i][j] -= 4;
    if (i > 0)
        grid[i - 1][j]++;
    if (i < 2)
        grid[i + 1][j]++;
    if (j > 0)
        grid[i][j - 1]++;
    if (j < 2)
        grid[i][j + 1]++;
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles and store the result in the first grid
 * @grid1: First sandpile grid
 * @grid2: Second sandpile grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    // Add the two grids together
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Topple cells until the grid is stable
    bool unstable = true;
    while (unstable)
    {
        unstable = false;

        // Check each cell for instability and topple if necessary
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    topple(grid1, i, j);
                    unstable = true;
                }
            }
        }
   }
}

#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * grid_is_stable - Function that determines if a grid is stable or not
 * @grid: the grid
 * Return: 1 if grid is stable, 0 if not
 */
int grid_is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, is_stable, t;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
	is_stable = grid_is_stable(grid1);
	for (; is_stable == 0; is_stable = grid_is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					is_stable = 1;
					t = 1;
					grid1[i][j] -= 4 * t;
					if (i > 0)
						grid1[i - 1][j] += 1 * t;
					if (j > 0)
						grid1[i][j - 1] += 1 * t;
					if (i < 2)
						grid1[i + 1][j] += 1 * t;
					if (j < 2)
						grid1[i][j + 1] += 1 * t;
				}
			}
		}
	}
}

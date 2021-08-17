#include "sandpiles.h"
#include <stdio.h>

/**
* sandpiles_sum - adds two sandpiles together
* @grid1: output grid, first input grid
* @grid2: second input grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, flowMap[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	add_piles(grid1, grid2);
	while (!check_stable(grid1))
	{
		printf("=\n");
		ripped_print_grid(grid1);
		for (i = 0; i <= 8; i++)
		{
			if (grid1[i / 3][i % 3] > 3)
				flowMap[i] = 1;
			else
				flowMap[i] = 0;
		}
		for (i = 0; i <= 8; i++)
		{
			if (flowMap[i])
			{
				grid1[i / 3][i % 3] -= 4;
				if (i / 3 != 0)
					grid1[i / 3 - 1][i % 3]++;
				if (i / 3 != 2)
					grid1[i / 3 + 1][i % 3]++;
				if (i % 3 != 0)
					grid1[i / 3][i % 3 - 1]++;
				if (i % 3 != 2)
					grid1[i / 3][i % 3 + 1]++;
			}
		}
	}
}

/**
* ripped_print_grid - literally the given function but without the static
* @grid: grid to print
*/
void ripped_print_grid(int grid[3][3])
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
* add_piles - adds two sandpiles together
* @grid1: output grid, first input grid
* @grid2: second input grid
*/
void add_piles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
* check_stable - determines if a sandpile will not flow
* @grid: sandpile to check
*
* Return: 1 if stable, else 0
*/
int check_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

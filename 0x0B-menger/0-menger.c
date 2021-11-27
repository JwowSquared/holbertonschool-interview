#include "menger.h"

/**
* menger - determines the literal side length of menger square, then calls draw
* @n: depth of menger square
*/
void menger(int n)
{
	int i, size;

	if (n < 0)
		return;

	if (n == 0)
	{
		printf("#\n");
		return;
	}

	size = 1;
	for (i = 0; i < n; i++)
		size *= 3;

	draw(size);
}

/**
* draw - draws a menger square
* @size: side length in #s
*/
void draw(int size)
{
	int row, col, r, c, flag;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			r = row;
			c = col;
			flag = 0;
			while (r > 0 && c > 0)
			{
				if (r % 3 == 1 && c % 3 == 1)
				{
					flag = 1;
					break;
				}
				r /= 3;
				c /= 3;
			}
			if (flag)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}

#include "menger.h"

/**
* main - entrypoint for menger
* @ac: argc
* @av: argv
*
* Return: always 0
*/
int main(int ac, char **av)
{
	int i, n, size;

	if (ac != 2)
	{
		printf("Usage: %s <number>\n", av[0]);
		return (2);
	}

	n = atoi(av[1]);

	if (n < 0)
		return (1);

	if (n == 0)
	{
		printf("#\n");
		return (0);
	}

	size = 1;
	for (i = 0; i < n; i++)
		size *= 3;

	menger(n, size);

	return (0);
}

/**
* menger - constructs a 2D menger square of size n
* @n: size of menger square
* @size: n value that menger was originally called with
*/
void menger(int n, int size)
{
	int row, col, r, c, flag;

	(void)n;

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

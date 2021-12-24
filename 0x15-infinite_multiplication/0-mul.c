#include "mul.h"

/**
* main - entrypoint for mul program
* @ac: argc
* @av: argv
*
* Return: 98 on failure, else 0
*/
int main(int ac, char **av)
{
	int i;

	if (ac != 3)
	{
		printf("Error\n");
		return (98);
	}

	for (i = 0; av[1][i] != '\0'; i++)
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			printf("Error\n");
			return (98);
		}

	for (i = 0; av[2][i] != '\0'; i++)
		if (av[2][i] < '0' || av[2][i] > '9')
		{
			printf("Error\n");
			return (98);
		}

	inf_mul(av[1], av[2], 0, 0);

	return (0);
}

/**
* inf_mul - prints the product of a and b, recursively
* @a: first number
* @b: second number
* @carry: overflow from the previous digit
* @depth: current digit being printed, e.g. 0 is 1s, 1 is 10s
*/
void inf_mul(char *a, char *b, int carry, int depth)
{
	printf("%s\n", "TEST");
	printf("%s\n", a);
	printf("%s\n", b);
	printf("%d\n", carry);
	printf("%d\n", depth);
}

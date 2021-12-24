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
	int a_len, b_len;

	if (ac != 3)
	{
		printf("Error\n");
		return (98);
	}

	for (a_len = 0; av[1][a_len] != '\0'; a_len++)
		if (av[1][a_len] < '0' || av[1][a_len] > '9')
		{
			printf("Error\n");
			return (98);
		}

	for (b_len = 0; av[2][b_len] != '\0'; b_len++)
		if (av[2][b_len] < '0' || av[2][b_len] > '9')
		{
			printf("Error\n");
			return (98);
		}

	inf_mul(av[1], av[2], a_len - 1, b_len - 1, 0, 0);
	printf("\n");

	return (0);
}

/**
* inf_mul - prints the product of a and b, recursively
* @a: first number
* @b: second number
* @a_end: highest index of a
* @b_end: highest index of b
* @carry: overflow from the previous digit
* @depth: current digit being printed, e.g. 0 is 1s, 1 is 10s
*/
void inf_mul(char *a, char *b, int a_end, int b_end, int carry, int depth)
{
	int out = 0, a_off = 0, b_off = 0;

	if (a_end + b_end < depth)
	{
		if (carry != 0)
			printf("%d", carry);
		return;
	}

	out = carry;

	if (a_end < depth)
		b_off = depth - a_end;
	else
		a_off = a_end - depth;

	while (a_off >= 0 && a_off <= a_end && b_off >= 0 && b_off <= b_end)
	{
		out += ((a[a_off] - 48) * (b[b_off] - 48));
		a_off++;
		b_off--;
	}

	inf_mul(a, b, a_end, b_end, out / 10, depth + 1);

	printf("%d", out % 10);
}

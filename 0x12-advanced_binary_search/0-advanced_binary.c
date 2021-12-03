#include "search_algos.h"

/**
* advanced_binary - searches an array for a value
* @array: pointer to array to search
* @size: size of the current slice of the array
* @value: value to search for
*
* Return: index of value in array, else -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int mid, out;
	char *sep = "";

	if (array == NULL)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%s%d", sep, array[i]);
		sep = ", ";
	}
	printf("\n");

	if (size == 1)
	{
		if (value == array[0])
			return (0);
		return (-1);
	}

	mid = size / 2 - 1 + (size % 2);

	if (value == array[mid])
	{
		if (mid > 0 && array[mid - 1] == array[mid])
			out = advanced_binary(array, mid + 1, value);
		else
			return (mid);
	}
	else if (value < array[mid])
		out = advanced_binary(array, mid + 1, value);
	else
		out = advanced_binary(array + mid + 1, size - mid - 1, value);

	if (out > -1 && value > array[mid])
		out += mid + 1;

	return (out);
}

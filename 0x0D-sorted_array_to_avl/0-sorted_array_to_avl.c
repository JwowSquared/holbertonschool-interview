#include "binary_trees.h"

/**
* sorted_array_to_avl - converts sorted array to AVL tree
* @array: integer array to convert
* @size: size of array/tree
*
* Return: pointer to AVL tree, else NULL
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		printf("%02d = [%d]\n", (int)i, array[i]);

	return (NULL);
}

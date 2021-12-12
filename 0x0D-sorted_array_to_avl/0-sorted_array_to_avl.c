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
	avl_t *head = NULL;

	if (array == NULL)
		return (NULL);

	head = new_avl(array[size / 2]);
	if (head == NULL || size == 1)
		return (head);

	insert_children(head, size / 2, (size + 1) / 4, array);

	return (head);
}

/**
* insert_children - places children of an avl node
* @parent: parent to give children
* @p: current index of the parent node
* @d: depth offset
* @array: array we are converting from
*/
void insert_children(avl_t *parent, int p, int d, int *array)
{
	avl_t *left = NULL;
	avl_t *right = NULL;

	/* Ignoring Malloc Errors */
	left = new_avl(array[p - d]);
	right = new_avl(array[p + d]);

	left->parent = parent;
	right->parent = parent;
	parent->left = left;
	parent->right = right;

	if (d <= 1)
		return;

	insert_children(left, p - d, d / 2, array);
	insert_children(right, p + d, d / 2, array);
}

/**
* new_avl - creates a new avl node
* @n: n value to store
*
* Return: pointer to new node, else NULL
*/
avl_t *new_avl(int n)
{
	avl_t *out = NULL;

	out = malloc(sizeof(avl_t));
	if (out == NULL)
		return (NULL);

	out->n = n;
	out->parent = NULL;
	out->left = NULL;
	out->right = NULL;

	return (out);
}

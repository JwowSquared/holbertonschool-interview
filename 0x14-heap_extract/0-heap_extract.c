#include "binary_trees.h"

/**
* heap_extract - extracts the root of a heap and rebuilds
* @root: double pointer to root of heap
*
* Return: value stored in root node, else 0
*/
int heap_extract(heap_t **root)
{
	heap_t *current, *last, *swap;
	int out, size;

	if (root == NULL || *root == NULL)
		return (0);

	current = *root;
	size = count_nodes(current);
	if (size == 1)
	{
		out = current->n;
		free(current);
		*root = NULL;
		return (out);
	}

	while (current->left != NULL)
	{
		if (current->right != NULL && current->left->n < current->right->n)
			swap = current->right;
		else
			swap = current->left;
		swap_value(current, swap);
		current = swap;
	}
	last = select_last(*root, size, size);
	out = current->n;
	swap_value(current, last);

	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}
	free(last);
	return (out);
}

/**
* swap_value - swaps the value of two nodes
* @a: node 1
* @b: node 2
*/
void swap_value(heap_t *a, heap_t *b)
{
	int temp;

	/* if i cared, id swap the connections instead of the value. */
	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
* select_last - finds the highest index node in a binary tree
* @root: root of tree
* @size: number of nodes in the binary tree
* @b: number that will eventually represent the binary of size
*
* Return: highest index node, else NULL
*/
heap_t *select_last(heap_t *root, int size, int b)
{
	heap_t *out;

	if (b < 2)
		return (root);

	out = select_last(root, size, b / 2);

	if (b % 2 == 0)
		return (out->left);
	return (out->right);
}

/**
* count_nodes - counts the number of nodes in a binary heap
* @root: pointer to current node
*
* Return: number of nodes in the tree
*/
int count_nodes(heap_t *root)
{
	int left = 0, right = 0;

	if (root == NULL)
		return (0);

	if (root->left != NULL)
		left = count_nodes(root->left);
	if (root->right != NULL)
		right = count_nodes(root->right);
	return (1 + left + right);
}

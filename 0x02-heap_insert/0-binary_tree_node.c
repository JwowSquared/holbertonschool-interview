#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_node - creates a new binary tree node
* @parent: pointer to the parent node
* @value: value to be stored in the new node
*
* Return: address of the new node, else NULL
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *out;

	out = malloc(sizeof(binary_tree_t));
	if (out == NULL)
		return (NULL);

	out->parent = parent;
	out->n = value;
	out->left = NULL;
	out->right = NULL;

	return (out);
}

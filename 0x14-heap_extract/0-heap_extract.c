#include "binary_trees.h"

/**
* heap_extract - extracts the root of a heap and rebuilds
* @root: double pointer to root of heap
*
* Return: value stored in root node, else 0
*/
int heap_extract(heap_t **root)
{
	heap_t *current, *next;
	int out;

	if (root == NULL || *root == NULL)
		return (0);

	current = *root;

	/* behaviour unclear. potentially just swap INT_MIN down the tree and it balances itself. i'm not so sure */
	return (current->n);
}

#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
* heap_insert - inserts a value into a binary tree
* @root: reference to the root node of the tree
* @value: value to be placed in the binary tree
*
* Return: address of new node
*/
heap_t *heap_insert(heap_t **root, int value)
{
	int count;
	heap_t *out, *parent;

	if (root == NULL)
		return (NULL);

	out = binary_tree_node(NULL, value);
	if (out == NULL)
		return (NULL);

	count = heap_count(*root) + 1;
	if (count == 1)
	{
		*root = out;
		return (*root);
	}

	parent = find_parent(*root, count, count);
	out->parent = parent;
	if (count % 2 == 0)
		parent->left = out;
	else
		parent->right = out;

	heap_swap_up(root, out);

	return (out);
}

/**
* heap_swap_up - travels up a binary tree, swapping larger values up
* @root: reference to root of binary tree
* @out: node to begin swap up from
*/
void heap_swap_up(heap_t **root, heap_t *out)
{
	heap_t *current, *parent;

	current = out;
	parent = current->parent;

	while (parent != NULL)
	{
		if (current->n > parent->n)
			heap_swap(current, parent, root);
		else
			current = current->parent;
		parent = current->parent;
	}
}

/**
* heap_swap - inner logic of heap_swap_up
* @current: current in heap_swap_up
* @parent: parent in heap_swap_up
* @root: pointer to root of binary tree
*/
void heap_swap(heap_t *current, heap_t *parent, heap_t **root)
{
	heap_t *temp;

	if (parent->parent != NULL && parent->parent->left == parent)
		parent->parent->left = current;
	else if (parent->parent != NULL)
		parent->parent->right = current;
	if (current->left != NULL)
		current->left->parent = parent;
	if (current->right != NULL)
		current->right->parent = parent;
		current->parent = parent->parent;
	parent->parent = current;
	if (parent->left == current)
	{
		if (parent->right != NULL)
			parent->right->parent = current;
		parent->left = current->left;
		current->left = parent;
		temp = current->right;
		current->right = parent->right;
		parent->right = temp;
	}
	else
	{
		if (parent->left != NULL)
			parent->left->parent = current;
		parent->right = current->right;
		current->right = parent;
		temp = current->left;
		current->left = parent->left;
		parent->left = temp;
	}
	if (current->parent == NULL)
		*root = current;
}

/**
* find_parent - returns the parent of the node to insert
* @current: always the root of the binary tree
* @idx: current count value that lowers as you recurse deeper
* @count: constant reference to the count you started with
*
* Return: pointer to the parent node to add the new node to as a child
*/
heap_t *find_parent(heap_t *current, int idx, int count)
{
	heap_t *prev;
	int fork = idx % 2;

	if (idx < 2)
		return (current);

	prev = find_parent(current, idx / 2, count);

	if (idx == count)
		return (prev);

	if (fork == 0)
		return (prev->left);
	return (prev->right);
}

/**
* heap_count - counts the number of nodes in a binary tree
* @root: current head
*
* Return: number of nodes in tree according to root as head
*/
int heap_count(heap_t *root)
{
	int c = 1;

	if (root == NULL)
		return (0);

	c += heap_count(root->left);
	c += heap_count(root->right);
	return (c);
}

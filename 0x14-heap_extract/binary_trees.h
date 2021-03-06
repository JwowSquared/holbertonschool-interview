#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

heap_t *_array_to_heap(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

int heap_extract(heap_t **root);
int count_nodes(heap_t *root);
heap_t *select_last(heap_t *root, int size, int b);
void swap_value(heap_t *a, heap_t *b);

#endif /* _BINARY_TREES_H_ */

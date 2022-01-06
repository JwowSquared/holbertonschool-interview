#include "sort.h"

/**
* merge_sort - performs the merge_sort on array
* @array: array to sort
* @size: size of array to sort
*/
void merge_sort(int *array, size_t size)
{
	int *aux;

	if (array == NULL || size < 2)
		return;

	aux = malloc(sizeof(int) * size);
	if (aux == NULL)
		return;

	h_merge(array, aux, size);

	free(aux);
}

/**
* h_merge - helper function to perform merge sort
* @array: array to sort
* @aux: auxillary array to assist with sorting
* @size: current size of array to sort
*/
void h_merge(int *array, int *aux, size_t size)
{
	size_t k = 0, i = 0, j = size / 2;
	size_t i_max = j, j_max = size;

	if (size < 2)
		return;

	h_merge(array, aux, j);
	h_merge(array + j, aux + j, size - j);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, j);
	printf("[right]: ");
	print_array(array + j, size - j);

	while (i < i_max && j < j_max)
	{
		if (array[i] < array[j])
			aux[k++] = array[i++];
		else
			aux[k++] = array[j++];
	}

	while (i < i_max)
		aux[k++] = array[i++];
	while (j < j_max)
		aux[k++] = array[j++];
	for (k = 0; k < size; k++)
		array[k] = aux[k];

	printf("[Done]: ");
	print_array(array, size);
}

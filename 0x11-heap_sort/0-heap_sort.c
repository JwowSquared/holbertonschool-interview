#include "sort.h"

/**
* heap_sort - heapifies an array and then siftDown sorts it
* @array: array to sort
* @size: size of array
*/
void heap_sort(int *array, size_t size)
{
	true_heap_sort(array, size, size);
}

/**
* true_heap_sort - the function that heap sorts but with the prototype i need
* @a: array to sort
* @size: size of current workable array
* @full: size of the entire array, for printing
*/
void true_heap_sort(int *a, size_t size, size_t full)
{
	int temp, i, j, swap, left, right;

	if (size < 2)
		return;

	for (i = size - 1; i >= 0; i--)
	{
		swap = i;
		while (swap != -1)
		{
			j = swap;
			left = 2 * j + 1;
			right = 2 * j + 2;
			swap = -1;

			if (left < (int)size && a[j] < a[left])
				swap = left;
			if (right < (int)size && a[j] < a[right] && a[left] < a[right])
				swap = right;

			if (swap != -1)
			{
				temp = a[j];
				a[j] = a[swap];
				a[swap] = temp;
				print_array(a, full);
			}
		}
	}

	temp = a[0];
	a[0] = a[size - 1];
	a[size - 1] = temp;
	print_array(a, full);
	true_heap_sort(a, size - 1, full);
}

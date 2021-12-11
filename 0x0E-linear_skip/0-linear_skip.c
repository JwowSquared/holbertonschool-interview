#include "search.h"

/**
* linear_skip - searches a list for value
* @list: pointer to list
* @value: value
*
* Return: pointer to first instance of value in list, else NULL
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	int i, jump = -1;
	skiplist_t *current, *end;
	char *p1 = "Value checked at index [%d] = [%d]\n";
	char *p2 = "Value found between indexes [%d] and [%d]\n";

	if (list == NULL)
		return (NULL);

	current = list;
	while (current != NULL)
	{
		end = current->express;
		if (jump == -1)
			jump = end->index - 1;

		if (end != NULL)
			printf(p1, (int)end->index, end->n);
		if (end == NULL || value <= end->n)
		{
			i = (int)current->index;
			jump = i + jump;
			if (end != NULL)
				jump++;
			printf(p2, i, jump);
			for (; i <= jump; i++)
			{
				if (current == NULL)
					break;
				printf(p1, i, current->n);
				if (value == current->n)
					return (current);
				current = current->next;
			}
			return (NULL);
		}
		current = end;
	}
	return (NULL);
}

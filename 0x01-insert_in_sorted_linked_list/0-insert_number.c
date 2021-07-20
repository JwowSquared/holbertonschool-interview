#include "lists.h"
#include <stdlib.h>

/**
* insert_node - inserts a number into a sorted linked list
* @head: double pointer to list head
* @number: number of node to add
*
* Return: pointer to new node, else NULL
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *out, *current, *prev = NULL;

	if (head == NULL)
		return (NULL);

	out = malloc(sizeof(listint_t));
	if (out == NULL)
		return (NULL);
	out->n = number;
	out->next = NULL;

	if (*head == NULL)
	{
		*head = out;
		return (out);
	}

	current = *head;
	while (current != NULL)
	{
		if (current->n > number)
		{
			if (prev != NULL)
				prev->next = out;
			out->next = current;
			return (out);
		}
		prev = current;
		current = current->next;
	}

	prev->next = out;
	return (out);
}

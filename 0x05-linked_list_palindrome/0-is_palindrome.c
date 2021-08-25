#include "lists.h"
#include <stddef.h>

/**
* is_palindrome - checks if a linked list is a palindrome
* @head: double pointer to the head of a linked list
*
* Return: 1 if list is a palindrome, else 0
*/
int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (1);

	if (helper(*head, *head) == NULL)
		return (0);
	return (1);
}

/**
* helper - recursive helper function for is_palindrome
* @current: linked list forwards
* @head: linked list backwards
*
* Return: pointer to something if palindrome, else NULL
*/
listint_t *helper(listint_t *current, listint_t *head)
{
	listint_t *pair = NULL;

	if (current == NULL)
		return (head);

	pair = helper(current->next, head);
	if (pair == NULL)
		return (NULL);

	if (current->n == pair->n)
	{
		if (current == head)
			return (current);
		return (pair->next);
	}
	return (NULL);
}

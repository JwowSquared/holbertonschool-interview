#include "lists.h"

/**
* check_cycle - determines if a linked list visits the same node twice
* @list: head of list to check
*
* Return: 1 if a cycle is present, else 0
*/
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (list == NULL)
		return (0);

	slow = list;
	fast = list->next;

	while (slow != NULL && fast != NULL)
	{
		if (slow == fast)
			return (1);

		slow = slow->next;
		if (fast->next == NULL)
			break;
		fast = fast->next->next;
	}

	return (0);
}

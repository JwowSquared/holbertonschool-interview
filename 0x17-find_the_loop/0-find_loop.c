#include "lists.h"

/**
* find_listint_loop - finds a loop in list
* @head: head of list
*
* Return: node where loop begins, else NULL
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
		return (NULL);

	slow = head;
	fast = head;
	while (slow && fast)
	{
		slow = slow->next;
		if (slow == head)
			return (head);
		fast = fast->next;
		if (!fast)
			return (NULL);
		fast = fast->next;
		if (slow == fast)
			return (find_listint_loop(head->next));
	}

	return (NULL);
}

#include "lists.h"

/**
 * find_listint_loop - find a loop in a linked list
 * @head: pointer to beginning of loop
 * Return: address of node where loop starts, NULL if no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast;
	listint_t *slow;

	if (!head || !head->next)
		return (NULL);

	fast = head->next->next;
	slow = head->next;

	for (; slow && fast && fast->next; slow = slow->next, fast = fast->next->next)
	{
		if (slow == fast)
			break;
	}
	if (slow == fast)
	{
		for (slow = head; slow != fast; slow = slow->next, fast = fast->next)
			;
		return (fast);
	}
	return (NULL);
}

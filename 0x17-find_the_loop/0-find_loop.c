#include "lists.h"

/**
 * find_listint_loop - find a loop in a linked list
 * @head: pointer to beginning of loop
 * Return: address of node where loop starts, NULL if no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast = head;
	listint_t *slow = head;

	if (!head)
		return (NULL);

	for (; slow; slow = slow->next, fast = fast->next->next)
	{
		if (slow->n == fast->n)
			return (slow);
	}
	return (NULL);
}

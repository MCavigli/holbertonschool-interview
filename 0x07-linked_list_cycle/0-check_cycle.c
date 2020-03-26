#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - Checks if a linked list has a cycle
 * @list: The list to check
 * Return: 0 if there isn't a cycle, 1 if there is
 */

int check_cycle(listint_t *list)
{
	listint_t *tort = list->next;
	listint_t *hare = list->next->next;

	if (!list)
		return (0);

	while (hare && hare->next->next)
	{
		if (hare->n == tort->n)
			return (1);
		hare = hare->next->next;
		tort = tort->next;
	}
	return (0);
}

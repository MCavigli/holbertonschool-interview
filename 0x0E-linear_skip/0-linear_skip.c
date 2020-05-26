#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *head = list;
	skiplist_t *slow = list;
	skiplist_t *fast = list->express;
	skiplist_t *tmp = list;

	if (!head)
		return (NULL);

	for (; fast; fast = fast->express)
	{
		printf("Value checked at index [%zu] = [%i]\n", fast->index, fast->n);

		if (fast->n > value)
		{
			tmp = slow;
			printf("Value found between indexes [%zu] and [%zu]\n", tmp->index, tmp->express->index);
			break;
		}
		slow = fast;
	}
	if (!fast)
		return (NULL);

	for (; tmp->n < value; tmp = tmp->next)
	{
		printf("Value checked at index [%zu] = [%i]\n", tmp->index, tmp->n);
	}
	printf("Value checked at index [%zu] = [%i]\n", tmp->index, tmp->n);
	return (tmp);
}

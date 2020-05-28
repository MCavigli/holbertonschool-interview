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
	int count = 0;

	if (!head)
		return (NULL);

	for (; fast; fast = fast->express)
	{
		printf("Value checked at index [%zu] = [%i]\n", fast->index, fast->n);

		if (fast->n > value)
		{
			printf("Value found between indexes [%zu] and [%zu]\n",
				   slow->index, slow->express->index);
			break;
		}
		slow = fast;
	}
	if (!fast)
	{
		for (; tmp; tmp = tmp->next)
			count++;
		printf("Value found between indexes [%zu] and [%d]\n",
			   slow->index, count - 1);

		slow = slow->next;
	}
	for (; slow && slow->n <= value; slow = slow->next)
	{
		printf("Value checked at index [%zu] = [%i]\n", slow->index, slow->n);

		if (slow->n == value)
			return (slow);
	}
	return (NULL);
}

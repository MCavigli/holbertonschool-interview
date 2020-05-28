#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *fast = list;
	skiplist_t *listlen;
	int count = 0;

	if (fast)
	{
		for (listlen = list; list; list = list->next)
			count++;

		for (; fast->express && fast->express->n < value; fast = fast->express)
		{
			printf("Value checked at index [%zu] = [%i]\n",
				   fast->express->index, fast->express->n);
		}
		if (fast->express)
		{
			printf("Value checked at index [%zu] = [%i]\n",
				   fast->express->index, fast->express->n);
			printf("Value found between indexes [%zu] and [%zu]\n",
				   fast->index, fast->express->index);
		}
		else
			printf("Value found between indexes [%zu] and [%d]\n",
				   fast->index, count - 1);

		for (; fast; fast = fast->next)
		{
			printf("Value checked at index [%zu] = [%d]\n", fast->index, fast->n);
			if (fast->n == value)
				return (fast);
		}
	}
	return (NULL);
}

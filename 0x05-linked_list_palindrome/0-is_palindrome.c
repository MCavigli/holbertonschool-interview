#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: double pointer to head of linked list
 * Return: 0 if list is not a palindrome, 1 if it is
 */

int is_palindrome(listint_t **head)
{
	listint_t *tmp = *head;
	int list_len = 0;
	int middle = 0;
	int i;

	for (; tmp; tmp = tmp->next)
		list_len++;
	if (list_len == 0 || list_len == 1)
		return (1);

	tmp = *head;
	middle = list_len / 2;

	for (i = 0; i <= middle; i++)
	{
		if (traverse_list(tmp, list_len, i + 1) == tmp->n)
		{
			tmp = tmp->next;
			list_len--;
			continue;
		}
		else
			break;
		if (i >= middle)
			return (1);
	}
	if (i >= middle)
		return (1);
	else
		return (0);
}

/**
 * traverse_list - traverses a linked list
 * @h: head of linked list
 * @len: the length to go down the list
 * @start_pos: the node to start on
 * Return: value of last node
 */

int traverse_list(listint_t *h, int len, int start_pos)
{
	listint_t *last = h;
	int i;

	for (i = start_pos; i < len; i++)
		last = last->next;

	return (last->n);
}

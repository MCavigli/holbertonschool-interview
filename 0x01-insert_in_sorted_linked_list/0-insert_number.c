#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a node into a sorted linked list
 * @head: double pointer to head of linked list
 * @number: the number to insert into the linked list
 * Return: The address of the new node, NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	if (!head)
		return (NULL);
	listint_t *new;
	listint_t *tmp = *head;
	listint_t *slow = *head;

	new = malloc(sizeof(listint_t));
	if (!tmp->next)
	{
		if (slow->n < number)
		{
			new = add_nodeint_end(head, number);
			return (new);
		}
		else
		{
			new->next = slow;
			new->n = number;
			*head = new;
			return (new);
		}
	}
	tmp = tmp->next;

	while (tmp)
	{
		if (number > slow->n && number < tmp->n)
		{
			new->n = number;
			slow->next = new;
			new->next = tmp;
			return (new);
		}
		tmp = tmp->next;
		slow = slow->next;
	}
	free_listint(new);
	return (NULL);
}

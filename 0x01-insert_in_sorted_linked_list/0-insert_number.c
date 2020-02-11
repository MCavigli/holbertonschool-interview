#include "lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * insert_node - inserts a node into a sorted linked list
 * @head: double pointer to head of linked list
 * @number: the number to insert into the linked list
 * Return: The address of the new node, NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp = *head;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;
	if (!*head)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	if (!tmp->next)
	{
		new = single_node_list(head, number);
		return (new);
	}
	if (tmp->n > number)
	{
		new->next = tmp;
		*head = new;
		return (new);
	}
	while (tmp->next)
	{
		if (tmp->next->n >= number)
			break;
		tmp = tmp->next;
	}
	new->next = tmp->next;
	tmp->next = new;
	return (new);
}

/**
 * single_node_list - Adds a new node if the list is only one node long
 * @head: double pointer to first (and only) node in the list
 * @number: the number to put in the new node
 * Return: address of the new node
 */
listint_t *single_node_list(listint_t **head, int number)
{
	listint_t *tmp = *head;
	listint_t *new = malloc(sizeof(listint_t));

	if (!new)
		return (NULL);

	if (tmp->n < number)
	{
		new = add_nodeint_end(head, number);
	}
	else
	{
		new->next = tmp;
		new->n = number;
		*head = new;
	}
	return (new);
}

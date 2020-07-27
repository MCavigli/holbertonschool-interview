#ifndef _LISTS_H_
#define _LISTS_H_
#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

listint_t *find_listint_loop(listint_t *head);

#endif /* _LISTS_H_ */

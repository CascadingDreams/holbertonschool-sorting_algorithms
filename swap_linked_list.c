#include "sort.h"

/**
 * swap_linked_list - Swaps two adjacent nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @a: The first node.
 * @b: The second node (a->next).
 */
void swap_linked_list(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
}

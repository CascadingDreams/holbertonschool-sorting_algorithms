#include "sort.h"
#include "swap_linked_list.c"

/**
 * insertion_sort_list - insertion sort linked list
 * @list: pointer to pointer of list to SORT_H
 *
 * Return: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_linked_list(list, temp->prev, temp);
			print_list(*list);
		}
		current = temp->next;
	}
}

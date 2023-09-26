#include "sort.h"
#include <stdio.h>

void swap_nodes(listint_t **list, listint_t *a, listint_t *b);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     using the Cocktail Shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to a pointer to the head of the list.
 * @a: The first node to swap.
 * @b: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *temp = NULL;

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;
	if (b->next)
		b->next->prev = a;

	temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;

	temp = a->next;
	a->next = b->next;
	b->next = temp;
}


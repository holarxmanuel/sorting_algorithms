#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		temp = current;
		while (prev && prev->n > temp->n)
		{
			if (temp->next)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = temp;
			prev->prev = temp;
			temp->next = prev;
			if (prev == *list)
				*list = temp;
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}

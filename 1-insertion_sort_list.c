#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *prev, *temp;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		while (prev != NULL && temp->n < prev->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;

			temp->next = prev;
			prev->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			prev = temp->prev;
		}

		current = current->next;
	}
}

#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
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

		while (prev && prev->n > current->n)
		{
			temp = current->next;

			if (temp)
				temp->prev = prev;

			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;

			prev->next = temp;
			current->prev = prev;
			current->next = prev;
			prev->prev = current;

			if (temp)
				print_list(*list); /* Print the list after swapping */
			else
				print_list(*list);

			prev = current->prev;
		}

		current = current->next;
	}
}

#include "sort.h"

/**
 * print_list - Print a doubly linked list of integers
 * @list: A pointer to the head of the list
 */
void print_list(const listint_t *list)
{
	const listint_t *current = list;

	while (current)
	{
		printf("%d", current->n);
		current = current->next;
		if (current)
			printf(", ");
	}
	printf("\n");
}

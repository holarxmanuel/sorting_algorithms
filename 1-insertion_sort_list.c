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
        temp = current;

        while (prev && prev->n > temp->n)
        {
            prev->next = temp->next;
            if (temp->next)
                temp->next->prev = prev;
            temp->prev = prev->prev;
            temp->next = prev;

            if (prev->prev)
                prev->prev->next = temp;
            else
                *list = temp;

            prev->prev = temp;

            print_list(*list);  /* Print the list after swapping */
            prev = temp->prev;
        }

        current = current->next;
    }
}

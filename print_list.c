#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    while (list)
    {
        printf("%d", list->n);
        list = list->next;
        if (list)
            printf(", ");
    }
    printf("\n");
}

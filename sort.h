#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototypes for the sorting algorithms */

/* 0. Bubble Sort */
void bubble_sort(int *array, size_t size);

/* 1. Insertion Sort */
void insertion_sort_list(listint_t **list);

/* 2. Selection Sort */
void selection_sort(int *array, size_t size);

/* 3. Quick Sort */
void quick_sort(int *array, size_t size);

/* 100. Shell Sort using Knuth sequence */
void shell_sort(int *array, size_t size);

/* Print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */

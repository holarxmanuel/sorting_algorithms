#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int max = array[0];
	size_t i;

	/* Find the maximum element in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create and initialize the counting array */
	int *counting = malloc((max + 1) * sizeof(int));

	if (!counting)
		return;

	for (i = 0; i <= max; i++)
		counting[i] = 0;

	/* Populate the counting array */
	for (i = 0; i < size; i++)
		counting[array[i]]++;

	/* Update the original array with sorted values */
	int index = 0;

	for (i = 0; (size_t)i <= max; i++) /* Fixed the comparison */
	{
		while (counting[i] > 0)
		{
			array[index] = i;
			index++;
			counting[i]--;
		}
	}

	free(counting);
}

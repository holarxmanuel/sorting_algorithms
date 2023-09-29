#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers using counting sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	int max = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array with size (max + 1) */
	int *counting = malloc((max + 1) * sizeof(int));
	if (counting == NULL)
		return;

	/* Initialize counting array with zeros */
	for (int i = 0; i <= max; i++)
		counting[i] = 0;

	/* Count occurrences of each element in the input array */
	for (size_t i = 0; i < size; i++)
		counting[array[i]]++;

	/* Update the input array with sorted values */
	int index = 0;
	for (int i = 0; i <= max; i++)
	{
		while (counting[i] > 0)
		{
			array[index] = i;
			index++;
			counting[i]--;
		}
	}

	/* Print the counting array */
	printf("Counting array:\n");
	for (int i = 0; i <= max; i++)
	{
		printf("%d", counting[i]);
		if (i < max)
			printf(", ");
	}
	printf("\n");

	/* Free dynamically allocated memory */
	free(counting);
}

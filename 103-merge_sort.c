#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers using Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}

/**
 * merge_sort_recursive - Recursively sorts an array.
 * @array: The array to be sorted.
 * @start: The starting index of the array.
 * @end: The ending index of the array.
 */
void merge_sort_recursive(int *array, size_t start, size_t end)
{
	if (start < end)
	{
		size_t middle = start + (end - start) / 2;

		merge_sort_recursive(array, start, middle);
		merge_sort_recursive(array, middle + 1, end);

		merge(array, start, middle, end);
	}
}

/**
 * merge - Merges two subarrays into a single sorted array.
 * @array: The array containing the subarrays to be merged.
 * @start: The starting index of the first subarray.
 * @middle: The ending index of the first subarray.
 * @end: The ending index of the second subarray.
 */
void merge(int *array, size_t start, size_t middle, size_t end)
{
	size_t i, j, k;
	size_t n1 = middle - start + 1;
	size_t n2 = end - middle;

	int *left = malloc(sizeof(int) * n1);
	int *right = malloc(sizeof(int) * n2);

	if (!left || !right)
		return;

	for (i = 0; i < n1; i++)
		left[i] = array[start + i];
	for (j = 0; j < n2; j++)
		right[j] = array[middle + 1 + j];

	i = 0;
	j = 0;
	k = start;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < n1)
		array[k++] = left[i++];

	while (j < n2)
		array[k++] = right[j++];

	free(left);
	free(right);
}

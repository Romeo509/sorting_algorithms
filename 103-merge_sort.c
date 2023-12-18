#include "sort.h"

/**
 * merge - Merges two subarrays of 'array'.
 * @array: The array to be sorted.
 * @size: The total size of the array.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, size_t size, int *left,
		size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged = malloc(sizeof(int) * size);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			merged[k] = left[i];
			i++;
		}
		else
		{
			merged[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		merged[k] = left[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		merged[k] = right[j];
		j++;
		k++;
	}
	for (i = 0; i < size; i++)
		array[i] = merged[i];

	printf("[Done]: ");
	print_array(merged, size);
	free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
	int *left = array;
	size_t left_size = mid;
	int *right = array + mid;
	size_t right_size = size - mid;

	if (size < 2)
		return;
	merge_sort(left, left_size);
	merge_sort(right, right_size);

	merge(array, size, left, left_size, right, right_size);
}

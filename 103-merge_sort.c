#include "sort.h"

/**
 * merge_subarray - Sorts a subarray of integers.
 * @subarray: Subarray of integers to sort.
 * @buffer: Temporary buffer for merging.
 * @start: Start index of the subarray.
 * @mid: Middle index of the subarray.
 * @end: End index of the subarray.
 *
 * Description: Merges two subarrays into a sorted subarray.
 */
void merge_subarray(int *subarray, int *buffer,
size_t start, size_t mid, size_t end)
{
	size_t left_index, right_index, buffer_index = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + start, mid - start);

	printf("[right]: ");
	print_array(subarray + mid, end - mid);

	for (left_index = start, right_index = mid;
	left_index < mid && right_index < end; buffer_index++)
		buffer[buffer_index] = (subarray[left_index] < subarray[right_index])
	? subarray[left_index++] : subarray[right_index++];

	for (; left_index < mid; left_index++)
		buffer[buffer_index++] = subarray[left_index];

	for (; right_index < end; right_index++)
		buffer[buffer_index++] = subarray[right_index];

	for (left_index = start, buffer_index = 0; left_index < end; left_index++)
		subarray[left_index] = buffer[buffer_index++];

	printf("[Done]: ");
	print_array(subarray + start, end - start);
}

/**
 *  merge_sort_recursive - Recursively applies the merge sort algorithm.
 * @subarray: Subarray of integers to sort.
 *  @buffer: Temporary buffer for merging.
 *  @start: Start index of the subarray.
 *  @end: End index of the subarray.
 *
 *  Description: Implements the merge sort algorithm through recursion.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		merge_sort_recursive(subarray, buffer, start, mid);
		merge_sort_recursive(subarray, buffer, mid, end);
		merge_subarray(subarray, buffer, start, mid, end);
	}
}

/**
 *merge_sort - Sorts an array of integers using merge sort.
 *@array: Array of integers to sort.
 *@size: Size of the array.
 *
 *Description: Sorts an array of integers in ascending order using merge sort.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);
	free(buffer);
}

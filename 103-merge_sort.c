#include "sort.h"

/**
 * _merge_init - initiate merge sort
 * @array: array to be sorted
 * @temp: temporary array to hold sorted elements
 * @size: size of the array
 *
 * Return: Void
 */
void _merge_init(int *array, int *temp, size_t size)
{
	size_t half = size / 2, i = 0, j = 0, k = 0;

	if (size < 2)
		return;

	_merge_init(array, temp, half);
	_merge_init(array + half, temp + half, size - half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);
	for (; k < size; k++)
		if (j >= size - half || (i < half && array[i] < (array + half)[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = (array + half)[j];
			j++;
		}
	for (; k < size; k++)
		array[k] = temp[k];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - initiate merge sort
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	_merge_init(array, temp, size);
	free(temp);
}

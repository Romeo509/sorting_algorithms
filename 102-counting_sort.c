#include "sort.h"

/**
 * get_max - Get the maximum value
 * in a list .
 * @array: list of integers.
 * @size: size of the array.
 *
 * Return: maximum integer .
 */
int get_max(int *array, int size)
{
	int max, j;

	for (max = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	return (max);
}

/**
 * counting_sort - Sort an array
 * using the counting sort algorithm.
 * @array: An array .
 * @size: The size of the array.
 *
 * Description: Returns the counting array
 * after sorting.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, max, j;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}

	for (j = 0; j < (max + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] += 1;
	for (j = 0; j < (max + 1); j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);

	for (j = 0; j < (int)size; j++)
	{
		sort[count[array[j]] - 1] = array[j];
		count[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sort[j];

	free(sort);
	free(count);
}

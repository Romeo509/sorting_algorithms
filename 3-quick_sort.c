#include "sort.h"

/**
 *swap - functions that swaps two integers in an array
 * @x: First integer to swap
 * @y: Second integer to swap
 *
 * Return: nothing
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - function that orders subarray and places pivot
 * by using lomuto partitioning scheme
 *
 * @array: Array of integers to sort
 * @size: Size of array
 * @left: Starting index of subarray
 * @right: Ending index of subarray
 *
 * Return: partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int x = left - 1, y;

	for (y = left; y <= right - 1; y++)
	{
		if (array[y] < array[right])
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	if (x + 1 != right)
	{
		swap(&array[x + 1], &array[right]);
		print_array(array, size);
	}
	return (x + 1);
}

/**
 * lomuto_sort - function that implement the quicksort algorithm
 * through recursion.
 * @array: array of integers to sort.
 * @size: The size of the array.
 * @left: starting index of the array
 * @right: ending index of the array
 *
 * Return: nothing
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int index;

	if (right - left > 0)
	{
		index = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, index - 1);
		lomuto_sort(array, size, index + 1, right);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using quicksort algorithm
 * @array: Array of integers to sort
 * @size: Size of array
 *
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}


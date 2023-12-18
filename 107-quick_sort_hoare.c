#include "sort.h"

/**
 * swap - the positions of two elements into an array
 * @array: array
 * @x: array element
 * @y: array element
 *
 */

void swap(int *array, ssize_t x, ssize_t y)
{
	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

/**
 * hoare_partition - hoare partition sorting scheme implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size array
 *
 * Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, checker = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			checker--;
		} while (array[checker] > pivot);
		if (current >= checker)
			return (current);
		swap(array, current, checker);
		print_array(array, size);
	}
}

/**
 * _quick_sort - qucksort algorithm implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array size
 *
 */
void _quick_sort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		_quick_sort(array, first, position - 1, size);
		_quick_sort(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - prepare the terrain to quicksort algorithm
 * @array: array
 * @size: array size
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	_quick_sort(array, 0, size - 1, size);
}

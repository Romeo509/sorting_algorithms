#include "sort.h"

/**
 * max_val - finds the max value in the array
 * @array: pointer to array
 * @size: size of the array
 *
 * Return: max value from array
 */
int max_val(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort - sorts an array of integers is ASC
 * order implementing Radix Sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *new_array;
	int i, max, e = 1;
	int tmp = size;

	if (!array || size < 2)
		return;

	max = max_val(array, size);

	new_array = malloc(sizeof(int) * size);
	while (max / e > 0)
	{
		int nav[30] = {0};

		i = 0;

		while (i < tmp)
		{
			nav[(array[i] / e) % 10]++;
			i++;
		}

		if (nav != NULL)
		{
			for (i = 1; i < 10; i++)
				nav[i] += nav[i - 1];

			for (i = tmp - 1; i >= 0; i--)
			{
				new_array[nav[(array[i] / e) % 10] - 1] = array[i];
				nav[(array[i] / e) % 10]--;
			}

			for (i = 0; i < tmp; i++)
				array[i] = new_array[i];
		}
		e *= 10;
		print_array(array, size);
	}
	free(new_array);
}

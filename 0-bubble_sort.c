#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers adjacent
 * to each other repeatedly to create a sorted list
 * in ascending order(bubble sort list)
 *
 * @array: The array
 * @size: size of array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
size_t k, h;
int tmp;

if (size < 2)
return;

for (k = 0; k < size - 1; k++)
{
for (h = 0; h < size - k - 1; h++)
{
if (array[h] > array[h + 1])
{
tmp = array[h];
array[h] = array[h + 1];
array[h + 1] = tmp;
print_array(array, size);
}
}
}
}

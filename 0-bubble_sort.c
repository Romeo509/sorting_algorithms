#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
size_t a, b;
int tmp;

if (size < 2)
return;

for (a = 0; a < size - 1; a++)
{
for (h = 0; b < size - a - 1; b++)
{
if (array[b] > array[b + 1])
{
tmp = array[b];
array[b] = array[b + 1];
array[b + 1] = tmp;
print_array(array, size);
}
}
}
}

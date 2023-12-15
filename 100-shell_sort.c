#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using Shell sort algorithm with Knuth sequence
 * @array: Array of integers to sort
 * @size: Size of array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int tmp;
if (!array || size < 2)
return;

while (gap < size / 3)
gap = gap * 3 + 1;

while (gap > 0)
{
for (i = gap; i < size; i++)
{
tmp = array[i];
j = i;
while (j >= gap && array[j - gap] > tmp)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = tmp;
}
print_array(array, size);
gap = (gap - 1) / 3;
}
}


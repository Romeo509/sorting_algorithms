#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point for sorting an array using the bubble sort algorithm.
 *
 * The program initializes an array of integers and sorts it using bubble sort,
 * a simple comparison-based sorting algorithm. Bubble sort repeatedly steps 
 * through the list, compares adjacent elements, and swaps them if they are in 
 * the wrong order. This process continues until the entire list is sorted. The 
 * array is printed before and after sorting to show the difference.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}

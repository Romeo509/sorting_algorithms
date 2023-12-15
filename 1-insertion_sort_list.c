#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly
 * linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			/* Swap the nodes */
			current->prev = prev->prev;
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			/* Print the list after each swap */
			print_list(*list);
		}
		current = temp;
	}
}

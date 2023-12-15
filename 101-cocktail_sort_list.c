#include "sort.h"

/**
 * swap_node_ahead - function that swaps a node in a listint_t
 * doubly-linked list list of integers with the node ahead of it.
 *
 * @head: pointer to the head of a doubly-linked list
 * @tail: pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 *
 * Return: nothing
 */
void swap_node_ahead(listint_t **head, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->next;

if ((*shaker)->prev != NULL)
(*shaker)->prev->next = tmp;
else
*head = tmp;
tmp->prev = (*shaker)->prev;
(*shaker)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *shaker;
else
*tail = *shaker;
(*shaker)->prev = tmp;
tmp->next = *shaker;
*shaker = tmp;
}

/**
 * swap_node_behind - function that swaps a node in a listint_t
 * doubly-linked list of integers with the node behind it.
 * @head: pointer to the head of a doubly-linked list of integers.
 * @tail: pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 *
 * Return: nothing
 */
void swap_node_behind(listint_t **head, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->prev;

if ((*shaker)->next != NULL)
(*shaker)->next->prev = tmp;
else
*tail = tmp;
tmp->next = (*shaker)->next;
(*shaker)->prev = tmp->prev;
if (tmp->prev != NULL)
tmp->prev->next = *shaker;
else
*head = *shaker;
(*shaker)->next = tmp;
tmp->prev = *shaker;
*shaker = tmp;
}

/**
 * cocktail_sort_list - function that sorts a listint_t doubly-linked
 * list of integers in ascending order
 * @head: pointer to the head of a listint_t doubly-linked list.
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **head) {
listint_t *tail, *shaker;
int shaken_not_stirred = 0;

if (head == NULL || *head == NULL || (*head)->next == NULL)
return;

for (tail = *head; tail->next != NULL;)
tail = tail->next;

/* Main loop for the Cocktail Shaker Sort */
while (shaken_not_stirred == 0) {
shaken_not_stirred = 1;

/* Forward pass */
for (shaker = *head; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n) {
swap_node_ahead(head, &tail, &shaker);
print_list((const listint_t *)*head);
shaken_not_stirred = 0;
}
}

/* Backward pass */
for (shaker = shaker->prev; shaker != *head;
shaker = shaker->prev) {
if (shaker->n < shaker->prev->n) {
swap_node_behind(head, &tail, &shaker);
print_list((const listint_t *)*head);
shaken_not_stirred = 0;
}
}
}
}


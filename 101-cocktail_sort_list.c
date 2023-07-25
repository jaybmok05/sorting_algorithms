#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using
 * the cocktail sort algorithm.
 *
 * @list: Double pointer to the doubly linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *check, *first = NULL, *last = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		/* Forward pass - Bubble sort from left to right */
		for (check = *list; check->next; check = check->next)
		{
			if (check->n > check->next->n)
			{
				swap_me(check, check->next, list);
				print_list(*list);
			}
		}
		last = check;

		/* Backward pass - Bubble sort from right to left */
		for (check = last; check->prev != first; check = check->prev)
		{
			if (check->n < check->prev->n)
			{
				swap_me(check->prev, check, list);
				print_list(*list);
			}
		}
		first = last;

	} while (first != last);
}

/**
 * swap_me - swap the nodes themselves.
 * @current: pointer.
 * @current_old: pointer.
 * @list: doubly linked list
 */

void swap_me(listint_t *current, listint_t *current_old, listint_t **list)
{
	listint_t *temp1 = current->next;
	listint_t *temp2 = current_old->prev;

	if (temp1 != NULL)
		temp1->prev = current_old;
	if (temp2 != NULL)
		temp2->next = current;
	current->prev = temp2;
	current_old->next = temp1;
	current->next = current_old;
	current_old->prev = current;
	if (*list == current_old)
		*list = current;
	print_list(*list);
}

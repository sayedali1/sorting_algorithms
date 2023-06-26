#include "sort.h"
/**
 * swapme - swap the nodes themselves.
 * @current: pointer.
 * @current_old: pointer.
 * @list: doubly linked list
 */
void swap_nodes(listint_t **list, listint_t *current, listint_t *current_old)
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

/**
 * cocktail_sort_list - fun that sort num using coctail sorting algorthim
 * @list: pointer to the list we want to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *step = (*list)->next, *first = NULL, *last = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {

		while (step->next != NULL)
		{
			if (step->n > (step->next)->n)
			{
				swap_nodes(list, step->next, step);
			}
			else
			{
				step = step->next;
			}
		}
		last = step;
		while (step->prev != first)
		{
			if (step->n < step->prev->n)
			{
				swap_nodes(list, step, step->prev);
			}
			else
				step = step->prev;
		}
		first = step;
	} while (first != last);
}

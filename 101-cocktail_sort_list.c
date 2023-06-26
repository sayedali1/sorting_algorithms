#include "sort.h"
/**
 * swap_nodes - fun that swap two nodes of a linked list
 * @h:pointer to the head of the list
 * @n1: the first node
 * @n2: the sec node
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
 * cocktail_sort_list - fun that sort num using coctail sorting algorthim
 * @list: pointer to the list we want to sort
 */
void cocktail_sort_list(listint_t **list)
{
	int swap;
	listint_t *step, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swap = 0;

		for (step = *list; step->next != NULL; step = step->next)
		{
			if (step->n > (step->next)->n)
			{
				swap_nodes(list, &step, step->next);
				print_list(*list);
				swap = 1;
			}
		}

		swap = 0;
		while (step->prev != NULL)
		{
			temp = step->prev;

			if (step->n < temp->n)
			{
				swap_nodes(list, &temp, step);
				print_list(*list);
				swap = 1;
			}
			else
				step = step->prev;
		}
	} while (swap == 1);
}

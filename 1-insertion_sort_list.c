#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in asecnding order using the
 * insertion sort algorithm
 * @list: list of integer to be sorted
*/

void insertion_sort_list(listint_t **list)
{
listint_t *templist;
listint_t *tempprev;

templist = (*list)->next;

	while (templist != NULL)
	{
		tempprev = templist;

		while (tempprev->prev != NULL && tempprev->n < tempprev->prev->n)
		{
			if (tempprev->prev->prev != NULL)
				tempprev->prev->prev->next = tempprev;

			else
				(*list) = tempprev;

			tempprev->prev->next = tempprev->next;

			if (tempprev->next != NULL)
				tempprev->next->prev = tempprev->prev;

			tempprev->next = tempprev->prev;
			tempprev->prev = tempprev->next->prev;
			tempprev->next->prev = tempprev;

			print_list(*list);
		}
		templist = templist->next;
	}
}

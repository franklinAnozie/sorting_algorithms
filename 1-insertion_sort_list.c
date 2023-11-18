#include "sort.h"

/**
 * insertion_sort_list - performs an insertion sort
 * on a list
 * @list: pointer to the head of the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp_node, *current_node = (*list)->next;
	listint_t *prev_node;

	while (current_node != NULL)
	{
		prev_node = current_node->prev;
		while (prev_node != NULL && prev_node->n > current_node->n)
		{
			temp_node = current_node->next;
			if (prev_node->prev != NULL)
				prev_node->prev->next = current_node;
			else
				*list = current_node;

			current_node->next = prev_node;
			current_node->prev = prev_node->prev;
			prev_node->next = temp_node;
			prev_node->prev = current_node;
			if (temp_node != NULL)
				temp_node->prev = prev_node;
			print_list(*list);
			prev_node = current_node->prev;
		}
		current_node = current_node->next;
	}
}

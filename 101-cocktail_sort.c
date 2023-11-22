#include "sort.h"
/**
 * cocktail_sort_list - Function that performs a cocktail sort
 * on an array
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp_node, *current_node;
	listint_t *prev_node, *head, *tail;
	int i, size = 0;

	if (list == NULL || *list == NULL)
		exit(EXIT_FAILURE);

	head = (*list);

	if (head->next != NULL)
	{
		tail = head->next;
		while (head->next != NULL)
		{
			current_node = head;
			while (current_node->next != NULL)
			{
				prev_node = current_node->prev;
				temp_node = current_node->next;
				if (temp_node->n < current_node->n)
				{
					if (prev_node != NULL)
						prev_node->next = temp_node;
					else
						*list = temp_node;
					if (temp_node->next != NULL)
						temp_node->next->prev = current_node;
					current_node->next = temp_node->next;
					current_node->prev = temp_node;
					temp_node->next = current_node;
					temp_node->prev = prev_node;
					print_list(*list);
				}
				else
					current_node = current_node->next;
			}
			tail = current_node;
		}
	}
}

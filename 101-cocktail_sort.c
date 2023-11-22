#include "sort.h"
/**
 * cocktail_sort - Function that performs a bubble sort
 * on an array
 * @array: array to be sorted
 * @size: size of the array
 */
/* void cocktail_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	if (array == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}

        for (k = j - 1; k > i; k--)
        {
        	if (array[k] < array[k - 1])
			{
				temp = array[k];
				array[k] = array[k - 1];
				array[k - 1] = temp;
				print_array(array, size);
			}
        }
	}
} */

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
            while (current_node->prev != NULL)
            {


/*         for (k = j - 1; k > i; k--)
        {
            next_node = current_node->next;
			if (next_node->n > current_node->n)
			{
                if (next_node->next != NULL)
				    next_node->next->prev = current_node;
                else
                    *list = current_node;
                temp_node = current_node->prev;
                current_node->prev = next_node;
                current_node->next = next_node->next;
                next_node->prev = temp_node;
                next_node->next = current_node;
				if (temp_node != NULL)
    				temp_node->next = next_node;
                print_list(*list);
                next_node = current_node->next;
			}
            current_node = current_node->prev;
        } */
	    }
    }
}
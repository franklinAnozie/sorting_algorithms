#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

void free_node(listint_t *list)
{
	listint_t *temp;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	free(list);
}

void free_node(listint_t *list)
{
	listint_t *temp;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	free(list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {43, 7, 78, 22, 64, 75, 86, 60, 57, 56, 12, 94, 99, 55, 67, 10, 27, 23, 14, 38, 89, 24, 39, 92, 35, 97, 88, 2, 46, 93};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}

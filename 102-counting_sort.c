#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int max = array[0], j, i = 1;
	int *count_array, *array_copy, size_c;

	size_c = (int)size;

	while (i < size_c)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	count_array = malloc(sizeof(int) * (max + 1));
	array_copy = malloc(sizeof(int) * (size_c));
	if (count_array == NULL)
		exit(EXIT_FAILURE);
	if (array_copy == NULL)
	{
		free(count_array);
		exit(EXIT_FAILURE);
	}
	for (j = 0; j <= max; j++)
		count_array[j] = 0;

	for (i = 0; i < size_c; i++)
		count_array[array[i]]++;

	for (j = 1; j <= max; j++)
		count_array[j] += count_array[j - 1];

	array_sort(count_array, array_copy, array, max, size_c);

	free(count_array);
	free(array_copy);
}

void array_sort(int *counter, int *new_array, int *array, int max, int size_c)
{
	int i, j = 0;

	while (j <= max)
	{
		if (j > 0)
			printf(", ");
		printf("%d", counter[j]);
		j++;
	}

	for (i = size_c - 1; i >= 0; i--)
		new_array[--counter[array[i]]] = array[i];

	for (i = 0; i < size_c; i++)
		array[i] = new_array[i];
}

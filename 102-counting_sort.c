#include "sort.h"

/**
 * counting_sort - counting sort function
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0], j, i = 1;
	int *count_array, *array_copy, size_c;

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	size_c = (int)size;

	while (i < size_c)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		exit(EXIT_FAILURE);
	array_copy = malloc(sizeof(int) * (size_c));
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

/**
 * array_sort - array sort function
 * @counter: counter
 * @new_array: new array
 * @array: array
 * @max: max
 * @size_c: size_c
 */
void array_sort(int *counter, int *new_array, int *array, int max, int size_c)
{
	int i, j = 0;

	print_array(counter, max);

	for (i = size_c - 1; i >= 0; i--)
		new_array[--counter[array[i]]] = array[i];

	for (i = 0; i < size_c; i++)
		array[i] = new_array[i];
}

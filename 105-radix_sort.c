#include "sort.h"

/**
 * radix_sort - performs radix sort operation
 * @array: array
 * @size: size
 */
void radix_sort(int *array, size_t size)
{
	int max = array[0], i = 0;
	int size_c = (int)size, position = 1;
	int *count_array, *copy_array;

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	for (; i < size_c; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = malloc(sizeof(int) * 10);
	if (count_array == NULL)
		exit(EXIT_FAILURE);
	copy_array = malloc(sizeof(int) * size);
	if (copy_array == NULL)
	{
		free(count_array);
		exit(EXIT_FAILURE);
	}

	for (; max / position > 0; position *= 10)
	{
		count_sort(array, count_array, copy_array, size_c, position);
		print_array(array, size_c);
	}

	free(count_array);
	free(copy_array);
}

/**
 * count_sort - radix sort helper function
 * @array: array
 * @counter: counter
 * @copy_array: copy_array
 * @size: size
 * @pos: pos
 */
void count_sort(int *array, int *counter, int *copy_array, int size, int pos)
{
	int i = 0;

	for (; i < 10; i++)
		counter[i] = 0;

	for (i = 0; i < size; i++)
	{
		if ((array[i] / pos) == 0)
			counter[0]++;
		else
			counter[(array[i] / pos) % 10]++;
	}

	for (i = 1; i < 10; i++)
		counter[i] += counter[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		if ((array[i] / pos) == 0)
			copy_array[--counter[0]] = array[i];
		else
			copy_array[--counter[(array[i] / pos) % 10]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = copy_array[i];
}

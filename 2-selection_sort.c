#include "sort.h"

/**
 * selection_sort - performs selection sort
 * on an array
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min;
	int temp;

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
		i++;
	}
}

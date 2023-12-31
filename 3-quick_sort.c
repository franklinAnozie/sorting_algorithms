#include "sort.h"

/**
 * quick_sort - performs quick sort
 * on an array
 * @array: array to be sorted
 * @size: size of array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	int min = 0, max = (int)size - 1;
	int sz = (int)size;

	if (array == NULL)
		exit(EXIT_FAILURE);

	_quick_sort(array, min, max, sz);
}

/**
 * _quick_sort - helper function for quick_sort
 * @array: array to be sorted
 * @min: minimum
 * @max: maximum
 * @size: size of @array
 */
void _quick_sort(int *array, int min, int max, int size)
{
	int partition;

	if (min < max)
	{
		partition = lomuto_partition(array, min, max, size);

		_quick_sort(array, min, partition - 1, size);
		_quick_sort(array, partition + 1, max, size);
	}
}

/**
 * lomuto_partition - helper function for _quick_sort
 * @array: array
 * @min: minimum
 * @max: maximum
 * @size: size
 * Return: int
 */
int lomuto_partition(int *array, int min, int max, int size)
{
	int pivot;
	int i = min, j = min;

	pivot = array[max];

	while (j < max)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, (size_t)size);
			}
			i++;
		}
		j++;
	}
	if (i != max)
	{
		swap(&array[i], &array[max]);
		print_array(array, (size_t)size);
	}
	return (i);
}

/**
 * swap - swaps two integer
 * @max: max
 * @min: min
 */
void swap(int *max, int *min)
{
	int temp = *max;
	*max = *min;
	*min = temp;
}

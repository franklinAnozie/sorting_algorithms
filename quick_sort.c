#include "sort.h"

/**
 * quick_sort - performs quick sort operation
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	int min = 0, max = (int)size - 1;
	int sz = (int)size;

	_quick_sort(array, min, max, sz);
}

/**
 * _quick_sort - helper function for quick sort
 * @array: array
 * @min: min
 * @max: max
 * @size: size
 */
void _quick_sort(int *array, int min, int max, int size)
{
	int partition;

	if (min < max)
	{
		partition = hoare_partition(array, min, max, size);

		_quick_sort(array, min, partition - 1, size);
		_quick_sort(array, partition + 1, max, size);
	}
}

/**
 * hoare_partition - implements hoare partition
 * @array: array
 * @min: min
 * @max: max
 * @size: size
 * Return: int
 */
int hoare_partition(int *array, int min, int max, int size)
{
	int pivot = array[min];
	int i = min, j = max;

	while (i < j)
	{
		while (array[i] <= pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, (size_t)size);
		}
	}
	swap(&array[min], &array[j]);
	print_array(array, (size_t)size);
	return (j);
}

/**
 * swap - performs swap operation
 * @max: max
 * @min: min
 */
void swap(int *max, int *min)
{
	int temp = *max;
	*max = *min;
	*min = temp;
}

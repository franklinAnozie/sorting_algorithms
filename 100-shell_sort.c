#include "sort.h"

/**
 * shell_sort - performs shell sort on an array
 * @array: array to be sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0;
	int **seq;

	if (array == NULL)
		exit(EXIT_FAILURE);

	seq = knuth_sequence((int)size);

	while (seq[0][i])
		i++;
	i = i - 1;
	while (seq[0][i])
	{
		if (seq[0][i] == 1)
		{
			insertion_sort(array, (int)size);
			print_array(array, size);
			break;
		}
		while (seq[0][i] + j < (int)size)
		{
			if (array[j] > array[j + seq[0][i]])
			{
				swap(&array[j], &array[j + seq[0][i]]);
				if (array[j] < array[j - seq[0][i]] && j - seq[0][i] >= 0)
					swap(&array[j], &array[j - seq[0][i]]);
			}
			j++;
		}
		print_array(array, size);
		j = 0;
		i--;
	}
	free(seq[0]);
	free(seq);
}

/**
 * knuth_sequence - helper function for shell sort
 * @size: size
 * Return: pointer to int
 */
int **knuth_sequence(int size)
{
	int **new_sequence;
	int i = 0, n = 0;

	new_sequence = malloc(sizeof(int *));
	new_sequence[0] = malloc(sizeof(int));

	while (n < size)
	{
		if (n == 0)
			n = 1;
		new_sequence[0][i] = n;
		i++;
		n = n * 3 + 1;
		new_sequence[0] = realloc(new_sequence[0], (i + 1) * sizeof(int));
	}
	new_sequence[0][i] = 0;

	return (new_sequence);
}

/**
 * insertion_sort - helper function to shell sort
 * that implements insertion sort algorithm
 * @array: array
 * @size: size
 */
void insertion_sort(int *array, int size)
{
	int i = 1, j;
	int temp;

	while (i < size)
	{
		j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j -= 1;
		}
		i += 1;
	}
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

#include "sort.h"

/**
 * knuth_sequence - implements knuth algorithm
 * @size: size
 * Return: int pointer
 */
int **knuth_sequence(int size)
{
	static int **new_sequence;
	int i = 0, n = 0;

	new_sequence = malloc(sizeof(int *));
	if (new_sequence == NULL)
		exit(EXIT_FAILURE);

	while (n < size)
	{
		new_sequence[i] = malloc(sizeof(int));
		if (new_sequence[i] == NULL)
		{
			free(new_sequence);
			exit(EXIT_FAILURE);
		}
		if (n == 0)
		{
			n = 1;
			new_sequence[0][i] = n;
			printf("new_sequence[0][%d]: %d\n", i, new_sequence[0][i]);
		}
		else
		{
			new_sequence[0][i] = n;
			printf("new_sequence[0][%d]: %d\n", i, new_sequence[0][i]);
		}
		n = n * 3 + 1;
		i++;
	}
	new_sequence = realloc(new_sequence, (i + 1) * sizeof(int *));
	new_sequence[i] = NULL;
	return (new_sequence);
}

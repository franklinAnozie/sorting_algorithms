#include "sort.h"

int **knuth_sequence(int size)
{
    int **new_sequence;
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
        }
        else
        {
            new_sequence[0][i] = n;
        }
        n = n * 3 + 1;
        i++;
    }
    new_sequence[0][i] = 0;
    return (new_sequence);
}

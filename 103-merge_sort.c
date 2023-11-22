#include "sort.h"

void merge_sort(int *array, size_t size)
{
    int size_c = (int)size;
    int start = 0, end = size_c - 1;

    if (array == NULL)
        exit(EXIT_FAILURE);
    
    merge_sort_rec(array, start, end);
}

void merge_sort_rec(int *array, int  start, int end)
{
    int mid;

    if (start != end)
    {
        mid = start + (end - start) / 2;

        merge_sort_rec(array, start, mid);
        merge_sort_rec(array, mid + 1, end);

        merge_arrays(array, start, mid, end);
    }
}

void merge_arrays(int *array, int start, int mid, int end)
{
    int i, j, k;
    int *new_array;

    printf("Merging...\n");

    new_array = malloc(sizeof(int) * (end + 1));
    if (new_array == NULL)
        exit(EXIT_FAILURE);
    i = start;
    j = mid + 1;
    k = start;

    printf("[left]: ");
    print_array(array + start, mid - start + 1);
    printf("[right]: ");
    print_array(array + mid + 1, end - mid);
    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
            new_array[k++] = array[i++];
        else
            new_array[k++] = array[j++];
    }
    while (j <= end)
        new_array[k++] = array[j++];
    
    while (i <= mid)
        new_array[k++] = array[i++];
        
    for (i = start; i <= end; i++)
        array[i] = new_array[i];
    
    printf("[Done]: ");
    print_array(array + start, end - start + 1);
    
    free(new_array);
}

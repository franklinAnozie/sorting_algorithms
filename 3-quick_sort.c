#include "sort.h"

void quick_sort(int *array, size_t size)
{
    int min = 0, max = (int)size - 1;
    int sz = (int)size;
    
    srand(time(NULL));
    
    _quick_sort(array, min, max, sz);
}

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

int lomuto_partition(int *array, int min, int max, int size)
{
    int pivotIndex = min + (rand() % (max - min));
    int pivot;
    int i = min, j = min;
    
    if (pivotIndex != max)
        swap(&array[pivotIndex], &array[max]);
    
    pivot = array[max];
    
    while (j < max)
    {
        if (array[j] <= pivot)
        {
            swap(&array[i], &array[j]);
            print_array(array, (size_t)size);
            i++;
        }
        j++;
    }
    swap(&array[i], &array[max]);
    print_array(array, (size_t)size);
    return (i);
}

#include "sort.h"

void quick_sort(int *array, size_t size)
{
    int min = 0, max = (int)size - 1;
    int sz = (int)size;
    
    _quick_sort(array, min, max, sz);
}

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

void swap(int *max, int *min)
{
    int temp = *max;
    *max = *min;
    *min = temp;
}


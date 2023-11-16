#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void insertion_sort(int *array, int size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void _quick_sort(int *array, int min, int max, int size);
int lomuto_partition(int *array, int min, int max, int size);
int hoare_partition(int *array, int min, int max, int size);
void swap(int *max, int *min);
void shell_sort(int *array, size_t size);
int **knuth_sequence(int size);
void free_sequence(int **seq, int size);

#endif
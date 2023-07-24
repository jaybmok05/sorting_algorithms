#ifndef SORT_H_FILE
#define SORT_H_FILE

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


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

/**
 * enum bool_e - manual definition of booleans, in case C99 stdbool.h not
 * available
 * @false: logical 0
 * @true: logical 1
 */

typedef enum bool_e
{
	false = 0,
	true
} bool;

/*list of function prototype*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void swap_ints(int *num_1, int *num_2);
#endif

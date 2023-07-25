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
void cocktail_sort_list(listint_t **list);
void swap_me(listint_t *current, listint_t *current_old, listint_t **list);
int get_max(int *array, int size);
void counting_sort(int *array, size_t size);

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
size_t back);

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
#endif

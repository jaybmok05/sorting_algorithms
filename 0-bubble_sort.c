#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using a bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, last_unsorted_index;
	int temp;
	bool swapped = true;

	/* Check for valid input or if sorting is unnecessary */
	if (!array || size < 2)
		return;

	/* Initialize the index of the last unsorted element */
	last_unsorted_index = size;

	do {
		swapped = false;
		/* Traverse through the unsorted part of the array */
		for (i = 1; i < last_unsorted_index; i++)
		{
			/* Swap adjacent elements if they are in the wrong order */
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				swapped = true;
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
		/* Reduce the range of unsorted elements after each pass */
		last_unsorted_index--;
	} while (swapped);
}

#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using
 * the Selection Sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: Number of elements in the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index, temp;

	if (!array || size < 2)
		return;

	/* At every position in the array */
	for (i = 0; i < size - 1; i++)
	{
		/* Scan from that position to the end, */
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			/* Determine the minimum value in that range */
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		/* If the min value < the value at initial range, swap*/
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}


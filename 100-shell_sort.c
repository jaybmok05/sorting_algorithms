#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, index_0, index_1;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap sequence */
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/* Loop over different gap sizes */
	for (; gap >= 1; gap /= 3)
	{
		/* Perform insertion sort with current gap size */
		for (index_0 = gap; index_0 < size; index_0++)
		{
			index_1 = index_0;
			/* Perform insertion*/
			do {
				if (array[index_1 - gap] > array[index_1])
				{
					swap_ints(array + index_1, array + (index_1 - gap));
					index_1 -= gap;
				}
				else
				{
					break;/* Element at the right place */
				}
			} while (index_1 >= gap);
		}
		print_array(array, size);
	}
}

/**
 * swap_ints - Swap two integers in an array.
 * @num_1: The first integer to swap.
 * @num_2: The second integer to swap.
 */

void swap_ints(int *num_1, int *num_2)
{
	int tmp = *num_1;

	*num_1 = *num_2;
	*num_2 = tmp;
}

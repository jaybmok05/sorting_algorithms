#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using a quick
 * sort algorithm, with Lomuto partition scheme
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}


/**
 * quicksort - Recursively sorts an array of integers using
 * Lomuto quicksort.
 * @array: Array of integers to be sorted.
 * @low: Index in array that indicates the beginning of the partition.
 * @high: Index in array that indicates the end of the partition.
 * @size: Number of elements in the array.
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}


/**
 * partition - Scans a partition of an array of integers for values less than
 * the pivot value, and swaps them with the first value in the partition.
 * Then, swaps the pivot value with the first value in the partition.
 * @array: Array of integers to be sorted.
 * @low: Index in the array that indicates the beginning of the partition.
 * @high: Index in the array that indicates the end of the partition.
 * @size: Number of elements in the array.
 * Return: New index at which to start a new recursive partition.
 */

int partition(int *array, int low, int high, size_t size)
{
	int left_ptr = low, current_index = low, pivot, temp;

	pivot = array[high];

	do {
		if (array[current_index] < pivot)
		{
			temp = array[left_ptr];
			array[left_ptr] = array[current_index];
			array[current_index] = temp;
			if (array[left_ptr] != array[current_index])
				print_array(array, size);
			left_ptr++;
		}
		current_index++;
	} while (current_index < high);

	temp = array[left_ptr];
	array[left_ptr] = array[high];
	array[high] = temp;

	if (array[left_ptr] != array[high])
		print_array(array, size);

	return (left_ptr);
}

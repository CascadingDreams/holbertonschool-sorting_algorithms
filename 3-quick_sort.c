#include "sort.h"

/**
 * swap_ints - Swap two integers if they are different
 * @a: First integer
 * @b: Second integer
 * Return: 1 if swap, 0 if nothing
 */
int swap_ints(int *a, int *b)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		return (1); /* Swap occurred */
	}
	return (0); /* No swap */
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Total size of array (for print)
 * Return: Final position of pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;
	int did_swap;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			did_swap = swap_ints(&array[i], &array[j]);
			if (did_swap)
				print_array(array, size);
		}
	}
	did_swap = swap_ints(&array[i + 1], &array[high]);
	if (did_swap)
		print_array(array, size);
	return (i + 1);
}

/**
 * quicksort - Recursive Quick Sort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Total size of array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot;

		pivot = lomuto_partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sort array of integers in ascending order
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

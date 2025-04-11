#include "sort.h"
#include "swap.c"

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the full array (for printing)
 * Return: Index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * quicksort - Recursively sorts the array using quick sort
 * @array: The array
 * @low: Starting index
 * @high: Ending index
 * @size: Total size of the array
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
 * quick_sort - Sorts an array using the Quick sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

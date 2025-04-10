#include "sort.h"

/**
 * swap - Swaps the values of two integers
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 *
 * This function exchanges the values of the two integers
 * pointed to by x and y. It uses a temporary variable to
 * hold one of the values during the swap.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to an array of integers
 * @size: Number of elements in the array
 * @cmp: Pointer to the comparison function
 *
 * Return: Index of the first element for which cmp doesn't return 0
 *         -1 if no element matches or size is non-positive
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array != NULL && cmp != NULL && size > 0)
	{
		int i;

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}

	return (-1);
}

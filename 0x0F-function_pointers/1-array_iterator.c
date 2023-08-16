#include "function_pointers.h"

/**
 * array_iterator - Executes a function on each element of an array
 * @array: Pointer to an array of integers
 * @size: Size of the array
 * @action: Pointer to a function to be executed on each element
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array != NULL && action != NULL)
	{
	size_t i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
	}
}

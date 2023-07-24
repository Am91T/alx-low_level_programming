#include "main.h"
#include <stdio.h>

/**
 * print_array - Prints n elements of an integer array.
 * @a: Pointer to the first element of the array.
 * @n: Number of elements to be printed.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < (n - 1); i++)
	{
		printf("%d, ", a[i]);
	}
		if (i == (n - 1))
		{
			printf("%d", a[n - 1]);
		}
			printf("\n");
}

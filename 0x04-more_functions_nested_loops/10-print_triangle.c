#include "main.h"

/**
 * print_triangle - Prints a triangle of size 'size' using the character '#'.
 * @size: The size of the triangle.
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
	_putchar('\n');
	}
	else
	{
		for (i = 1; i <= size; i++)
		{
		for (j = 1; j <= size - i; j++)
	{
		_putchar(' ');
	}
		for (j = 1; j <= i; j++)
	{
		_putchar('#');
	}
		_putchar('\n');
	}
	}
}

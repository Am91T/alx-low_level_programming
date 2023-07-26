#include "main.h"

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 * Return: 0
 */
void print_number(int n)
{
	int digit, is_negative = 0;
	int divisor = 1;
	int temp = n;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	while (temp /= 10)
		divisor *= 10;

	if (is_negative)
		_putchar('-');

	while (divisor)
	{
		digit = n / divisor;
		_putchar('0' + digit);
		n -= digit * divisor;
		divisor /= 10;
	}
}

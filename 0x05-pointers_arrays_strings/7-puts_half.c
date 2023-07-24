#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: Pointer to the input string.
 *
 * Return: The length of the string (excluding the null terminator).
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * puts_half - Prints the second half of a string followed by a new line.
 * @str: Pointer to the input string.
 */
void puts_half(char *str)
{
	int length = _strlen(str);
	int n = (length + 1) / 2;

	while (*(str + n) != '\0')
	{
		_putchar(*(str + n));
		n++;
	}
	_putchar('\n');
}

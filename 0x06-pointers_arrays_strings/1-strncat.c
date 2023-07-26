#include "main.h"

/**
 * _strncat - Concatenates two strings up to n bytes.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to concatenate from src.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;
	int dest_len = 0;

	/* Find the length of dest */
	while (*ptr)
	{
		ptr++;
		dest_len++;
	}

	/* Append up to n bytes from src to dest */
	while (*src && n > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}

	/* Null-terminate dest after appending src */
	*ptr = '\0';

	return (dest);
}

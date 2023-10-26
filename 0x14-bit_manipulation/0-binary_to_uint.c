#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: Pointer to the binary string.
 * Return: The converted number, or 0 if there are non-binary char or NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] == '0')
			result = (result << 1);
		else if (b[i] == '1')
			result = (result << 1) | 1;
		else
			return (0);
	}

	return (result);
}

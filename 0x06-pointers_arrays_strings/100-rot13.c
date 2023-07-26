#include "main.h"

/**
 * rot13 - Encodes a string using ROT13.
 * @str: The input string to modify.
 *
 * Return: A pointer to the modified string.
 */
char *rot13(char *str)
{
	char *s = str;
	char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i;

	while (*s != '\0')
	{
		for (i = 0; i < 52; i++)
		{
			if (*s == letter[i])
			{
				*s = rot13[i];
				break;
			}
		}
		s++;
	}

	return (str);
}

#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: The input string to modify.
 *
 * Return: A pointer to the modified string.
 */
char *leet(char *str)
{
	char leet_map[10] = {'o', 'l', '\0', 'e', 'a', '\0', '\0', 't', '\0', 'a'};
	int i = 0, j;

	while (str[i] != '\0')
	{
		j = 0;
		while (j < 10)
		{
			if ((str[i] == leet_map[j] || str[i] == leet_map[j] - 32))
			{
				str[i] = j + '0';
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}

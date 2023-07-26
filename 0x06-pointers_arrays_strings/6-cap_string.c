#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The input string to modify.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
	int i = 0;

	/* Capitalize the first letter of the string */
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;

	while (str[i] != '\0')
	{
		/* Check for separators and capitalize the next letter */
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		    str[i] == ',' || str[i] == ';' || str[i] == '.' ||
		    str[i] == '!' || str[i] == '?' || str[i] == '"' ||
		    str[i] == '(' || str[i] == ')' || str[i] == '{' ||
		    str[i] == '}')
		{
			i++; /* Move to the next character */

			/* Capitalize the next letter if it's lowercase */
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		else
		{
			i++; /* Move to the next character */
		}
	}

	return (str);
}

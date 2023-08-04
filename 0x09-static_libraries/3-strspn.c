#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: the string to search
 * @accept: the characters to match
 *
 * Return: the number of bytes in the initial segment of s which consist only
 * of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, j;
	int found;

	for (i = 0; s[i]; i++)
	{
		found = 0;
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				found = 1;
				break;
			}
		}
		if (!found)
			break;
	}
	return (count);
}

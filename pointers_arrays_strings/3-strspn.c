#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: the string to be searched
 * @accept: the characters to allow in the prefix
 *
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;
	int j;
	int match;

	while (s[i] != '\0')
	{
		match = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
		}
		if (match == 0)
			return (i);
		i++;
	}

	return (i);
}

#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring.
 * @haystack: the string to search
 * @needle: the substring to find
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	while (*haystack != '\0')
	{
		h = haystack;
		n = needle;

		while (*n != '\0' && *haystack == *n)
		{
			haystack++;
			n++;
		}

		if (*n == '\0')
			return (h);

		haystack = h + 1;
	}

	if (*needle == '\0')
		return (haystack);

	return (NULL);
}

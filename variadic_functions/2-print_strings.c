#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: the string to be printed between the strings.
 * @n: the number of strings passed to the function.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		/* Növbəti arqumenti string (char *) kimi alırıq */
		str = va_arg(args, char *);

		/* Şərt: Əgər string NULL-dursa (nil) çap et, əks halda özünü çap et */
		if (str == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", str);
		}

		/* Şərt: Ayırıcı NULL deyilsə və sonuncu sətirdə deyiliksə, ayırıcını çap et */
		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");

	va_end(args);
}

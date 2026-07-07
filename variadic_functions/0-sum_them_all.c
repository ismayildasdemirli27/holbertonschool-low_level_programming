#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters.
 * @n: the number of parameters passed to the function.
 *
 * Return: the sum of all parameters. If n == 0, return 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	if (n == 0)
		return (0);

	/* Initialize the va_list 'args' to retrieve the additional arguments */
	va_start(args, n);

	/* Loop through each argument and add it to the sum */
	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}

	/* Clean up the va_list */
	va_end(args);

	return (sum);
}

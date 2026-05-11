#include "main.h"

/**
 * _puts_recursion - bir sətri çap edir və ardınca yeni sətir qoyur.
 * @s: çap olunacaq sətirə göstərici (pointer).
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}

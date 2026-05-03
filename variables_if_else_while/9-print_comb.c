#include <stdio.h>

/**
 * main - prints all single digit numbers of base 10 separated by , 
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
		if (n != 57)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}

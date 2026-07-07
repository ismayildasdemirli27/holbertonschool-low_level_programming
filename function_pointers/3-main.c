#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - performs simple operations
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	int (*func)(int, int);

	/* Arqument sayının düzgünlüyünü yoxlayırıq */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	func = get_op_func(argv[2]);

	/* Operatorun düzgün olub olmadığını yoxlayırıq */
	if (func == NULL || argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	/* 0-a bölmə/qalıq xətasını yoxlayırıq */
	if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	/* Nəticəni çap edirik */
	printf("%d\n", func(num1, num2));
	return (0);
}

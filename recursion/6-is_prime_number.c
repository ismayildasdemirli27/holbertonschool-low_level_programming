#include "main.h"

/**
 * check_prime - Ədədin sadə olub-olmadığını yoxlayan köməkçi funksiya
 * @n: Yoxlanılacaq ədəd
 * @i: Bölünməni yoxlamaq üçün sayağac (iterator)
 *
 * Return: Əgər sadə ədəddirsə 1, əks halda 0
 */
int check_prime(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
		
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - Verilmiş ədədin sadə olub-olmadığını qaytarır
 * @n: Yoxlanılacaq ədəd
 *
 * Return: Sadə ədəddirsə 1, mürəkkəbdirsə 0
 */
int is_prime_number(int n)
{
	/* 1 və 1-dən kiçik ədədlər sadə ədəd hesab edilmir */
	if (n <= 1)
		return (0);
		
	/* Yoxlamağa 2-dən başlayırıq, çünki hər ədəd 1-ə bölünür */
	return (check_prime(n, 2));
}

#include "main.h"

/**
 * actual_sqrt_recursion - Təbii kvadrat kökü tapmaq üçün köməkçi funksiya
 * @n: Kvadrat kökü tapılacaq ədəd
 * @i: Yoxlamaq üçün istifadə olunan sayağac (iterator)
 *
 * Return: Kvadrat kök, əks halda -1
 */
int actual_sqrt_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	
	return (actual_sqrt_recursion(n, i + 1));
}

/**
 * _sqrt_recursion - Ədədin təbii kvadrat kökünü qaytarır
 * @n: Kvadrat kökü tapılacaq ədəd
 *
 * Return: n-in kvadrat kökü, əgər təbii kökü yoxdursa -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
		
	return (actual_sqrt_recursion(n, 0));
}

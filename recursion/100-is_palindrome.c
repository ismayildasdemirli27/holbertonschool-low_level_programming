#include "main.h"

/**
 * _strlen_recursion - Sətrin uzunluğunu tapır
 * @s: Uzunluğu tapılacaq sətir
 * Return: Sətrin uzunluğu
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - Palindromu rekursiv olaraq yoxlayır
 * @s: Yoxlanılacaq sətir
 * @i: Başlanğıc indeksi (iterator)
 * @len: Sətrin uzunluğu
 * Return: Palindromdursa 1, deyilsə 0
 */
int check_palindrome(char *s, int i, int len)
{
	if (*(s + i) != *(s + len - 1))
		return (0);
	if (i >= len)
		return (1);
	return (check_palindrome(s, i + 1, len - 1));
}

/**
 * is_palindrome - Sətrin palindrom olub-olmadığını yoxlayır
 * @s: Yoxlanılacaq sətir
 * Return: Palindromdursa 1, deyilsə 0
 */
int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (check_palindrome(s, 0, _strlen_recursion(s)));
}

#include "main.h"

/**
 * _isalpha - Hərfin əlifba xarakteri olub-olmadığını yoxlayır
 * @c: Yoxlanılacaq xarakter (ASCII dəyəri)
 *
 * Return: Əgər hərfdirsə 1, əks halda 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

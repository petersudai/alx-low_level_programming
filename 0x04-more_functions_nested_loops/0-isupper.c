#include "main.h"

/**
 * __isupper - checks if character is uppercase
 * @c: the function parameter
 * Return: success 1 failure 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

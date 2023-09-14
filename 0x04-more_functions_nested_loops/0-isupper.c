#include "main.h"

/**
 * _isupper - checks if character is uppercase
 * @c: the function parameter
 * Return: success 1 failure 0
 */

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

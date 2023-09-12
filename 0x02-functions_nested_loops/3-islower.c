#include "main.h"

/**
 * _islower - checks if character is lowercase
 *
 * Return: 0 or 1
 */

int _islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

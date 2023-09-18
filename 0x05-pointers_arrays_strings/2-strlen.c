#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: string pointer
 * Return: length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;

	return (i);
}

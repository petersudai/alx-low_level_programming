#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: pointer to the string
 * @accept: pointer to the byte to search for
 *
 * Return: s or 0
 */

char *_strpbrk(char *s, char *accept)
{
	char *accept_ptr;

	while (*s != '\0')
	{
		accept_ptr = accept;
		while (*accept_ptr != '\0')
		{
			if (*s == *accept_ptr)
				return (s);
			accept_ptr++;
		}
		s++;
	}
	return (NULL);
}



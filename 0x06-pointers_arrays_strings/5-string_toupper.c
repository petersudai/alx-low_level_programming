#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase.
 * @str: string to be changed
 *
 * Return: str
 */

char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr = *ptr - 32;
		}
		ptr++;
	}
	return (str);
}

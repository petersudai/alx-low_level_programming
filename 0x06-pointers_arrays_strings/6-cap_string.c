#include "main.h"

/**
 * cap_string -  capitalizes all words of a string.
 * @str: string to be capitalized
 *
 * Return: str
 */

char *cap_string(char *str)
{
	int capitalize = 1;
	char *ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == ',' ||
		*ptr == ';' || *ptr == '.' || *ptr == '!' || *ptr == '?' ||
		*ptr == '"' || *ptr == '(' || *ptr == ')' || *ptr == '{' ||
		*ptr == '}')
		{
			capitalize = 1;
		}
		else if (capitalize && ((*ptr >= 'a' && *ptr <= 'z')))
		{
			*ptr = *ptr - 32;
			capitalize = 0;
		}
		else if (!capitalize && ((*ptr >= 'A' && *ptr <= 'Z')))
		{
			*ptr = *ptr + 32;
		}
		else
		{
			capitalize = 0;
		}
		ptr++;
	}
	return (str);
}

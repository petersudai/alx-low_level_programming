#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The input string.
 *
 * Return: Pointer to the modified string.
 */
char *cap_string(char *str)
{
	int capitalize = 1;

	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n' || *str == ','
				|| *str == ';' || *str == '.' || *str == '!' || *str == '?'
				|| *str == '"' || *str == '(' || *str == ')' || *str == '{' || *str == '}')
		{
			capitalize = 1;
		}
		else if (capitalize && ((*str >= 'a' && *str <= 'z')))
		{
			*str = *str - 32;
			capitalize = 0;
		}
		else if (!capitalize && ((*str >= 'A' && *str <= 'Z')))
		{
			*str = *str + 32;
		}
		else
			capitalize = 0;
		str++;
	}
	return (str);
}

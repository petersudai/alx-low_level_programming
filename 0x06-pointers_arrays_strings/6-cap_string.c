#include "main.h"

/**
 * cap_string - capitalizes all words of a string.
 * @str: string to be capitalized
 *
 * Return: str
 */

char *cap_string(char *str)
{
int capitalize = 1;

while (*str != '\0')
	if ((*str >= 'a'  && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
	{
		if (capitalize && (*str >= 'a' && *str <= 'z'))
		{
			*str = *str - 32;
			capitalize = 0;
		}
		else if (!capitalize && (*str >= 'A' && *str <= 'Z'))
			*str = *str + 32;
		else
			capitalize = 1;
		str++;
	}
return (str);
}

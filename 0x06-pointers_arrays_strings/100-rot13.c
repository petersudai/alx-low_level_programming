#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 algorithm.
 * @str: The input string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
		if ((*ptr >= 'a' && *ptr <= 'm') || (*ptr >= 'A' && *ptr <= 'M'))
		{
			*ptr += 13;
		}
		else if ((*ptr >= 'n' && *ptr <= 'z') || (*ptr >= 'N' && *ptr <= 'Z'))
		{
			*ptr -= 13;
		}
		ptr++;
	}
	return (str);
}

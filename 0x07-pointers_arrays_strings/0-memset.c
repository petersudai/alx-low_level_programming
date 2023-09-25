#include "main.h"

/**
 * *_memset -  fills memory with a constant byte.
 * @s: Pointer to the memory area to be filled
 * @b: the constant byte to fill the memory area
 * @n: number of bytes to be filled
 *
 * Return: pointer s
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *original_s = s;

	while (n--)
	{
		*s++ = b;
	}
	return (original_s);
}

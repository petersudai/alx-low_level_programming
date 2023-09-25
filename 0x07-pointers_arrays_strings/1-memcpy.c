#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: pointer to the destination memory area
 * @src: pointer to thesource memory area
 * @n: number of bytes to be copied
 *
 * Return: pointer to dest
 */

char *_memcopy(char *dest, char *src, unsigned int n)
{
	char *original_dest = dest;

	while (n--)
	{
		*dest++ = *src++;
	}

	return (original_dest);
}

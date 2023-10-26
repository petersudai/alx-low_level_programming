#include "main.h"

/**
 * set_bit - sets value of a bit to 1 at a given index
 * @n: pointer to number in which to set bit
 * @index: index of bit to set
 *
 * Return: 1 if it works, or -1 on error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = *n | (1 << index);
	return (1);
}

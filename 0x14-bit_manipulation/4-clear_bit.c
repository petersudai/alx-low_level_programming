#include "main.h"

/**
 * clear_bit - sets value of a bit to 0 at given index
 * @n: pointer to number in which to clear the bit
 * @index: index of bit to clear
 *
 * Return: 1 if it works, -1 error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = *n & ~(1 << index);
	return (1);
}

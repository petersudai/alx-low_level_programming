#include "main.h"

/**
 * get_bit - returns value of a bit at given index
 * @n: number in which to get bit
 * @index: index of bit to retrieve
 *
 * Return: value of bit at index 'index', or -1 if error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}

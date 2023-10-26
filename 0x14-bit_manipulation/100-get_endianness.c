#include "main.h"

/**
 * get_endianness - checks the endianness of system
 *
 * Return: 0 if big endian and 1 if not
 */

int get_endianness(void)
{
	unsigned int check = 1;
	char *check_ptr = (char *)&check;

	return (*check_ptr);
}

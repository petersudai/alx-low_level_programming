#include "hash_tables.h"

/**
 * key_index - get index at which key and value pair should be stored
 * in the array of hsh table
 * @key: key string
 * @size: size of array of hash table
 *
 * Return: index at which key-value pair should be stored
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	if (key == NULL || size == 0)
		return (0);

	hash_value = hash_djb2(key);

	return (hash_value % size);
}

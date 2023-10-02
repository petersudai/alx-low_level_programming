#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates array of characters,initializes it with specific char
 *
 * @size: The size of the array to be created.
 * @c: The character used for initialization.
 *
 * Return: If size is 0 or if memory allocation fails, returns NULL.
 *         Otherwise, returns a pointer to the initialized array.
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);
	array = malloc(sizeof(char) * size);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;
	return (array);
}

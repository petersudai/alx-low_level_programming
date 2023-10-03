#include <stdlib.h>
#include "main.h"

/**
 * argstostr -  Entry point
 *@ac: int
 *@av: double pointer
 * Return: Always 0.
 */

char *argstostr(int ac, char **av)
{
	int total_length = 0;
	int i, j, index;
	char *result;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total_length++;
		total_length++;
	}
	result = malloc(total_length + 1);

	if (result == NULL)
		return (NULL);
	index = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			result[index++] = av[i][j];
		}
		result[index++] = '\n';
	}
	result[index] = '\0';

	return (result);
}

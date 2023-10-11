#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function
 * @argc: count
 * @argv: array
 *
 * Return: 0 ;
 */

int main(int argc, char *argv[])
{
	int bytes, i;
	unsigned char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	bytes = atoi(argv[1]);

	if (bytes <= 0)
	{
		printf("Error\n");
		return (2);
	}

	ptr = (unsigned char *)main;

	for (i = 0; i < bytes; i++)
	{
		printf("%02x", *ptr++);
		if (i != bytes - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}

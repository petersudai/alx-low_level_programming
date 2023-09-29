#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 * @argc: number of commandline arguments
 * @argv: array of command line arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc >= 1)
	{
		printf("%s\n", argv[0]);
	}
	return (0);
}

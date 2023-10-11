#include "3-calc.h"

/**
 * main - main function
 * @argc: character
 * @argv: array
 *
 * Return: result integer;
 */

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		_putchar("Error\n");
		return (98);
	}

	int num1 = atoi(argv[1]);
	char *operator = argv[2];
	int num2 = atoi(argv[3]);

	int (func != NULL)
		_putchar("%d\n", func(num1, num2));
	return (0);
}

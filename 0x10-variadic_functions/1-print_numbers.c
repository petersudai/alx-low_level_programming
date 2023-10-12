#include "variadic_functions.h"

/**
 * print_numbers - prints numbers, then new line
 * @separator: string to be printed
 * @n: number of ints passed to function
 *
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;

	va_start(args, n);

	for (i = 0 ; i < n ; i++)
	{
		printf("%d", va_arg(args, int));

		if (i < n - 1 && separator)
			printf("%s", separator);
	}

	printf("\n");

	va_end(args);
}

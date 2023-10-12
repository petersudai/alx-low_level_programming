#include "variadic_functions.h"

/**
 * print_strings - prints strings then a new line
 * @separator: string to be printed between the strings
 * @n: number of strings passed to function
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;
	const char *str;

	va_start(args, n);

	for (i = 0 ; i < n ; i++)
	{
		str = va_arg(args, const char *);

		if (str)
		{
			printf("%s", str);
		}
		else
		{
			printf("(nil)");
		}

		if (i < n - 1 && separator)
			printf("%s", separator);
	}
	printf("\n");

	va_end(args);
}

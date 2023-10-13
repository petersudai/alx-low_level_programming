#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * @...: arguments corresponding to the format specifiers
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead*
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *s;
	char c;
	float f;
	unsigned int i = 0;
	int n;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				c = va_arg(args, int), printf("%c", c);
				break;
			case 'i':
				n = va_arg(args, int), printf("%d", n);
				break;
			case 'f':
				f = va_arg(args, double), printf("%f", f);
				break;
			case 's':
				s = va_arg(args, char *);
				if (s)
					printf("%s", s);
				else
					printf("(nil)");
				break;
			default:
				i++;
				continue;
		}
		if (format[i + 1] != '\0')
		{
			char *sep = ", ";

			printf("%s", sep);
		}
		i++;
	}
	va_end(args), printf("\n");
}

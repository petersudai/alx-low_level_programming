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
	const char *ptr = format;
	char *str;
	float f;
	int i;
	int first_arg = 1;

	va_start(args, format);

	while (ptr != NULL && *ptr != '\0')
	{
		if (!first_arg)
			printf(", ");

		switch (*ptr)
		{
			case 'c':
				i = va_arg(args, int), printf("%c", i);
				break;
			case 'i':
				i = va_arg(args, int), printf("%d", i);
				break;
			case 'f':
				f = va_arg(args, double), printf("%f", f);
				break;
			case 's':
				str = va_arg(args, char *);
				if (str)
					printf("%s", str);
				else
					printf("(nil)");
				break;
			default:
				break;
		}
		if (*(ptr + 1) != '\0' && (*ptr == 'c' || *ptr == 'i' ||
					*ptr == 'f' || *ptr == 's'))
			printf(", ");
		ptr++;
	}
	va_end(args), printf("\n");
}

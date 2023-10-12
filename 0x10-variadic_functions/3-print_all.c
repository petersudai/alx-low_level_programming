#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *ptr = format;
	char *str;
	float f;
	int i;

	va_start(args, format);

	while (ptr != NULL && *ptr != '\0')
	{
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
		if (*(ptr + 1) && (*ptr == 'c' || *ptr == 'i' ||
				*ptr == 'f' || *ptr == 's'))
		{
			char *sep = ", ";

			printf("%s", sep);
		}
		ptr++;
	}
	va_end(args), printf("\n");
}

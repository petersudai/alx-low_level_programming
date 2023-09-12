#include "main.h"

/**
 * main - prints putchar
 *
 * Return: always 0 (success)
 */

int main(void)
{
	char text[] = "_putchar";
	int i = 0;

	while (i < 8)
	{
		_putchar(text[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}

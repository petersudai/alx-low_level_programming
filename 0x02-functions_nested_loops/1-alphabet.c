include "main"

/**
 * main - prints alphabet in lowercase
 *
 * Return: 0 always (success)
 */

void print_alphabet(void);
{
	char letter = "a";

	while (letter <= "z")
	{
		_putchar(letter);
		letter++;
	}

	_putchar('\n');
	return (0);
}

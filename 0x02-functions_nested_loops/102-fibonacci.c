#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int first = 1, second = 2, next, i;

	printf("%d, %d", first, second);

	for (i = 3; i <= 50; i++)
	{
		next = first + second;
		printf(", %d", next);
		first = second;
		second = next;
	}

	printf("\n");

	return (0);
}

#include <stdio.h>

/**
 * generateFibonacci - Generates the first n Fibonacci numbers and prints them.
 * @n: The number of Fibonacci numbers to generate.
 *
 * This function generates the first n Fibonacci numbers and prints them,
 * separated by commas.
 */
void generateFibonacci(int n)
{
	int first = 1, second = 2, next, i;

	for (i = 1; i <= n; i++)
	{
		printf("%d", first);

		if (i != n)
		{
			printf(", ");
		}

		next = first + second;
		first = second;
		second = next;
	}
	printf("\n");
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	generateFibonacci(50);
	return (0);
}

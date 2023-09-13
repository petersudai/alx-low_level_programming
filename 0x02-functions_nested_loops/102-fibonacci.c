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
	int fib[n];
	int i;

	fib[0] = 1;
	fib[1] = 2;

	for (i = 2; i < n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	for (i = 0; i < n; i++)
	{
		printf("%d", fib[i]);
		if (i != n - 1)
		{
			printf(", ");
		}
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

#include <stdio.h>
/**
 * find_multiples_sum - Calculates the sum of multiples of 3 or 5
 * @limit: The upper limit (excluded).
 *
 * Return: The sum of the multiples.
 */
int find_multiples_sum(int limit)
{
	int total_sum = 0;
	int i;

	for (i = 0; i < limit; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			total_sum += i;
	}

	return (total_sum);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	int limit = 1024;
	int result = find_multiples_sum(limit);

	printf("%d\n", result);

	return (0);
}

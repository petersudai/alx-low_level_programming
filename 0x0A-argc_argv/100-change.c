#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints minimum number of coins to make change for an amount of money
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 for error
 */

int main(int argc, char *argv[])
{
	int cents, num, i;
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins = sizeof(coins) / sizeof(coins[0]);

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	num = 0;

	for (i = 0 ; i < num_coins ; i++)
	{
		num += cents / coins[i];
		cents %= coins[i];
	}
	printf("%d\n", num);

	return (0);
}



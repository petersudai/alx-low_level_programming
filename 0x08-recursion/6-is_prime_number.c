#include "main.h"

/**
 * check_prime - function to recursively check for prime
 * @n: number to be checked
 * @div: divisor to check for divisibility
 *
 * Return: 1 if n is prime number, 0 if not
 */

int check_prime(int n, int div)
{
	if (div == n)
		return (1);
	if (n % div == 0)
		return (0);

	return (check_prime(n, div + 1));
}

/**
 * is_prime_number - function that returns 1 if prime number, otherwise 0
 * @n: number to be checked
 *
 * Return: 1 if prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (check_prime(n, 2));
}

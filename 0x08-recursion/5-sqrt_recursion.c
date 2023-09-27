#include "main.h"

/**
 * _sqrt - functionfor finding the square root recursively
 * @num: number to rooted
 * @root: the root of the number
 *
 * Return: square root or -1
 */

int _sqrt(int num, int root)
{
	if (root * root == num)
		return (root);
	if (root * root > num)
		return (-1);
	return (_sqrt(num, root + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: natural square root of n, or -1
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	return (_sqrt(n, 1));
}



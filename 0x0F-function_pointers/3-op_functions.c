#include "3-calc.h"

/**
 * op_add - returns sum of a and b
 * @a: first integer
 * @b: second integer
 *
 * Return: sum of a and b
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - returns difference of a and b
 * @a: first integer
 * @b: second integer
 *
 * Return: difference of a and b
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_div - returns result of dividing a by b
 * @a: first integer
 * @b: second integer
 *
 * Return: result of dividing a by b
 */

int op_div(int a, int b)
{
	if (b != 0)
		return (a / b);
	_putchar("Error\n");
	exit(100);

}

/**
 * op_mul - returns the product of a and b
 * @a: first integer
 * @b: second integer
 *
 * Return: product of a and b
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_mod - returns the remainder of the division of a by b
 * @a: first integer
 * @b: second integer
 *
 * Return: remainder of the division of a by b
 */

int op_mod(int a, int b)
{
	if (b != 0)
		return (a % b);
	_putchar("Error\n");
	exit(100);
}

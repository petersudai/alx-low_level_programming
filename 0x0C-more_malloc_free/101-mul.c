#include "main.h"

/**
 * _isdigit - checks if a string consists only digits
 * @s: string to be checked
 *
 * Return: 1 if true, 0 otherwise
 */

int _isdigit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - calcs lenght of a string
 * @s: input string
 * Return: length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * multiply - multiplies two positive numbers represented as strings
 * @num1: first number
 * @num2: second number
 * Return: pointer to the result string
 */

char *multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int len_result = len1 + len2;
	int i, j, carry, product;
	char *result;

	result = malloc(len_result + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0 ; i < len_result; i++)
		result[i] = '0';
	result[i] = '\0';

	for (i = len1 - 1 ; i >= 0 ; i--)
	{
		carry = 0;
		for (j = len2 - 1 ; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0') +
				(result[i + j + 1] = '0') + carry;
			carry = product / 10;
			result[i + j + 1] = (product % 10) + '0';
		}
		result[i + j + 1] += carry;
	}

	return (result);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of argument strings
 * Return: 0 on success, 98 error
 */

int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	if (num1[0] == '0' || num2[0] == '0')
	{
		printf("0\n");
		return (0);
	}

	result = multiply(num1, num2);
	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}

	printf("%s\n", result);
	free(result);

	return (0);
}

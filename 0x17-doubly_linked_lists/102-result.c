#include <stdio.h>

/**
 * is_palindrome - checks if  a number is a pailindrome
 * @num: the number to be checked
 *
 * Return: the number checked if it is a palindrome
 */

int is_palindrome(int num)
{
	int reversed = 0, original = num;
	
	while (num > 0)
	{
		reversed = reversed * 10 + num % 10;
		num /= 10;
	}
	
	return (original) == reversed;
}

/**
 * main - main function
 *
 * Return: void
 */

int main(void)
{
	int max_palindrome, i, j, product;
	FILE *file;

	max_palindrome = 0;

	for (i = 100; i < 1000; i++)
	{
		for (j = i; j < 1000; j++)
		{
			product = i * j;
			if (is_palindrome(product) && product > max_palindrome)
			{
				max_palindrome = product;
			}
		}
	}

		file = fopen("102-result", "w");
		if (file != NULL)
		{
			fprintf(file, "%d", max_palindrome);
			fclose(file);
		}
		return (0);
}

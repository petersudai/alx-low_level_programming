#include "main.h"

/**
 * check_palindrome - function to recursively check for palindrome
 * @s: string
 * @a: starting index
 * @z: ending index
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int check_palindrome(char *s, int a, int z)
{
	if (a >= z)
		return (1);
	if (s[a] != s[z])
		return (0);
	return (check_palindrome(s, a + 1, z - 1));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to be checked
 *
 * Return: 1 if s is a palindrome, 0 otherwise
 */

int is_palindrome(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (check_palindrome(s, 0, length - 1));
}

#include<stdio.h>

/**
 * main - a program that prints the alphabet in lowercase, followed by a new line.
 *
 * Return: always 0 (Success)
 */

int main(void)
{
	char i;

	for (i = 'a' ; i <= 'z'; i++)
		putchar(i);
	putchar('\n');
	return (0);
}

#include <stdio.h>

void print_message(void)__attribute__((constructor));

/**
 * print_message - prints message before main is executed
 */

void print_message(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon mmy back!\n");
}

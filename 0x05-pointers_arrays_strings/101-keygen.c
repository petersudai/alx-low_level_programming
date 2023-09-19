#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates keygen
 *
 * Return: 0 always
 */

#define PASSWORD_LENGTH 6

void generatePassword(char *password) {
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int i;

	for (i = 0 ; i < PASSWORD_LENGTH - 1 ; i++)
	{
		int index = rand() % (sizeof(charset) - 1);
		password[i] = charset[index];
	}

	password[PASSWORD_LENGTH - 1] = '\n';
}
int main() 
{
	char password[PASSWORD_LENGTH];
	srand(time(NULL));

	generatePassword(password);

	printf("Generate Password: %s", password);

	return (0);
}

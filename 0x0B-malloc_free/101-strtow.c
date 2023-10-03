#include <stdlib.h>

/**
 * get_word_length - Calculates the length of a word in a string.
 *
 * @str: The input string.
 *
 * Return: The length of the word.
 */
int get_word_length(char *str)
{
	int length = 0;

	while (*str != ' ' && *str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}

/**
 * copy_word - Copies a word from source to destination.
 *
 * @src: The source string.
 * @dest: The destination string.
 * @length: The length of the word to copy.
 *
 * Return: Nothing.
 */
void copy_word(char *src, char *dest, int length)
{
	int i;

	for (i = 0; i < length; i++)
		dest[i] = src[i];

	dest[length] = '\0';
}

/**
 * count_words - Counts the number of words in a string.
 *
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (*str == ' ')
			in_word = 0;
		else if (in_word == 0)
		{
			count++;
			in_word = 1;
		}
		str++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 *
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	int num_words, i, word_length;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);

	if (num_words == 0)
		return (NULL);

	words = (char **)malloc((num_words + 1) * sizeof(char *));

	if (words == NULL)
		return (NULL);

	i = 0;

	while (*str)
	{
		if (*str != ' ')
		{
			word_length = get_word_length(str);
			words[i] = (char *)malloc((word_length + 1) * sizeof(char));
			if (words[i] == NULL)
				return (NULL);
			copy_word(str, words[i], word_length);
			i++;
			str += word_length;
		}
		else
			str++;
	}

	words[i] = NULL;

	return (words);
}

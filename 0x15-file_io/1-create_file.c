#include "main.h"

/**
 * create_file - creates file with speciific content
 * @filename: name of file to create
 * @text_content: content to write on file
 *
 * Return: 1 success, -1 fail
 */

int create_file(const char *filename, char *text_content)
{
	int fd, write_result, close_result;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		write_result = write(fd, text_content, strlen(text_content));
		if (write_result == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close_result = close(fd);
	if (close_result == -1)
		return (-1);
	return (1);
}

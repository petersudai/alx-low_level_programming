#include "main.h"

/**
 * append_text_to_file - appends text to end of file
 * @filename: name of file
 * @text_content: string to be added at end of file
 *
 * Return: 1 success, -1 fail
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_result, close_result;
	off_t offset;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
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

	offset = lseek(fd, 0, SEEK_END);
	if (offset == (off_t)-1)
	{
		close(fd);
		return (-1);
	}

	close_result = close(fd);
	if (close_result == -1)
		return (-1);
	return (1);
}

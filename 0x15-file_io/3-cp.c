#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_error - prints an error message and exits with specified code
 * @message: error message format string
 * @file_name: name of file related to error
 * @exit_code: exit code to return
 */

void print_error(const char *message, const char *file_name, int exit_code)
{
	dprintf(STDERR_FILENO, message, file_name);
	exit(exit_code);
}

/**
 * copy_file - copies the content of one file to another
 * @from: the source file name
 * @to: destination file name
 */

void copy_file(const char *from, const char *to)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	fd_from = open(from, O_RDONLY);

	if (fd_from == -1)
	{
		print_error("Error; Can't read from %s\n", from, 98);
	}

	fd_to = open(to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error("Error: Can't write to %s\n", to, 99);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read || bytes_written == -1)
		{
			close(fd_from);
			close(fd_to);
			print_error("Error: Can't write to %s\n", to, 99);
		}
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		print_error("Error: Can't close fd %d\n", fd_from, 100);
	}
}
/**
 * main - entry point
 * @argc: number of command-line arguments
 * @argv: array of strings
 *
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from filr_to\n", argv[0]);
		return (97);
	}

	copy_file(argv[1], argv[2]);
	return (0);
}

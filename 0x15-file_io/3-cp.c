#include "main.h"
#define BUF_SIZE 1024

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0 (Success)
 **/
int main(int argc, char *argv[])
{
	int fd_from, fd_to, res_read, res_write, res_close;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = malloc(sizeof(char) * BUF_SIZE);
	if (!buffer)
		return (0);

	fd_from = open(argv[1], O_RDONLY);
	error_98(fd_from, buffer, argv[1]);
	fd_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	error_99(fd_to, buffer, argv[2]);

	do {
		res_read = read(fd_from, buffer, BUF_SIZE);
		if (res_read == 0)
			break;
		error_98(res_read, buffer, argv[1]);
		res_write = write(fd_to, buffer, res_read);
		error_99(res_write, buffer, argv[2]);
	} while (res_write >= BUF_SIZE);
	res_close = close(fd_to);
	error_100(res_close, buffer);
	res_close = close(fd_from);
	error_100(res_close, buffer);
	free(buffer);
	return (0);
}
/**
 * error_98 - Checks error 98
 * @fd: File descriptor
 * @buffer: Buffer
 * @filename: File name
 **/
void error_98(int fd, char *buffer, char *filename)
{
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		free(buffer);
		exit(98);
	}
}

/**
 * error_99 - Checks error 99
 * @fd: File descriptor
 * @buffer: Buffer
 * @filename: File name
 **/
void error_99(int fd, char *buffer, char *filename)
{
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		free(buffer);
		exit(99);
	}
}

/**
 * error_100 - Checks error 100
 * @fd: File descriptor
 * @buffer: Buffer
 **/
void error_100(int fd, char *buffer)
{
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd);
		free(buffer);
		exit(100);
	}
}

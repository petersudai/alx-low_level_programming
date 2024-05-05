#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error_message - Prints error message to standard error
 * @message: The error message to print
 */
void error_message(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *         (the ELF filename is expected at argv[1])
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;
	ssize_t bytes_read;

	if (argc != 2)
		error_message("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Error: Cannot open ELF file");

	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read == -1 || bytes_read != sizeof(header))
		error_message("Error: Cannot read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
		error_message("Error: Not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header.e_ident[i], i < EI_NIDENT - 1 ? ' ' : '\n');
	printf("  Class:                             %s\n",
	       header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
	       (header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "Unknown"));
	printf("  Data:                              %s\n",
	       header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	       (header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown"));
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
	       (header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
	        (header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
	         (header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
	          (header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
	           (header.e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM" :
	            (header.e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone (embedded) application" : "Unknown")))))));
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

	close(fd);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

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
 * print_magic - Prints the ELF magic bytes
 * @e_ident: Array containing the magic bytes
 */
void print_magic(unsigned char *e_ident)
{
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - Prints the ELF class
 * @e_ident: Array containing the magic bytes
 */
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("Unknown\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }
}

/**
 * print_data - Prints the ELF data encoding
 * @e_ident: Array containing the magic bytes
 */
void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("Unknown\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }
}

/**
 * print_version - Prints the ELF version
 * @e_ident: Array containing the magic bytes
 */
void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the ELF OS/ABI
 * @e_ident: Array containing the magic bytes
 */
void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone (embedded) application\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }
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
    Elf64_Ehdr ehdr;
    ssize_t bytes_read;

    if (argc != 2)
        error_message("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        error_message("Error: Cannot open ELF file");

    bytes_read = read(fd, &ehdr, sizeof(ehdr));
    if (bytes_read == -1 || bytes_read != sizeof(ehdr))
        error_message("Error: Cannot read ELF header");

    if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
        ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
        ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
        ehdr.e_ident[EI_MAG3] != ELFMAG3)
        error_message("Error: Not an ELF file");

    printf("ELF Header:\n");
    print_magic(ehdr.e_ident);
    print_class(ehdr.e_ident);
    print_data(ehdr.e_ident);
    print_version(ehdr.e_ident);
    print_osabi(ehdr.e_ident);

    close(fd);
    return (0);
}

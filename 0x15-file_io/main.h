#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void print_error(const char *message, const char *file_name, int exit_code);
void copy_file(const char *from, const char *to);
void error_98(int fd, char *buffer, char *filename);
void error_99(int fd, char *buffer, char *filename);
void error_100(int fd, char *buffer);

#endif

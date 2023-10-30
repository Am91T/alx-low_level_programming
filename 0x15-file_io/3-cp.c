#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void display_error(const char *message);

void copy_file_contents(int from, int to);

void close_files(int fd1, int fd2);

/**
* display_error - Display an error message and exit with a specific code.
* @message: The error message to display.
*/
void display_error(const char *message)
{
	dprintf(2, "%s", message);
	exit(1);
}

/**
* main - Entry point for the cp program.
* @ac: The number of arguments.
* @av: An array of arguments.
* Return: 0 on success, or an error code on failure.
*/
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
		display_error("Usage: cp file_from file_to\n");

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		display_error("Error: Can't read from file\n");

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		display_error("Error: Can't write to file\n");

	copy_file_contents(fd_from, fd_to);

	close_files(fd_from, fd_to);

	return (0);
}

/**
* copy_file_contents - Copy the contents of one file to another.
* @from: The source file descriptor.
* @to: The destination file descriptor.
*/
void copy_file_contents(int from, int to)
{
	char buffer[1024];

	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(from, buffer, sizeof(buffer)) > 0))
	{
		bytes_written = write(to, buffer, bytes_read);
		if (bytes_written == -1)
			display_error("Error: Can't write to file\n");
	}

	if (bytes_read == -1)
		display_error("Error: Can't read from file\n");
}

/**
* close_files - Close file descriptors.
* @fd1: The first file descriptor to close.
* @fd2: The second file descriptor to close.
*/
void close_files(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

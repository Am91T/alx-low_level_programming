#include "main.h"

/**
 * open_file - Opens the file with the given filename.
 * @filename: The name of the file to open.
 *
 * Return: The file descriptor on success, or -1 on failure.
 */
int open_file(const char *filename)
{
	int fd;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDONLY);
	return (fd);
}

/**
 * read_and_print - Reads from the file descriptor and prints to stdout.
 * @fd: The file descriptor.
 * @buffer: The buffer to store read data.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 */
ssize_t read_and_print(int fd, char *buffer, size_t letters)
{
	ssize_t read_bytes, write_bytes;

	read_bytes = read(fd, buffer, letters);
	if (read_bytes == -1)
		return (-1);

	write_bytes = write(STDOUT_FILENO, buffer, read_bytes);
	if (write_bytes == -1 || write_bytes != read_bytes)
		return (-1);

	return (read_bytes);
}

/**
 * read_textfile -Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print,
 *         0 on failure or if filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t result;

	fd = open_file(filename);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	result = read_and_print(fd, buffer, letters);

	close(fd);
	free(buffer);

	return (result);
}

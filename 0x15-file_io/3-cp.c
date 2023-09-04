#include "main.h"

/**
 * print_usage_error - print usage error message and exit
 * @prog_name: the name of the program
 */
void print_usage_error(const char *prog_name)
{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", prog_name);
	exit(97);
}

/**
 * print_read_error - print read error message and exit
 * @filename: the name of the file that couldn't be read
 */
void print_read_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * print_write_error - print write error message and exit
 * @filename: the name of the file that couldn't be written
 */
void print_write_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
}

/**
 * print_close_error - print close error message and exit
 * @fd: the file descriptor that couldn't be closed
 */
void print_close_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - entry point for the cp program
 * @argc: the number of command-line arguments
 * @argv: an array of command-line arguments
 *
 * Return: 0 on success, or exit with a specific code on failure
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, read_result, write_result;
	char buffer[1024];

	if (argc != 3)
		print_usage_error(argv[0]);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		print_read_error(argv[1]);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
		print_write_error(argv[2]);

	while ((read_result = read(file_from, buffer, 1024)) > 0)
	{
		write_result = write(file_to, buffer, read_result);
		if (write_result == -1)
			print_write_error(argv[2]);
	}

	if (read_result == -1)
		print_read_error(argv[1]);

	if (close(file_from) == -1)
		print_close_error(file_from);

	if (close(file_to) == -1)
		print_close_error(file_to);

	return (0);
}

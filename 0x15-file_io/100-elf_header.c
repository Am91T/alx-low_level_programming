#include "main.h"

/**
 * print_error_and_exit - Print an error message and exit.
 * @message: The error message to print.
 */
void print_error_and_exit(const char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(98);
}

/**
 * open_and_check_elf_file - Open an ELF file and return the file descriptor.
 * @filename: The name of the ELF file to open.
 * Return: The file descriptor or -1 on failure.
 */
int open_and_check_elf_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		print_error_and_exit("Cannot open file");
	}
	return (fd);
}

/**
 * read_elf_header - Read the ELF header and validate it.
 * @fd: The file descriptor of the ELF file.
 * @header: A pointer to the ELF header structure.
 */
void read_elf_header(int fd, Elf64_Ehdr *header)
{
	ssize_t result = read(fd, header, sizeof(Elf64_Ehdr));

	if (result != (ssize_t)sizeof(Elf64_Ehdr) ||
			memcmp(header->e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_error_and_exit("Not a valid ELF file");
	}
}

/**
 * print_elf_header_info - Print the ELF header information.
 * @header: A pointer to the ELF header structure.
 */
void print_elf_header_info(const Elf64_Ehdr *header)
{
	printf("ELF Header:\n\tMagic:\t\t");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x%c", header->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
	}

	printf("\tClass:\t\t\t%s\n", get_elf_info(header->e_ident[EI_CLASS]));
	printf("\tData:\t\t\t%s\n", get_elf_info(header->e_ident[EI_DATA]));
	printf("\tVersion:\t\t%u (current)\n", header->e_version);
	printf("\tOS/ABI:\t\t\t%s\n", get_elf_info(header->e_ident[EI_OSABI]));
	printf("\tABI Version:\t\t%u\n", header->e_ident[EI_ABIVERSION]);
	printf("\tType:\t\t\t%s (%s)\n", get_elf_info(header->e_type),
		   get_elf_info(9 + header->e_type));
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, non-zero on failure.
 *
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error_and_exit("Usage: elf_header elf_filename");
	}

	int fd = open_and_check_elf_file(argv[1]);
	Elf64_Ehdr header;
	read_elf_header(fd, &header);

	print_elf_header_info(&header);

	close(fd);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
* error_exit - print an error message and exit with the given status code
* @msg: the error message
* @status: the exit status code
*/
void error_exit(const char *msg, int status)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(status);
}

/**
* print_elf_header - print the ELF header information
* @header: pointer to the ELF header structure
*/
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n",
		header->e_ident[0], header->e_ident[1], header->e_ident[2],
		header->e_ident[3], header->e_ident[4], header->e_ident[5],
		header->e_ident[6], header->e_ident[7], header->e_ident[8],
		header->e_ident[9], header->e_ident[10], header->e_ident[11],
		header->e_ident[12], header->e_ident[13], header->e_ident[14],
		header->e_ident[15]);
	printf("  Class:                             ");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
}

/**
* main - entry point for the elf_header program
* @argc: the number of command-line arguments
* @argv: an array of command-line arguments
*
* Return: 0 on success, or exit with a specific code on failure
*/
int main(int argc, char *argv[])
{
	int fd;

	Elf64_Ehdr header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename", 98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Cannot read file", 98);

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit("Error: Cannot read ELF header", 98);

	if (lseek(fd, 0, SEEK_SET) == -1)
		error_exit("Error: Cannot seek to beginning of file", 98);

	print_elf_header(&header);

	close(fd);

	return (0);
}

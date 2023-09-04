#include "main.h"

/**
 * print_error - Print an error message and exit.
 * @message: The error message to print.
 */
void print_error(const char *message)
{
        dprintf(STDERR_FILENO, "Error: %s\n", message);
        exit(98);
}

/**
 * check_read - Check if a read operation was successful.
 * @fd: The file descriptor.
 * @buf: The buffer to read into.
 * @size: The size to read.
 */
void check_read(int fd, void *buf, size_t size)
{
        ssize_t result;

        result = read(fd, buf, size);

        if (result != (ssize_t)size)
        {
                print_error("Cannot read ELF header");
        }
}

/**
 * get_elf_info - Get information about the ELF format.
 * @index: The index of the information to retrieve.
 * Return: A string describing the ELF information.
 */
char *get_elf_info(int index)
{
        const char *elf_info[] = {
                "ELF32",
                "ELF64",
                "2's complement, little endian",
                "2's complement, big endian",
                "UNIX - System V",
                "HP-UX",
                "NetBSD",
                "Linux",
                "Solaris",
                "REL (Relocatable file)",
                "EXEC (Executable file)",
                "DYN (Shared object file)",
                "CORE (Core file)"
        };

        return (strdup((index >= 0 && index <= 12) ? elf_info[index] : "<unknown>"));
}

/**
 * open_elf_file - Open an ELF file and return the file descriptor.
 * @filename: The name of the ELF file to open.
 * Return: The file descriptor or -1 on failure.
 */
int open_elf_file(const char *filename)
{
        int fd = open(filename, O_RDONLY);

        if (fd == -1)
        {
                print_error("Cannot open file");
        }
        return (fd);
}

/**
 * read_elf_header - Read the ELF header into the provided structure.
 * @fd: The file descriptor of the ELF file.
 * @header: A pointer to the ELF header structure.
 */
void read_elf_header(int fd, Elf64_Ehdr *header)
{
        check_read(fd, header, sizeof(Elf64_Ehdr));
        if (memcmp(header->e_ident, ELFMAG, SELFMAG) != 0)
        {
                print_error("Not an ELF file");
        }
}

/**
 * print_elf_header - Print the ELF header information.
 * @header: A pointer to the ELF header structure.
 */
void print_elf_header(const Elf64_Ehdr *header)
{
        int i;

        printf("ELF Header:\n\tMagic:\t\t");
        for (i = 0; i < EI_NIDENT; i++)
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
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
	print_error("Usage: elf_header elf_filename");
	}

	fd = open_elf_file(argv[1]);
	read_elf_header(fd, &header);
	print_elf_header(&header);

	close(fd);
	return (0);
}

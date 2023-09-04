#include "main.h"

void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(98);
}

void check_read(int fd, void *buf, size_t size)
{
	ssize_t result;
	result = read(fd, buf, size);
	if (result != (ssize_t)size)
	{
		print_error("Cannot read ELF header");
	}
}

char *get_elf_info(int index)
{
	char *info;
	switch (index)
	{
	case 0:
		info = strdup("ELF32");
		break;
	case 1:
		info = strdup("ELF64");
		break;
	case 2:
		info = strdup("2's complement, little endian");
		break;
	case 3:
		info = strdup("2's complement, big endian");
		break;
	case 4:
		info = strdup("UNIX - System V");
		break;
	case 5:
		info = strdup("HP-UX");
		break;
	case 6:
		info = strdup("NetBSD");
		break;
	case 7:
		info = strdup("Linux");
		break;
	case 8:
		info = strdup("Solaris");
		break;
	case 9:
		info = strdup("REL (Relocatable file)");
		break;
	case 10:
		info = strdup("EXEC (Executable file)");
		break;
	case 11:
		info = strdup("DYN (Shared object file)");
		break;
	case 12:
		info = strdup("CORE (Core file)");
		break;
	default:
		info = strdup("<unknown>");
	}
	return (info);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;
	int i; /* Declare 'i' outside of the for loop */
	int class_info_index;
	int data_info_index;
	int osabi_info_index;
	int type_info_index;
	char *class_info;
	char *data_info;
	char *osabi_info;
	char *type_info;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	class_info_index = header.e_ident[EI_CLASS];
	class_info = get_elf_info(class_info_index);

	data_info_index = header.e_ident[EI_DATA];
	data_info = get_elf_info(data_info_index);

	osabi_info_index = header.e_ident[EI_OSABI];
	osabi_info = get_elf_info(osabi_info_index);

	type_info_index = header.e_type;
	type_info = get_elf_info(type_info_index);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Cannot open file");
	}

	check_read(fd, &header, sizeof(header));

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_error("Not an ELF file");
	}

	printf("ELF Header:\n\tMagic:\t\t");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x%c", header.e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
	}

	printf("\tClass:\t\t\t%s\n", class_info);
	printf("\tData:\t\t\t%s\n", data_info);
	printf("\tVersion:\t\t%u (current)\n", header.e_version);
	printf("\tOS/ABI:\t\t\t%s\n", osabi_info);
	printf("\tABI Version:\t\t%u\n", header.e_ident[EI_ABIVERSION]);
	printf("\tType:\t\t\t%s (%s)\n", type_info, get_elf_info(9 + header.e_type));
	printf("\tEntry point address:\t0x%lx\n", (unsigned long)header.e_entry);

	free(class_info);
	free(data_info);
	free(osabi_info);
	free(type_info);

	close(fd);
	return (0);
}

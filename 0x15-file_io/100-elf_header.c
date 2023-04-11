#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(const char *msg);
void print_elf_header(Elf64_Ehdr *header);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Error opening file");
        return 98;
    }

    Elf64_Ehdr header;
    ssize_t n = read(fd, &header, sizeof(header));
    if (n != sizeof(header)) {
        print_error("Error reading ELF header");
        close(fd);
        return 98;
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}

void print_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}

void print_elf_header(Elf64_Ehdr *header) {
    printf("ELF Header:\n");

    // Magic
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    // Class
    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
            break;
    }

    // Data
    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
            break;
    }

    // Version
    printf("  Version:                           %d", header->e_ident[EI_VERSION]);
    switch (header->e_ident[EI_VERSION]) {
        case EV_NONE:
            printf(" (invalid)\n");
            break;
        case EV_CURRENT:
            printf(" (current)\n");
            break;
        default:
            printf("\n");
            break;
    }

    // OS/ABI
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case
    }
    

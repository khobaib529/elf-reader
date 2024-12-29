#include "elf_parser.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "fcntl.h"
#include "unistd.h"

static inline void parse_elf_ehdr(elf_data_t* elf_data) {
  elf_data->elf_ehdr = malloc(sizeof(Elf_Ehdr));
  int bytes_read = pread(elf_data->fd, elf_data->elf_ehdr, sizeof(Elf_Ehdr), 0);
  if (bytes_read == -1) {
    fprintf(stderr, "Error: Failed to read ELF header: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (bytes_read != sizeof(Elf_Ehdr)) {
    fprintf(stderr,
            "Error: Incomplete read of ELF header (expected %zu bytes, got %d "
            "bytes)\n",
            sizeof(Elf_Ehdr), bytes_read);
    exit(EXIT_FAILURE);
  }
}

static inline void parse_elf_phdr(elf_data_t* elf_data) {
  Elf_Ehdr* elf_ehdr = elf_data->elf_ehdr;
  int byte_to_read = elf_ehdr->e_phentsize * elf_ehdr->e_phnum;
  elf_data->elf_phdr = malloc(byte_to_read);
  int bytes_read =
      pread(elf_data->fd, elf_data->elf_phdr, byte_to_read, elf_ehdr->e_phoff);
  if (bytes_read == -1) {
    fprintf(stderr, "Error: Failed to read program headers: %s\n",
            strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (bytes_read != byte_to_read) {
    fprintf(stderr,
            "Error: Incomplete read of program headers (expected %d bytes, got "
            "%d bytes)\n",
            byte_to_read, bytes_read);
    exit(EXIT_FAILURE);
  }
}

void parse_elf(elf_data_t* elf_data) {
  parse_elf_ehdr(elf_data);
  parse_elf_phdr(elf_data);
}

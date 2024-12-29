#include "elf_reader.h"

#include <stdio.h>

// Function to print ELF header to a given file descriptor
void print_elf_ehdr(int fd, Elf_Ehdr* elf_ehdr) {
  dprintf(fd, "ELF Header:\n");
  dprintf(fd, "  e_ident:       ");
  for (int i = 0; i < EI_NIDENT; ++i) {
    dprintf(fd, "%02x ", elf_ehdr->e_ident[i]);
  }
  dprintf(fd, "\n");
  // Will be implemented later
}

#ifndef ELF_READER_H_
#define ELF_READER_H_

#include <stdlib.h>

#include "elf_parser.h"

typedef struct {
  char* data;
  size_t size;
} slice_t;

void print_elf_ehdr(int fd, Elf_Ehdr* elf_ehdr);
void print_elf_phdr(int fd, elf_data_t* elf_data);
#endif  // ELF_READER_H_

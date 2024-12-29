#ifndef ELF_PARSER_H_
#define ELF_PARSER_H_

#include <stdlib.h>

#include "elf_types.h"

typedef struct elf_data {
  int fd;
  Elf_Ehdr* elf_ehdr;
  Elf_Phdr* elf_phdr;
  Elf_Shdr* elf_shdr;
} elf_data_t;

void parse_elf(elf_data_t* elf_data);

#endif  // ELF_PARSER_H_
#include "elf_reader.h"

#include <stdio.h>

static void print_elf32_ehdr(int fd, Elf32_Ehdr* elf32_ehdr) {
  dprintf(fd, "Elf32_Ehdr {\n");

  // Print e_ident as hexadecimal values
  dprintf(fd, "  e_ident:       ");
  for (int i = 0; i < EI_NIDENT; ++i) {
    dprintf(fd, "%02x ", elf32_ehdr->e_ident[i]);
  }
  dprintf(fd, "\n");

  dprintf(fd, "  e_type:        ");
  dprintf(fd, "%04x\n", elf32_ehdr->e_type);
  dprintf(fd, "  e_machine:     ");
  dprintf(fd, "%04x\n", elf32_ehdr->e_machine);
  dprintf(fd, "  e_version:     ");
  dprintf(fd, "%08x\n", elf32_ehdr->e_version);
  dprintf(fd, "  e_entry:       ");
  dprintf(fd, "%08x\n", elf32_ehdr->e_entry);
  dprintf(fd, "  e_phoff:       ");
  dprintf(fd, "%08x\n", elf32_ehdr->e_phoff);
  dprintf(fd, "  e_shoff:       ");
  dprintf(fd, "%08x\n", elf32_ehdr->e_shoff);
  dprintf(fd, "  e_flags:       ");
  dprintf(fd, "%08x\n", elf32_ehdr->e_flags);
  dprintf(fd, "  e_ehsize:      ");
  dprintf(fd, "%04x\n", elf32_ehdr->e_ehsize);
  dprintf(fd, "  e_phentsize:   ");
  dprintf(fd, "%04x\n", elf32_ehdr->e_phentsize);
  dprintf(fd, "  e_phnum:       ");
  dprintf(fd, "%04x\n", elf32_ehdr->e_phnum);
  dprintf(fd, "  e_shentsize:   ");
  dprintf(fd, "%04x\n", elf32_ehdr->e_shentsize);
  dprintf(fd, "  e_shnum:       ");
  dprintf(fd, "%04x\n", elf32_ehdr->e_shnum);
  dprintf(fd, "  e_shstrndx:    ");
  dprintf(fd, "%04x\n", elf32_ehdr->e_shstrndx);

  dprintf(fd, "}\n");
}

static void print_elf64_ehdr(int fd, Elf64_Ehdr* elf64_ehdr) {
  dprintf(fd, "Elf64_Ehdr {\n");

  dprintf(fd, "  e_ident:       ");
  for (int i = 0; i < EI_NIDENT; ++i) {
    dprintf(fd, "%02x ", elf64_ehdr->e_ident[i]);
  }
  dprintf(fd, "\n");

  dprintf(fd, "  e_type:        ");
  dprintf(fd, "%04x\n", elf64_ehdr->e_type);
  dprintf(fd, "  e_machine:     ");
  dprintf(fd, "%04x\n", elf64_ehdr->e_machine);
  dprintf(fd, "  e_version:     ");
  dprintf(fd, "%08x\n", elf64_ehdr->e_version);
  dprintf(fd, "  e_entry:       ");
  dprintf(fd, "%016lx\n", elf64_ehdr->e_entry);
  dprintf(fd, "  e_phoff:       ");
  dprintf(fd, "%016lx\n", elf64_ehdr->e_phoff);
  dprintf(fd, "  e_shoff:       ");
  dprintf(fd, "%016lx\n", elf64_ehdr->e_shoff);
  dprintf(fd, "  e_flags:       ");
  dprintf(fd, "%08x\n", elf64_ehdr->e_flags);
  dprintf(fd, "  e_ehsize:      ");
  dprintf(fd, "%04x\n", elf64_ehdr->e_ehsize);
  dprintf(fd, "  e_phentsize:   ");
  dprintf(fd, "%04x\n", elf64_ehdr->e_phentsize);
  dprintf(fd, "  e_phnum:       ");
  dprintf(fd, "%04x\n", elf64_ehdr->e_phnum);
  dprintf(fd, "  e_shentsize:   ");
  dprintf(fd, "%04x\n", elf64_ehdr->e_shentsize);
  dprintf(fd, "  e_shnum:       ");
  dprintf(fd, "%04x\n", elf64_ehdr->e_shnum);
  dprintf(fd, "  e_shstrndx:    ");
  dprintf(fd, "%04x\n", elf64_ehdr->e_shstrndx);

  dprintf(fd, "}\n");
}

void print_elf_ehdr(int fd, elf_data_t* elf_data) {
  Elf_Ehdr* elf_ehdr = elf_data->elf_ehdr;
#if defined(__x86_64__)  // If compiling for a 64-bit architecture
  print_elf64_ehdr(fd, elf_ehdr);
#elif defined(__i386__)
  print_elf32_ehdr(fd, elf_ehdr);
#else
#error "Unsupported architecture"
#endif  // __x86_64__
}

static void print_elf32_phdr(int fd, Elf32_Phdr* elf32_phdr) {
  dprintf(fd, "Elf32_Phdr {\n");

  dprintf(fd, "  p_type:        ");
  dprintf(fd, "%08x\n", elf32_phdr->p_type);
  dprintf(fd, "  p_offset:      ");
  dprintf(fd, "%08x\n", elf32_phdr->p_offset);
  dprintf(fd, "  p_vaddr:       ");
  dprintf(fd, "%08x\n", elf32_phdr->p_vaddr);
  dprintf(fd, "  p_paddr:       ");
  dprintf(fd, "%08x\n", elf32_phdr->p_paddr);
  dprintf(fd, "  p_filesz:      ");
  dprintf(fd, "%08x\n", elf32_phdr->p_filesz);
  dprintf(fd, "  p_memsz:       ");
  dprintf(fd, "%08x\n", elf32_phdr->p_memsz);
  dprintf(fd, "  p_flags:       ");
  dprintf(fd, "%08x\n", elf32_phdr->p_flags);
  dprintf(fd, "  p_align:       ");
  dprintf(fd, "%08x\n", elf32_phdr->p_align);

  dprintf(fd, "}\n");
}

static void print_elf64_phdr(int fd, Elf64_Phdr* elf64_phdr) {
  dprintf(fd, "Elf64_Phdr {\n");

  dprintf(fd, "  p_type:        ");
  dprintf(fd, "%08lx\n", elf64_phdr->p_type);
  dprintf(fd, "  p_flags:       ");
  dprintf(fd, "%08lx\n", elf64_phdr->p_flags);
  dprintf(fd, "  p_offset:      ");
  dprintf(fd, "%016lx\n", elf64_phdr->p_offset);
  dprintf(fd, "  p_vaddr:       ");
  dprintf(fd, "%016lx\n", elf64_phdr->p_vaddr);
  dprintf(fd, "  p_paddr:       ");
  dprintf(fd, "%016lx\n", elf64_phdr->p_paddr);
  dprintf(fd, "  p_filesz:      ");
  dprintf(fd, "%016lx\n", elf64_phdr->p_filesz);
  dprintf(fd, "  p_memsz:       ");
  dprintf(fd, "%016lx\n", elf64_phdr->p_memsz);
  dprintf(fd, "  p_align:       ");
  dprintf(fd, "%016lx\n", elf64_phdr->p_align);

  dprintf(fd, "}\n");
}

void print_elf_phdr(int fd, elf_data_t* elf_data) {
  Elf_Ehdr* elf_phdr = elf_data->elf_phdr;
  int i = 0;
  while (i != elf_data->elf_ehdr->e_phnum) {
#if defined(__x86_64__)  // If compiling for a 64-bit architecture
    print_elf64_phdr(fd, elf_phdr);
#elif defined(__i386__)
    print_elf32_phdr(fd, elf_phdr);
#else
#error "Unsupported architecture"
#endif  // __x86_64__
    ++i;
    ++elf_phdr;
  }
}

#ifndef ELF_TYPES_H_
#define ELF_TYPES_H_

#include <elf.h>

// Define Elf_Ehdr based on the architecture (32-bit or 64-bit)
#if defined(__x86_64__)  // If compiling for a 64-bit architecture
typedef Elf64_Ehdr Elf_Ehdr;
typedef Elf64_Phdr Elf_Phdr;
typedef Elf64_Shdr Elf_Shdr;
typedef Elf64_Sym Elf_Sym;
#elif defined(__i386__)
typedef Elf32_Ehdr Elf_Ehdr;
typedef Elf32_Phdr Elf_Phdr;
typedef Elf32_Shdr Elf_Shdr;
typedef Elf32_Sym Elf_Sym;
#else
#error "Unsupported architecture"
#endif  // __x86_64__

#endif  // ELF_TYPES_H_
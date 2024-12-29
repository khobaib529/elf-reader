#include "cmd_arg_parser.h"

#include <stdio.h>
#include <stdlib.h>

#include "string.h"

void parse_cmd_args(int argc, char* argv[], options_t* options) {
  // Iterate through each argument and set the corresponding flags
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--all") == 0) {
      options->all = 1;
    } else if (strcmp(argv[i], "-h") == 0 ||
               strcmp(argv[i], "--file-header") == 0) {
      options->file_headers = 1;
    } else if (strcmp(argv[i], "-l") == 0 ||
               strcmp(argv[i], "--program-headers") == 0 ||
               strcmp(argv[i], "--segments") == 0) {
      options->program_headers = 1;
    } else if (strcmp(argv[i], "-S") == 0 ||
               strcmp(argv[i], "--section-headers") == 0 ||
               strcmp(argv[i], "--sections") == 0) {
      options->section_headers = 1;
    } else {
      if (options->elf_file_path == NULL) {
        options->elf_file_path = argv[i];
      } else {
        fprintf(stderr, "Error: Multiple ELF file paths provided.\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
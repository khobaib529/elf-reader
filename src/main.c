#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cmd_arg_parser.h"
#include "elf_parser.h"
#include "elf_reader.h"

int main(int argc, char *argv[]) {
  // Parse command line arguments
  options_t options;
  memset(&options, 0, sizeof(options));
  parse_cmd_args(argc, argv, &options);

  // Parse ELF file
  elf_data_t elf_data;
  memset(&elf_data, 0, sizeof(elf_data_t));

  if (options.elf_file_path == NULL) {
    fprintf(stderr, "No file given");
  }

  elf_data.fd = open(options.elf_file_path, O_RDONLY);
  if (elf_data.fd == -1) {
    fprintf(stderr, "Error opening file '%s': %s\n", options.elf_file_path,
            strerror(errno));
    return EXIT_FAILURE;
  }

  parse_elf(&elf_data);

  if (options.file_headers == 1) {
    print_elf_ehdr(STDOUT_FILENO, &elf_data);
  }
  if (options.program_headers == 1) {
    print_elf_phdr(STDOUT_FILENO, &elf_data);
  }

  return 0;
}

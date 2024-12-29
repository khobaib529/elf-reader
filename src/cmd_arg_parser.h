#ifndef CMD_ARG_PARSER_H_
#define CMD_ARG_PARSER_H_

#include <stdint.h>

typedef struct options {
  uint8_t all;
  uint8_t file_headers;
  uint8_t program_headers;
  uint8_t section_headers;
  uint8_t section_groups;
  uint8_t section_details;
  uint8_t syms;
  uint8_t dyn_syms;
  uint8_t lto_syms;
  char* elf_file_path;
} options_t;

void parse_cmd_args(int argc, char* argv[], options_t* options);

#endif  // CMD_ARG_PARSER_H_

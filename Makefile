# Target executable
TARGET = elf_reader

# Source and object files
SRC = src/elf_reader.c src/cmd_arg_parser.c src/main.c src/elf_parser.c
HDRS = src/cmd_arg_parser.h src/elf_reader.h src/elf_types.h src/elf_parser.h src/elf_types.h

# Compiler flags
CFLAGS = -Wall

# Default target
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(SRC)
	gcc $(CFLAGS) $(SRC) -o $(TARGET)

# Clean the build (delete object and executable files)
clean:
	rm $(TARGET)

format:
	clang-format -i --style="Google" $(SRC) $(HDRS)

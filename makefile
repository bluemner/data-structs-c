OUTPUT_DIR= bin
COMPILER = gcc
FLAGS =-W -ggdb 
SOURCE_DIR = source/
INCLUDES_DIR = includdes/

all: stack

stack: $(SOURCE_DIR)stack.c | make_dir
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)stack.c -o $(OUTPUT_DIR)/stack.o
list: $(SOURCE_DIR)list.c | make_dir
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)list.c -o $(OUTPUT_DIR)/list.o
make_dir:
	mkdir -p $(OUTPUT_DIR)
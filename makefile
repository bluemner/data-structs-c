OUTPUT_DIR= bin
COMPILER = gcc
FLAGS =-W -ggdb 
SOURCE_DIR = source/
INCLUDES_DIR = includes/
TEST_DIR = test/
all: stack

stack: $(SOURCE_DIR)stack.c | make_dir
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)stack.c -o $(OUTPUT_DIR)/stack.o
list: $(SOURCE_DIR)list.c | make_dir
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)list.c -o $(OUTPUT_DIR)/list.o
queue: $(SOURCE_DIR)queue.c | make_dir
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)queue.c -o $(OUTPUT_DIR)/queue.o
queue_test: $(SOURCE_DIR)queue.c $(TEST_DIR)queue_test.c  | make_dir
	$(COMPILER) $(FLAGS) -I$(INCLUDES_DIR) $(SOURCE_DIR)queue.c $(TEST_DIR)queue_test.c -o $(OUTPUT_DIR)/queue_test.o
make_dir:
	mkdir -p $(OUTPUT_DIR)
OUTPUT_DIR= bin
COMPILER = gcc
FLAGS =-W -ggdb 
SOURCE_DIR = source/
INCLUDES_DIR = includes/
TEST_DIR = test/
all: stack list queue tree

stack: $(SOURCE_DIR)stack.c | make_dir
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)stack.c -o $(OUTPUT_DIR)/stack.o
list: $(SOURCE_DIR)list.c | make_dir
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)list.c -o $(OUTPUT_DIR)/list.o
queue: $(SOURCE_DIR)queue.c | make_dir
	$(COMPILER) $(FLAGS) -I$(INCLUDES_DIR) $(SOURCE_DIR)queue.c -o $(OUTPUT_DIR)/queue.o
test_queue: $(SOURCE_DIR)queue.c $(TEST_DIR)test_queue.c  | make_dir
	$(COMPILER) $(FLAGS) -I$(INCLUDES_DIR) $(SOURCE_DIR)queue.c $(TEST_DIR)test_queue.c -o $(OUTPUT_DIR)/test_queue.o
tree: $(SOURCE_DIR)tree.c | make_dir
	$(COMPILER) $(FLAGS) -I$(INCLUDES_DIR) $(SOURCE_DIR)tree.c -o $(OUTPUT_DIR)/tree.o
test_tree: $(SOURCE_DIR)tree.c $(TEST_DIR)test_tree.c  | make_dir
	$(COMPILER) $(FLAGS) -I$(INCLUDES_DIR) $(SOURCE_DIR)tree.c $(TEST_DIR)test_tree.c -o $(OUTPUT_DIR)/test_tree.o
test_merge_sort: $(SOURCE_DIR)merge_sort.c $(TEST_DIR)test_merge_sort.c  | make_dir
	$(COMPILER) $(FLAGS) -I$(INCLUDES_DIR) $(SOURCE_DIR)merge_sort.c $(TEST_DIR)test_merge_sort.c -o $(OUTPUT_DIR)/test_merge_sort.o
make_dir:
	mkdir -p $(OUTPUT_DIR)

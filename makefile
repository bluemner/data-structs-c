OUTPUT_DIR:=bin
COMPILER:= gcc
FLAGS:=-Wall -g -ggdb -fsanitize=address
LIBRARY_FLAGS:=-c -fPIC -shared
# Folders 
SOURCE_DIR:= source/
HEADERS_DIR:= include/
TEST_DIR:= test/
# Includes
INCLUDES:=-I $(HEADERS_DIR)

all: stack list queue tree
########################################################################################
stack: $(SOURCE_DIR)stack.c | make_dir
	$(COMPILER) $(FLAGS)  $(SOURCE_DIR)stack.c -o $(OUTPUT_DIR)/stack.o
########################################################################################

list: $(SOURCE_DIR)list.c | make_dir
	$(COMPILER) $(FLAGS) $(LIBRARY_FLAGS) $(INCLUDES) $(SOURCE_DIR)list.c -o $(OUTPUT_DIR)/liblist.so
test_list: list $(TEST_DIR)test_list.c  | make_dir
	$(COMPILER) $(FLAGS) $(INCLUDES) $(OUTPUT_DIR)/liblist.so $(TEST_DIR)test_list.c -o $(OUTPUT_DIR)/test_list.o
########################################################################################
queue: $(SOURCE_DIR)queue.c | make_dir
	$(COMPILER) $(FLAGS) $(LIBRARY_FLAGS) $(INCLUDES) $(SOURCE_DIR)queue.c -o $(OUTPUT_DIR)/libqueue.so
test_queue: queue $(TEST_DIR)test_queue.c  | make_dir
	$(COMPILER) $(FLAGS) $(INCLUDES) $(OUTPUT_DIR)/libqueue.so $(TEST_DIR)test_queue.c -o $(OUTPUT_DIR)/test_queue.o
########################################################################################
tree: $(SOURCE_DIR)tree.c | make_dir
	$(COMPILER) $(FLAGS) $(INCLUDES) $(SOURCE_DIR)tree.c -o $(OUTPUT_DIR)/tree.so
test_tree: $(SOURCE_DIR)tree.c $(TEST_DIR)test_tree.c  | make_dir
	$(COMPILER) $(FLAGS) $(INCLUDES) $(SOURCE_DIR)tree.c $(TEST_DIR)test_tree.c -o $(OUTPUT_DIR)/test_tree.o
########################################################################################
test_merge_sort: $(SOURCE_DIR)merge_sort.c $(TEST_DIR)test_merge_sort.c | make_dir
	$(COMPILER) $(FLAGS) $(INCLUDES) $(SOURCE_DIR)merge_sort.c $(TEST_DIR)test_merge_sort.c -o $(OUTPUT_DIR)/test_merge_sort.o
########################################################################################
make_dir:
	mkdir -p $(OUTPUT_DIR)

clean:
	rm $(OUTPUT_DIR)/*.so
	rm $(OUTPUT_DIR)/*.o
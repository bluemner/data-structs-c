#ifndef __DATA_STRUCTS_LIST_H__
#define __DATA_STRUCTS_LIST_H__
#include <stdio.h>
#include <stdlib.h>

typedef void* pointer;
typedef struct list_node_s list_node;

typedef struct list_node_s{
   pointer  value;
   list_node* source;
   list_node* target;
} list_node;

typedef struct list_s  {
   size_t count;
   list_node* last;
   list_node* root;
} list ;


typedef enum list_print_modes
{
   LIST_PRINT_VERBOSE = 0,
   LIST_PRINT_FAST = 1
} list_print_mode;


/**
 * Creates a double linked list 
 * becuse double or nothing...
 * 
 * @note
 *      a root node is placed at the start
 *         | Root    |
 * NULL <--- Source  |
 *         | Target -----> NULL
 * 
 * @param[out] l The list your are looking for or have just wasted memory on  not sure...
 */
void list_create(list* l);

/**
 * Makes a list node
 * @returns: node used by list 
 */
list_node* list_node_create(list_node* source, const pointer value);

/**
 * Destory's the node. 
 * @param[out] node that will deallocated.
 */
void list_destory_node(list_node* node);

/**
 * @note the pointer will not be deallocated. 
 * @param[out] l list that will be modifed
 */
void list_destory(list* l);


/**
 * Add to a list
 * Args:
 *    l : list that will be modifed
 * @param[in] value pointer to be added to the list.
 */
void list_add(list *l, const pointer value);
/**
 * Prints the list
 * Args:
 * @param[out] l list that will be modifed
 * @param[in] mode mode of print 
 *          VERBOSE - Everything 
 *          FAST - Skips loops (basic)
 */
void list_print(list *l, const list_print_mode mode);
/**
 * Size of list
 * Returns:
 *      Current number of elements 
 *      in list 
 */
size_t list_size(list *l);
/**
 * remove pointer  from list
 * 
 * @param[out] l list that will be modifed
 * @param[in] value remove a pointer from the list
 * @returns pointer if removed will be NULL if not found.
 */
pointer list_remove(list *l, const pointer value);
#endif
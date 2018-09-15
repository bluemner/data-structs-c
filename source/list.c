#include <stdio.h>
#include <stdlib.h>

typedef long type;
typedef struct list list;
typedef struct list_node list_node;

/**
 * Creates a double linked list 
 * becuse double or nothing...
 * 
 * Note:
 *      a root node is placed at the start
 *         | Root    |
 * NULL <--- Source  |
 *         | Target -----> NULL
 * 
 * Returns:
 *      The list your are looking for
 *      or have just wasted memory on 
 *      not sure...
 */
list* make_list();

/**
 * Makes a list node
 * Returns:
 *      node used by list 
 */
list_node* make_list_node(list_node* source, type value);

/**
 * Nuke the list node...
 * I would set the node to null
 * after but it's your call... 
 */
void destory_list_node(list_node* ln);

/**
 * All good things must come
 * to an end so why not end 
 * this list right????
 * Args:
 *    l : list that will be modifed
 */
void destory_list(list* l);


/**
 * Add to a list
 * Args:
 *    l : list that will be modifed
 *    t : type you wish to add to list
 */
void add(list *l,type t);
/**
 * Prints the list
 * Args:
 *    l : list that will be modifed
 *    mode: mode of print 
 *          VERBOSE - Everything 
 *          FAST - Skips loops (basic)
 */
void print_list(list *l, int mode);
/**
 * Size of list
 * Returns:
 *      Current number of elements 
 *      in list 
 */
size_t size(list *l);
/**
 * Prints the list
 * Args:
 *    l : list that will be modifed
 *    t : remove a type from the list
 *        this will deallocate the 
 *        memory 
 */
type remove_type(list *l, type t);

const int VERBOSE = 0;
const int FAST = 1; 

struct list{
    size_t count;
    list_node* last;
    list_node* root;
};

struct list_node{
    type value;
    list_node* source;
    list_node* target;
};

list* make_list(){
    list* result = (list*) malloc( sizeof(list) );
    result->root = make_list_node(NULL,((type) NULL));
    result->last = result -> root;
    result->count = 0;
    return result;    
}


list_node* make_list_node(list_node* source, type value){
    list_node* result = (list_node*) malloc(sizeof(list_node));
    result -> source = source;
    result -> target = NULL;
    result -> value = value;
    return result;
}


void destory_list_node(list_node* ln){
    if(ln==NULL)return;
    free(ln);
}
void destory_list(list* l){
    if(l==NULL)return;
    list_node* current = l->last;
    while(current != NULL){
        if(current->source == NULL){
            destory_list_node(current);
            return;
        }
        current= current->source;
        destory_list_node(current->target);
    }
    free(l);
    l = NULL;

}
int contains(list *l, type t){
    list_node* current = l->root->target; 
    while(current != NULL){
        if(current->value == t) return -1;
        current = current->target;
    }
    return 0;
}
void add(list *l,type t){
    if(contains(l,t)){
        printf("Um... why add this same thing?\n");
        return;
    }
    list_node* temp = make_list_node(l->last,t);
    l->last->target=temp;
    l->last = temp;
    l->count++;
}
void print_list(list *l, int mode){
    if(l == NULL){
        printf("No list here...\n");
        return; 
    }
    list_node* current  = l->root->target;
    printf("List::\n\tsize::%zu\n", l->count);
    if(mode == FAST) return;
    printf("\tValues::\n");
    while(current != NULL){
        printf("\t\tvalue::%zu\n",current->value);
        current = current->target;
    }
}
size_t size(list *l){
    return l->count;
}

type remove_type(list *l,type t){
    list_node* current = l->root->target; 
    list_node* temp  = NULL;
    while(current != NULL){
        if(current->value == t){
            temp = current;
            // Allways will be an empty root for source
            current->source->target = current->target;
            if(current->target != NULL){
                // Remove middle
                current->target->source = current->source;
            }else{
                // Remove last element
                current->source->target = NULL;
                l->last = current->source;
            }
            l->count--;
            break;
        }
        current = current->target;
    }

    
    if(temp == NULL) return ((type) NULL);
    
    type result = temp->value;
    destory_list_node(temp); 
    return result ;
}

int main(){
    list* l = make_list();
    print_list(l, FAST);
    size_t i;
    for(i =0; i < 10;++i){
        add(l,i);
    }
    print_list(l, VERBOSE);
    remove_type(l,3);
    add(l,3);
    add(l,3);
    print_list(l,VERBOSE);

    destory_list(l);
    l = NULL;
    print_list(l, VERBOSE);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef long type;
typedef struct stack stack;

/**
 * Clears the stack
 *  Args: 
 *       s : stack to be modified
 */
void clear(stack* s);
/**
 *  Destroy the stack
 * Args:
 *      s : stack to be deallocated
 *          from memory
 */
void destory(stack* s);

/**
 * Push value onto the stack
 * Args:
 *      value: value to be added 
 */
void push(stack* s,type value);
/**
 * Print a pretty version of the sack
 *  Args:
 *      s : stack to be added
 *      mode: mode of print 
 *            VERBOSE - Everything 
 *            FAST - Skips loops (basic)
 */
void print_stack(stack* s, int mode);

/**
 * Current size 
 * Args:
 *      s : stack to be added
 * Returns:
 *      stack current size
 */
size_t size(stack* s);

/**
 * Current max capacity
 * Args:
 *      s : stack to be added
 * Returns:
 *      max capcity or stack buffer size
 */
size_t capacity(stack* s);

/**
 * Removes "top" of the stack
 * Args:
 *      s : stack to be added
 * Returns:
 *      The current top element
 */
type pop(stack* s);
/**
 * Create a stack type
 * Returns:
 *      the stack you are looking for
 */
stack* make_stack();

const int VERBOSE = 0;
const int FAST = 1;

struct stack{
    size_t size;
    size_t capacity;
    type * values;
};

void clear(stack* s){
    s->size = 0;
}
void destory(stack* s){
    if(s == NULL) 
        return;

    if(s->values != NULL)
        free(s->values);

    s->values = NULL;
    free(s);
    s= NULL;

}
void push(stack* s,type value){
    if( size(s) == s->capacity){
       printf("Capacity Upgrade...\n");
       s->capacity= s->capacity * 2;
       s->values = realloc(s->values, s->capacity * sizeof(type));
    }
    s->values[s->size++] = value;
}

void print_stack(stack* s, int mode){
    if( s == NULL){
        printf("Stack:\n\tDestroyed...");
        return;
    }
    size_t i;
    printf("Stack:\n");
    printf("\tSize::%zu\n", s->size);
    printf("\tCapacity::%zu\n", s->capacity);
    if(FAST) return;
    printf("\tValues::\n");
    for(i =0; i < s->size;++i){
        printf("\t\tvalue_%zu::%zu\n",i,s->values[i]);
    }
}

size_t size(stack* s){
    return s->size;
}

size_t capacity(stack* s){
    return  s->capacity;
}

type pop(stack* s){
    s->size--;
    return s->values[s->size +1];
}

stack* make_stack(){   
    stack* s =  (stack*) malloc(sizeof(stack));
    s->values = (type*) malloc(128 * sizeof(type));
    s->size= 0;
    s->capacity = 128;
    return s;
}

int main(){
    stack* s = make_stack();
    print_stack(s, FAST);
    type i;
    for(i=0; i<129; ++i){
        push(s,i);
    }
    print_stack(s,FAST);
    for(i=0; i<10; ++i){
        pop(s);
    }
    print_stack(s,FAST);
    destory(s);
    print_stack(s,FAST);
   
    return 0;
}
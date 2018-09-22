#ifndef __bluemner_queue_h__
#define __bluemner_queue_h__

#include <stdio.h>
#include <stdlib.h>

typedef long type;
typedef struct queue queue;
typedef struct queue_node queue_node;
const int VERBOSE;
const int FAST; 

/**
 * Prints the current queue 
 */
void print_queue(queue* q, int mode);

/**
 * Queue goes boom, not really just 
 * set to zero but boom sounds better
 */
void destory_queue(queue* q);

/**
 * Add item to the end of the queue
 */
size_t enqueue(queue* q, type t);

/**
 * Return the size of the queue
 */ 
size_t size(queue* q);

/**
 * Remove the next element an return the value
 */
type dequeue(queue* q);

/**
 *  Pointers, so many pointers,
 *  Returns: a brand new queue 
 *    (really is a pointer to an address of the 
 *     pointer to the queue but who cares about
 *     the little details  )
 */
queue* make_queue();


/**
 * Are these really just a waste of space?
 */
queue_node* make_queue_node(type t);


struct queue{
    size_t size;
    queue_node* next;
    queue_node* last;
};

struct queue_node{
    type value;
    queue_node* target;
};
#endif
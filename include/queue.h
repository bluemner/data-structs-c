#ifndef __DATA_STRUCTS_QUEUE_H__
#define __DATA_STRUCTS_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "common.h"


typedef struct queue queue;
typedef struct queue_node queue_node;

/**
 * Prints the current queue 
 */
void print_queue(queue* q, print_mode mode);

/**
 * Queue goes boom, not really just 
 * set to zero but boom sounds better
 */
void destory_queue(queue* q);

/**
 * Add pointer to the end of the queue
 */
size_t enqueue(queue* q, pointer t);

/**
 * Return the size of the queue
 */ 
size_t size(queue* q);

/**
 * Remove the next element an return the value
 */
pointer dequeue(queue* q);

/**
 *  Pointers, so many pointers,
 *  @returns: a brand new queue 
 *    (really is a pointer to an address of the 
 *     pointer to the queue but who cares about
 *     the little details  )
 */
queue* make_queue();


/**
 * Are these really just a waste of space?
 */
queue_node* make_queue_node(pointer t);


struct queue{
    size_t size;
    queue_node* next;
    queue_node* last;
};

struct queue_node{
    pointer value;
    queue_node* target;
};
#endif
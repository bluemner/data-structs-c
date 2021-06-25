#ifndef __DATA_STRUCTS_QUEUE_H__
#define __DATA_STRUCTS_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "common.h"


typedef struct queue queue;
typedef struct queue_node queue_node;

/* 
 * Queue data structure
 */
struct queue{
    size_t size; /*Current number of elements in queue*/
    queue_node* next; /*Next queue node element*/
    queue_node* last; /*Previous queue element*/
};

/*
 * Queue node
 */
struct queue_node{
    pointer value;
    queue_node* target;
};

/**
 * Prints the current queue 
 * @param[out] q queue
 * @param[in] mode print mode level
 */
void print_queue(queue* q, const print_mode mode);

/**
 * Deallocated the queue
 * @param[out] q queue to deallocate
 */
void destory_queue(queue* q);

/**
 * Add pointer to the end of the queue
 * @param[out] q queue to add item to 
 * @param[in] item pointer to item you want to queue
 */
size_t enqueue(queue* q, const pointer item);

/**
 * Return the size of the queue
 * @param[out] queue to get size
 */ 
size_t size(queue* q);

/**
 * Remove the next element an return the value
 * @param[out] queue to remove element
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

#endif
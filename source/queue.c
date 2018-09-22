#include "queue.h"

const int VERBOSE = 0;
const int FAST = 1;

void print_queue(queue* q, int mode){
    if(q == NULL){
        printf("No Queue here...\n");
        return; 
    }    

    printf("Queue::\n\tsize::%zu\n", q->size);
    
    if(mode == FAST) return;   
    printf("\tValues::\n");
    queue_node* current = q->next;
    while(current != NULL)
    {
        printf("\t\tvalue::%zu\n",current->value);
        current = current->target;
    }
}

void destory_queue(queue* q){
    queue_node* current = q->next;
    queue_node* next;
    while(current != NULL)
    {
        next = current->target;
        free(current);
        current = next;
    }
    q->next=NULL;
    q->last=NULL;
    q=NULL;
}

size_t enqueue(queue* q, type t){
    queue_node * qn  = make_queue_node(t);
    qn->value = t;
    if(q->last != NULL)
        q->last->target = qn;
    q->last = qn;
    if(q->next == NULL)
        q->next = qn;

    return ++q->size;
}

size_t size(queue* q){
    return q->size;
}

type dequeue(queue* q){
    queue_node* qn = q->next;
    q->next =  qn->target;
    type result = qn->value;
    free(qn);
    q->size--;
    return result;
}

queue* make_queue(){
    queue* q = (queue*) malloc(sizeof(queue));
    q->size =  0;
    return q;
}

queue_node* make_queue_node(type t){
    queue_node* qn = malloc(sizeof(queue_node));
    qn->value =  t;
    qn->target = NULL;
    return qn;
}

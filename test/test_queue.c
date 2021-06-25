#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "queue.h"

size_t PASSED = 0;
size_t TOTAL  = 0;

queue* test_make_queue(){
    queue* q = make_queue();
    assert(q != NULL && "Make Queue::Tried to make queue but got nothing");
    assert(size(q)== 0 && "Make Queue:: size not set to zero");
    ++PASSED;
    return q;
}

/**
 * Test Enqueue
 */
void test_enqueue(queue* q, size_t max){
    uint8_t i;
    uint8_t values[10] = {0,1,2,3,4,5,6,7,8,9};
    for( i =0; i < max; i++){
        enqueue(q,&values[i]);
        assert(i+1 == size(q) && "Enqueue:: Size error\n");
    }
    assert(max == size(q));
    ++PASSED;
}

void test_dequeue(queue* q, size_t max){
    size_t i;
    for( i =0; i < max; i++){
        pointer v = dequeue(q);
        assert(v == ((pointer) i) && "Dequeue:: Value return error\n");
        assert(max-i-1 == size(q) && "Dequeue:: Size error\n");
    }
    ++PASSED;
}

void test_destory_queue(queue* q){
    destory_queue(q);
    assert(q->next == NULL &&  "Destory:: Next was not set to null");
    assert(q->last == NULL &&  "Destory:: Last was not set to null");
    assert(q->size == 0 &&  "Destory:: Size was not set to zero");
    ++PASSED;
}

/**
 * Print out the stats of the test at the end
 */
void queue_stats(){
    printf("Unit Test Stats::\n\tPassed::%zu\n\tTotal::%zu\n", PASSED, TOTAL);
}

int main(){
    printf("Running unit test for queues\n");
    
    TOTAL = 4;
    queue * q = test_make_queue();
    
    size_t test_size = 3;
    test_enqueue(q,test_size);    
    test_dequeue(q,test_size);
    test_destory_queue(q);

    queue_stats();
    return 0;
}
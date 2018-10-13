#include "merge_sort.h"
#include <stdio.h>
#include <assert.h>

size_t PASSED = 0;
size_t TOTAL  = 0;
type* make_empty_list(const size_t size){
    size_t* list = malloc(sizeof(type) * size);
    return list;
}
type* make_list(const size_t size){
    size_t i;
    size_t* list = malloc(sizeof(type) * size);
    for(i=0; i< size; i++)
        list[i]=size-i;
    
    return list;
}

type* make_expected_list(const size_t size){
    size_t i;
    size_t* list = malloc(sizeof(size_t) * size);
    for(i=0; i< size; i++)
        list[i]=size-i;
    
    return list;
}


void destory_list(type* list){
    free(list);
    list=NULL;
}

void test_value(type expected, type actual){
    ++TOTAL;
    assert(expected == actual && "test value");
    ++PASSED;
}
void test_sorted_list(
    type* actual,
    type* expected,
    const size_t size){
    ++TOTAL;
    size_t i;
    for(i=0; i<size; i++)
        test_value(expected[i], actual[i]);

    ++PASSED;
}


/**
 * Print out the stats of the test at the end
 */
void stats(){
    printf("Unit Test Stats::\n\tPassed::%zu\n\tTotal::%zu\n", PASSED, TOTAL);
}
int main(){
    const size_t size = 10;
    type* list = make_list(size);
    type* want = make_expected_list(size);
    type* buffer = make_empty_list(size);
    merge_sort(list,buffer, size);
    test_sorted_list(list,want,size);
    destory_list(list);
    destory_list(want);
    destory_list(buffer);
    
    stats();
}
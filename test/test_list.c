#include "list.h"
#include <assert.h>
#include <stdint.h>
/**
 * Main
 */
int main(){
    list l;
    list_create(&l);
    list_print(&l, PRINT_MODE_SUMMARY);
    uint8_t i;
    uint8_t values[10] = {0,1,2,3,4,5,6,7,8,9};

    for(i = 0; i < 10; ++i){
        list_add(&l,&values[i]);
        assert(list_size(&l) == i+1);
    }
    list_print(&l, PRINT_MODE_VERBOSE);
    // Test remove value
    list_remove(&l,&values[3]);
    assert(list_size(&l) == 9);
    list_print(&l, PRINT_MODE_SUMMARY);
    // Re add the value that was just removed
    list_add(&l,&values[3]);
    assert(list_size(&l) == 10);
    list_print(&l, PRINT_MODE_SUMMARY);
    // Don't readded the same value
    list_add(&l,&values[3]);
    assert(list_size(&l) == 10);
    list_print(&l, PRINT_MODE_SUMMARY);
    // Destroy the list
    list_destory(&l);
    list_print(&l, PRINT_MODE_VERBOSE);
    return 0;
}
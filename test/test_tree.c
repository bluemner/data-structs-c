#include <assert.h>
#include "tree.h"

size_t PASSED = 0;
size_t TOTAL  = 0;

void test_tree_add(tree* t,size_t MAX){
    ++TOTAL;
    size_t i;
    for(i=0; i< MAX; i++){
        tree_add(t,i);
        assert(size(t) == i+1  && "Tree Add:: Size is off");
    }
    ++PASSED;
}

/**
 * Make a tree:
 *  
 */
tree* test_make_tree(){
    ++TOTAL;
    tree* t = make_tree();
    assert(t != NULL && "Make Tree:: NULL POINTER!!!");
    assert(t->root == NULL && "Make Tree:: Root Should be NULL");
    assert(t->size == 0 && "Make Tree:: Size Should be Zero(0) ");
    ++PASSED;
    return t;
}

/**
 * Destory tree
 * Things to check::
 *   [X] Empty tree (null guards)
 *   [X] Free all nodes that are in tree (bfs or dfs)
 *   [X] Set tree size to zero
 *   [X] Set root to NULL
 */
void test_destory_tree(tree* t){
    ++TOTAL;
    destory_tree(t);
    assert(t->root == NULL && "Destory:: root should be null");
    assert(t->size == 0 && "Destory:: Size Should be Zero(0)");
    ++PASSED;
}

/**
 * Print out the stats of the test at the end
 */
void tree_stats(){
    printf("Unit Test Stats::\n\tPassed::%zu\n\tTotal::%zu\n", PASSED, TOTAL);
}

int main(int argc, char const *argv[])
{
    
    tree* t = test_make_tree();
    test_tree_add(t,1);
    test_destory_tree(t);
    tree_stats();
    return 0;
}
#ifndef __bluemner_tree_h__
#define __bluemner_tree_h__

#include<stdio.h>
#include<stdlib.h>

typedef void* type;
typedef struct tree tree;
typedef struct tree_node tree_node;
const int VERBOSE;
const int FAST; 

tree* make_tree();
tree_node* make_tree_node(type value);
void destory_tree(tree* t);
void destory_tree_nodes(tree_node* tn);
size_t size(tree* t);
void tree_add_helper(tree_node* it, tree_node* tn);
void tree_add(tree*t, type value);
void tree_remove(tree* t,type value);

struct tree{
    tree_node* root;
    size_t size;
};
struct tree_node{
    tree_node* left;
    tree_node* right;
    type value;
};
#endif
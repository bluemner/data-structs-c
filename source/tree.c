#include "tree.h"

tree* make_tree(){
    tree* t = malloc(sizeof(tree));
    t->size = 0;
    t->root = make_tree_node((type)NULL);
    return t;
}

tree_node* make_tree_node(type value){
    tree_node* tn = malloc(sizeof(tree_node));
    tn->left = NULL;
    tn->right = NULL;
    tn->value = value;
    return tn;
}
void destory_tree(tree* t){
    if(t->root == NULL) return;
    destory_tree_nodes(t->root);
    free(t->root);
    free(t);
    t->root = NULL;
    t->size = 0;
    t=NULL;
}
void destory_tree_nodes(tree_node* tn){
    //left 
    if(tn->left  != NULL){
        destory_tree_nodes(tn->left);
        tn->left = NULL;
    }
    //right
    if(tn->right != NULL){
        destory_tree_nodes(tn->right);
        tn->right=  NULL;
    }
    //current
    free(tn);
    tn=NULL;
}

size_t size(tree* t){
    return t->size;
}
void tree_add_helper(tree_node* it, tree_node* tn){
    // LEFT 
    if( tn->value <=  it->value)
    
        if (it->left != NULL)
            tree_add_helper( it->left ,tn);
        else
            it->left = tn;
    
    // RIGHT 
    else
        if(it->right !=NULL)
            tree_add_helper(it->right, tn);
        else 
            it->right = tn;
        
}
void tree_add(tree* t, type value){
  tree_node* tn = make_tree_node(value);
  if(t->root != NULL)
    tree_add_helper(t->root, tn);
  else 
    t->root = tn;

  ++t->size;
}

tree_node* tree_remove_helper(tree_node* it,tree_node* parent,type value){
    //       r
    //      / \
    //     x   y
    //    / \    
    //   z   v
    // value -> x
    tree_node* tmp;
    if(it == NULL) return it;

    if(it->value == value){
        if(it->left != NULL){
            tmp = it->left;
            while(tmp->right !=NULL){
                tmp= tmp->right;
            }
            tmp->left = it->right;
            tmp =it->left;
            free(it);
            return tmp;
        }
        tmp =it->right;
        free(it);
        return tmp;
    }
    if (it->value > value)
        tree_remove_helper(it->left,it,value);
        return it->left;
    return NULL;
}

void tree_remove(tree* t,type value){
    if(t->root != NULL) 
        tree_remove_helper(t->root,NULL,value);
    return;
}
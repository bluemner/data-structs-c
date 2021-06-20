#include "list.h"

void list_create(list* l){
    l->root = list_node_create(NULL, NULL);
    l->last = l -> root;
    l->count = 0;    
}

list_node* list_node_create(list_node* source, const pointer value){
    list_node* result = (list_node*) malloc(sizeof(list_node));
    result -> source = source;
    result -> target = NULL;
    result -> value = value;
    return result;
}

void list_destory_node(list_node* node){
    if ( node == NULL ) return;
    free(node);
}

void list_destory(list* l){
    if(l==NULL)return;
    list_node* current = l->root;
    list_node* next = NULL;
    while(current != NULL){
        next = current->target;
        list_destory_node(current);
        current = next;
    }
    l->count =0;
    l->root = NULL;
}

int list_contains(list *l, pointer value){
    list_node* current = l->root->target; 
    while(current != NULL){
        if(current->value == value) return -1;
        current = current->target;
    }
    return 0;
}

void list_add(list *l, const pointer value){
    if(list_contains(l,value)) return;
    list_node* temp = list_node_create(l->last,value);
    l->last->target=temp;
    l->last = temp;
    l->count = 1 + l->count;
}

void list_print(list *l, const list_print_mode mode){
    if(l == NULL || l->root == NULL){
        printf("No list here...\n");
        return; 
    }

    list_node* current = l->root->target;
    printf("List::\n\tsize::%zu\n", l->count);
    if(mode == LIST_PRINT_FAST) return;
    printf("\tValues::\n");
    while(current != NULL){
        printf("\t\tvalue::%p\n",current->value);
        current = current->target;
    }
}

size_t list_size(list *l){
    return l->count;
}

pointer list_remove(list *l,const pointer value){
    if(l == NULL || l->root == NULL) return NULL;
    list_node* current = l->root->target; 
    list_node* temp  = NULL;
    while(current != NULL){
        if(current->value == value){
            temp = current;
            // Allways will be an empty root for source
            current->source->target = current->target;
            if(current->target != NULL){
                // Remove middle
                current->target->source = current->source;
            }else{
                // Remove last element
                current->source->target = NULL;
                l->last = current->source;
            }
            l->count--;
            break;
        }
        current = current->target;
    }
    if(temp == NULL) return NULL;
    
    pointer result = temp->value;
    list_destory_node(temp); 
    return result ;
}

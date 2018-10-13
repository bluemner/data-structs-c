#include "merge_sort.h"
void merge_sort(
    type* data,
    type* buffer,
    const size_t size){
        clone(data, buffer, 0,size);
        merge_sort_split(data,buffer,0,size);
    }

void merge_sort_split(
    type* data,
    type* buffer,
    const size_t start,
    const size_t end){
        if(end-start < 2) return;
        size_t middle = (size_t) ( (start + end) / 2);
        //LEFT 
        merge_sort_split(data,buffer,start,middle);
        //RIGHT
        merge_sort_split(data,buffer,middle,end);
        merge_sort_merge(data,buffer,start,middle,end);
    }
void merge_sort_merge(
    type* data,
    type* buffer,
    const size_t start,
    const size_t middle,
    const size_t end){
        size_t i;
        size_t left_index = start;
        size_t right_index = middle;
        for( i= start ; i < end; i++ ){
           if( left_index < middle && 
                (right_index >= end ||  
                 buffer[left_index] >= buffer[right_index])){
               data[i]= buffer[left_index];
               left_index++;
           }else {
               data[i]= buffer[right_index]; 
               right_index++;
           }    
        }
    }
void clone(
    type* source,
    type* buffer,
    const size_t start,
    const size_t end ){
        size_t i;
        for(i=start;i<end; i++){
            buffer[i]=source[i];
        }
    }

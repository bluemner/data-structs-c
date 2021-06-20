#ifndef __DATA_STRUCTS_MERGE_SORT_H__
#define __DATA_STRUCTS_MERGE_SORT_H__

#include <stdio.h>
#include <stdlib.h>

typedef size_t type;

void merge_sort(
    type* data,
    type* buffer,
    const size_t size);

void merge_sort_split(
    type* source,
    type* buffer,
    size_t start,
    size_t end );

void merge_sort_merge(
    type* data,
    type* buffer,
    size_t start,
    size_t middle,
    size_t end);
/**
 * 
 */
void clone(
    type* source,
    type* buffer,
    size_t start,
    size_t end );

#endif
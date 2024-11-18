#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    This structure represents a node from a list which contain:
    the size of the array of segments, the array of segments, the
    index of the city which the route ends and a pointer to the next
    node.
*/

typedef struct list{
    int index_city;
    int size_sections;
    float *sections;
    struct list *next;
} *List;

/*
    It allocate memory for a node in the list and
    for the array. It assign the fields of the node.
*/
List createList(int idx, int size, float *arr);

/*
    This function add a element at the end of the list
*/

List addLast(List list, int idx, int size, float *arr);

/*
    This function checks if the list in empty.
    It returns 0, if the list isn't empty. Otherwise
    it returns 1.
*/

int isEmptyList(List list);

/*
    It returns the biggest element from the
    first position (from the array of segments)
    from list.
*/

float maxOfList(List list);

/*
    This function deallocates the memory allocated for a list.
*/

void freeList(List list);

#endif
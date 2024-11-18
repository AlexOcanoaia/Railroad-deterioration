#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Structura list reprezinta un nod din lista care
    contine: index-ul orasului in care se termina ruta,
    dimensiunea vectorului de tronsoane, vectorul ce contine
    gradul de degradare al tronsoanelor si pointer la urmatorul 
    nod din lista.

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
    Returneaza cel mai mare element de pe pozitia 0
    (din vectorii de tronsoane) din lista.

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
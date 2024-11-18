#ifndef GRAPH_H_
#define GRAPH_H_

#include "list.h"

/*
    Structure that stores the name of cities
    inside the graph and assigns them an index
    (the index is equal with the position index)
*/

typedef struct index {
    char *city_name;
} *Index;

/*
    Structure that stores the routes inside
    the graph.
*/

typedef struct routes{
    int start;
    int end;
} *Routes;

/*
    Structure that represents the graph which contain:
    the index corresponding to each city, the number 
    of routes, the routes and the adjacency list.

*/

typedef struct graph {
    Index index;
    int R;
    Routes route;
    List *adLists;
} *Graph;

/*
    It allocates memory for the graph and for structures
    inside the graph. It assign the fields of the graph.
*/

Graph createGraph(int R);

/*
    This function adds an edge in the graph. The edge will be
    in both direction (if the A-B route exist, then will exist
    the B-A route).
*/

Graph insertEdge(Graph g, int idx1, int idx2, int size, float *arr);

/*
    It returns the index that was assigned to the city.
*/

int returnIndex(Index index, int size, char *name);

/*
    It returns the bigger number.
*/

float max(float a, float b);

/*
    It returns the largest neighboring coefficient.
*/

float *maxVector(List *list, int size);

/*
    This function returns the name of the city that 
    is located at the index i.
*/

char *returnName(Index index, int i);

/*
    It adds a city in the array and assigned an index to that city.
*/

void addIndex(Index index, int size, char *name);

/*
    It adds a route in the array
*/

void addRoute(Routes route, int start, int end, int idx);

/*
    This function it reverse an array.
*/

void reverse(float *v, int size);

/*
    It prints the routes that are in graph and 
    the array of segments asociated to every route.
    At the end, it calculates if a route can be keeped
    or not.
*/

void printGraph(Graph g, float L, FILE *output);

/*
    It calculates the coefficient of the railroads
*/

void gradesOfSections(Graph g, int years);

/*
    This function deallocates the memory allocated for a graph.
*/

void freeGraph(Graph g);

#endif
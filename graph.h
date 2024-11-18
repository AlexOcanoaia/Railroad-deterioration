#ifndef GRAPH_H_
#define GRAPH_H_

#include "list.h"

/*
    Structura ce retine numele oraselor aflate in graf
    si retine index-ul lor (numele orasului de pe pozitia i
    din vector are index-ul i).

    Structure that stores the name of cities
    inside the graph and assigns them an index
    (the index is equal with the position index)
*/

typedef struct index {
    char *city_name;
} *Index;

/*
    Structura ce retine rutele grafului.

    Structure that stores the routes inside
    the graph.
*/

typedef struct routes{
    int start;
    int end;
} *Routes;

/*
    Structura ce reprezinta graful si contine 
    urmatoarele campuri: indecsii atribuiti
    oraselor, numarul de rute, rutele si listele
    de adiacenta.

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
    Functie ce aloca memorie pentru graf. 
    Aloca memorie pentru lista si structurile din graf si 
    atribuie numarul de rute.

    It allocates memory for the graph and for structures
    inside the graph. It assign the fields of the graph.
*/

Graph createGraph(int R);

/*
    Functie ce introduce o muchie in graf. Fiind un graf
    neorientat, muchia va introdusa in doua liste de adiacenta
    (daca exista ruta A-B, va exista si ruta B-A si va avea 
    vectorul de tronsoane inversat).

    This function adds an edge in the graph. The edge will be
    in both direction (if the A-B route exist, then will exist
    the B-A route).
*/

Graph insertEdge(Graph g, int idx1, int idx2, int size, float *arr);

/*
    Functie va returna index-ul care i-a fost atribuit
    orasului (char *name).

    It returns the index that was assigned to the city.
*/

int returnIndex(Index index, int size, char *name);

/*
    Functie va returna care numar este mai mare.

    It returns the bigger number.
*/

float max(float a, float b);

/*
    Functie returneaza un vector care contine maximul
    (de pe pozitia 0 din vectorii de tronsoane) din fiecare
    lista a grafului (maxim[i] este maximul listei i din graf)


*/

float *maxVector(List *list, int size);

/*
    Functie va returna numele orasului care se afla
    la index-ul i.

    This function returns the name of the city that 
    is located at the index i.
*/

char *returnName(Index index, int i);

/*
    Functie adauga un oras in vector si ii atribuie un index.

    It adds a city in the array and assigned an index to that city.
*/

void addIndex(Index index, int size, char *name);

/*
    Functie adauga o ruta in vector.

    It adds a route in the array
*/

void addRoute(Routes route, int start, int end, int idx);

/*
    This function it reverse an array.
*/

void reverse(float *v, int size);

/*
    Functie care printeaza rutele care sunt in graf
    si vectorul de tronsoane asociat fiecarei rute. 
    La final, calculeaza daca o ruta poate fi pastrata
    sau nu.

    It prints the routes that are in graph and 
    the array of segments asociated to every route.
    At the end, it calculates if a route can be keeped
    or not.
*/

void printGraph(Graph g, float L, FILE *output);

/*
    Functie care calculeaza cum se schimba gradele
    de degradare al tronsoanelor dupa un anumit numar de 
    ani.

    It calculates 
*/

void gradesOfSections(Graph g, int years);

/*
    This function deallocates the memory allocated for a graph.
*/

void freeGraph(Graph g);

#endif
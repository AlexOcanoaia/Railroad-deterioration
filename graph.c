#include "graph.h"

Graph createGraph(int R) {
    Graph g = malloc(sizeof(struct graph));
    if (!g) {
        return NULL;
    }
    g->R = R;
    g->index = calloc(2 * R, sizeof(struct index));
    if (!g->index) {
        free(g);
        return NULL;
    }
    g->route = calloc(R, sizeof(struct routes));
    if (!g->route) {
        free(g->index);
        free(g);
        return NULL;
    }
    g->adLists = calloc(2 * R, sizeof(struct list));
    if (!g->adLists) {
        free(g->route);
        free(g->index);
        free(g);
        return NULL;
    }
    return g;
}

int returnIndex(Index index, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (index[i].city_name != NULL) {
            if (strcmp(index[i].city_name, name) == 0) {
                return i;
            }
        }
    }
    return -1;
}

void addIndex(Index index, int size, char *name) {
    if (returnIndex(index, size, name) != -1) {
        return;
    }
    Index iter = index;
    for (int i = 0; i < size; i++) {
        if (iter[i].city_name == NULL) {
            iter[i].city_name = strdup(name);
            return;
        }
    }
}

char *returnName(Index index, int i) {
    if (index[i].city_name != NULL) {
        return index[i].city_name;
    }
    return NULL;
}

void addRoute(Routes route, int start, int end, int idx) {
    route[idx].start = start;
    route[idx].end = end;
}

void reverse(float *v, int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int tmp = v[start];
        v[start] = v[end];
        v[end] = tmp;
        start++;
        end--;
    }
}

Graph insertEdge(Graph g, int idx1, int idx2, int size, float *arr) {
    if (!g) {
        return NULL;
    }
    g->adLists[idx1] = addLast(g->adLists[idx1], idx2, size, arr);
    reverse(arr, size);
    g->adLists[idx2] = addLast(g->adLists[idx2], idx1, size, arr);
    return g;
}

void printGraph(Graph g, float L, FILE *output) {
    int *v = malloc(g->R * sizeof(int));
    for (int i = 0; i < g->R; i++) {
        v[i] = -1;
        int idx = g->route[i].start;
        int aux = g->route[i].end;
        if (g->adLists[idx] != NULL) {
            List iter = g->adLists[idx];
            while (iter) {
                if (iter->index_city == aux) {
                    fprintf(output, "%s ", returnName(g->index, idx));
                    fprintf(output, "%s ", returnName(g->index, iter->index_city));
                    fprintf(output, "%d ", iter->size_sections);
                    float sum = 0;
                    for (int j = 0; j < iter->size_sections; j++) {
                        fprintf(output, "%.2f ", iter->sections[j]);
                        sum += iter->sections[j];
                    }
                    sum = sum / iter->size_sections;
                    if (sum < L) {
                        v[i] = i + 1;
                    }
                    fprintf(output, "\n");
                }
                iter = iter->next;
            }
        }
    }
    for (int i = 0; i < g->R; i++) {
        if (v[i] != -1) {
            fprintf(output, "%d ", v[i]);
        }
    }
    free(v);
}

float max(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

float *maxVector(List *list, int size) {
    float *maxim = malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        maxim[i] = maxOfList(list[i]);
    }
    return maxim;
}

void gradesOfSections(Graph g, int years) {
    if (!g) {
        return;
    }
    for (int i = 0; i < years; i++) {
        float *maxim_lists = maxVector(g->adLists, 2 * g->R);
        for (int j = 0; j < 2 * g->R; j++) {
            if (g->adLists[j] != NULL) {
                List iter = g->adLists[j];
                while (iter) {
                    int idx = iter->index_city;
                    int size = iter->size_sections;
                    float *new_section = malloc(size * sizeof(float)); 
                    for (int k = 0; k < size; k++) {
                        if (iter->sections[k] != 0) {
                            new_section[k] = iter->sections[k] * 2;
                            if (new_section[k] > 100) {
                                new_section[k] = 100;
                            }
                        } 
                        else {
                            if (k > 0 && k < size - 1) {
                                float a = iter->sections[k - 1];
                                float b = iter->sections[k + 1];
                                new_section[k] = max(a, b) / 2;
                            } else {
                                float aux = 0;
                                float maxim;
                                if (k == 0 && k == size - 1) {
                                    maxim = max(maxim_lists[j], maxim_lists[idx]);
                                } else {
                                if (k == 0) {
                                    aux = iter->sections[k + 1];
                                    maxim = maxim_lists[j];
                                } else {
                                    aux = iter->sections[k - 1];
                                    maxim = maxim_lists[idx];
                                    }
                                }
                                new_section[k] = max(aux, maxim) / 2;
                            }
                        }
                    }
                    for (int k = 0; k < size; k++) {
                        iter->sections[k] = new_section[k];
                    }
                    free(new_section);
                    iter = iter->next;
                }
            }
        }
        free(maxim_lists);
    }
}

void freeGraph(Graph g) {
    for (int i = 0; i < 2 * g->R; i++) {
        if (g->adLists[i] != NULL) {
            freeList(g->adLists[i]);
        }
        if (g->index[i].city_name != NULL) {
            free(g->index[i].city_name);
        }
    }
    free(g->route);
    free(g->index);
    free(g->adLists);
    free(g);
}

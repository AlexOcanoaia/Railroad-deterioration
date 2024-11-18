#include "list.h"

List createList(int idx, int size, float *arr) {
    List list = malloc(sizeof(struct list));
    if (!list) {
        return NULL;
    }
    list->index_city = idx;
    list->size_sections = size;
    list->sections = malloc(size * sizeof(float));
    if (!list->sections) {
        free(list);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        list->sections[i] = arr[i];
    }
    list->next = NULL;
    return list;
}

int isEmptyList(List list) {
    if (!list) {
        return 1;
    }
    return 0;
}

List addLast(List list, int idx, int size, float *arr) {
    if (isEmptyList(list) == 1) {
        return createList(idx, size, arr);
    }
    List iter = list;
    while (iter->next) {
        iter = iter->next;
    }
    iter->next = createList(idx, size, arr);
    return list;
}

float maxOfList(List list) {
    List iter = list;
    float max = 0;
    while (iter) {
        if (iter->sections[0] > max) {
            max = iter->sections[0];
        }
        iter = iter->next;
    }
    return max;
}

void freeList(List list) {
    while (list) {
        List tmp = list;
        free(tmp->sections);
        list = list->next;
        free(tmp);
    }
}

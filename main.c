#include "graph.h"

#define MAX_SIZE 100

int main() {
    FILE *input_file = fopen("file.in", "rt");
    if (!input_file) {
        return -1;
    }
    FILE *output_file = fopen("file.out", "wt");
    if (!output_file) {
        return -1;
    }

    char buffer[MAX_SIZE];
    int R, years;
    float L;
    fgets(buffer, MAX_SIZE, input_file);
    R = atoi(buffer);
    fgets(buffer, MAX_SIZE, input_file);
    years = atoi(buffer);
    fgets(buffer, MAX_SIZE, input_file);
    L = atof(buffer);
    Graph g = createGraph(R);
    int count = 0, size;
    for (int i = 0; i < R; i++) {
        fscanf(input_file, "%s", buffer);
        addIndex(g->index, 2 * R, buffer);
        int idx1 = returnIndex(g->index, 2 * R,  buffer);
        fscanf(input_file, "%s", buffer);
        addIndex(g->index, 2 * R, buffer);
        int idx2 = returnIndex(g->index, 2 * R,  buffer);
        addRoute(g->route, idx1, idx2, count);
        count++;
        fscanf(input_file, "%d", &size);
        float *arr = malloc(size * sizeof(float));
        for (int j = 0; j < size; j++) {
            fscanf(input_file, "%f", &arr[j]);
        }
        fgets(buffer, MAX_SIZE, input_file);
        g = insertEdge(g, idx1, idx2, size, arr);
        free(arr);
    }
    gradesOfSections(g, years);
    printGraph(g, L, output_file);
    freeGraph(g);

    fclose(input_file);
    fclose(output_file);
    return 0;
}

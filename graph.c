#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_vertice(Graph *graph, int n){
    if(n > graph->num_vertices || n <= 0) return 0; //greater than or EQUAL because of the left shift
    return 1;
}

Graph *construct_graph(int n){
    int **matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        int *row_i = (int*) malloc(n * sizeof(int));
        memset(row_i, -1, n*sizeof(int)); //sets all elements of the row to -1
        matrix[i] = row_i;
    }

    Graph *g = (Graph*) malloc(sizeof(Graph));
    g->matrix = matrix;
    g->num_vertices = n;
    return g;
}

int add_edge(Graph *graph, int src, int dest, int weigth){
    if(!is_valid_vertice(graph, src) || !is_valid_vertice(graph, dest)) return -1;

    graph->matrix[src-1][dest-1] = weigth; //shifts the indices one to the left in order to not waste the 0th position of the arrays
    graph->matrix[dest-1][src-1] = weigth;
    return 0;
}

void print_info(Graph *graph){
    printf("V = [");
    for(int i = 0; i < graph->num_vertices; i++){
        if(i != graph->num_vertices - 1) printf("%d, ", i+1);
        else printf("%d", i+1);
    }
    printf("]\n");

    printf("E = [");
    int counter = 0;
    for (int i = 0; i < graph->num_vertices - 1; i++) {
        for (int j = i + 1; j < graph->num_vertices; j++) { //starts from the diagonal (j = i + 1), because the matrix is symmetric and the diagonal has no edges
            if(graph->matrix[i][j] != -1){
                if (counter != 0) printf(", ");
                printf("(%d, %d)", i+1, j+1);
                counter += 1;
            }
        }
    }
    printf("]\n");
}

int *neighbors(Graph *graph, int vertice){
    if(!is_valid_vertice(graph, vertice)) return NULL;

    int *neighbors = (int*) malloc(graph->num_vertices * sizeof(int));
    memset(neighbors, -1, graph->num_vertices * sizeof(int));
    int last_index = 0;

    for (int i = 0; i < graph->num_vertices; i++) {
        if(graph->matrix[vertice-1][i] != -1){
            neighbors[last_index] = i+1;
            last_index++;
        }
    }

    return neighbors;
}

int remove_edge(Graph *graph, int src, int dest){
    if(!is_valid_vertice(graph, src) || !is_valid_vertice(graph, dest)) return -1;

    graph->matrix[src-1][dest-1] = -1;
    graph->matrix[dest-1][src-1] = -1;
    return 0;
}

int exist_edge(Graph *graph, int src, int dest){
    return graph->matrix[src-1][dest-1] != -1 ? 1 : 0;
}

int max_neighbors(Graph *graph){
    int max = 0;

    for (int i = 0; i < graph->num_vertices; i++) {
        int counter = 0;

        for (int j = 0; j < graph->num_vertices; j++) {
            if(graph->matrix[i][j] != -1){
                counter++;
            }
        }

        if(counter > max) max = counter;
    }

    return max;
}

int **adjacency_matrix(Graph *graph){
    return graph->matrix;
}

void delete_graph(Graph *graph){
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->matrix[i]); //frees rows
    }
    free(graph->matrix);
    free(graph);
    graph = NULL;
}

#include "graph.h"
#include <stdio.h>

//aux function
void print_arr(int *arr, int length){
    for (int i = 0; i < length; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

//aux function
void print_matrix(int **matrix, int length){
    for (int i = 0; i < length; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < length; j++) {
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    Graph *g = construct_graph(8);

    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 3, 4);
    add_edge(g, 1, 8, 3);

    add_edge(g, 2, 3, 5);
    add_edge(g, 2, 4, 6);
    add_edge(g, 2, 8, 2);

    add_edge(g, 3, 5, 8);
    add_edge(g, 3, 4, 9);

    add_edge(g, 4, 5, 7);
    add_edge(g, 4, 6, 10);

    printf("does the edge (%d, %d) exist? %d\n", 2, 4, exist_edge(g, 2, 4));
    printf("does the edge (%d, %d) exist? %d\n", 1, 6, exist_edge(g, 1, 6));
    
    print_info(g);

    int *arr = neighbors(g, 1);
    int i = 0;
    printf("Neighbors of %d: ", 1);
    while(arr[i] > 0){
        printf("%d, ", arr[i]);
        i++;
    }
    printf("\n");

    delete_graph(g);
    //print_matrix(g->matrix, g->num_vertices);
}
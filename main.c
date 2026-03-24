#include "graph.h"
#include <stdio.h>
#include <stdbool.h>

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
    int option;
    int N, x, y, w, res;
    bool print_status = 1;

    Graph *G;

    scanf("%d", &option);
    while (option != -1) {
        switch(option){
            case 0:
                scanf("%d", &N);
                G = construct_graph(N);
                break;
            case 1:
                scanf("%d %d %d", &x, &y, &w);
                add_edge(G, x, y, w);
                break;
            case 2:
                scanf("%d %d", &x, &y);
                res = exist_edge(G, x, y);
                print_status = 0;
                break;
            default:
                printf("unrecognized option %d!\n", option);
        }

        scanf("%d", &option);
    }

    if (print_status) {
        print_info(G);
    } else {
        printf("%d\n", res);
    }

    delete_graph(G);
}

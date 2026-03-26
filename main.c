#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_neighbors(int *arr, int length){
    for (int i = 0; i < length; i++) {
        if (arr[i] == -1) continue;
        printf("%d ", i+1);
    }
    printf("\n");
}

int main(){
    int option;
    int N, x, y, w, res;
    int *list;
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
                printf("%d\n", res);
                print_status = 0;
                break;
            case 3:
                scanf("%d", &N);
                list = neighbors(G, N);
                print_neighbors(list, G->num_vertices);
                print_status = 0;
                free(list);
                break;
            default:
                printf("unrecognized option %d!\n", option);
        }

        scanf("%d", &option);
    }

    if (print_status) {
        print_info(G);
    }

    delete_graph(G);
}

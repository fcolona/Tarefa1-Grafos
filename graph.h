typedef struct Graph {
    int **matrix;
} Graph;

Graph *construct_graph(int n);
void add_edge(Graph *graph, int src, int dest, int weigth);
int exist_edge(Graph *graph, int src, int dest);
int *neighbors(Graph *graph, int vertice);
int remove_edge(Graph *graph, int src, int dest);
void print_info(Graph *graph);
int delete_graph(Graph *graph);
int max_neighbors(Graph *graph);
int **adjacency_matrix(Graph *graph);
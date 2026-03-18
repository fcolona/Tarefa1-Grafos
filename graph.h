typedef struct Graph {
    int **matrix;
    int num_vertices;
} Graph;

Graph *construct_graph(int n);
int add_edge(Graph *graph, int src, int dest, int weigth);
int exist_edge(Graph *graph, int src, int dest);
int *neighbors(Graph *graph, int vertice);
int remove_edge(Graph *graph, int src, int dest);
void print_info(Graph *graph);
void delete_graph(Graph *graph);
int max_neighbors(Graph *graph);
int **adjacency_matrix(Graph *graph);
int is_valid_index(Graph *graph, int n);
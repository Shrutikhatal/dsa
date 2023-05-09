
/*Write a Program to implement Prim’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to represent
a graph.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Edge {
    int node;
    int weight;
    struct Edge* next;
};

struct Graph {
    int num_nodes;
    struct Edge* adj_list[MAX_NODES];
};

struct Graph* create_graph(int num_nodes) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;
    int i;
    for (i = 0; i < num_nodes; i++) {
        graph->adj_list[i] = NULL;
    }
    return graph;
}

void add_edge(struct Graph* graph, int node1, int node2, int weight) {
    struct Edge* new_edge = (struct Edge*) malloc(sizeof(struct Edge));
    new_edge->node = node2;
    new_edge->weight = weight;
    new_edge->next = graph->adj_list[node1];
    graph->adj_list[node1] = new_edge;

    new_edge = (struct Edge*) malloc(sizeof(struct Edge));
    new_edge->node = node1;
    new_edge->weight = weight;
    new_edge->next = graph->adj_list[node2];
    graph->adj_list[node2] = new_edge;
}

void prim(struct Graph* graph) {
    int visited[MAX_NODES] = {0};
    int parent[MAX_NODES];
    int key[MAX_NODES];
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        key[i] = 1000000;
    }
    key[0] = 0;
    parent[0] = -1;
    int count;
    for (count = 0; count < graph->num_nodes - 1; count++) {
        int min_key = 1000000;
        int min_node;
        int j;
        for (j = 0; j < graph->num_nodes; j++) {
            if (!visited[j] && key[j] < min_key) {
                min_key = key[j];
                min_node = j;
            }
        }
        visited[min_node] = 1;
        struct Edge* edge = graph->adj_list[min_node];
        while (edge != NULL) {
            int node = edge->node;
            int weight = edge->weight;
            if (!visited[node] && weight < key[node]) {
                parent[node] = min_node;
                key[node] = weight;
            }
            edge = edge->next;
        }
    }
    printf("Edges of minimum spanning tree:\n");
    for (i = 1; i < graph->num_nodes; i++) {
        printf("(%d, %d) - %d\n", parent[i], i, key[i]);
    }
}

int main() {
    int num_nodes, num_edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    struct Graph* graph = create_graph(num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    int i;
    for (i = 0; i < num_edges; i++) {
        int node1, node2, weight;
        printf("Enter the endpoints and weight of edge %d: ", i + 1);
        scanf("%d%d%d", &node1, &node2, &weight);
        add_edge(graph, node1, node2, weight);
    }
    prim(graph);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// Edge structure
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Graph structure
typedef struct Graph {
    int V;
    int E;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Create a new graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;
}

// Find function for union-find algorithm
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// Union function for union-find algorithm
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Comparison function for sorting edges
int myComp(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

// Kruskal's algorithm to find minimum spanning tree
void KruskalMST(Graph* graph) {
    Edge result[MAX_VERTICES];
    int e = 0;
    int i = 0;

    Edge* edges = (Edge*) malloc(graph->E * sizeof(Edge));
    for (int u = 0; u < graph->V; u++) {
        for (int v = u + 1; v < graph->V; v++) {
            if (graph->adjMatrix[u][v] != 0) {
                edges[i].src = u;
                edges[i].dest = v;
                edges[i].weight = graph->adjMatrix[u][v];
                i++;
            }
        }
    }

    qsort(edges, graph->E, sizeof(edges[0]), myComp);

    int parent[MAX_VERTICES];
    for (int j = 0; j < graph->V; j++) {
        parent[j] = -1;
    }

    i = 0;
    while (e < graph->V - 1 && i < graph->E) {
        Edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    printf("Edges of Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d (%d)\n", result[i].src, result[i].dest, result[i].weight);
    }
}
int main() {
int V, E;
printf("Enter the number of vertices: ");
scanf("%d", &V);
printf("Enter the number of edges: ");
scanf("%d", &E);
Graph* graph = createGraph(V, E);

int src, dest, weight;
for (int i = 0; i < E; i++) {
    printf("Enter source, destination and weight of edge %d: ", i + 1);
    scanf("%d %d %d", &src, &dest, &weight);
    addEdge(graph, src, dest, weight);
}

KruskalMST(graph);

return 0;

}
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Edge {
    int u, v, weight;
} Edge;

int parent[MAX], rank[MAX];

// Function to find the set of a vertex
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

// Function to merge two sets
void merge(int x, int y) {
    if (rank[x] > rank[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
}

// Function to compare two edges based on weight
int cmp(const void* a, const void* b) {
    Edge* x = (Edge*)a;
    Edge* y = (Edge*)b;
    return x->weight - y->weight;
}

// Function to perform Kruskal's algorithm
void kruskal(int n, int m, Edge* edges) {
    int i, j, u, v, total_weight = 0;

    // Initialize parent and rank arrays
    for (i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by weight
    qsort(edges, m, sizeof(Edge), cmp);

    // Find MST using Kruskal's algorithm
    for (i = 0; i < m; i++) {
        u = find(edges[i].u);
        v = find(edges[i].v);
        if (u != v) {
            printf("(%d, %d) weight: %d\n", edges[i].u, edges[i].v, edges[i].weight);
            total_weight += edges[i].weight;
            merge(u, v);
        }
    }

    printf("Total weight of MST: %d\n", total_weight);
}

int main() {
    int n, m, i, u, v, weight;
    Edge* edges;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Allocate memory for edges array
    edges = (Edge*)malloc(m * sizeof(Edge));

    // Read edges from input
    printf("Enter edges and their weights:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].weight = weight;
    }

    // Find MST using Kruskal's algorithm
    kruskal(n, m, edges);

    return 0;
}
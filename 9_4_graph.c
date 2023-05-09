#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

struct Node {
    int dest;
    int weight;
    struct Node* next;
};

struct Graph {
    int num_nodes;
    struct Node* adj_list[MAX_NODES];
};

struct Graph* create_graph(int num_nodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;

    for (int i = 0; i < num_nodes; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

void add_edge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->dest = dest;
    new_node->weight = weight;
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
}

void dijkstra(struct Graph* graph, int start_node, int end_node) {
    int distance[MAX_NODES];
    int visited[MAX_NODES];
    int previous[MAX_NODES];
    int min_distance, next_node;

    for (int i = 0; i < graph->num_nodes; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
        previous[i] = -1;
    }

    distance[start_node] = 0;

    for (int i = 0; i < graph->num_nodes - 1; i++) {
        min_distance = INT_MAX;

        for (int j = 0; j < graph->num_nodes; j++) {
            if (!visited[j] && distance[j] <= min_distance) {
                min_distance = distance[j];
                next_node = j;
            }
        }

        visited[next_node] = 1;

        struct Node* neighbor = graph->adj_list[next_node];

        while (neighbor != NULL) {
            int new_distance = distance[next_node] + neighbor->weight;

            if (new_distance < distance[neighbor->dest]) {
                distance[neighbor->dest] = new_distance;
                previous[neighbor->dest] = next_node;
            }

            neighbor = neighbor->next;
        }
    }

    if (distance[end_node] == INT_MAX) {
        printf("There is no path between nodes %d and %d.\n", start_node, end_node);
        return;
    }

    printf("The shortest distance between nodes %d and %d is %d.\n", start_node, end_node, distance[end_node]);

    int path[MAX_NODES];
    int path_length = 0;
    int current_node = end_node;

    while (current_node != start_node) {
        path[path_length] = current_node;
        path_length++;
        current_node = previous[current_node];
    }

    path[path_length] = start_node;
    path_length++;

    printf("The shortest path between nodes %d and %d is: ", start_node, end_node);

    for (int i = path_length - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }

    printf("\n");
}

int main() {
struct Graph* graph = create_graph(6);
add_edge(graph, 0, 1, 4);
add_edge(graph, 0, 2, 3);
add_edge(graph, 1, 2, 1);
add_edge(graph, 1, 3, 2);
add_edge(graph, 2, 3, 4);
add_edge(graph, 2, 4, 3);
add_edge(graph, 3, 4, 2);
add_edge(graph, 3, 5, 1);
add_edge(graph, 4, 5, 4);

dijkstra(graph, 0, 5);

return 0;
}
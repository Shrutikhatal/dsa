#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    struct Node* adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

void initGraph(struct Graph* graph, int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void printGraph(struct Graph* graph, int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void bfs(struct Graph* graph, int startVertex, int numVertices) {
    struct Node* queue[MAX_VERTICES];
    int front = -1, rear = -1;

    graph->visited[startVertex] = 1;
    queue[++rear] = graph->adjList[startVertex];

    while (front != rear) {
        struct Node* currentNode = queue[++front];
        printf("%d ", currentNode->vertex);

        while (currentNode) {
            int adjVertex = currentNode->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[++rear] = graph->adjList[adjVertex];
            }

            currentNode = currentNode->next;
        }
    }
}

void dfs(struct Graph* graph, int currentVertex) {
    graph->visited[currentVertex] = 1;
    printf("%d ", currentVertex);

    struct Node* currentNode = graph->adjList[currentVertex];
    while (currentNode) {
        int adjVertex = currentNode->vertex;

        if (graph->visited[adjVertex] == 0) {
            dfs(graph, adjVertex);
        }

        currentNode = currentNode->next;
    }
}

int main() {
    struct Graph graph;
    int numVertices, numEdges, i, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initGraph(&graph, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numEdges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printGraph(&graph, numVertices);

    printf("BFS traversal: ");
    bfs(&graph, 0, numVertices);

    for (i = 0; i < numVertices; i++) {
        graph.visited[i] = 0;
    }

    printf("\nDFS traversal: ");
    dfs(&graph, 0);

    return 0;
}

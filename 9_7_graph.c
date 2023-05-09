#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6  // Number of vertices

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
  
    printPath(parent, parent[j]);
  
    printf("%d ", j);
}

int printSolution(int dist[], int n, int parent[], int src, int dest)
{
    printf("Shortest distance from %d to %d is: %d\n", src, dest, dist[dest]);
    printf("Path: %d ", src);
    printPath(parent, dest);
    printf("\n");
}

void dijkstra(int graph[V][V], int src, int dest)
{
    int dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0, parent[i] = -1;
  
    dist[src] = 0;
  
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
  
        sptSet[u] = 1;
  
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
  
    printSolution(dist, V, parent, src, dest);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0 },
                        { 4, 0, 8, 0, 0, 0 },
                        { 0, 8, 0, 7, 0, 4 },
                        { 0, 0, 7, 0, 9, 14 },
                        { 0, 0, 0, 9, 0, 10 },
                        { 0, 0, 4, 14, 10, 0 } };
    int src = 0, dest = 2;
  
    dijkstra(graph, src, dest);
  
    return 0;
}

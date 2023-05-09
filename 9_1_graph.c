/*Write a c Program to accept a graph from user and represent it
with Adjacency Matrix and perform BFS and DFS traversals on
it.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
void creategraph(int adjM[][MAX_NODES], int n){
    int i , j, origin , dest;
    printf("Enter edges in format origin-> destination\n");
    for(int i=0; i<n;i++){
        scanf("%d%d", &origin,&dest);
        adjM[origin][dest]=1;
        adjM[dest][origin]=1;
    }
}
void printgraph(int adjM[][MAX_NODES],int n){
    printf("Adjancy matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",adjM[i][j]);
            printf("\n ");
        }
    }
}

void BFS(int adjM[][MAX_NODES], int n, int start){
    int visited[MAX_NODES]={0};
    int queue[MAX_NODES], front=-1, rear=-1;
    visited[start]=1;
    queue[++rear]=start;
    while(front!=rear){
        int current=queue[++front];
        printf("%d ", current);
        for(int i=0; i<n;i++){
        if(adjM[current][i]==1 && visited[i]==0){
         visited[i]=1;
         queue[++rear]=i;
            }
        }
    }
    printf("\n");
}

void dfs(int adjM[][MAX_NODES], int n, int start,int visited[]){
    visited[start]=1;
    printf("%d ", start);
    for(int i=0;i<n;i++){
        if(adjM[start][i]==1 && visited[i]==0){
            dfs(adjM, n , i, visited);
        }
    }
}
int main(){
int adjM[MAX_NODES][MAX_NODES] = {0};
    int n, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    creategraph(adjM, n);
    printgraph(adjM, n);

    printf("Enter starting node for BFS: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
        BFS(adjM, n, start);

    int visited[MAX_NODES] = {0};
    printf("Enter starting node for DFS: ");
    scanf("%d", &start);
    printf("DFS traversal: ");
    dfs(adjM, n, start, visited);
    printf("\n");
    return 0;
}
#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX], visited[MAX], count, mindistance, nextnode, i, j;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = (G[i][j] == 0) ? INFINITY : G[i][j];
    
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    
    while (count < n - 1) {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i] && mindistance + cost[nextnode][i] < distance[i]) {
                distance[i] = mindistance + cost[nextnode][i];
                pred[i] = nextnode;
            }
        count++;
    }
    
    for (i = 0; i < n; i++)
        if (i != startnode) {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            while (j != startnode) {
                j = pred[j];
                printf(" <- %d", j);
            }
        }
}

int main() {
    int G[MAX][MAX], n, u, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    
    printf("\nEnter the starting node: ");
    scanf("%d", &u);
    dijkstra(G, n, u);
    
    return 0;
}

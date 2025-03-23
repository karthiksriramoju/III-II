#include <stdio.h>
#define MAX 10
#define INF 9999

int G[MAX][MAX], spanning[MAX][MAX], n;

int prims() {
    int cost[MAX][MAX], visited[MAX] = {0}, distance[MAX], from[MAX], min_cost = 0, no_of_edges = n - 1;

    // Initialize cost matrix and spanning tree matrix
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cost[i][j] = (G[i][j] == 0) ? INF : G[i][j], spanning[i][j] = 0;

    visited[0] = 1;
    for (int i = 1; i < n; i++) distance[i] = cost[0][i], from[i] = 0;

    while (no_of_edges--) {
        int min_distance = INF, v = -1;
        for (int i = 1; i < n; i++)
            if (!visited[i] && distance[i] < min_distance)
                v = i, min_distance = distance[i];

        if (v == -1) break; // No valid vertex found

        int u = from[v];
        spanning[u][v] = spanning[v][u] = distance[v];  // Add edge to spanning tree
        visited[v] = 1;
        min_cost += cost[u][v];

        for (int i = 1; i < n; i++)
            if (!visited[i] && cost[i][v] < distance[i])
                distance[i] = cost[i][v], from[i] = v;
    }
    return min_cost;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter adjacency matrix:\n");
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &G[i][j]);

    int total_cost = prims();

    printf("\nSpanning tree matrix:\n");
    for (int i = 0; i < n; i++, printf("\n")) 
        for (int j = 0; j < n; j++) 
            printf("%d\t", spanning[i][j]);

    printf("\nTotal cost of spanning tree = %d\n", total_cost);
    return 0;
}

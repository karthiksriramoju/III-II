#include <stdio.h>

#define INF 999

int graph[20][20], mst[20][20], n;

int prims() {
    int cost[20][20], dist[20], parent[20], visited[20];
    int i, j, edgesLeft, u, v, minDist, totalCost = 0;

    // Initialize cost matrix and MST matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cost[i][j] = (graph[i][j] == 0) ? INF : graph[i][j];
            mst[i][j] = 0;
        }
    }

    // Initialize dist, parent, visited arrays
    dist[0] = 0; visited[0] = 1;
    for (i = 1; i < n; i++) {
        dist[i] = cost[0][i];
        parent[i] = 0;
        visited[i] = 0;
    }

    edgesLeft = n - 1;

    while (edgesLeft > 0) {
        minDist = INF;
        v = -1;

        // Find unvisited vertex with minimum dist
        for (i = 1; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                v = i;
                minDist = dist[i];
            }
        }
        if (v == -1) break; // No more edges

        u = parent[v];
        mst[u][v] = mst[v][u] = cost[u][v];
        visited[v] = 1;
        totalCost += cost[u][v];
        edgesLeft--;

        // Update distances
        for (i = 1; i < n; i++) {
            if (!visited[i] && cost[v][i] < dist[i]) {
                dist[i] = cost[v][i];
                parent[i] = v;
            }
        }
    }

    return totalCost;
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int cost = prims();

    printf("\nMinimum cost of spanning tree: %d\n", cost);
    printf("\nEdges in the spanning tree:\n");
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (mst[i][j] != 0)
                printf("%d - %d: %d\n", i, j, mst[i][j]);

    return 0;
}

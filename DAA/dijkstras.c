#include <stdio.h>
#include <limits.h>

#define MAX 10

int nextNode(int dist[], int vis[], int n) {
    int min = INT_MAX, min_idx = -1;
    for (int i = 0; i < n; i++)
        if (!vis[i] && dist[i] < min) {
            min = dist[i];
            min_idx = i;
        }
    return min_idx;
}

void printPath(int pred[], int j) {
    if (pred[j] == -1)
        return;
    printPath(pred, pred[j]);
    printf(" <- %d", j);
}

int main() {
    int graph[MAX][MAX], dist[MAX], vis[MAX], pred[MAX];
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        vis[i] = 0;
        pred[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = nextNode(dist, vis, n);
        vis[u] = 1;

        for (int v = 0; v < n; v++) {
            if (vis[v] || graph[u][v] == 0 || dist[u] == INT_MAX)
                continue;

            int newDist = dist[u] + graph[u][v];
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pred[v] = u;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        printf("\nDistance of node %d = %d", i, dist[i]);
        printf("\nPath = %d", start);
        printPath(pred, i);
        printf("\n");
    }

    return 0;
}

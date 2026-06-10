#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int minDistance(int V, int dist[], bool sptSet[]) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int V, int dist[], int src) {
    printf("\nShortest distances from Source Vertex %d:\n", src);
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t\t INF (Unreachable)\n", i);
         else
            printf("%d \t\t %d\n", i, dist[i]);

    }
}
void dijkstra(int V, int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(V, dist, sptSet);
        if (u == -1 || dist[u] == INT_MAX)
            break;
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(V, dist, src);
}
int main() {
    int V, src;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("\nEnter the adjacency matrix (%d x %d):\n", V, V);
    printf("(Type 0 if there is no direct edge between the vertices)\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    }
    printf("\nEnter the starting (source) vertex (0 to %d): ", V - 1);
    scanf("%d", &src);
    if (src < 0 || src >= V) {
        printf("Invalid source vertex. It must be between 0 and %d.\n", V - 1);
        return 1;
    }
    dijkstra(V, graph, src);
    return 0;
}

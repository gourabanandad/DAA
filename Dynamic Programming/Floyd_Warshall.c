#include <stdio.h>
#include <limits.h>
#define INF 999
void floydwarshall(int n, int graph[][n]){
    int dist[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = graph[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Shortest distances between every pair of vertices:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    int n = 3;
    // printf("Enter the number of vertices: ");
    // scanf("%d", &n);
    int graph[n][n];
    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         scanf("%d", &graph[i][j]);
    //         if (i == j) {
    //             graph[i][j] = 0; // Distance to self is zero
    //         }
    //     }
    // }
    graph[0][0] = 0; graph[0][1] = 3; graph[0][2] = INF; graph[0][3] = 5;
    graph[1][0] = 2; graph[1][1] = 0; graph[1][2] = INF; graph[1][3] = 4;
    graph[2][0] = INF; graph[2][1] = 1; graph[2][2] = 0; graph[2][3] = INF;
    graph[3][0] = INF; graph[3][1] = INF; graph[3][2] = 2; graph[3][3] = 0;
    floydwarshall(n, graph);
    return 0;
}
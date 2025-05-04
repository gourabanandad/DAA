#include <stdio.h>
#include<stdbool.h>

void dfs(int matrix[10][10], int node, bool visited[]){
    printf("%d\n", node);
    visited[node] = true;
    for(int i=0;i<10;i++){
        if(matrix[node][i]==1 && !visited[i]){
            dfs(matrix, i, visited);
        }
    }
}
int main() {
    int matrx[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 0, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}};
    bool visited[10];
    for(int i=0;i<10;i++){
        visited[i] = false;
    }
    dfs(matrx, 2, visited);
    return 0;
}
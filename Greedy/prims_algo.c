// Prims algorithm: Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.
// It is a popular algorithm used in network design, clustering, and other applications.
#include <stdio.h>

int main() {
    // Your code here
    // Example graph represented as an adjacency matrix
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    int numVertices = 5;
    int selected[5] = {0}; // Track selected vertices
    int numEdges = 0; // Number of edges in the MST
    int totalWeight = 0; // Total weight of the MST
    selected[0] = 1; // Start with the first vertex
    printf("Edges in the MST:\n");
    while (numEdges < numVertices - 1) {
        int minWeight = 999999; // Initialize to a large value
        int u = -1, v = -1; // Track the vertices of the minimum edge
        for (int i = 0; i < numVertices; i++) {
            if (selected[i]) { // If vertex i is selected
                for (int j = 0; j < numVertices; j++) {
                    if (!selected[j] && graph[i][j] && graph[i][j] < minWeight) {
                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        selected[v] = 1; // Select vertex v
        printf("%d -- %d == %d\n", u, v, minWeight);
        totalWeight += minWeight;
        numEdges++;
    }
    printf("Total weight of MST: %d\n", totalWeight);
    // Note: In a real implementation, you would also need to handle the case where the graph is not connected.
    // This implementation assumes a connected graph.
    // In a real-world scenario, you would also need to free any dynamically allocated memory.
    // In this case, we are not using dynamic memory allocation, so no need to free anything.
    // If you were to use dynamic memory allocation, you would typically use malloc() to allocate memory
    // and free() to deallocate it when it's no longer needed.
    // Example of dynamic memory allocation (not used in this case)
    // int* dynamicArray = (int*)malloc(numVertices * sizeof(int));
    return 0;
}
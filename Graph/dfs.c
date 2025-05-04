/*
    Problem Statement:
    -------------------
    Given an undirected graph represented by an adjacency matrix, perform a Depth-First
    Search (DFS) traversal starting from a specified node. The program should print the
    nodes visited during the traversal.

    DFS is a graph traversal algorithm that explores as far as possible along each branch
    before backtracking. It can be used to explore connected components, detect cycles, or
    find paths in a graph. The graph is represented as a 10x10 adjacency matrix where
    matrix[i][j] = 1 indicates an edge between nodes i and j.

    Example:
    Input:
        Adjacency matrix (10x10) with edges as defined in the code, start node = 2

    Output:
        2
        1
        3
        4
        5
        6
        7
        8
        0
        9

    Explanation:
        Starting from node 2, DFS explores nodes in a depth-first manner, visiting all
        reachable nodes in the connected component containing node 2. The output shows
        the order of nodes visited.

    Approach:
    ---------
    Three methods are implemented below:
    1. Standard DFS (Original): Recursive DFS traversal starting from a given node.
    2. Iterative DFS: Uses a stack to perform DFS iteratively, avoiding recursion.
    3. DFS with Component Counting: Counts the number of connected components in the graph.
*/

#include <stdio.h>
#include <stdbool.h>

// ----------------------
// 1. Standard DFS (Original)
// ----------------------
void dfs_standard(int matrix[10][10], int node, bool visited[]) {
    // Print the current node and mark it as visited
    printf("%d\n", node);
    visited[node] = true;

    // Explore all adjacent nodes
    for (int i = 0; i < 10; i++) {
        // If there is an edge and the node is not visited, recurse
        if (matrix[node][i] == 1 && !visited[i]) {
            dfs_standard(matrix, i, visited);
        }
    }
}

// ----------------------
// 2. Iterative DFS
// ----------------------
void dfs_iterative(int matrix[10][10], int start, bool visited[]) {
    // Create a stack for iterative DFS
    int stack[10];
    int top = -1;

    // Push the starting node to the stack
    stack[++top] = start;

    // Process nodes until the stack is empty
    while (top >= 0) {
        // Pop a node from the stack
        int node = stack[top--];

        // If not visited, print and mark as visited
        if (!visited[node]) {
            printf("%d\n", node);
            visited[node] = true;
        }

        // Push all unvisited adjacent nodes to the stack
        for (int i = 9; i >= 0; i--) { // Reverse order to mimic recursive DFS
            if (matrix[node][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
}

// ----------------------
// 3. DFS with Component Counting
// ----------------------
void dfs_component(int matrix[10][10], int node, bool visited[]) {
    // Mark the current node as visited
    visited[node] = true;

    // Explore all adjacent nodes
    for (int i = 0; i < 10; i++) {
        if (matrix[node][i] == 1 && !visited[i]) {
            dfs_component(matrix, i, visited);
        }
    }
}

int count_components(int matrix[10][10], int n) {
    // Initialize visited array
    bool visited[10] = {false};
    int components = 0;

    // Perform DFS from each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_component(matrix, i, visited);
            components++;
        }
    }

    return components;
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Initialize adjacency matrix for a graph with 10 nodes
    int matrix[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0, 1, 0, 1},
        {0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    // Initialize visited array
    bool visited[10] = {false};

    // -------- Standard DFS --------
    printf("DFS traversal starting from node 2:\n");
    dfs_standard(matrix, 2, visited);

    // -------- Iterative DFS --------
    // for (int i = 0; i < 10; i++) visited[i] = false;
    // printf("Iterative DFS traversal starting from node 2:\n");
    // dfs_iterative(matrix, 2, visited);

    // -------- DFS with Component Counting --------
    // printf("Number of connected components: %d\n", count_components(matrix, 10));

    return 0;
}
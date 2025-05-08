/*
    Problem Statement:
    -------------------
    Given weights and values of `n` items, put these items in a knapsack of capacity `w` 
    to get the **maximum total value** in the knapsack.

    Each item can be included **at most once** (0/1 Knapsack Problem).

    Example:
    --------
    Input:
        weights[] = {1, 3, 4, 6}
        values[]  = {2, 3, 5, 7}
        capacity w = 10

    Output: 12
    (We can include items with weights 4 and 6, values 5 and 7 → total value = 12)

    Approach:
    ---------
    - Use Dynamic Programming (Tabulation) to build a table `t[w+1][n+1]`.
    - `t[i][j]` represents the maximum value for weight `i` using first `j` items.
    - If weight of current item > capacity, we ignore it.
    - Otherwise, we take the maximum of:
        a) Including the item → value + solve for remaining capacity
        b) Excluding the item → carry over previous best result
*/

#include <stdio.h>

// Utility function to return maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack using Tabulation (Bottom-Up Dynamic Programming)
int knapsack(int weights[], int values[], int w, int n) {
    int t[w + 1][n + 1];  // DP table: t[i][j] stores max value with capacity i and j items

    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;  // Base Case: 0 capacity or 0 items = 0 value
            }
            else if (weights[j - 1] > i) {
                t[i][j] = t[i][j - 1];  // Cannot include item j-1
            }
            else {
                // Include item j-1 or exclude it
                t[i][j] = max(values[j - 1] + t[i - weights[j - 1]][j - 1],
                             t[i][j - 1]);
            }
        }
    }

    return t[w][n];  // Max value with full capacity and all items
}

int main() {
    int weights[] = {1, 3, 4, 6};
    int values[]  = {2, 3, 5, 7};
    int w = 10;  // Knapsack capacity
    int n = sizeof(weights) / sizeof(int);  // Number of items

    printf("Maximum value that can be put in knapsack: %d\n", knapsack(weights, values, w, n));
    return 0;
}

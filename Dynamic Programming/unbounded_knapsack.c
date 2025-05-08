/*
    Problem Statement:
    -------------------
    Given a set of items, each with a weight and a value, and a knapsack with a maximum
    weight capacity, determine the maximum value that can be achieved by selecting items
    such that the total weight does not exceed the knapsack capacity. Unlike the 0/1
    Knapsack problem, each item can be selected an unlimited number of times.

    This is known as the Unbounded Knapsack problem, where the goal is to maximize the
    total value while respecting the weight constraint.

    Example:
    Input:
        weights[] = {1, 3, 4, 6}
        values[] = {2, 3, 5, 7}
        w = 10 (knapsack capacity)
        n = 4 (number of items)

    Output:
        20

    Explanation:
        To achieve the maximum value of 20 within a weight limit of 10:
        - Select the item with weight 1 and value 2 ten times (10 * 2 = 20).
        - Total weight = 10 * 1 = 10, which is within the capacity.
        Other combinations are possible but yield lower values.

    Approach:
    ---------
    Three methods are implemented below:
    1. Divide and Conquer (Recursive): Uses recursion to explore all possible combinations.
    2. Memoization (Top-down DP): Uses a memoization table to avoid redundant calculations.
    3. Tabulation (Bottom-up DP): Uses a 2D DP table to compute the maximum value iteratively.
*/

#include <stdio.h>
#include <string.h>

// ----------------------
// Utility function to find maximum of two integers
// ----------------------
int max(int a, int b) {
    // Return the larger of a or b
    return (a > b) ? a : b;
}

// ----------------------
// 1. Divide and Conquer (Recursive)
// ----------------------
int unbounded_knapsack_recursive(int weights[], int values[], int w, int n) {
    // Base case: If capacity is 0 or no items are left, no value can be achieved
    if (w == 0 || n == 0) return 0;

    // If current item's weight exceeds remaining capacity, exclude it
    if (weights[n-1] > w)
        return unbounded_knapsack_recursive(weights, values, w, n-1);

    // Choose maximum of including the current item (multiple times possible) or excluding it
    return max(values[n-1] + unbounded_knapsack_recursive(weights, values, w - weights[n-1], n),
               unbounded_knapsack_recursive(weights, values, w, n-1));
}

// ----------------------
// 2. Memoization (Top-down DP)
// ----------------------
int unbounded_knapsack_memo(int weights[], int values[], int w, int n, int t[][100]) {
    // Base case: If capacity is 0 or no items are left, no value can be achieved
    if (w == 0 || n == 0) return 0;

    // If result is already computed, return it
    if (t[w][n] != -1) return t[w][n];

    // If current item's weight exceeds remaining capacity, exclude it
    if (weights[n-1] > w)
        t[w][n] = unbounded_knapsack_memo(weights, values, w, n-1, t);
    else
        // Choose maximum of including the current item or excluding it
        t[w][n] = max(values[n-1] + unbounded_knapsack_memo(weights, values, w - weights[n-1], n, t),
                      unbounded_knapsack_memo(weights, values, w, n-1, t));

    return t[w][n];
}

// ----------------------
// 3. Tabulation (Bottom-up DP)
// ----------------------
int unbounded_knapsack_tabulation(int weights[], int values[], int w, int n) {
    // Create DP table with dimensions (w+1) x (n+1)
    int t[w+1][n+1];

    // Initialize the table
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= n; j++) {
            // Base case: If capacity is 0 or no items, value is 0
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
            // If current item's weight exceeds capacity, exclude it
            else if (weights[j-1] > i) {
                t[i][j] = t[i][j-1];
            }
            // Choose maximum of including the current item or excluding it
            else {
                t[i][j] = max(values[j-1] + t[i - weights[j-1]][j], t[i][j-1]);
            }
        }
    }

    // Final answer: maximum value achievable with capacity w and n items
    return t[w][n];
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Input arrays and knapsack capacity
    int weights[] = {1, 3, 4, 6};
    int values[] = {2, 3, 5, 7};
    int w = 10; // Knapsack capacity
    int n = sizeof(weights) / sizeof(int); // Number of items

    // -------- Divide and Conquer --------
    // printf("Recursive: %d\n", unbounded_knapsack_recursive(weights, values, w, n));

    // -------- Memoization --------
    // int t[100][100];
    // memset(t, -1, sizeof(t));
    // printf("Memoization: %d\n", unbounded_knapsack_memo(weights, values, w, n, t));

    // -------- Tabulation --------
    printf("Tabulation: %d\n", unbounded_knapsack_tabulation(weights, values, w, n));

    return 0;
}
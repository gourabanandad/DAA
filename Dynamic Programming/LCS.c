/*
    Problem Statement:
    -------------------
    Given two strings `x` and `y`, find the **length of their Longest Common Subsequence (LCS)**.

    A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
    For example, the LCS of "ABCBDAB" and "BDCABAD" is "BDAB", and its length is 4.

    Approaches Used:
    ----------------
    1. Brute Force (Commented out): Recursively checks all combinations - exponential time.
    2. Memoization (Top-down DP): Optimizes the brute-force by storing intermediate results in a table.
       Time Complexity: O(m * n), Space Complexity: O(m * n)
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

// Utility function to return the maximum of two integers
int max(int a, int b){
    return (a > b) ? a : b;
}

// 2D memoization table to store results of subproblems
int t[100][100];

// Function to compute LCS length using memoization
int lcs(char *x, char *y, int m, int n){
    if (m == 0 || n == 0) {
        return t[m][n] = 0;  // Base Case: one of the strings is empty
    }
    if (t[m][n] != -1) {
        return t[m][n];  // If already computed, return the result
    }
    if (x[m - 1] == y[n - 1]) {
        // If characters match, include it and move both pointers
        t[m][n] = 1 + lcs(x, y, m - 1, n - 1);
    } else {
        // If not matched, try two options: exclude from x or from y
        t[m][n] = max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
    }
    return t[m][n];
}

int main() {
    // Input strings
    char x[] = "ABCBDABABCBDABABCBDABABCBDAB";
    char y[] = "BDCABADBDCABADBDCABADBDCABAD";

    // Variables to measure time
    clock_t start, end;
    double time_used;

    // Lengths of the strings
    int m = strlen(x);
    int n = strlen(y);

    // Start measuring execution time
    start = clock();

    // Initialize memoization table with -1
    memset(t, -1, sizeof(t));

    // Compute LCS
    printf("Length of LCS: %d\n", lcs(x, y, m, n));

    // End measuring time
    end = clock();

    // Calculate and print time taken
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %.8f seconds\n", time_used);

    return 0;
}

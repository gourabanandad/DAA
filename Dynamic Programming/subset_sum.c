/*
    Problem Statement:
    -------------------
    Given an array of positive integers and a target sum, count the number of subsets
    of the array whose sum is equal to the target sum.

    This is a variation of the Subset Sum problem where we are asked to count
    all possible subsets instead of just checking existence.

    Example:
    Input:
        arr[] = {2, 8, 10, 5, 3, 7}
        sum = 10

    Output:
        3

    Explanation:
        The subsets that sum to 10 are:
        - {2, 8}
        - {10}
        - {3, 7}

    Approach:
    ---------
    Three methods are implemented below:
    1. Divide and Conquer (Recursive): Uses recursion to explore all subsets.
    2. Memoization (Top-down DP): Uses a memoization table to avoid redundant calculations.
    3. Tabulation (Bottom-up DP): Uses a 2D DP table to compute the count iteratively.
*/

#include <stdio.h>
#include <string.h>

// ----------------------
// 1. Divide and Conquer (Recursive)
// ----------------------
int count_subset_sum_recursive(int *arr, int sum, int n) {
    // Base case: If sum becomes 0, a valid subset is found
    if (sum == 0) return 1;

    // If no items are left and sum is still positive, no subset is possible
    if (n == 0) return 0;

    // If current element is greater than remaining sum, exclude it
    if (arr[n-1] > sum)
        return count_subset_sum_recursive(arr, sum, n-1);

    // Include the current element (subtract it from sum) or exclude it
    return count_subset_sum_recursive(arr, sum - arr[n-1], n-1) + 
           count_subset_sum_recursive(arr, sum, n-1);
}

// ----------------------
// 2. Memoization (Top-down DP)
// ----------------------
int count_subset_sum_memo(int *arr, int sum, int n, int t[][100]) {
    // Base case: If sum is 0, one subset (empty subset) is found
    if (sum == 0) return 1;

    // If no items are left and sum is not zero, no subset is possible
    if (n == 0) return 0;

    // If result is already computed, return it
    if (t[n][sum] != -1) return t[n][sum];

    // If current item is greater than sum, exclude it
    if (arr[n-1] > sum)
        t[n][sum] = count_subset_sum_memo(arr, sum, n-1, t);
    else
        // Include or exclude current item
        t[n][sum] = count_subset_sum_memo(arr, sum - arr[n-1], n-1, t) + 
                     count_subset_sum_memo(arr, sum, n-1, t);

    return t[n][sum];
}

// ----------------------
// 3. Tabulation (Bottom-up DP)
// ----------------------
int count_subset_sum_tabulation(int *arr, int sum, int n) {
    // Create DP table with dimensions (n+1) x (sum+1)
    int t[n+1][sum+1];

    // Initialize the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            // Base case: Empty subset always makes sum 0
            if (j == 0) {
                t[i][j] = 1;
            }
            // If no items and sum > 0, no subset is possible
            else if (i == 0) {
                t[i][j] = 0;
            }
            // If current element is greater than sum, exclude it
            else if (arr[i-1] > j) {
                t[i][j] = t[i-1][j];
            }
            // Include or exclude the current element
            else {
                t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
            }
        }
    }

    // Final answer: number of subsets to form 'sum' using 'n' elements
    return t[n][sum];
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Input array and target sum
    int arr[] = {2, 8, 10, 5, 3, 7};
    int sum = 10;
    int n = sizeof(arr) / sizeof(int);

    // -------- Divide and Conquer --------
    // printf("Recursive: %d\n", count_subset_sum_recursive(arr, sum, n));

    // -------- Memoization --------
    // int t[100][100];
    // memset(t, -1, sizeof(t));
    // printf("Memoization: %d\n", count_subset_sum_memo(arr, sum, n, t));

    // -------- Tabulation --------
    printf("Tabulation: %d\n", count_subset_sum_tabulation(arr, sum, n));

    return 0;
}
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
    Three methods are shown below:
    1. Divide and Conquer (recursive)
    2. Memoization (Top-down DP)
    3. Tabulation (Bottom-up DP)
*/

#include <stdio.h>
#include <string.h>

// ----------------------
// 1. Divide and Conquer (Recursive)
// ----------------------

// int count_subset_sum(int *arr, int sum, int n) {
//     // Base case: If sum becomes 0, we've found a valid subset
//     if (sum == 0) return 1;

//     // If no items left and sum is still positive, no subset possible
//     if (n == 0) return 0;

//     // If current element is greater than remaining sum, exclude it
//     if (arr[n-1] > sum)
//         return count_subset_sum(arr, sum, n-1);

//     // Include the element or exclude it
//     return count_subset_sum(arr, sum - arr[n-1], n-1) + count_subset_sum(arr, sum, n-1);
// }

// ----------------------
// 2. Memoization (Top-down DP)
// ----------------------

// int count_subset_sum(int *arr, int sum, int n, int t[n+1][sum+1]) {
//     // Base case: if sum is 0, one subset (empty subset) is found
//     if (sum == 0) return 1;

//     // If no items left and sum is not zero, no subset is possible
//     if (n == 0) return 0;

//     // If result already computed, return it
//     if (t[n][sum] != -1) return t[n][sum];

//     // If current item is greater than sum, exclude it
//     if (arr[n-1] > sum)
//         t[n][sum] = count_subset_sum(arr, sum, n-1, t);
//     else
//         // Include or exclude current item
//         t[n][sum] = count_subset_sum(arr, sum - arr[n-1], n-1, t) + count_subset_sum(arr, sum, n-1, t);

//     return t[n][sum];
// }

// ----------------------
// 3. Tabulation (Bottom-up DP)
// ----------------------

int count_subset_sum(int *arr, int sum, int n) {
    // Create DP table
    int t[n+1][sum+1];

    // Fill the table using bottom-up approach
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {

            if (j == 0) {
                // Base case: Empty subset always makes sum 0
                t[i][j] = 1;
            }
            else if (i == 0) {
                // If no items and sum > 0, no subset possible
                t[i][j] = 0;
            }
            else if (arr[i-1] > j) {
                // If current element is greater than sum, exclude it
                t[i][j] = t[i-1][j];
            }
            else {
                // Include or exclude the current element
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
    int arr[] = {2, 8, 10, 5, 3, 7};
    int sum = 10;
    int n = sizeof(arr) / sizeof(int);

    // -------- Divide and Conquer --------
    // printf("%d ", count_subset_sum(arr, sum, n));

    // -------- Memoization --------
    // int t[n+1][sum+1];
    // memset(t, -1, sizeof(t));
    // printf("%d ", count_subset_sum(arr, sum, n, t));

    // -------- Tabulation --------
    printf("%d ", count_subset_sum(arr, sum, n));

    return 0;
}

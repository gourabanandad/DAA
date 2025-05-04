/*
    Problem Statement:
    -------------------
    Given an array `arr[]` representing the dimensions of matrices in a chain,
    where the i-th matrix has dimensions arr[i-1] x arr[i],
    find the **minimum number of scalar multiplications** needed to multiply the chain.

    Example:
    For arr[] = {10, 20, 40, 30, 50}, there are 4 matrices:
        M1: 10x20
        M2: 20x40
        M3: 40x30
        M4: 30x50
    Task: Determine the optimal order of matrix multiplication to minimize cost.

    Approach:
    ---------
    - This is solved using recursion (Divide and Conquer).
    - We try every possible place to split the product (from i to j) and recursively compute the cost.
    - Cost of multiplication is calculated as arr[i-1] * arr[k] * arr[j].
    - Base Case: If i >= j, no matrix or a single matrix, so cost = 0.

    Note: This is an inefficient approach for large inputs. A DP (memoized) or tabulated version is better.
*/

#include <stdio.h>
#include <limits.h>

// Recursive function to find minimum multiplication cost
int mcm(int *arr, int i, int j) {
    int mn = INT_MAX;

    // Base case: Only one matrix or no matrix
    if(i >= j) {
        return 0;
    }

    // Try all possible positions to split the matrix chain
    for(int k = i; k < j; k++) {
        // Cost = cost of multiplying left half + right half + cost of multiplying resulting matrices
        int cost = mcm(arr, i, k) + mcm(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);

        // Store minimum cost
        if(cost < mn) {
            mn = cost;
        }
    }

    return mn;
}

int main() {
    int arr[] = {10, 20, 40, 30, 50};
    int n = sizeof(arr) / sizeof(int);

    // Call MCM with i = 1 and j = n-1 (as the array stores dimensions, not matrices)
    printf("Minimum number of multiplications: %d\n", mcm(arr, 1, n - 1));
    return 0;
}

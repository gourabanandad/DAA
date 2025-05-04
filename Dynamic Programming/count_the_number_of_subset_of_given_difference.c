/*
    Problem Statement:
    -------------------
    Given an array of positive integers and a target difference (diff), count the number of ways
    to partition the array into two subsets such that the **difference between the sum** of the two subsets is equal to `diff`.

    That is, count the number of subsets such that:
        |sum(S1) - sum(S2)| = diff

    This is commonly solved by converting it to a subset sum problem using the formula:

        sum(S1) - sum(S2) = diff
        sum(S1) + sum(S2) = total_sum
        --------------------------------
        => 2 * sum(S1) = total_sum + diff
        => sum(S1) = (total_sum + diff) / 2

    So now, the task reduces to:
        Find number of subsets with sum = (total_sum + diff)/2

    Constraints:
    - total_sum + diff must be even, otherwise no valid subset.

    Example:
    Input: arr[] = {5, 8, 12, 4, 10}, diff = 1  
    Output: 3
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Function to count number of subsets with given difference
int count_given_diff_subset(int *arr, int sum, int n, int diff) {
    int s = (sum + diff) / 2; // required subset sum

    // Initialize DP table
    int t[n+1][s+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {

            if (i == 0) {
                // No elements — no subset can be formed except when j=0
                t[i][j] = 0;
            } 
            else if (j == 0) {
                // There's always one subset with sum = 0: the empty subset
                t[i][j] = 1;
            } 
            else if (arr[i-1] > j) {
                // If current element is greater than sum, exclude it
                t[i][j] = t[i-1][j];
            } 
            else {
                // Include or exclude the current element
                t[i][j] = t[i-1][j] + t[i-1][j - arr[i-1]];
            }
        }
    }

    return t[n][s]; // Number of subsets with required sum
}

int main() {
    int arr[] = {5, 8, 12, 4, 10}; // Input array
    int diff = 1;                  // Target difference between subsets
    int n = sizeof(arr) / sizeof(int);

    // Calculate total sum of elements
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Check if (sum + diff) is even, otherwise return 0 (invalid partition)
    if ((sum + diff) % 2 != 0) {
        printf("0\n"); // No valid subset possible
        return 0;
    }

    // Call the function and print result
    printf("%d\n", count_given_diff_subset(arr, sum, n, diff));
    return 0;
}

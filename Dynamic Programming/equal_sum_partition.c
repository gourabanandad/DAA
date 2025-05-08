/*
    Problem Statement:
    -------------------
    Given an array of positive integers, determine whether it can be partitioned into **two subsets** 
    such that the sum of elements in both subsets is **equal**.

    This is a variation of the **subset sum problem**.
    
    Logic:
    -------
    If the total sum of the array is odd, it's **not possible** to divide it equally.
    If the total sum is even, check if there's a subset with sum = total_sum / 2.
    If such a subset exists, the rest of the elements must also sum to total_sum / 2,
    meaning the array can be split into two equal-sum subsets.

    Example:
    --------
    Input:  arr[] = {1, 2, 5}
    Output: No

    Explanation: 
    Total sum = 8 (even), check if subset with sum = 4 exists.
    No such subset exists => Cannot partition into equal subsets.
*/

#include <stdio.h>

// Tabulation method to check if subset with given sum exists
int equal_sum(int *arr, int sum, int n) {
    int t[sum+1][n+1];

    for (int i = 0; i <= sum; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                // A sum of 0 can always be achieved with empty subset
                t[i][j] = 1;
            } 
            else if (j == 0) {
                // With 0 elements, we can't make a positive sum
                t[i][j] = 0;
            } 
            else {
                if (arr[j-1] > i) {
                    // If element is larger than current sum, exclude it
                    t[i][j] = t[i][j-1];
                } else {
                    // Either include it or exclude it
                    t[i][j] = (t[i - arr[j-1]][j-1] || t[i][j-1]);
                }
            }
        }
    }

    return t[sum][n]; // Returns 1 if subset with given sum exists, else 0
}

int main() {
    int arr[] = {1, 2, 5};     // Input array
    int sum = 0;
    int n = sizeof(arr) / sizeof(int);

    // Calculate total sum
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Check if sum is even
    if (sum % 2 == 0) {
        // Check if subset with sum = sum/2 exists
        if (equal_sum(arr, sum/2, n)) {
            printf("Yes\n"); // Can be partitioned
        } else {
            printf("No\n");  // Cannot be partitioned
        }
    } else {
        printf("No\n");      // Odd sum can't be equally split
    }

    return 0;
}

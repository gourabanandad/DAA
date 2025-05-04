/*Given an array of positive integers, divide it into two subsets such that the absolute difference between the sums of the subsets is minimum.

For example, for arr = {5, 8, 12, 4, 10}, the total sum is 39. The goal is to find two subsets whose sums are as close as possible to each other — say, 19 and 20, giving a minimum difference of 1.*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*
    Function: min_sub_diff
    ----------------------
    Uses Dynamic Programming (Subset Sum variant) to determine the minimum difference
    between the sums of two subsets of a given array.

    arr: The input array
    sum: Total sum of the array
    n:   Number of elements in the array

    Returns:
    Minimum subset sum difference
*/
int min_sub_diff(int *arr, int sum, int n) {
    int t[n+1][sum+1];

    // Initialize the DP table
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(i == 0)
                t[i][j] = 0;  // 0 elements can't make any positive sum
            else if(j == 0)
                t[i][j] = 1;  // Sum 0 is always possible (with empty subset)
            else if(arr[i-1] > j)
                t[i][j] = t[i-1][j];  // Can't include the element
            else
                t[i][j] = t[i-1][j] || t[i-1][j - arr[i-1]];  // Include or exclude
        }
    }

    // Now, try to find the closest sum to total_sum/2
    int min = INT_MAX;
    int limit = sum / 2;

    for(int i = 0; i <= limit; i++) {
        if(t[n][i]) {
            int diff = abs(sum - 2 * i);
            if(diff < min) {
                min = diff;
            }
        }
    }

    return min;
}

int main() {
    int arr[] = {5, 8, 12, 4, 10};
    int n = sizeof(arr) / sizeof(int);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Minimum Subset Sum Difference: %d\n", min_sub_diff(arr, sum, n));
    return 0;
}

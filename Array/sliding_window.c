/*
    Problem Statement:
    -------------------
    Given an array of integers and a number 'k',
    find the maximum sum of any contiguous subarray of size 'k'
    using the sliding window technique.

    Example:
    Input:  arr[] = {2, 1, 5, 1, 3, 2}, k = 3
    Output: 9
    Explanation: Subarray with maximum sum is [5, 1, 3]
*/

#include <stdio.h>

// Function to find the maximum sum of a subarray of size k
int maxSumSubarray(int arr[], int n, int k) {
    // Edge case: if window size k is greater than array size
    if (n < k) {
        printf("Invalid input: Window size is larger than array size.\n");
        return -1;
    }

    int max_sum = 0;     // Will store the maximum sum found
    int window_sum = 0;  // Temporary sum for the current window

    // Step 1: Calculate the sum of the first window of size k
    for (int i = 0; i < k; i++) {
        max_sum += arr[i];
    }

    // Initialize window_sum with the first window's sum
    window_sum = max_sum;

    // Step 2: Slide the window through the array
    for (int i = k; i < n; i++) {
        // Slide the window: add the next element and remove the first element of the previous window
        window_sum += arr[i] - arr[i - k];

        // Update max_sum if the current window's sum is greater
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    // Return the maximum sum found
    return max_sum;
}

int main() {
    // Example input array
    int arr[] = {2, 1, 5, 1, 3, 2};
    int k = 3;  // Size of the window
    int n = sizeof(arr) / sizeof(arr[0]);  // Length of the array

    // Call the function and store the result
    int result = maxSumSubarray(arr, n, k);

    // Print the result
    if (result != -1) {
        printf("Maximum sum of a subarray of size %d is %d\n", k, result);
    }

    return 0;
}

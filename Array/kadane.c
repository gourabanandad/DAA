/*
Kadane’s Algorithm – Maximum Subarray Sum

Problem Statement:
Given an integer array arr[], find the contiguous subarray (containing at least 
one number) which has the largest sum and return its sum.

Example Input:
    arr[] = {-2, 1, -3, 5, -1, 3, 1, -4, 4}

Output:
    8  → (from subarray [5, -1, 3, 1])

⏱️ Time Complexity:  O(n)
🧠 Space Complexity: O(1)
*/

#include <stdio.h>

// Function to find the maximum sum of a contiguous subarray using Kadane's Algorithm
int maxSubarraySum(int arr[], int n) {
    int currentMax = arr[0];
    int maxSoFar = arr[0];

    for (int i = 1; i < n; i++) {
        // Either add current element to the previous subarray OR start fresh from current element
        if (arr[i] > currentMax + arr[i])
            currentMax = arr[i];
        else
            currentMax = currentMax + arr[i];

        // Update the overall maximum if needed
        if (currentMax > maxSoFar)
            maxSoFar = currentMax;
    }

    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 5, -1, 3, 1, -4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, n);
    printf("Maximum Subarray Sum is: %d\n", maxSum);

    return 0;
}

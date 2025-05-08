/*
    Problem Statement:
    -------------------
    Write a program to generate the first 'n' terms of the **Fibonacci series** using iteration.

    The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones.
    The sequence starts with 0 and 1.

    Example:
    --------
    Input:  n = 10
    Output: 0 1 1 2 3 5 8 13 21 34

    Approach:
    ---------
    - Use an array to store Fibonacci terms.
    - Set arr[0] = 0 and arr[1] = 1.
    - For each index i from 2 to n-1, calculate arr[i] = arr[i-1] + arr[i-2].
*/

#include <stdio.h>

// Function to generate the Fibonacci series up to n terms
void fibo(int *arr, int n) {
    arr[0] = 0;             // First Fibonacci number
    arr[1] = 1;             // Second Fibonacci number
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];  // Current = previous + one before previous
    }
}

int main() {
    int n = 10;             // Number of Fibonacci terms to generate
    int arr[n];             // Array to store Fibonacci series

    fibo(arr, n);           // Generate the series

    // Print the Fibonacci series
    printf("The Fibonacci series is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
    Problem Statement:
    -------------------
    Given an array of integers, sort the array in ascending order. The program should
    take the size of the array and its elements as input from the user, and output the
    sorted array.

    This is a classic sorting problem where the goal is to rearrange the elements of the
    array such that they are in non-decreasing order.

    Example:
    Input:
        Enter the size of the array: 5
        Enter the array: 64 34 25 12 22

    Output:
        Original array is: 64 34 25 12 22
        Sorted array is: 12 22 25 34 64

    Explanation:
        The array is sorted in ascending order using a sorting algorithm.

    Approach:
    ---------
    Three methods are implemented below:
    1. Iterative Bubble Sort (Original): Repeatedly compares and swaps adjacent elements.
    2. Recursive Bubble Sort: Uses recursion to perform bubble sort passes.
    3. Optimized Iterative Bubble Sort: Adds a flag to stop early if the array is sorted.
*/

#include <stdio.h>

// ----------------------
// 1. Iterative Bubble Sort (Original, Corrected)
// ----------------------
void bubble_sort_iterative(int arr[], int n) {
    // Iterate through the array
    for (int i = 0; i < n - 1; i++) {
        // Compare and swap adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ----------------------
// 2. Recursive Bubble Sort
// ----------------------
void bubble_sort_recursive(int arr[], int n) {
    // Base case: If only one element, array is sorted
    if (n <= 1) return;

    // One pass of bubble sort: compare and swap adjacent elements
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            // Swap arr[j] and arr[j + 1]
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }

    // Recursively sort the remaining n-1 elements
    bubble_sort_recursive(arr, n - 1);
}

// ----------------------
// 3. Optimized Iterative Bubble Sort
// ----------------------
void bubble_sort_optimized(int arr[], int n) {
    // Iterate through the array
    for (int i = 0; i < n - 1; i++) {
        // Flag to check if any swaps occurred
        int swapped = 0;
        // Compare and swap adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no swaps occurred, array is sorted
        if (swapped == 0) break;
    }
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Input array size
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Input array elements
    int arr[n];
    printf("Enter the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print original array
    printf("Original array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // -------- Iterative Bubble Sort --------
    // bubble_sort_iterative(arr, n);

    // -------- Recursive Bubble Sort --------
    // bubble_sort_recursive(arr, n);

    // -------- Optimized Iterative Bubble Sort --------
    bubble_sort_optimized(arr, n);

    // Print sorted array
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
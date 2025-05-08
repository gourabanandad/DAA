/*
    Problem Statement:
    -------------------
    Given an array of integers, sort the array in ascending order using the Insertion
    Sort algorithm. The program should take the size of the array and its elements as
    input from the user, and output the sorted array.

    Insertion Sort is a simple, comparison-based sorting algorithm that builds the sorted
    array one element at a time by inserting each element into its correct position in
    the previously sorted portion of the array.

    Example:
    Input:
        Enter the size of the array: 5
        Enter the array: 64 34 25 12 22

    Output:
        Sorted array is: 12 22 25 34 64

    Explanation:
        The array is sorted in ascending order by iteratively inserting each element into
        its correct position in the sorted portion of the array.

    Approach:
    ---------
    Three methods are implemented below:
    1. Standard Insertion Sort (Original): Iteratively shifts elements to insert each element.
    2. Recursive Insertion Sort: Uses recursion to perform the insertion process.
    3. Optimized Insertion Sort: Uses swaps instead of shifts for clarity and potential optimization.
*/

#include <stdio.h>

// ----------------------
// 1. Standard Insertion Sort (Original)
// ----------------------
void insertion_sort(int arr[], int n) {
    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Store the current element to be inserted
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key in its correct position
        arr[j + 1] = key;
    }
}

// ----------------------
// 2. Recursive Insertion Sort
// ----------------------
void insertion_sort_recursive(int arr[], int n) {
    // Base case: If array has 1 or fewer elements, it is sorted
    if (n <= 1) return;

    // Recursively sort the first n-1 elements
    insertion_sort_recursive(arr, n - 1);

    // Insert the last element into its correct position
    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && key < arr[j]) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

// ----------------------
// 3. Optimized Insertion Sort (Swap-Based)
// ----------------------
void insertion_sort_optimized(int arr[], int n) {
    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Compare and swap with previous elements until in correct position
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            // Swap arr[j] and arr[j-1]
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
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

    // Note: The original code declares an unused array brr[n], which is omitted here
    // as it is not used in the sorting process

    // -------- Standard Insertion Sort --------
    insertion_sort(arr, n);

    // -------- Recursive Insertion Sort --------
    // insertion_sort_recursive(arr, n);

    // -------- Optimized Insertion Sort --------
    // insertion_sort_optimized(arr, n);

    // Print sorted array
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
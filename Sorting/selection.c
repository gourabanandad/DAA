/*
    Problem Statement:
    -------------------
    Given an array of integers, sort the array in ascending order using the Selection
    Sort algorithm. The program should take the size of the array and its elements as
    input from the user, and output the sorted array.

    Selection Sort is a simple, comparison-based sorting algorithm that repeatedly selects
    the minimum element from the unsorted portion of the array and places it at the beginning
    of the sorted portion. It is not stable but is in-place.

    Example:
    Input:
        Enter the size of the array: 5
        Enter the array: 64 34 25 12 22

    Output:
        Original array is: 64 34 25 12 22
        Sorted array will be:
        12 22 25 34 64

    Explanation:
        The array is sorted in ascending order by finding the minimum element in the unsorted
        portion and swapping it with the first element of the unsorted portion.

    Approach:
    ---------
    Three methods are implemented below:
    1. Standard Selection Sort (Original): Iteratively finds the minimum and swaps.
    2. Recursive Selection Sort: Uses recursion to select the minimum and sort.
    3. Optimized Selection Sort: Adds early termination if the array is already sorted.
*/

#include <stdio.h>

// ----------------------
// Utility function to swap two elements
// ----------------------
void swap(int *a, int *b) {
    // Swap values using a temporary variable
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ----------------------
// 1. Standard Selection Sort (Original)
// ----------------------
void selection_sort_standard(int arr[], int n) {
    // Iterate through the array, treating i as the boundary of the sorted portion
    for (int i = 0; i < n - 1; i++) {
        // Initialize minimum index as the first element of the unsorted portion
        int min_idx = i;
        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted portion
        swap(&arr[min_idx], &arr[i]);
    }
}

// ----------------------
// 2. Recursive Selection Sort
// ----------------------
void selection_sort_recursive(int arr[], int n, int i) {
    // Base case: If i reaches n-1, the array is sorted
    if (i >= n - 1) return;

    // Find the minimum element in the unsorted portion
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[min_idx]) {
            min_idx = j;
        }
    }

    // Swap the minimum element with the first element of the unsorted portion
    swap(&arr[min_idx], &arr[i]);

    // Recursively sort the remaining array
    selection_sort_recursive(arr, n, i + 1);
}

// ----------------------
// 3. Optimized Selection Sort
// ----------------------
void selection_sort_optimized(int arr[], int n) {
    // Iterate through the array
    for (int i = 0; i < n - 1; i++) {
        // Initialize minimum index
        int min_idx = i;
        int swapped = 0; // Flag to check if any swap occurs
        // Find the minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                swapped = 1;
            }
        }
        // Swap only if a smaller element was found
        if (swapped) {
            swap(&arr[min_idx], &arr[i]);
        } else {
            // If no swap occurred, the array is sorted
            break;
        }
    }
}

// ----------------------
// Utility function to print the array
// ----------------------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    printArray(arr, n);

    // -------- Standard Selection Sort --------
    selection_sort_standard(arr, n);

    // -------- Recursive Selection Sort --------
    // selection_sort_recursive(arr, n, 0);

    // -------- Optimized Selection Sort --------
    // selection_sort_optimized(arr, n);

    // Print sorted array
    printf("Sorted array will be: \n");
    printArray(arr, n);

    return 0;
}
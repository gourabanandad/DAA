/*
    Problem Statement:
    -------------------
    Given an array of integers, sort the array in ascending order using the Quick Sort
    algorithm. The program should take an array as input and output the sorted array.

    Quick Sort is a divide-and-conquer, comparison-based sorting algorithm that selects
    a pivot element, partitions the array around the pivot, and recursively sorts the
    subarrays. It is efficient for large datasets but not stable.

    Example:
    Input:
        arr[] = {10, 50, 30, 20, 40}

    Output:
        10 20 30 40 50

    Explanation:
        The array is sorted in ascending order by selecting the last element as the pivot,
        partitioning the array, and recursively sorting the subarrays.

    Approach:
    ---------
    Three methods are implemented below:
    1. Standard Quick Sort (Original, Corrected): Recursive with last element as pivot.
    2. Quick Sort with Random Pivot: Selects a random pivot to avoid worst-case scenarios.
    3. Iterative Quick Sort: Uses a stack to eliminate recursion for better space efficiency.
*/

#include <stdio.h>
#include <stdlib.h>

// ----------------------
// Utility function to swap two elements
// ----------------------
void swap(int *a, int *b) {
    // Swap values using a temporary variable
    int c = *a;
    *a = *b;
    *b = c;
}

// ----------------------
// 1. Standard Quick Sort (Original, Corrected)
// ----------------------
void quicksort_standard(int *arr, int start, int end) {
    // Base case: If start is greater than or equal to end, subarray is sorted
    if (start < end) {
        // Partition the array using the last element as pivot
        int j = start - 1;
        int pivot = arr[end];
        for (int i = start; i < end; i++) {
            if (arr[i] <= pivot) {
                swap(&arr[i], &arr[++j]);
            }
        }
        swap(&arr[j + 1], &arr[end]);
        int pi = j + 1; // Pivot index

        // Recursively sort the left and right subarrays
        quicksort_standard(arr, start, pi - 1);
        quicksort_standard(arr, pi + 1, end);
    }
}

// ----------------------
// 2. Quick Sort with Random Pivot
// ----------------------
int partition_random(int *arr, int start, int end) {
    // Select a random pivot and swap it with the end element
    int pivot_idx = start + rand() % (end - start + 1);
    swap(&arr[pivot_idx], &arr[end]);

    // Partition using the last element (now the random pivot)
    int j = start - 1;
    int pivot = arr[end];
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(&arr[i], &arr[++j]);
        }
    }
    swap(&arr[j + 1], &arr[end]);
    return j + 1; // Return pivot index
}

void quicksort_random(int *arr, int start, int end) {
    // Base case: If start is less than end, partition and sort
    if (start < end) {
        // Partition the array and get pivot index
        int pi = partition_random(arr, start, end);

        // Recursively sort the left and right subarrays
        quicksort_random(arr, start, pi - 1);
        quicksort_random(arr, pi + 1, end);
    }
}

// ----------------------
// 3. Iterative Quick Sort
// ----------------------
void quicksort_iterative(int *arr, int start, int end) {
    // Create a stack for iterative implementation
    int stack[end - start + 1];
    int top = -1;

    // Push initial start and end indices
    stack[++top] = start;
    stack[++top] = end;

    // Process stack until empty
    while (top >= 0) {
        // Pop end and start indices
        end = stack[top--];
        start = stack[top--];

        // Partition the array
        if (start < end) {
            int j = start - 1;
            int pivot = arr[end];
            for (int i = start; i < end; i++) {
                if (arr[i] <= pivot) {
                    swap(&arr[i], &arr[++j]);
                }
            }
            swap(&arr[j + 1], &arr[end]);
            int pi = j + 1;

            // Push smaller subarray first to ensure O(log n) space
            if (pi - 1 > start) {
                stack[++top] = start;
                stack[++top] = pi - 1;
            }
            if (pi + 1 < end) {
                stack[++top] = pi + 1;
                stack[++top] = end;
            }
        }
    }
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Input array
    int arr[] = {10, 50, 30, 20, 40};
    int start = 0;
    int end = 4; // Size of array - 1

    // -------- Standard Quick Sort --------
    quicksort_standard(arr, start, end);

    // -------- Quick Sort with Random Pivot --------
    // quicksort_random(arr, start, end);

    // -------- Iterative Quick Sort --------
    // quicksort_iterative(arr, start, end);

    // Print sorted array
    printf("Sorted array is: ");
    for (int i = 0; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
/*
    Problem Statement:
    -------------------
    Given an array of integers, sort the array in ascending order using the Merge Sort
    algorithm. The program should take an array as input and output the sorted array.

    Merge Sort is a divide-and-conquer, comparison-based sorting algorithm that divides
    the array into two halves, recursively sorts them, and then merges the sorted halves
    to produce a fully sorted array. It is stable and efficient for large datasets.

    Example:
    Input:
        arr[] = {12, 11, 13, 5, 6, 7}

    Output:
        Given array is
        12 11 13 5 6 7
        Sorted array is
        5 6 7 11 12 13

    Explanation:
        The array is sorted in ascending order by recursively dividing it into smaller
        subarrays, sorting them, and merging them back together.

    Approach:
    ---------
    Three methods are implemented below:
    1. Standard Merge Sort (Original): Recursive divide-and-conquer with merging.
    2. Iterative Merge Sort: Uses iteration instead of recursion for sorting.
    3. In-Place Merge Sort: Attempts to reduce space usage by merging in-place (less practical).
*/

#include <stdio.h>
#include <stdlib.h>

// ----------------------
// 1. Standard Merge Sort (Original)
// ----------------------
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes of two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays for left and right subarrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    // If subarray has more than one element, divide and sort
    if (left < right) {
        // Calculate middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// ----------------------
// 2. Iterative Merge Sort
// ----------------------
void merge_iterative(int arr[], int left, int mid, int right, int temp[]) {
    // Same merge logic as standard merge, using a temporary array
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Copy to temporary arrays
    for (int i = 0; i < n1; i++)
        temp[left + i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        temp[mid + 1 + j] = arr[mid + 1 + j];

    // Merge back to arr
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
            arr[k] = temp[i];
            i++;
        } else {
            arr[k] = temp[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        arr[k] = temp[i];
        i++;
        k++;
    }
}

void mergeSort_iterative(int arr[], int n) {
    // Temporary array for merging
    int temp[n];

    // Start with subarrays of size 1, then 2, 4, etc.
    for (int size = 1; size < n; size *= 2) {
        // Merge subarrays of current size
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;
            merge_iterative(arr, left, mid, right, temp);
        }
    }
}

// ----------------------
// 3. In-Place Merge Sort (Simplified)
// ----------------------
void merge_inplace(int arr[], int left, int mid, int right) {
    // Simplified in-place merge by shifting elements
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            // Shift elements to insert arr[j] in correct position
            int temp = arr[j];
            for (int k = j; k > i; k--)
                arr[k] = arr[k - 1];
            arr[i] = temp;
            i++;
            mid++;
            j++;
        }
    }
}

void mergeSort_inplace(int arr[], int left, int right) {
    // Same recursive structure as standard merge sort
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort_inplace(arr, left, mid);
        mergeSort_inplace(arr, mid + 1, right);
        merge_inplace(arr, left, mid, right);
    }
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Input array
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Print original array
    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // -------- Standard Merge Sort --------
    mergeSort(arr, 0, arr_size - 1);

    // -------- Iterative Merge Sort --------
    // mergeSort_iterative(arr, arr_size);

    // -------- In-Place Merge Sort --------
    // mergeSort_inplace(arr, 0, arr_size - 1);

    // Print sorted array
    printf("Sorted array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
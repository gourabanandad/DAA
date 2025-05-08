/*
    Problem Statement:
    -------------------
    Given an array of non-negative integers, sort the array in ascending order using the
    Radix Sort algorithm. The program should take an array as input and output the sorted array.

    Radix Sort is a non-comparison-based sorting algorithm that sorts integers by processing
    their digits from the least significant to the most significant, using a stable sorting
    algorithm (Counting Sort) for each digit position. It is efficient for integers with a
    bounded number of digits.

    Example:
    Input:
        arr[] = {170, 45, 75, 90, 802, 24, 2, 66}

    Output:
        Original array:
        170 45 75 90 802 24 2 66
        Sorted array:
        2 24 45 66 75 90 170 802

    Explanation:
        The array is sorted in ascending order by processing each digit (units, tens, hundreds)
        using Counting Sort, ensuring stability at each step.

    Approach:
    ---------
    Three methods are implemented below:
    1. Standard Radix Sort (Original): Uses Counting Sort for each digit, processes least to most significant.
    2. Radix Sort for Negative Numbers: Handles both positive and negative integers by separating them.
    3. Bucket-Based Radix Sort: Uses buckets instead of Counting Sort for digit processing.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------------------
// Utility function to get the maximum value in the array
// ----------------------
int getMax(int arr[], int n) {
    // Initialize max with first element
    int max = arr[0];
    // Iterate to find the maximum
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ----------------------
// 1. Standard Radix Sort (Original)
// ----------------------
void countingSort(int arr[], int n, int exp) {
    // Output array to store sorted numbers
    int output[n];
    // Count array for digits 0-9
    int count[10] = {0};

    // Count occurrences of each digit at position exp (10^i)
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count[i] to hold the cumulative position for digits
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements in their sorted position
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy sorted numbers back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    // Find the maximum number to determine the number of digits
    int max = getMax(arr, n);

    // Perform Counting Sort for each digit position (units, tens, etc.)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// ----------------------
// 2. Radix Sort for Negative Numbers
// ----------------------
int getMaxAbs(int arr[], int n) {
    // Find maximum absolute value
    int max = abs(arr[0]);
    for (int i = 1; i < n; i++) {
        if (abs(arr[i]) > max) {
            max = abs(arr[i]);
        }
    }
    return max;
}

void countingSort_negative(int arr[], int n, int exp) {
    // Output array and count array for digits -9 to 9
    int output[n];
    int count[19] = {0}; // -9 to 9, indexed as 0 to 18

    // Count occurrences of each digit (shifted to 0-18)
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit + 9]++;
    }

    // Update count for cumulative positions
    for (int i = 1; i < 19; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit + 9] - 1] = arr[i];
        count[digit + 9]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort_negative(int arr[], int n) {
    // Find maximum absolute value
    int max = getMaxAbs(arr, n);

    // Process each digit position
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort_negative(arr, n, exp);
    }
}

// ----------------------
// 3. Bucket-Based Radix Sort
// ----------------------
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void bucketSort(int arr[], int n, int exp) {
    // Create 10 buckets for digits 0-9
    Node* buckets[10] = {NULL};

    // Place elements into buckets based on digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = buckets[digit];
        buckets[digit] = newNode;
    }

    // Collect elements from buckets back to array
    int index = 0;
    for (int i = 0; i < 10; i++) {
        Node* current = buckets[i];
        while (current) {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void radixSort_bucket(int arr[], int n) {
    // Find maximum number
    int max = getMax(arr, n);

    // Process each digit position
    for (int exp = 1; max / exp > 0; exp *= 10) {
        bucketSort(arr, n, exp);
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
    // Input array
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print original array
    printf("Original array:\n");
    printArray(arr, n);

    // -------- Standard Radix Sort --------
    radixSort(arr, n);

    // -------- Radix Sort for Negative Numbers --------
    // radixSort_negative(arr, n);

    // -------- Bucket-Based Radix Sort --------
    // radixSort_bucket(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
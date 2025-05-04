/*
    Problem Statement:
    -------------------
    Given an array of integers, sort the array in ascending order using the Heap Sort
    algorithm. The program should take an array as input and output the sorted array.

    Heap Sort is a comparison-based sorting algorithm that uses a binary heap data
    structure. It first builds a max-heap from the array and then repeatedly extracts
    the maximum element to build the sorted array.

    Example:
    Input:
        arr[] = {12, 11, 13, 5, 6, 7}

    Output:
        Given array is
        12 11 13 5 6 7
        Sorted array is
        5 6 7 11 12 13

    Explanation:
        The array is sorted in ascending order by building a max-heap and extracting
        elements in decreasing order, placing them at the end of the array.

    Approach:
    ---------
    Three methods are implemented below:
    1. Standard Heap Sort (Original): Uses recursive heapify to build a max-heap and sort.
    2. Iterative Heapify: Replaces recursive heapify with an iterative version for better space efficiency.
    3. Min-Heap Heap Sort: Uses a min-heap to sort in ascending order by building the heap and extracting elements.
*/

#include <stdio.h>

// ----------------------
// 1. Standard Heap Sort (Original)
// ----------------------
void heapify(int arr[], int n, int i) {
    // Initialize largest as root
    int largest = i;
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max-heap by heapifying non-leaf nodes
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (maximum) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// ----------------------
// 2. Iterative Heapify
// ----------------------
void heapify_iterative(int arr[], int n, int i) {
    while (1) {
        // Initialize largest as root
        int largest = i;
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; // Right child

        // Find largest among root, left, and right child
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is root, heap property is satisfied
        if (largest == i)
            break;

        // Swap root with largest and continue with largest subtree
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        i = largest;
    }
}

void heapSort_iterative(int arr[], int n) {
    // Build max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_iterative(arr, n, i);

    // Extract elements
/*
  Problem: Two Sum in Sorted Array using Two Pointers Technique
  ------------------------------------------------------------
  Given a sorted array and a target sum, find the first pair of elements
  whose sum equals the target.
 
  Approach:
  - Use two pointers starting at the beginning (left) and end (right) of the array.
  - Calculate the sum of elements at these pointers.
  - If sum equals target, print the pair and return.
  - If sum is less than target, move left pointer right to increase sum.
  - If sum is greater than target, move right pointer left to decrease sum.
 
  Time Complexity: O(n), where n is the size of the array
  Space Complexity: O(1)
 */

#include <stdio.h>
void twoSumSorted(int arr[], int n, int target) {
    int left = 0;          // Initialize left pointer at start of array
    int right = n - 1;     // Initialize right pointer at end of array

    while (left < right) {
        int sum = arr[left] + arr[right];  // Sum of elements at left and right pointers

        if (sum == target) {
            // Pair found with sum equal to target
            printf("Pair found: %d + %d = %d\n", arr[left], arr[right], target);
            return;
        }
        else if (sum < target) {
            // Sum too small, move left pointer right to increase sum
            left++;
        }
        else {
            // Sum too large, move right pointer left to decrease sum
            right--;
        }
    }

    // No pair found with the given target sum
    printf("No pair found with the given target.\n");
}

int main() {
    int arr[] = {1, 2, 4, 7, 11, 15};  // Example sorted array
    int target = 15;                    // Target sum to find
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    twoSumSorted(arr, n, target);       // Call the function

    return 0;
}

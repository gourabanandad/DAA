// Prefix sum is a key concept to find the sum of any subarray efficiently.
// Instead of calculating the sum repeatedly for every subarray,
// we preprocess the array to build a prefix sum array.

#include <stdio.h>

int main() {
    // Input array
    int arr[] = {8, 9, 2, 5, 6, 3};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(int);

    // Declare the prefix array to store cumulative sums
    int prefix[n];

    // Initialize the first element of prefix array
    prefix[0] = arr[0];

    // Build the prefix sum array
    for (int i = 1; i < n; i++) {
        // Each element stores sum from arr[0] to arr[i]
        prefix[i] = prefix[i - 1] + arr[i];
    }

    /*
        Now the prefix array holds:
        prefix[0] = 8
        prefix[1] = 8 + 9 = 17
        prefix[2] = 8 + 9 + 2 = 19
        prefix[3] = 8 + 9 + 2 + 5 = 24
        prefix[4] = 8 + 9 + 2 + 5 + 6 = 30
        prefix[5] = 8 + 9 + 2 + 5 + 6 + 3 = 33

        So, prefix = {8, 17, 19, 24, 30, 33}

        To find sum of any subarray from index l to r:
        sum(l, r) = prefix[r] - prefix[l - 1]
        (Make sure l > 0, otherwise just use prefix[r])
    */

    // Example: Find sum of subarray from index 1 to 3
    // That is: arr[1] + arr[2] + arr[3] = 9 + 2 + 5 = 16
    int sum = prefix[3] - prefix[0];

    // Output the result
    printf("%d", sum); // Output: 16

    return 0;
}

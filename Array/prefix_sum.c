// Prefix sum is a key concept to find out the sum of any subarray of the array
#include <stdio.h>

int main() {
    int arr[] = {8, 9, 2, 5, 6, 3};
    int n = sizeof(arr)/sizeof(int);
    int prefix[n];
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    // 0 -> 8
    // 1 -> 8+9 = 17
    // 2 -> 8+9+2 = 19
    // 3 -> 8+9+2+5 = 24
    // 4 -> 8+9+2+5+6 = 30
    // 5 -> 8+9+2+5+6+3 = 33
    // prefix = {8, 17, 19, 24, 30, 33}
    // sum(l, r) = sum of a subarray of range of l to r then sum(l, r) = prefix[r]-prefix[l-1]
    int sum = prefix[3]-prefix[0]; // sum = arr[1] + arr[2] + arr[3]
    printf("%d", sum);
    
    return 0;
}
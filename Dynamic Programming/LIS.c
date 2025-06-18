#include <stdio.h>
#define MAX 1000
int list[MAX]; // Global variable to store the longest decreasing subsequence
int LIS(int arr[], int n){
    int lis[n]; // Array to store the length of the longest decreasing subsequence ending at each index
    int prev[n]; // Array to store the previous index in the longest decreasing subsequence
    // Initialize the lis and prev arrays
    for(int i=0; i<n;i++){
        lis[i]=1;
        prev[i] = -1;
    }
    int lastindex = 0;
    int max = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((arr[j]<arr[i]) && (lis[i] < lis[j]+1)){
                lis[i] = lis[j]+1;
                prev[i] = j;
            }
        }
        if(lis[i] > max){
            max = lis[i];
            lastindex = i;
        }
    }
    int k = max - 1;
    while(k>=0){
        list[k] = arr[lastindex];
        lastindex = prev[lastindex];
        k--;
    }
    return max;
}
int main() {
    // This program finds the length of the longest decreasing subsequence in an array
    // and also prints the elements of that subsequence.
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Length of Longest Decreasing Subsequence is %d\n", LIS(arr, n));
    printf("Elements of Longest Decreasing Subsequence are: ");
    for (int i = 0; i < n; i++) {
        if (list[i] != 0) {
            printf("%d ", list[i]);
        }
    }
    return 0;
}
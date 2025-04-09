#include <stdio.h>
#include<string.h>

// Devide and conqure
// int count_subset_sum(int *arr, int sum, int n){
//     if(n==0 && sum>0){
//         return 0;
//     }
//     else if(sum==0){
//         return 1;
//     }
//     else if(arr[n-1]>sum){
//         return count_subset_sum(arr, sum, n-1);
//     }
//     else{
//         return (count_subset_sum(arr, sum-arr[n-1], n-1) + count_subset_sum(arr, sum, n-1));
//     }
// }

// Memoization
// int count_subset_sum(int *arr, int sum, int n, int t[n+1][sum+1]){
//     if(sum==0){
//         return 1;
//     }
//     if(n==0){
//         return 0;
//     }
//     if(t[n][sum]!=-1){
//         return t[n][sum];
//     }
//     else if(arr[n-1]>sum){
//         t[n][sum] = count_subset_sum(arr, sum, n-1, t);
//     }
//     else{
//         t[n][sum] = (count_subset_sum(arr, sum-arr[n-1], n-1, t) + count_subset_sum(arr, sum, n-1, t));
//     }
//     return t[n][sum];
// }

// Tabulization

int count_subset_sum(int *arr, int sum, int n){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                t[i][j] = 1;
            }
            else if(i==0){
                t[i][j] = 0;
            }
            else if(arr[i-1] > j){
                t[i][j] = t[i-1][j];
            }
            else{
                t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]);
            }
        }
    }
    return t[n][sum];
}


int main() {
    int arr[] = {2, 8, 10, 5, 3, 7};
    int sum = 10;
    int n = sizeof(arr)/sizeof(int);
    // Divide and Conqure
    // printf("%d ", count_subset_sum(arr, sum, n));

    // Memoization
    // int t[n+1][sum+1];
    // memset(t, -1, sizeof(t));
    // printf("%d ", count_subset_sum(arr, sum, n, t));

    // Tabulization
    printf("%d ", count_subset_sum(arr, sum, n));
    return 0;
}
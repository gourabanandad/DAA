#include <stdio.h>
#include <string.h>
// Brute Force Technique
// int subset_sum(int *arr, int sum, int n){
//     if(sum==0){
//         return 1;
//     }
//     if(n==0){
//         return 0;
//     }
//     if(arr[n-1]>sum){
//         return subset_sum(arr, sum, n-1);
//     }
//     else{
//         return subset_sum(arr, sum-arr[n-1], n-1) || subset_sum(arr, sum, n-1);
//     }
// }


// Memoization 

// int subset_sum(int *arr, int sum, int n, int t[100][100]){
//     if(sum==0){
//         return 1;
//     }
//     if(n==0){
//         return 0;
//     }
//     if(t[n][sum]!=-1){
//         return t[n][sum];
//     }
//     if(arr[n-1]>sum){
//         t[n][sum] = subset_sum(arr, sum, n-1, t);
//     }
//     else{
//         t[n][sum] = (subset_sum(arr, sum-arr[n-1], n-1, t) || subset_sum(arr, sum, n-1, t));
//     }
//     return t[n][sum];
// }

// Tabulation

int subset_sum(int * arr, int sum, int n){
    int t[sum+1][n+1];
    for(int i=0;i<=sum;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                t[i][j] = 1;
            }
            else if(j==0){
                t[i][j] = 0;
            }
            else{
                if(arr[j-1]>i){
                    t[i][j] = t[i][j-1];
                }
                else{
                    t[i][j] = (t[i-arr[j-1]][j-1] || t[i][j-1]);
                }
            }
            
        }
    }
    return t[sum][n];
}

int main() {
    int arr[] = {1, 5, 2, 3};
    int sum = 12;
    int n = sizeof(arr)/sizeof(int);
    
    // memset(t, -1, sizeof(t));
    if(subset_sum(arr, sum, n)){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
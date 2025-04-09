// Problem statement: Suppose there are some coin in an array. Your task is to choose minimum number of coin to achive a desired total.
#include <stdio.h>
#include<limits.h>
// Finding Minimum element
int min(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

// Function to calculate the number of minimum coin.
// This is basically using Tabulaization method or bottom up approach in dynamic programming.
int count_min_coins(int *arr, int sum, int n){
    int t[sum+1][n+1];              // Initialize the dp table of (sum x n) size.
    for(int i=0;i<=sum;i++){
        for(int j=0;j<=n;j++){
            if(j==0){
                t[i][j] = INT_MAX-1;// For the situation when there are zero coins in the array and we have achive non zero target so we need infinte number of coins.
            }
            else if(i==0){
                t[i][j] = 0;  // For the situation where there are some coins in the array but we have achive zero as a target so we need zero number of coins.
            }
            else if(i==2){
                if(j%arr[0]==0){
                    t[i][j] = j/arr[0]; // when the sum is 2 
                }
                else{
                    t[i][j] = INT_MAX-1;
                }
            }
            else if(arr[j-1]>i){
                t[i][j] = t[i][j-1];
            }
            else{
                t[i][j] = min(t[i][j-1], 1+t[i-arr[j-1]][j]);
            }
        }
    }
    return t[sum][n];
}
// Main Function
int main() {
    int arr[] = {2, 4, 5, 6};
    int sum = 6;
    int n = sizeof(arr)/sizeof(int); // Finding the size of the array using sizeof operator
    printf("%d ", count_min_coins(arr, sum, n));
    return 0;
}
#include <stdio.h>
#include<limits.h>
int mcm(int *arr, int i, int j){
    int mn = INT_MAX;
    if(i>=j){
        return 0;
    }
    else{
        
        for(int k=i;k<j;k++){
            int cost = mcm(arr, i, k) + mcm(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
            if(cost<mn){
                mn = cost;
            }
        }
    }
    return mn;
}
int main() {
    int arr[] = {10, 20, 40, 30, 50};
    int n = sizeof(arr)/sizeof(int);
    printf("%d ", mcm(arr, 1, n-1));
    return 0;
}
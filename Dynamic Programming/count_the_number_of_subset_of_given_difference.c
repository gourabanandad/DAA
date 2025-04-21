#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int count_given_diff_subset(int *arr, int sum, int n, int diff){
    int s = ((sum+diff)/2);
    int t[n+1][s+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(i==0){
                t[i][j] = 0;
            }
            else if(j==0){
                t[i][j] = 1;
            }
            else if(arr[i-1]>j){
                t[i][j] = t[i-1][j];
            }
            else{
                t[i][j] = (t[i-1][j] + t[i-1][j-arr[i-1]]);
            }
        }
    }
    
    return t[n][s];
}

int main(){
    int arr[] = {5, 8, 12, 4, 10};
    int diff = 1;
    int n = sizeof(arr)/sizeof(int);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("%d", count_given_diff_subset(arr, sum, n, diff));
    return 0;
}
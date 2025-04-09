#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int min_sub_diff(int *arr, int sum, int n){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
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
                t[i][j] = (t[i-1][j] || t[i-1][j-arr[i-1]]);
            }
        }
    }
    int min = INT_MAX;
    if(sum%2==0){
        for(int i=1;i<=sum/2;i++){
            if(t[n][i]){
                min = (min<(sum-2*i))?min:(sum-2*i);
            }
        }
        return min;
    }
    else{
        for(int i=1;i<=sum/2+1;i++){
            if(t[n][i]){
                min = (min<abs(sum-2*i))?min:abs(sum-2*i);
            }
        }
        return min;
    }
    
}

int main(){
    int arr[] = {5, 8, 12, 4, 10};
    int n = sizeof(arr)/sizeof(int);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("%d", min_sub_diff(arr, sum, n));
    return 0;
}
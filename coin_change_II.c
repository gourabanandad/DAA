#include <stdio.h>
#include<limits.h>
int min(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int count_min_coins(int *arr, int sum, int n){
    int t[sum+1][n+1];
    for(int i=0;i<=sum;i++){
        for(int j=0;j<=n;j++){
            if(j==0){
                t[i][j] = INT_MAX-1;
            }
            else if(i==0){
                t[i][j] = 0;
            }
            else if(i==2){
                if(j%arr[0]==0){
                    t[i][j] = j/arr[0];
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
int main() {
    int arr[] = {2, 4, 5, 6};
    int sum = 6;
    int n = sizeof(arr)/sizeof(int);
    printf("%d ", count_min_coins(arr, sum, n));
    return 0;
}
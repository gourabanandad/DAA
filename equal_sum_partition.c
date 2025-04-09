#include <stdio.h>

// Tabulization
// Similar to subset sum
int equal_sum(int *arr, int sum, int n){
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
                    t[i][j] = (t[i-arr[j-1]][j-1]||t[i][j-1]);
                }
            }
        }
    }
    return t[sum][n];
}

int main() {
    int arr[] = {1,2,5};
    int sum = 0;
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    if(sum%2==0){
        if(equal_sum(arr, sum/2, n)){
            printf("Yes");
        }
        else{
            printf("No");
        }
    }
    else{
        printf("No");
    }
    return 0;
}
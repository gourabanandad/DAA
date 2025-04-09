#include<stdio.h>
void fibo(int *arr, int n) {
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<n;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
}
int main(){
    int n = 10;
    int arr[n];
    fibo(arr, n);
    printf("The fibnacci series is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
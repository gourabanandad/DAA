#include<stdio.h>

int main(){
    int n,key,j;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    int brr[n];
    printf("Enter the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n-1;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("Sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
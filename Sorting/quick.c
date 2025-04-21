#include<stdio.h>

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void quicksort(int *arr, int start, int end){	
	if(start<=end){
		int i;
		int j = start-1;
		int pivot = arr[end];
		for(i=start; i<=end; i++){
		if(pivot>arr[i]){
			swap(&arr[i], &arr[++j]);
		}
	}
	swap(&arr[j+1], &arr[end]);
	int pi = j+1;
	quicksort(arr, start, pi-1);
	quicksort(arr, pi+1, end);
	}
	
}
int main(){
	int start = 0;
	int end = 4;
	int arr[] = {10, 50, 30, 20, 40};
	quicksort(arr, start, end);
	int i;
	for(i=0;i<=4;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}


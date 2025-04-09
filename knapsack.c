#include<stdio.h>
// #include<string.h>
int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

//// Without Dynamic Programming

//int knapsack(int weights[], int values[], int w, int n){
//	if(n==0 || w==0){
//		return 0;
//	}
//	else if(weights[n-1]>w){
//		return knapsack(weights, values, w, n-1);
//	}
//	else{
//		return max(values[n-1]+knapsack(weights, values, w-weights[n-1], n-1), knapsack(weights, values, w, n-1));
//	}
//}

//// Memoization
//
//int t[100][100];
//int knapsack(int weights[], int values[], int w, int n){
//	if(n==0||w==0){
//		return 0;
//	}
//	if(t[w][n]!=0){
//		return t[w][n];
//	}
//	else if(weights[n-1]>w){
//		t[w][n] =  knapsack(weights, values, w, n-1);
//	}
//	else{
//		t[w][n] = max(values[n-1]+knapsack(weights, values, w-weights[n-1], n-1), knapsack(weights, values, w, n-1));
//	}
//	return t[w][n];
//}

// Tabulation

int knapsack(int weights[], int values[], int w, int n){
	int t[w+1][n+1];
	int i, j;
	for(i=0;i<=w;i++){
		for(j=0;j<=n;j++){
			if(i==0||j==0){
				t[i][j] = 0;
			}
			else if(weights[j]>i){
				t[i][j] = t[i][j-1];
			}
			else{
				t[i][j] = max(values[j]+t[i-weights[j]][j-1], t[i][j-1]);
			}
		}
	}
	return t[w][n];
}

int main(){
	int weights[] = {1, 3, 4, 6};
	int values[]= {2, 3, 5, 7};
	int w = 10;
	// memset(t, 0, sizeof(t));
	int n = sizeof(weights)/sizeof(int);
	printf("%d", knapsack(weights, values, w, n));
	return 0;
}


#include<stdio.h>

int max(int a, int b){
    int m = (a>b)?a:b;
    return m;
}

int unbounded_knapsack(int weights[], int values[], int w, int n){
	int t[w+1][n+1];
	int i, j;
	for(i=0;i<=w;i++){
		for(j=0;j<=n;j++){
			if(i==0||j==0){
				t[i][j] = 0;
			}
			else if(weights[j-1]>i){
				t[i][j] = t[i][j-1];
			}
			else{
				t[i][j] = max(values[j-1]+t[i-weights[j-1]][j], t[i][j-1]);
			}
		}
	}
	return t[w][n];
}

int main(){
	int weights[] = {1, 3, 4, 6};
	int values[]= {2, 3, 5, 7};
	int w = 10;
	int n = sizeof(weights)/sizeof(int);
	printf("%d", unbounded_knapsack(weights, values, w, n));
	return 0;
}
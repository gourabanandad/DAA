#include <stdio.h>

int coin_change_maximum_way(int * coin, int total, int n){
    int t[total+1][n+1];
    for(int i=0;i<=total;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                t[i][j] = 1;
            }
            else if(j==0){
                t[i][j] = 0;
            }
            else{
                if(coin[j-1]>i){
                    t[i][j] = t[i][j-1];
                }
                else{
                    t[i][j] = (t[i-coin[j-1]][j] + t[i][j-1]);
                }
            }
            
        }
    }
    return t[total][n];
}

int main() {
    int coin[] = {1, 5, 2, 3};
    int total = 12;
    int n = sizeof(coin)/sizeof(int);
    printf("%d", coin_change_maximum_way(coin, total, n));
    return 0;
}
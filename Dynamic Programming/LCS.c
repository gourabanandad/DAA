#include <stdio.h>
#include<string.h>
#include<time.h>
int max(int a, int b){
    return (a>b)?a:b;
}
// Brute Force method 

// int lcs(char *x, char *y, int m, int n){
//     if(m==0 || n==0){
//         return 0;
//     }
//     if(x[m-1]==y[n-1]){
//         return 1+lcs(x, y, m-1, n-1);
//     }
//     else{
//         return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));  // We can eleminate either the first string element or 2nd string element
//     }
// }

// Memoization or Top down approach

int t[100][100];
int lcs(char *x, char *y, int m, int n){
    if(m==0 || n==0){
        return t[m][n] = 0;
    }
    if(t[m][n]!=-1){
        return t[m][n];
    }
    if(x[m-1]==y[n-1]){
        t[m][n] = 1+lcs(x, y, m-1, n-1);
    }
    else{
        t[m][n] = max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));  // We can eleminate either the first string element or 2nd string element
    }
    return t[m][n];
}

int main() {
    char x[] = "ABCBDABABCBDABABCBDABABCBDAB";
    char y[] = "BDCABADBDCABADBDCABADBDCABAD";
    clock_t start, end;
    double time_used;
    int m = sizeof(x)/sizeof(char);
    int n = sizeof(y)/sizeof(char);
    start = clock();
    memset(t, -1, sizeof(t));
    printf("%d\n", lcs(x, y, m-1, n-1));
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%.8f", time_used);
    return 0;
}
/*
    Problem Statement:
    -------------------
    Given an array of coin denominations and a total amount,
    find the total number of ways to make the total using **unlimited supply** of coins.

    Example:
    Input:
        coins[] = {1, 5, 2, 3}
        total = 12
    Output:
        15

    Explanation:
        There are 15 different ways to make sum 12 using coins of denominations 1, 5, 2, and 3.
        You can reuse each coin any number of times.

    Approach:
    ----------
    Use Dynamic Programming:
    - Let t[i][j] represent the number of ways to make sum 'i' using the first 'j' coins.
    - If coin[j-1] > i: skip current coin.
    - Else: include current coin or exclude it.
*/

#include <stdio.h>

// Function to calculate the number of ways to make 'total' using 'n' coins
int coin_change_maximum_way(int *coin, int total, int n) {
    // Create a DP table where t[i][j] is number of ways to make sum i using first j coins
    int t[total + 1][n + 1];

    // Fill the DP table
    for (int i = 0; i <= total; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                // Base Case: Only one way to make sum 0 (use no coin)
                t[i][j] = 1;
            } else if (j == 0) {
                // Base Case: Can't make positive sum with 0 coins
                t[i][j] = 0;
            } else {
                if (coin[j - 1] > i) {
                    // Current coin is too large to be included
                    t[i][j] = t[i][j - 1];
                } else {
                    // Include the coin + Exclude the coin
                    t[i][j] = t[i - coin[j - 1]][j] + t[i][j - 1];
                }
            }
        }
    }

    // Final answer is in t[total][n]
    return t[total][n];
}

int main() {
    // Coin denominations
    int coin[] = {1, 5, 2, 3};

    // Target total
    int total = 12;

    // Number of coins
    int n = sizeof(coin) / sizeof(int);

    // Output the result
    printf("%d", coin_change_maximum_way(coin, total, n));

    return 0;
}

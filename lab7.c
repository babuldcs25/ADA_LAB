#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    int dp[W + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {


        for (int w = W; w >= weights[i]; w--) {

            dp[w] = max(dp[w],
                        values[i] + dp[w - weights[i]]);
        }
    }

    return dp[W];
}

int main() {
    int n, W;


    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];


    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }


    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);


    int result = knapsack(W, weights, values, n);

    printf("Maximum Profit = %d\n", result);

    return 0;
}

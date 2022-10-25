#include <stdio.h>

int coin_change(int coins[], int size, int sum)
{
    int dp[size + 1][sum + 1];

    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0) {
                dp[0][j] = 0;
            }
            else if (j == 0) {
                dp[i][0] = 1;
            }
            else if (coins[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[size][sum];
}

int main()
{
    int coins[] = { 1, 2, 3, 4, 5, 7};
    int size = sizeof(coins) / sizeof(coins[0]);
    int sum = 12;
    int result = coin_change(coins, size, sum);
    printf("Number of ways are :  %d",result);
    return 0;
}

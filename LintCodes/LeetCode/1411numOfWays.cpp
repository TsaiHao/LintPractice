#include "LeetCode.h"
using namespace std;

int numOfWays(int n)
{
    int mod = 1e9 + 7;
    vector<vector<long long>> dp(2, vector<long long>(n + 1, 0));

    dp[0][1] = 6;
    dp[1][1] = 6;
    for (int i = 2; i <= n; ++i)
    {
        dp[0][i] = ((3 * dp[0][i - 1]) % mod + 
                        (2 * dp[1][i - 1]) % mod) % mod;
        dp[1][i] = ((2 * ((dp[1][i - 1] + dp[0][i - 1]) % mod))) % mod;
    }
    return (dp[0][n] + dp[1][n]) % mod;
}
#include <algorithm>
#include <numeric>

#include "LeetCode.h"
using namespace std;

int cuttingRope(int n)
{
    if (n < 5) {
        if (n == 1 || n == 4) {
            return n;
        }
        else {
            return n - 1;
        }
    }
    vector<int> dp(n, 0);
    iota(dp.begin(), dp.end(), 1);
    for (int i = 4; i < n; ++i)
    {
        for (int j = 0; j < i / 2 + 1; ++j) {
            if (dp[j] * dp[i - j - 1] > dp[i]) {
                dp[i] = dp[j] * dp[i - j - 1];
            }
        }
    }
    return dp[n - 1];
}
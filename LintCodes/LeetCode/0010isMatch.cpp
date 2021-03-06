#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include "LeetCode.h"
using namespace std;

inline bool charEqual(const char a, const char b)
{
    return b == '.' || a == b;
}

bool isMatch(string s, string p)
{
    s = " " + s;
    p = " " + p;

    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < s.size() + 1; ++i)
    {
        for (int j = 1; j < p.size() + 1; ++j)
        {
            if (charEqual(s[i - 1], p[j - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                if (!charEqual(s[i - 1], p[j - 2])) {
                    dp[i][j] = dp[i][j - 2];
                }
                else {
                    dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                }
            }
        }
    }
    return dp.back().back();
}

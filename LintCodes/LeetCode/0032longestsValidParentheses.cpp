#include <string>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

int longestValidParentheses(string s)
{
    int len = s.size();
    vector<int> record(len, 0);
    vector<int> stk;
    int longest = 0;

    for (int i = 0; i < len; ++i)
    {
        if (s[i] == ')') {
            if (stk.empty()) {
                continue;
            }
            int index = stk.back();
            stk.pop_back();
            record[i] = record[i - 1] + 2;
            if (index != 0)
            {
                record[i] += record[index - 1];
            }
            if (record[i] > longest) {
                longest = record[i];
            }
        }
        if (s[i] == '(')
        {
            stk.push_back(i);
        }
    }
    return longest;
}
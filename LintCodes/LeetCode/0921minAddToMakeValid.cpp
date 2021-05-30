#include <algorithm>
#include <stack>

#include "LeetCode.h"
using namespace std;

int minAddToMakeValid(string S)
{
    if (S.empty())
    {
        return 0;
    }
    stack<int> stk;
    int toAdd = 0;
    for (size_t i = 0; i < S.size(); ++i)
    {
        if (S[i] == ')') {
            if (stk.empty())
                ++toAdd;
            else {
                stk.pop();
            }
        }
        else {
            stk.push('(');
        }
    }
    toAdd += stk.size();
    return toAdd;
}
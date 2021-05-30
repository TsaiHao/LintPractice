#include <vector>
#include <string>

#include "LeetCode.h"
using namespace std;

void step(vector<string>& result, int stk, string now, bool psh, int n, int eta)
{
    if (psh)
    {
        if (eta <= 0)
        {
            return;
        }
        now.push_back('(');
        ++stk;
        --eta;
        if (now.size() == n)
        {
            result.push_back(now);
            return;
        }
        else 
        {
            step(result, stk, now, true, n, eta);
            step(result, stk, now, false, n, eta);
        }
    }
    else 
    {
        if (stk == 0)
        {
            return;
        }
        --stk;
        now.push_back(')');
        if (now.size() == n)
        {
            result.push_back(now);
            return;
        }
        else 
        {
            step(result, stk, now, true, n, eta);
            step(result, stk, now, false, n, eta);
        }
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    string now;
    step(result, 0, now, true, n * 2, n);
    return result;
}
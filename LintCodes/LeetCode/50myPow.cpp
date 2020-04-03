#include <algorithm>

#include "LeetCode.h"
using namespace std;

// use 3 to split n
// non recursive way
double myPow(double x, int n)
{
    if (n == 0) {
        return 1;
    }
    bool neg = n < 0;
    unsigned int exp;
    if (n == INT32_MIN)
    {
        exp = INT32_MAX + 1;
    }
    else
    {
        exp = (n < 0 ? -n : n);
    }
    
    double pw = 1;
    double memo[3] = {1, x, x*x};
    vector<int> residual;

    while(exp > 0)
    {
        residual.push_back(exp % 3);
        exp /= 3;
    }
    while(residual.size() > 1)
    {
        pw *= memo[residual.back()];
        residual.pop_back();
        pw = pw * pw *pw;
    }
    if (!residual.empty())
        pw *= memo[residual.back()];
    return neg ? 1/pw : pw;
}
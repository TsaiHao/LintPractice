#include <algorithm>
#include "leetcode.h"
using namespace  std;

int maxProfit2(vector<int>& prices)
{
    int i_1 = INT32_MIN;
    int i_0 = 0;
    for (auto& x: prices) {
        int temp = i_1;
        i_1 = max(i_1, i_0 - x);
        i_0 = max(i_0, temp + x);
    }
    return i_0;
}
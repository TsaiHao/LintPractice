#include "LeetCode.h"
using namespace std;

int translateNum(int num)
{
    vector<int> v;
    if (num <= 10) {
        return 1;
    }
    while (num > 0)
    {
        v.push_back(num % 10);
        num /= 10;
    }

    int count = 1;
    int prev = 0;
    for (auto iter = v.begin() + 1; iter < v.end(); ++iter)
    {
        if (*iter * 10 + *(iter - 1) < 26) {
            count *= 2;
            count -= prev;
            prev = 1;
        }
        else
        {
            prev = 0;
        }
    }
    return count;
}
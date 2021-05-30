#include <algorithm>
#include <numeric>
#include "LeetCode.h"

using namespace std;


inline int sum(vector<int>& arr, int value)
{
    return accumulate(arr.begin(), arr.end(), 0, 
    [value](int a, int b) {
        return a + (b > value ? value : b);
    });
}
int findBestValue(vector<int>& arr, int target)
{
    if (arr.empty())
    {
        return 0;
    }
    sort(arr.begin(), arr.end());

    int maxv = arr.back(), minv = arr.front();
    if (target > maxv * arr.size())
    {
        return maxv;
    }

    int prefix = 0;
    for (auto iter = arr.begin(); iter < arr.end(); ++iter)
    {
        target -= prefix;
        int avg = target / (arr.end() - iter);
        if (avg < *iter)
        {
            double x = (double)target / (arr.end() - iter);
            if (x - avg > 0.5)
            {
                return avg + 1;
            }
            else {
                return avg;
            }
        }
        prefix = *iter;
    }
    return maxv;
}
#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    size_t size = nums.size();
    if (size <= 1) {
        return size;
    }

    vector<int> dp{ 1 };
    for (int i = 1; i < size; ++i) {
        dp.push_back(1);
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
   
    return *max_element(dp.begin(), dp.end());
}
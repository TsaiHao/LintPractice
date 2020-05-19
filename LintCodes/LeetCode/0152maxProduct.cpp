#include <numeric>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

int calculate(vector<int>& nums, int negNum)
{
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    auto prodFun = [](const int& a, const int& b)->int { return a * b; };
    if (negNum % 2 == 0) {
        return accumulate(nums.begin(), nums.end(), 1, prodFun);
    }

    auto findFun = [](const int& a)->bool { return a < 0; };
    auto leftNeg = nums.end();
    auto rightNeg = nums.end();
    for (auto iter = nums.begin(); iter != nums.end(); ++iter)
    {
        if (*iter < 0) {
            if (leftNeg == nums.end()) {
                leftNeg = iter;
            }
            rightNeg = iter;
        }
    }
    return max(accumulate(nums.begin(), rightNeg, 1, prodFun),
                accumulate(leftNeg + 1, nums.end(), 1, prodFun));
}
int findMaxproduct(vector<int>& nums)
{
    vector<int> part;
    int maxPro = 0;
    int negNums = 0;

    for (auto iter = nums.begin(); iter < nums.end(); ++iter)
    {
        if (*iter == 0) {
            maxPro = max(maxPro, calculate(part, negNums));
            part.clear();
            negNums = 0;
            continue;
        }
        if (*iter < 0) {
            ++negNums;
        }
        part.push_back(*iter);
    }
    maxPro = max(maxPro, calculate(part, negNums));
    return maxPro;
}
int maxProduct(vector<int>& nums)
{
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    return findMaxproduct(nums);
}}
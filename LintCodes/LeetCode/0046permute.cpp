#include <algorithm>
#include <numeric>

#include "LeetCode.h"
using namespace std;

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> res;
    if (nums.empty())
    {
        return res;
    }
    while (next_permutation(nums.begin(), nums.end()))
    {
        res.push_back(nums);
    }
    return res;
}
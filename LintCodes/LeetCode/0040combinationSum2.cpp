#include <algorithm>
#include "LeetCode.h"
using namespace std;

using vit = vector<int>::iterator;
vector<vector<int>> res;
void dfs(vit beg, vit end, int target, vector<int>& nums)
{
    if (beg >= end) {
        if (0 == target) {
            res.push_back(nums);
        }
        return;
    }
    if (0 >= target) {
        if (0 == target)
            res.push_back(nums);
        return;
    }
    for (auto iter = beg; iter < end; ++iter) {
        if (iter != beg && (*iter == *(iter - 1))) {
            continue;
        }
        nums.push_back(*iter);
        dfs(iter + 1, end, target - *iter, nums);
        nums.pop_back();
    }
}
//40
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> s;
    dfs(candidates.begin(), candidates.end(), target, s);
    return res;
}
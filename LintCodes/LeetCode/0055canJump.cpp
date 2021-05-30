#include <algorithm>

#include "LeetCode.h"
using namespace std;

bool canReach(size_t start, bool* reachable, vector<int>& nums)
{
    if (nums[start] == 0) {
        reachable[start] = false;
        return false;
    }
    if (start == 0) {
        reachable[start] = true;
        return true;
    }
    for (long i = start - 1; i >=0; --i)
    {
        if (reachable[i] && start - i <= nums[i]) {
            reachable[start] = true;
            return true;
        }
    }
    reachable[start] = false;
    return false;
}

bool canJump(vector<int>& nums)
{
    if (nums.size() <= 1) {
        return true;
    }

    size_t N = nums.size();
    bool* reachable = new bool[nums.size()];
    for (size_t i = 0; i < nums.size(); ++i) 
    {
        if (!canReach(i, reachable, nums))
        {
            continue;
        }
        if (N - i - 1 <= nums[i] )
        {
            return true;
        }
    }

    delete[] reachable;
}
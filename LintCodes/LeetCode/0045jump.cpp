#include "LeetCode.h"

using std::vector;
int jump(vector<int>& nums)
{
    if (nums.empty()) {
        return 0;
    }
    int board = 0;
    int maxDistance = 0;
    int step = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        maxDistance = max(maxDistance, i + nums[i]);
        if (i == board) {
            ++step;
            board = maxDistance;
        }
    }
    return step;
}
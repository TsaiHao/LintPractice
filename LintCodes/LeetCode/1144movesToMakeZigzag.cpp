#include "LeetCode.h"

using namespace std;

int movesToMakeZigzag(vector<int> &nums) {
    if (nums.size() <= 1) {
        return 0;
    }
    int oddTimes = 0, evenTimes = 0;
    int n = nums.size();
    for (int i = 0; i < n; i += 2) {
        int low = 0;
        if (i == 0) low = nums[1];
        else if (i == n - 1) low = nums[n - 2];
        else low = (nums[i + 1] < nums[i - 1] ? nums[i + 1] : nums[i - 1]);
        oddTimes += (nums[i] < low ? 0 : nums[i] - low + 1);
    }
    for (int i = 1; i < n; i += 2) {
        int low;
        if (i == n - 1) low = nums[n - 2];
        else low = (nums[i + 1] < nums[i - 1] ? nums[i + 1] : nums[i - 1]);
        evenTimes += (nums[i] < low ? 0 : nums[i] - low + 1);
    }
    return (oddTimes < evenTimes ? oddTimes : evenTimes);
}

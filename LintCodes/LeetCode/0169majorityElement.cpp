#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

int majorityElement(vector<int>& nums)
{
    if (nums.empty()) {
        return 0;
    }
    int candinate = nums.front();
    int count = 1;

    for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
        if (candinate == *iter) {
            ++count;
        }
        else {
            --count;
        }
        if (count == 0) {
            candinate = *iter;
            count = 1;
        }
    }
    return candinate;
}
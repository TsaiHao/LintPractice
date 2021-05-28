#include "LeetCode.h"

int totalHammingDistance(vector<int>& nums) {
    int bits = 32;
    unsigned int mask = 1;
    int dis = 0;

    for (int i = 0; i < 32; ++i) {
        int zeros = 0, ones = 0;
        for (auto const &x : nums) {
            (mask & x) ? ++zeros : ++ones;
        }
        mask <<= 1;
        dis += zeros * ones;
    }

    return dis;
}
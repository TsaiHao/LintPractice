#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

int maxArea(vector<int>& height)
{
    if (height.size() < 2) {
        return -1;
    }

    auto left = height.begin();
    auto right = height.end() - 1;
    int maxarea = 0;
    while(left < right)
    {
        int area = min(*left, *right) * (right - left);
        if (area > maxarea) {
            maxarea = area;
        }
        if (*left < *right) {
            int l = *left;
            while(left < right && (*left <= l))
            {
                ++left;
            }
        }
        else {
            int r = *right;
            while(left < right && (*right <= r)) 
            {
                --right;
            }
        }
    }
    return maxarea;
}
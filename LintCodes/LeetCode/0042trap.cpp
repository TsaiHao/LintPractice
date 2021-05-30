#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

void fillMaxVector(vector<int>& height, vector<int>& left, vector<int>& right, int low, int high)
{
    if (high <= low) 
    {
        return;
    }

    int maxv = height[low], maxi = low;
    for (int i = low; i < high; ++i)
    {
        if (height[i] > maxv)
        {
            maxv = height[i];
            maxi = i;
        }
    }
    for (int i = maxi; i >= low; --i)
    {
        if (right[i] == -1)
        {
            right[i] = maxi;
        }
    }
    for (int i = maxi; i < high; ++i)
    {
        if (left[i] == -1)
        {
            left[i] = maxi;
        }
    }
    fillMaxVector(height, left, right, low, maxi);
    if (maxi != high)
        fillMaxVector(height, left, right, maxi + 1, high);
}

int trap(vector<int>& height)
{
    int len = height.size();
    if (len < 3)
    {
        return 0;
    }
    vector<int> leftMax(len, -1), rightMax(len, -1);
    fillMaxVector(height, leftMax, rightMax, 0, len);
    int area = 0;
    for (int i = 0; i < len; ++i)
    {
        int bin = min(height[leftMax[i]], height[rightMax[i]]) - height[i];
        if (bin > 0)
        {
            area += bin;
        }
    }
    return area;
}
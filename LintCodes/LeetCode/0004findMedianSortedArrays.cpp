#include <algorithm>

#include "LeetCode.h"
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    size_t m = nums1.size();
    size_t n = nums2.size();
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int left = 0, right = m; 
    int median = (m + n + 1) >> 1;

    while (left <= right)
    {
        int i = (left + right) >> 1;
        int j = median - i;
        if (i < right && nums2[j-1] > nums1[i]) {
            left = i + 1;
        }
        else if (i > left && nums1[i - 1] > nums2[j]) {
            right = i - 1;
        }
        else 
        {
            int maxLeft;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            }
            else if (j == 0) {
                maxLeft = nums1[i - 1];
            }
            else 
                maxLeft = max(nums1[i - 1], nums2[j - 1]);
            if (((n + m) & 0x01) == 1) {
                return maxLeft;
            }

            else {
                int maxRight = 0;
                if (i == m) {
                    maxRight = nums2[j];
                }
                else if (j == n) {
                    maxRight = nums1[i];
                }
                else 
                    maxRight = max(nums1[i], nums2[j]);
                return double(maxRight + maxLeft) / 2.0;
            }
        }
    }
    return 0;
}

void test0004()
{
    vector<int> nums1{1, 2}, nums2{3, 4};
    cout << "midian of ";
    displayArray(nums1, cout);
    cout << " and ";
    displayArray(nums2, cout);
    cout << "is " << findMedianSortedArrays(nums1, nums2) << endl;
    cout << "test done" << endl; 
}
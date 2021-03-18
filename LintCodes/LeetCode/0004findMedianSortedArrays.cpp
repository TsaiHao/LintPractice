#include <algorithm>
#include <limits.h>
#include "LeetCode.h"
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size(), n = nums2.size();
    int k = (m + n + 1) / 2;
    int left = 0, right = m;
    int median1, median2;

    while (left <= right) {
        int m1 = (left + right) / 2;
        int m2 = k - m1;

        int nums1_left = (m1 == 0 ? INT_MIN : nums1[m1 - 1]);
        int nums1_right = (m1 == m ? INT_MAX : nums1[m1]);
        int nums2_left = (m2 == 0 ? INT_MIN : nums2[m2 - 1]);
        int nums2_right = (m2 == n ? INT_MAX: nums2[m2]);

        if (nums1_left <= nums2_right) {
            median1 = max(nums1_left, nums2_left);
            median2 = min(nums2_right, nums1_right);
            left = m1 + 1;
        } else {
            right = m1 - 1;
        }
    }
    return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
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
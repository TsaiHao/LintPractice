#include <algorithm>
#include <vector>

#include "Declaration.h"

using std::vector;
using std::swap;
using vsizet = std::vector<int>::size_type;

int selectKthLargest(vector<int> &nums, vsizet beg, vsizet end, vsizet n)
{
	if (beg >= end)
		return nums[beg];
	auto left = beg, right = end;
	int pivot = nums[vsizet((beg + end) / 2)];
	while (left <= right)
	{
		while (left <= right && nums[left] > pivot)
		{
			++left;
		}
		while (left <= right && nums[right] < pivot)
		{
			--right;
		}
		if (left <= right)
		{
			swap(nums[left], nums[right]);
			++left;
			--right;
		}
	}

	if (n >= left)
	{
		return selectKthLargest(nums, left, end, n);
	}
	else if (n <= right)
	{
		return selectKthLargest(nums, beg, right, n);
	}
	else
	{
		return nums[n];
	}
}

int kthLargestElement(int n, vector<int>& nums)
{
	if (n > nums.size() || n < 1)
		return 0;
	else
		return selectKthLargest(nums, 0, nums.size() - 1, n - 1);
}
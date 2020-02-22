#include <vector>
#include <algorithm>
#include "Declaration.h"

using std::vector;
using std::sort;

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
	int len = nums.size();
	int sum, left, right;
	int ivalue, jvalue;
	vector<int> tmp;
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < len - 3; ++i) 
	{
		if (i != 0 && nums[i] == nums[i - 1])
			continue;
		ivalue = nums[i];
		for (int j = i + 1; j < len - 2; ++j) 
		{
			if (j != i + 1 && nums[j - 1] == nums[j])
				continue;
			jvalue = nums[j];
			sum = target - (ivalue + jvalue);
			left = j + 1;
			right = len - 1;

			while (left < right)
			{
				int leftv = nums[left], rightv = nums[right];
				if (leftv + rightv == sum) 
				{
					tmp.clear();
					tmp.push_back(ivalue);
					tmp.push_back(jvalue);
					tmp.push_back(leftv);
					tmp.push_back(rightv);
					res.push_back(tmp);
					
					while (left < right && nums[left] == leftv) {
						++left;
					}
					while (left < right && nums[right] == rightv) {
						--right;
					}
				}
				else
				{
					if (leftv + rightv < sum)
					{
						while (left < right && nums[left] == leftv) {
							++left;
						}
					}
					else
					{
						while (left < right && nums[right] == rightv) {
							--right;
						}
					}
				}
			}
		}
	}
	return res;
}
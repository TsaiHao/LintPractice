#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	using vst = vector<int>::size_type;
	vector<vector<int>> res;
	vst numsize = nums.size();
	if (numsize < 3) {
		return res;
	}

	sort(nums.begin(), nums.end());
	for (vst i = 0; i < nums.size() - 2; ++i) {
		if (i != 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		vector<int> tmp;
		vst left = i + 1, right = nums.size() - 1;
		int sum = -nums[i];
		while (left < right) {
			int lvalue = nums[left], rvalue = nums[right], realSum = nums[left] + nums[right];
			if (realSum == sum) {
				tmp.push_back(nums[i]);
				tmp.push_back(lvalue);
				tmp.push_back(rvalue);
				while (left < right && nums[left] == lvalue) {
					++left;
				}
				while (left < right && nums[right] == rvalue) {
					--right;
				}
				res.push_back(tmp);
				tmp.clear();
			}
			else if (realSum < sum) {
				while (left < right && nums[left] == lvalue) {
					++left;
				}
			}
			else {
				while (left < right && nums[right] == rvalue) {
					--right;
				}
			}
		}
	}

	return res;
}
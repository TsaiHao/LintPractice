#include <vector>
#include <algorithm>
#include <numeric>

#include "LeetCode.h"
using namespace std;

vector<int> singleNumbers(vector<int>& nums)
{
	if (nums.empty()) {
		return vector<int>({ 0,0 });
	}

	int x =	accumulate(nums.begin(), nums.end(), 0, [](int x, int y) { return x ^ y; });
	int mask = 1;

	while ((mask & x) == 0)
	{
		mask <<= 1;
	}
	int left = 0;
	for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
		if ((*iter & mask) == 0) {
			left ^= (*iter);
		}
	}
	int right = left ^ x;
	return vector<int>({ left, right });
}
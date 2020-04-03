#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

typedef vector<int>::iterator iter;
void quickSort(iter beg, iter end)
{
	if (end - beg < 2) {
		return;
	}
	int pivot = *(end - 1);
	auto left = partition(beg, end, [pivot](int x) {return x < pivot; });
	auto right = partition(left, end, [pivot](int x) {return x <= pivot; });
	quickSort(beg, left);
	quickSort(right, end);
}

vector<int> sortArray(vector<int>& nums)
{
	quickSort(nums.begin(), nums.end());
	return nums;
}
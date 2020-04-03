#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	if (intervals.size() <= 1) {
		return intervals;
	}
	sort(intervals.begin(), intervals.end(), [](vector<int> x1, vector<int> x2) {
		return x1[0] < x2[0];
		});
	vector<vector<int>> res;
	
	res.push_back(*intervals.begin());
	for (auto iter = intervals.begin() + 1; iter != intervals.end(); ++iter) {
		if ((*iter)[0] <= res.back()[1]) {
			if ((*iter)[1] <= res.back()[1]) {
				continue;
			}
			else {
				res.back()[1] = (*iter)[1];
			}
		}
		else {
			res.push_back(*iter);
		}
	}
	return res;
}
#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

int maxProfit(vector<int>& prices)
{
	if (prices.size() <= 1) {
		return 0;
	}
	int minValue = 0;
	int maxProfit = 0;
	for (auto i = prices.begin(); i != prices.end(); ++i) {
		if (i == prices.begin()) {
			minValue = *i;
		}
		int profit = *i - minValue;
		profit = profit < 0 ? 0 : profit;
		maxProfit = max(maxProfit, profit);
		minValue = minValue > (*i) ? (*i) : minValue;
	}
	return maxProfit;
}


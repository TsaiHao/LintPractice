#include <vector>
#include <algorithm>
#include <limits.h>
#include "LeetCode.h"
using namespace std;

int maxProfit3(vector<int>& prices)
{
	int state_2_1 = -INT_MAX, state_2_0 = 0;
	int state_1_1 = -INT_MAX, state_1_0 = 0;
	for (auto iter = prices.begin(); iter != prices.end(); ++iter) {
		state_2_0 = max(state_2_0, state_2_1 + *iter);
		state_2_1 = max(state_2_1, state_1_0 - *iter);
		state_1_0 = max(state_1_0, state_1_1 + *iter);
		state_1_1 = max(state_1_1, -*iter);
	}
	return state_2_0;
}
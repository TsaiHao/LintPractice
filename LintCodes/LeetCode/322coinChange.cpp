#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

using vit = vector<int>::iterator;
void coinChange(vit beg, vit end, int amount, int& minCoins, int upCount)
{
	if (beg >= end) {
		return;
	}
	if (amount <= 0) {
		return;
	}

	int tail = *(end - 1);
	if (upCount + amount / tail > minCoins) {
		return;
	}
	if (amount % tail == 0) {
		minCoins = min(amount / tail + upCount, minCoins);
		return;
	}
	int factor = amount / tail;
	do {
		coinChange(beg, end - 1, amount - factor * (tail), minCoins, factor + upCount);
		--factor;
	} while (factor >= 0);
}

int coinChange(vector<int>& coins, int amount)
{
	if (coins.empty()) {
		return -1;
	}
	if (amount <= 0) {
		return 0;
	}
	sort(coins.begin(), coins.end());
	vector<int> res;
	int minCoins = INT_MAX;
	coinChange(coins.begin(), coins.end(), amount, minCoins, 0);
	return minCoins == INT_MAX ? -1: minCoins;
}
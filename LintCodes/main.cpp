#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "LintCode/LintCode.h"
#include "Leetcode/LeetCode.h"

using namespace std;

int main()
{
	vector<vector<int>> test;
	test.push_back({ 1, 3 });
	test.push_back({ 2, 6 });
	test.push_back({ 8, 10 });
	test.push_back({ 15, 18 });
	for (auto v : merge(test)) {
		for (auto i : v) {
			cout << i << '\t';
		}
		cout << endl;
	}
	return 0;
}

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "LintCode/LintCode.h"
#include "Leetcode/LeetCode.h"

using namespace std;

int main()
{
	vector<vector<string>> vv;
	vv.push_back({ "John", "johnsmith@mail.com", "john00@mail.com" });
	vv.push_back({ "John", "johnnybravo@mail.com" });
	vv.push_back({ "John", "johnsmith@mail.com", "john_newyork@mail.com" });
	vv.push_back({ "Mary", "mary@mail.com" });

	auto res = accountsMerge(vv);
	for (auto& v : res) {
		for (auto& s : v) {
			cout << s << '\t';
		}
		cout << endl;
	}
	return 0;
}

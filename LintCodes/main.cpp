#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "LintCode/LintCode.h"
#include "LeetCode/LeetCode.h"
using namespace std;
	
int main(int argc, char* argv[])
{
	vector<vector<int>> vv;
	vector<int> v;
	vector<string> dict;
	string s, word;
	int i;

	if (argc < 2)
	{
		cerr << "usage error" << endl;
		exit(1);
	}	
	int nth = atoi(argv[1]);
	if (nth == 0)
	{
		cerr << "number error" << endl;
		exit(1);
	}

	if (nth == 10)
	{
		cin >> s >> word;
		cout << isMatch(s, word) << endl;
	}
	
	if (nth == 30)
	{
		cin >> s;
		while (cin >> word) {
			dict.push_back(word);
		}
		v = findSubstring(s, dict);
		for (auto i: v) {
			cout << i << '\t';
		}
		cout << endl;
	}

	if (nth == 32)
	{
		while (cin >> s) {
			cout << "longest valid parentheses: " << longestValidParentheses(s) << endl;
		}
	}

	if (nth == 42)
	{
		while (cin >> i) {
			v.push_back(i);
		}
		cout << trap(v) << endl;
	}
	return 0;
}

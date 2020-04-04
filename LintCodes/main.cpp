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

	if (nth == 30)
	{
		cin >> s;
		while (cin >> word)
		{
			dict.push_back(word);
		}
		v = findSubstring(s, dict);
		for (auto i: v)
		{
			cout << i << '\t';
		}
		cout << endl;
	}
	
	if (nth == 32)
	{
		while (cin >> s)
		{
			cout << "longest valid parentheses: " << longestValidParentheses(s) << endl;
		}
	}
	return 0;
}

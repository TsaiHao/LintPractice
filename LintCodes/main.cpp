#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>
#include "LintCode/LintCode.h"
#include "LeetCode/LeetCode.h"
using namespace std;
typedef istream_iterator<int> in;

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

	if (nth == 343) 
	{
		int x;
		while (cin >> x) {
			cout << "max multiply: " << cuttingRope(x) << endl;
		}
	}
	if (nth == 445)
	{
		int n1, n2;
		while (cin >> n1 >> n2) {
			fun445test(n1, n2);
		}
	}

	if (nth == 946) 
	{
		int M;
		cin >> M;
		vector<int> pushed(M), popped(M);
		for (int i = 0; i < M; ++i) {
			cin >> pushed[i];
		}
		for (int j = 0; j < M; ++j) {
			cin >> popped[j];
		}
		cout << validateStackSequences(pushed, popped) << endl;
	}
	return 0;
}

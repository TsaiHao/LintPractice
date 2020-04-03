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
	int a = atoi(argv[1]);
	auto v = generateParenthesis(a);
	for (auto s: v)
	{
		cout << s << endl;
	}
	return 0;
}

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "LintCode/LintCode.h"
#include "LeetCode/LeetCode.h"
using namespace std;
	
int main()
{
	vector<vector<int>> board{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
	gameOfLife(board);
	for (auto v: board)
	{
		for (auto i : v) 
		{
			cout << i << '\t';
		}
		cout << endl;
	}
	return 0;
}

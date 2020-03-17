#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>
#include "LintCode/LintCode.h"
#include "LeetCode/LeetCode.h"
#include <deque>
#include <thread>
#include <chrono>
#include <future>
#include <list>
using namespace std;
	
int main()
{
	vector<vector<int>> grid;
	grid.push_back({ 1,1,0,0,0 });
	grid.push_back({ 1,1,0,0,0 });
	grid.push_back({ 0,0,0,1,1 });
	grid.push_back({ 0,0,0,1,1 });

	cout << maxAreaOfIsland(grid) << endl;
	return 0;
}

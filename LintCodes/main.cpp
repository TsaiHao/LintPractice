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
	vector<vector<int>> grid{ {1, 0, 1}, {0, 0, 0}, {1, 0, 1} };
	cout << maxDistance(grid) << endl;
	return 0;
}

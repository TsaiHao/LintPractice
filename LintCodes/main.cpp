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
	vector<int> v{1, 2, 5, 2};
	auto a = singleNumbers(v);

	cout << a[0] << ", " << a[1] << endl;
	return 0;
}

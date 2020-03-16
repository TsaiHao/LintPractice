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
	string s;
	while(cin >> s) {
		cout << myAtoi(s) << endl;
	}
	return 0;
}

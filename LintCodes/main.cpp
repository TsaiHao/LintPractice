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
	vector<string> vs;
	string tmp;
	string start, end;
	cin >> start >> end;
	while(cin >> tmp)
	{
		vs.push_back(tmp);
	}
	cout << ladderLength(start, end, vs) << endl;
	return 0;
}

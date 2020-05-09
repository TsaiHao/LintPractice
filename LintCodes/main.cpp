#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
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

	if (nth == 4) 
		test0004();

	if (nth == 7) 
		test0007();

	if (nth == 23) 
		test0023();
		
	if (nth == 347) 
		test0347();

	return 0;
}

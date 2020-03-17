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
	vector<string> words{ "cat", "bt", "hat", "tree" };
	string chars = "atach";
	cout << countCharacters(words, chars) << endl;
	return 0;
}

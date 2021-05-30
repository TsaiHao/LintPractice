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
    vector<int> v{2, 1, 3, 5, 4, 6, 7};
    cout << getWinner(v, 2) << endl;

	return 0;
}

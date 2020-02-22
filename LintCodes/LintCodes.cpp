#include <string>
#include <iostream>
#include <vector>

#include "LintCodes.h"
#include "algorithms/Declaration.h"
using namespace std;

int main()
{
	vector<int> vv{ 1, 3, 4, -2, 3, -5, 0 };
	auto res = fourSum(vv, 1);

	for (auto& v : res)
	{
		for (auto i : v)
			cout << i << '\t';
		cout << endl;
	}
	return 0;
}

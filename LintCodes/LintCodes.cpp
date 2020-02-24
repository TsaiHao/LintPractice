#include <string>
#include <iostream>
#include <vector>

#include "LintCodes.h"
#include "algorithms/Declaration.h"
using namespace std;

int main()
{
	vector<int> v({ 1, 2 , 6, 4 , 5, 8, 20, 34, 32});
	cout << kthLargestElement(2, v);

	return 0;
}

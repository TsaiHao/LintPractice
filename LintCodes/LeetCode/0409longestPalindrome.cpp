#include <string>
#include <vector>

#include "LeetCode.h"
using namespace std;

int longestPalindrome(string s)
{
	vector<int> charCount(128, 0);
	for (auto c : s) {
		++charCount[int64_t(c)];
	}
	int length = 0;
	int odd = 0;
	for (auto i : charCount) {
		if (i % 2 == 0) {
			length += i;
		}
		else {
			odd = 1;
			length += i - 1;
		}
	}

	return length + odd;
}
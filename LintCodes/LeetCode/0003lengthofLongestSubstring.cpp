#include <string>
#include <unordered_map>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

int lengthOfLongestSubstring(string s)
{
	if (s.size() <= 1) {
		return s.size();
	}
	unordered_map<char, string::size_type> charPosi;
	size_t longestDis = 0;
	auto leftBound = s.begin();

	for (auto iter = s.begin(); iter != s.end(); ++iter) {
		auto nowPosi = charPosi.find(*iter);
		
		if (nowPosi == charPosi.end()) {
			charPosi[*iter] = iter - s.begin();
			continue;
		}
		auto strPosi = charPosi[*iter] + s.begin();
		charPosi[*iter] = iter - s.begin();
		if (strPosi < leftBound) {
			//charPosi[*iter] = iter - s.begin();
			continue;
		}
		else {
			size_t nowDis = iter - leftBound;
			longestDis = max(longestDis, nowDis);
			leftBound = strPosi + 1;
		}
	}
	if (leftBound != s.end()) {
		size_t nowDis = s.end() - leftBound;
		longestDis = max(longestDis, nowDis);
	}
	return longestDis;
}
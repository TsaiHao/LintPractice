#include <vector>
#include <string>
#include <unordered_map>

#include "LeetCode.h"
using namespace std;

inline bool canExpressed(string& sentence, unordered_map<char, int> dict)
{
	for (auto iter = sentence.begin(); iter != sentence.end(); ++iter) {
		if (dict.find(*iter) == dict.end()) {
			return false;
		}
		if (dict[*iter] <= 0) {
			return false;
		}
		--dict[*iter];
	}
	return true;
}
int countCharacters(vector<string>& words, string chars)
{
	if (words.empty() || chars.empty()) {
		return 0;
	}

	unordered_map<char, int> odict;
	for (auto iter = chars.begin(); iter != chars.end(); ++iter) {
		if (odict.find(*iter) == odict.end()) {
			odict[*iter] = 1;
		}
		else {
			++odict[*iter];
		}
	}

	int total_size = 0;
	for (auto iter = words.begin(); iter != words.end(); ++iter) {
		if (canExpressed(*iter, odict)) {
			total_size += iter->size();
		}
	}
	return total_size;
}
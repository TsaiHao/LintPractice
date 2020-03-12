#include <string>
#include <deque>
#include "LeetCode.h"
using namespace std;

int gcdofInts(int a, int b)
{
	if (a < b) {
		swap(a, b);
	}

	while (b > 1) {
		int r = a % b;
		if (r == 0) {
			return b;
		}
		a = b;
		b = r;
	}
	return 1;
}

bool isValid(const string& str, const string substr)
{
	if (str.empty() || substr.empty()) {
		return false;
	}
	int length = str.size();
	int l = substr.size();
	if (length % l != 0) {
		return false;
	}
	if (length == l) {
		return str == substr;
	}
	auto iter = str.begin();
	while (iter + l <= str.end()) {
		if (string(iter, iter + l) == substr) {
			iter += l;
		}
		else {
			return false;
		}
	}
	
	return true;
}

deque<int> getDivisor(int a)
{
	deque<int> ret;
	deque<int> aci;
	for (int i = 2; i * i <= a; ++i) {
		if (a % i == 0) {
			ret.push_front(i);
			if (i != a/i)
				aci.push_back(a / i);
		}
	}
	while (!aci.empty()) {
		ret.push_front(aci.back());
		aci.pop_back();
	}
	ret.push_front(a);
	ret.push_back(1);
	return ret;
}

string gcdOfStrings(string str1, string str2)
{
	if (str1.empty() || str2.empty()) {
		return string("");
	}
	int length1 = str1.size(), length2 = str2.size();
	int gcd = gcdofInts(length1, length2);
	for (int i : getDivisor(gcd)) {
		string tmp = string(str1.begin(), str1.begin() + i);
		if (isValid(str1, tmp) && isValid(str2, tmp)) {
			return tmp;
		}
	}
	return string("");
}
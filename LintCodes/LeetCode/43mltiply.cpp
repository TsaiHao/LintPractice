#include <string>
#include <sstream>
#include <vector>
#include "LeetCode.h"
using namespace std;

string stringPlus(string& s1, string& s2)
{
	auto iter1 = s1.rbegin();
	auto iter2 = s2.rbegin();
	string res("");
	bool overflow = false;
	char c = '0';
	while (iter1 != s1.rend() && iter2 != s2.rend()) {
		c = *iter1 + *iter2 - '0' + (int)overflow;
		if (c > '9') {
			overflow = true;
			c -= 10;
		}
		else {
			overflow = false;
		}
		res.push_back(c);
		++iter1;
		++iter2;
	}
	while (iter1 != s1.rend()) {
		c = *iter1 + (int)overflow;
		if (c > '9') {
			overflow = true;
			c -= 10;
		}
		else {
			overflow = false;
		}
		res.push_back(c);
		++iter1;
	}
	while (iter2 != s2.rend()) {
		c = *iter2 + (int)overflow;
		if (c > '9') {
			overflow = true;
			c -= 10;
		}
		else {
			overflow = false;
		}
		res.push_back(c);
		++iter2;
	}
	if (overflow) {
		res.push_back('1');
	}
	return string(res.rbegin(), res.rend());
}

string stringMultiplyOneBit(string& s, char c)
{
	int n = c - '0';
	if (n == 0) {
		return string("0");
	}
	auto iter = s.rbegin();
	int overBit = 0;
	int m = 0;
	string res("");
	while (iter != s.rend()) {
		m = (*iter - '0') * n + overBit;
		overBit = m / 10;
		char r = (char)(m % 10) + '0';
		res.push_back(r);
		++iter;
	}
	if (overBit != 0) {
		res.push_back((char)overBit + '0');
	}
	return string(res.rbegin(), res.rend());
}

string multiply(string num1, string num2)
{
	if (num1 == "0" || num2 == "0") {
		return string("0");
	}

	int numbits = num2.size();
	vector<string> bitRes;
	for (auto i = num2.begin(); i != num2.end(); ++i) {
		bitRes.push_back(stringMultiplyOneBit(num1, *i));
	}
	string res("0");
	for (auto i : bitRes) {
		for (int n = numbits - 1; n > 0; --n) {
			i.push_back('0');
		}
		--numbits;
		res = stringPlus(res, i);
	}
	return res;
}
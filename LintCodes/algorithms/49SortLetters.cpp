#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include <array>
#include "Declaration.h"
using std::string;
using std::map;
using std::pair;
using std::array;

inline int convertLetter(char c)
{
	if (c < 0x60)
	{
		return c - 0x27;
	}
	else
	{
		return c - 0x61;
	}
}
void sortLetters(string& chars)
{
	auto nchar = chars.size();
	string sorted(nchar, '0');
	array<size_t, 52> count = { 0 };

	for (size_t i = 0; i < nchar; ++i)
	{
		int a = convertLetter(chars[i]);
		count[a]++;
	}
	for (size_t i = 1; i < 52; ++i)
	{
		count[i] += count[i - 1];
	}
	for (size_t i = 0; i < nchar; ++i)
	{
		int index = convertLetter(chars[i]);
		sorted[count[index] - 1] = chars[i];
		count[index]--;
	}
	chars = sorted;
}
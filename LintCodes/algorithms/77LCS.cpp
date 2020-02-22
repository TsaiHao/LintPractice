#include <string>
#include <algorithm>

#include "Declaration.h"
using std::string;
using std::max;
int LCS(string& s1, string& s2)
{
	auto m = s1.size(), n = s2.size();
	int** trace = new int* [m + 1];
	for (int i = 0; i < m + 1; ++i)
	{
		trace[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; ++i)
	{
		trace[i][0] = 0;
	}
	for (int j = 0; j <= n; ++j)
	{
		trace[0][j] = 0;
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) {
				trace[i][j] = trace[i - 1][j - 1] + 1;
			}
			else {
				trace[i][j] = max(trace[i - 1][j], trace[i][j - 1]);
			}
		}
	}

	int lcs = trace[m][n];
	for (int i = 0; i < m + 1; ++i)
	{
		delete[] trace[i];
	}
	delete[] trace;
	return lcs;
}
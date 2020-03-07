#include <vector>

#include "LeetCode.h"
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> res;
	if (matrix.empty() || matrix[0].empty()) {
		return res;
	}
	size_t m = matrix.size(), n = matrix[0].size();
	size_t x = 0, y = 0;
	size_t offset = 0;

	while (offset <= (m / 2) && offset <= (n / 2)) {
		for (x = offset, y = offset; y <= n - offset - 1; ++y) {
			res.push_back(matrix[x][y]);
		}
		for (; x <= m - offset - 1; ++x) {
			res.push_back(matrix[x][y]);
		}
		for (; y > offset; --y) {
			res.push_back(matrix[x][y]);
		}
		for (; x > offset; --x) {
			res.push_back(matrix[x][y]);
		}
		offset++;
	}
	return res;
}
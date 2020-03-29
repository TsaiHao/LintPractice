#include <vector>
#include <algorithm>
#include <utility>

#include "LeetCode.h"
using namespace std;
typedef pair<size_t, size_t> cord;

const cord operator+(const cord& lhs, const cord& rhs)
{
	cord c;
	c.first = lhs.first + rhs.first;
	c.second = lhs.second + rhs.second;
	return c;
}

int maxDistance(vector<vector<int>>& grid)
{
	cord dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	if (grid.empty() || grid[0].empty()) {
		return 0;
	}
	size_t row = grid.size(), col = grid[0].size();
	int zeros = 0;
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < col; ++j) {
			if (grid[i][j] == 0) {
				++zeros;
			}
		}
	}
	if (zeros == 0 || zeros == row * col) {
		return -1;
	}

	int n = 1;
	while (zeros > 0) {
		
		for (size_t i = 0; i < row; ++i) {
			for (size_t j = 0; j < col; ++j) {
				if (grid[i][j] == n) {
					if (i > 0 && grid[i - 1][j] == 0) {
						grid[i - 1][j] = n + 1;
						--zeros;
					}
					if (i < row - 1 && grid[i + 1][j] == 0) {
						grid[i + 1][j] = n + 1;
						--zeros;
					}
					if (j > 0 && grid[i][j - 1] == 0) {
						grid[i][j - 1] = n + 1;
						--zeros;
					}
					if (j < col - 1 && grid[i][j + 1] == 0) {
						grid[i][j + 1] = n + 1;
						--zeros;
					}
				}
			}
		}
		++n;
	}
	return n - 1;
}
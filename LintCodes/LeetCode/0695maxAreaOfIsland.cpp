#include <vector>
#include <algorithm>
#include <deque>
#include <utility>

#include "LeetCode.h"
using namespace std;

int findArea(vector<vector<int>>& grid, size_t i, size_t j, vector<vector<bool>> visited)
{
	pair<size_t, size_t> tmp({ i, j });
	if (visited[i][j]) {
		return 0;
	}
	visited[i][j] = true;
	deque<pair<size_t, size_t>> cors{ tmp };
	int area = 0;
	while (!cors.empty()) {
		tmp = cors.front();
		int row = tmp.first;
		int col = tmp.second;
		cors.pop_front();
		if (grid[row][col] == 1) {
			++area;
			grid[row][col] = 0;
			if (row > 0 && grid[row - 1][col] == 1 && !visited[row - 1][col]) {
				cors.push_back({ tmp.first - 1, tmp.second });
				visited[row - 1][col] = true;
			}
			if (row < grid.size() - 1 && grid[row + 1][col] == 1 && !visited[row + 1][col]) {
				cors.push_back({ row + 1, col });
				visited[row + 1][col] = true;
			}
			if (col > 0 && grid[row][col - 1] == 1 && !visited[row][col - 1]) {
				cors.push_back({ row, col - 1 });
				visited[row][col - 1] = true;
			}
			if (col < grid[0].size() - 1 && grid[row][col + 1] == 1 && !visited[row][col + 1]) {
				cors.push_back({ row, col + 1 });
				visited[row][col + 1] = true;
			}
		}
	}
	return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int maxArea = 0;
	if (grid.empty() || grid[0].empty()) {
		return 0;
	}
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
	for (size_t i = 0; i < grid.size(); ++i) {
		for (size_t j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == 1) {
				int area = findArea(grid, i, j, visited);
				maxArea = max(area, maxArea);
			}
		}
	}
	return maxArea;
}
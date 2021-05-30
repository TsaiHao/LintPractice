#include <algorithm>

#include "LeetCode.h"
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    for (auto& line : matrix) {
        if (line[0] > target) {
            return false;
        }
        if (line.back() < target) {
            continue;
        }
        auto iter = lower_bound(line.begin(), line.end(), target);
        if (iter == line.end() || *iter != target) {
            continue;
        }
        if (*iter == target) {
            return true;
        }
    }
}